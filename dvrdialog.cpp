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
	QString jsonPath = QFileDialog::getSaveFileName(this, "����", ".", "JSON(*.json)");

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

		//����Json�ĵ�
		QJsonDocument document;
		document.setObject(boxJson);
		QByteArray byteArray = document.toJson(QJsonDocument::Compact);
		QString jsonStr(byteArray);

		QFile jsonFile;
		jsonFile.setFileName(jsonPath);
		bool isOk = jsonFile.open(QIODevice::WriteOnly);
		if (isOk == true) {
			jsonFile.write(jsonStr.toUtf8());
			MyWidget::showInfoDialogModal("��ʾ", "����ɹ�!");
			//����һ���Ի�������Ϊ"����ɹ���"
		}
		else {
			//����һ���Ի�������Ϊ"�����ļ�ʧ��"
			MyWidget::showInfoDialogModal("��ʾ", "�����ļ�ʧ��");
		}
		jsonFile.close();
	}
	else {
		//����һ���Ի�������Ϊ"�����ļ���·�����Ϸ�"
		MyWidget::showInfoDialogModal("��ʾ", "�����ļ���·�����Ϸ�");
	}

}
