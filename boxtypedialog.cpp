#include "boxtypedialog.h"
#include "ui_boxtypedialog.h"
#include <QString>

using namespace std;

BoxTypeDialog::BoxTypeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoxTypeDialog)
{
    ui->setupUi(this);
    if (ui->comboBoxType->currentText() == "DVR") {
        ui->comboBoxNailColor->setDisabled(true);
    }
    //创建一个函数指针，指向特定的信号函数
    void (QComboBox::*indexChangedSingal)(const QString&) = &QComboBox::currentIndexChanged;
    connect(ui->comboBoxType,indexChangedSingal , this, &BoxTypeDialog::on_comboBoxType_currentIndexChanged);
}

BoxTypeDialog::~BoxTypeDialog()
{
    delete ui;
}

string BoxTypeDialog::getBoxType()
{
    boxType = ui->comboBoxType->currentText().toStdString();
    return boxType;
}

string BoxTypeDialog::getNailColor() {
    return ui->comboBoxNailColor->currentText().toStdString();
}

void BoxTypeDialog::on_comboBoxType_currentIndexChanged(const QString& text) {
    //如果选择的钉盒类型为"POLYX"，那么钉子颜色的下拉框可以选择(enabled)
    //如果选择的钉盒类型为"DVR"，那么钉子颜色的下拉框不可以选择(disabled)
    if (text == "POLYX") {
        ui->comboBoxNailColor->setEnabled(true);
    }
    else if (text == "DVR") {
        ui->comboBoxNailColor->setDisabled(true);
    }
}
