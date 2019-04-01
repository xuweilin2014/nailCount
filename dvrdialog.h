#ifndef DVRDIALOG_H
#define DVRDIALOG_H

#include <QDialog>
#include <map>
#include <iostream>

using namespace std;

namespace Ui {
class DVRDialog;
}

class DVRDialog : public QDialog
{
    Q_OBJECT

public:
	explicit DVRDialog(map<string, int>& nailNums, QWidget *parent = 0);
	void setNailNumOnDialog();
	void saveNailNumsAsJson();
    ~DVRDialog();

private:
    Ui::DVRDialog *ui;
	map<string, int> nailNums;
};

#endif // DVRDIALOG_H
