#include "dvrdialog.h"
#include "ui_dvrdialog.h"
#include <map>
#include <iostream>

using namespace std;

DVRDialog::DVRDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DVRDialog)
{
    ui->setupUi(this);
}

DVRDialog::~DVRDialog()
{
    delete ui;
}

void DVRDialog::setNailNumOnDialog(map<string, int>& nailNums) {
	map<string, int>::iterator nailIter = nailNums.begin();
	for (; nailIter != nailNums.end(); nailIter++) {
		string lineName = "line" + nailIter->first;
		QLineEdit* line = findChild<QLineEdit*>(QString::fromStdString(lineName));
		line->setText(QString::fromStdString(to_string(nailIter->second)));
	}
}
