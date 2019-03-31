#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
	void initButtonIcon();
	void showInfoDialogNonModal(const QString& title,const QString& info);
	void showInfoDialogModal(const QString& title, const QString& info);
    ~MyWidget();

private slots:
    void on_uploadImage_clicked();
    void on_boxType_clicked();
    void on_nailCount_clicked();

private:
    Ui::MyWidget *ui;
	bool isImageUploaded;
	string boxType;
	string nailColor;
	string imgPath;

};

#endif // MYWIDGET_H
