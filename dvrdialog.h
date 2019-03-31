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
    explicit DVRDialog(QWidget *parent = 0);
	void setNailNumOnDialog( map<string, int>& nailNums);
    ~DVRDialog();

private:
    Ui::DVRDialog *ui;
};

#endif // DVRDIALOG_H
