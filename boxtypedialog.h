#ifndef BOXTYPEDIALOG_H
#define BOXTYPEDIALOG_H

#include <QDialog>
#include <QString>

using namespace std;

namespace Ui {
class BoxTypeDialog;
}

class BoxTypeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BoxTypeDialog(QWidget *parent = 0);
    string getBoxType();
    string getNailColor();
    ~BoxTypeDialog();

private slots:
    void on_comboBoxType_currentIndexChanged(const QString& text);

private:
    Ui::BoxTypeDialog *ui;
    string boxType;
};

#endif // BOXTYPEDIALOG_H
