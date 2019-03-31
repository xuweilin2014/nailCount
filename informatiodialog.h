#ifndef INFORMATIODIALOG_H
#define INFORMATIODIALOG_H

#include <QDialog>

namespace Ui {
class InformatioDialog;
}

class InformatioDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformatioDialog(QWidget *parent = 0);
    void setInfo(const QString& info);
    ~InformatioDialog();

private:
    Ui::InformatioDialog *ui;
};

#endif // INFORMATIODIALOG_H
