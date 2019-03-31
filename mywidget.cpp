#include "mywidget.h"
#include "ui_mywidget.h"
#include "boxtypedialog.h"
#include "dvrdialog.h"
#include "nailcount.h"
#include "informatiodialog.h"
#include <QIcon>
#include <QSize>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QDebug>
#include <QImageReader>
#include <QList>

extern vector<string> BOXTYPE;

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget),isImageUploaded(false),imgPath(""),nailColor("")
{
    ui->setupUi(this);
	findBoxType();
    initButtonIcon();
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::initButtonIcon(){
    //设置上传图片按钮的Icon
    QPushButton* uploadImage = ui->uploadImage;
    QIcon iconUploadImage(":/icon/icons/上传图片.png");
    uploadImage->setIcon(iconUploadImage);
    uploadImage->setIconSize(QSize(30,30));
    uploadImage->setFlat(true);

    //设置摄像按钮的Icon
    QPushButton* film = ui->film;
    QIcon iconFilm(":/icon/icons/摄像.png");
    film->setIcon(iconFilm);
    film->setIconSize(QSize(30,30));
    film->setFlat(true);

    //设置生成Excel文档按钮的Icon
    QPushButton* genExcel = ui->genExcel;
    QIcon iconGenExcel(":/icon/icons/Excel文件.png");
    genExcel->setIcon(iconGenExcel);
    genExcel->setIconSize(QSize(30,30));
    genExcel->setFlat(true);

    //设置计数按钮的Icon
    QPushButton* nailCount = ui->nailCount;
    QIcon iconCount(":/icon/icons/计数.png");
    nailCount->setIcon(iconCount);
    nailCount->setIconSize(QSize(45,45));
    nailCount->setFlat(true);

    //设置盒子类型按钮的Icon
    QPushButton* boxType = ui->boxType;
    QIcon iconBoxType(":/icon/icons/类型.png");
    boxType->setIcon(iconBoxType);
    boxType->setIconSize(QSize(30,30));
    boxType->setFlat(true);

}


void MyWidget::on_uploadImage_clicked()
{
	QImage* image = new QImage();
    QString fileName = QFileDialog::getOpenFileName(this,"上传图片",".",
              "Image (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    if(fileName.isEmpty() == false){
        qDebug() << fileName;
        bool flag = image->load(fileName,"jpg");
        if(flag){
            QSize imageSize = ui->graphicsView->size();
			imgPath = fileName.toStdString();
            QGraphicsScene* scene = new QGraphicsScene(this);
            //调整图片的大小
            scene->addPixmap(QPixmap::fromImage(image->scaled(imageSize,Qt::KeepAspectRatio)));
            ui->graphicsView->setScene(scene);
            ui->graphicsView->show();
			isImageUploaded = true;
        }else{
            //显示information框，"图片上传失败"
			showInfoDialogModal("警告", "图片上传失败");
        }
    }else{
        //显示一个警告框，"文件的路径名不能为空"
		showInfoDialogModal("警告", "文件的路径名不能为空");
    }

	delete image;
}


void MyWidget::on_boxType_clicked()
{
    BoxTypeDialog* boxTypeDialog = new BoxTypeDialog(this);
    int ret = boxTypeDialog->exec();
    if(ret == QDialog::Accepted){
        boxType = boxTypeDialog->getBoxType();
		nailColor = boxTypeDialog->getNailColor();
    }

    delete boxTypeDialog;
}


void MyWidget::on_nailCount_clicked()
{
	
	if (!isImageUploaded) {
		//生成一个警告框，内容为"请先上传图片"
		showInfoDialogModal("警告", "请先上传图片");
		return;
	}

	bool isTypeLegal = false;
	map<string, int> nailNums;
	int nailVal;
	vector<string>::iterator typeIter = BOXTYPE.begin();
	for (; typeIter != BOXTYPE.end(); typeIter++) {
		if (boxType == *typeIter) {
			findBoxDetail(boxType);
			if (imgPath != "") {
				Mat image = imread(imgPath.data());
				if (boxType == "DVR") {
					nailNums = boxDVR(image);
				}
				else if (boxType == "POLYX") {
					if (nailColor.empty()) {
						const QString info = "请先选择钉盒中钉子的颜色";
						showInfoDialogModal("警告", info);
						return ;
					}
					else if(nailColor == "绿色"){
						nailVal = boxPOLYX(image, "green");
					}
					else if (nailColor == "黄色") {
						nailVal = boxPOLYX(image, "yellow");
					}
				}
			}
			isTypeLegal = true;
		}
	}

	if (!isTypeLegal) {
		//生成一个警告框，内容为"请先选择合适的钉盒类型"
		showInfoDialogModal("警告", "请先选择合适的钉盒类型");
	}
	else {
		if (boxType == "DVR") {
			DVRDialog* dvrDialog = new DVRDialog(this);
			dvrDialog->setNailNumOnDialog(nailNums);
			int ret = dvrDialog->exec();
			delete dvrDialog;
		}
		else if (boxType == "POLYX") {
            //生成一个信息框，内容为钉子的数目
			const QString info = "PLOYX钉盒的数目为 " + QString::fromStdString(to_string(nailVal));
			showInfoDialogNonModal("钉子数目", info);
		}
	}
}

//生成一个非模态的对话窗口
void MyWidget::showInfoDialogNonModal(const QString& title, const QString& info) {
	InformatioDialog* infoDialog = new InformatioDialog(this);
	infoDialog->setAttribute(Qt::WA_DeleteOnClose);
	infoDialog->setInfo(info);
	infoDialog->setWindowTitle(title);
	infoDialog->show();
}

//生成一个模态的对话窗口
void MyWidget::showInfoDialogModal(const QString& title, const QString& info) {
	InformatioDialog* infoDialog = new InformatioDialog(this);
	infoDialog->setInfo(info);
	infoDialog->setWindowTitle(title);
	infoDialog->exec();
	delete infoDialog;
}
