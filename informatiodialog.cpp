#include "informatiodialog.h"
#include "ui_informatiodialog.h"

InformatioDialog::InformatioDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformatioDialog)
{
    ui->setupUi(this);
}

InformatioDialog::~InformatioDialog()
{
    delete ui;
}

void InformatioDialog::setInfo(const QString &info){
    ui->infoLabel->setText(info);
}
