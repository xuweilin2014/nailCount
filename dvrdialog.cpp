#include "dvrdialog.h"
#include "ui_dvrdialog.h"
#include "mywidget.h"
#include <map>
#include <iostream>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

using namespace std;

DVRDialog::DVRDialog(map<string, int>& nails, QWidget *parent) :
	QDialog(parent),nailNums(nails),
    ui(new Ui::DVRDialog)
{
    ui->setupUi(this);
	connect(ui->buttonSave, &QPushButton::clicked, this, &DVRDialog::saveNailNumsAsJson);
}

DVRDialog::~DVRDialog()
{
    delete ui;
}

void DVRDialog::setNailNumOnDialog() {
	map<string, int>::iterator nailIter = nailNums.begin();
	for (; nailIter != nailNums.end(); nailIter++) {
		string lineName = "line" + nailIter->first;
		QLineEdit* line = findChild<QLineEdit*>(QString::fromStdString(lineName));
		line->setText(QString::fromStdString(to_string(nailIter->second)));
	}
}

void DVRDialog::saveNailNumsAsJson() {
	QString jsonPath = QFileDialog::getSaveFileName(this, "保存", ".", "JSON(*.json)");

	if (jsonPath.isEmpty() == false) {
		map<string, int>::iterator nailIter = nailNums.begin();
		QJsonObject boxJson;
		QJsonArray boxArray;
		for (; nailIter != nailNums.end(); nailIter++) {
			QJsonObject lineJson;
			lineJson.insert(QString::fromStdString(nailIter->first), nailIter->second);
			boxArray.append(lineJson);
		}
		boxJson.insert("DVR", QJsonValue(boxArray));

		//构建Json文档
		QJsonDocument document;
		document.setObject(boxJson);
		QByteArray byteArray = document.toJson(QJsonDocument::Compact);
		QString jsonStr(byteArray);

		QFile jsonFile;
		jsonFile.setFileName(jsonPath);
		bool isOk = jsonFile.open(QIODevice::WriteOnly);
		if (isOk == true) {
			jsonFile.write(jsonStr.toUtf8());
			MyWidget::showInfoDialogModal("提示", "保存成功!");
			//弹出一个对话框，内容为"保存成功！"
		}
		else {
			//弹出一个对话框，内容为"保存文件失败"
			MyWidget::showInfoDialogModal("提示", "保存文件失败");
		}
		jsonFile.close();
	}
	else {
		//弹出一个对话框，内容为"保存文件的路径不合法"
		MyWidget::showInfoDialogModal("提示", "保存文件的路径不合法");
	}

}
