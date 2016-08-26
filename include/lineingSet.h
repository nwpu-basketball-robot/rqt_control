#ifndef LINEING_H
#define LINEING_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QtGui>

class LineingSet : public QMainWindow
{
    Q_OBJECT
public:
    //构造函数
    explicit LineingSet(QObject *parent, Ui_MainWindow &ui);

public slots:
    //显示滑条数值
    void showSliderEditValue(int value);
private:
    Ui_MainWindow ui_rqtWidget ;
    //初始化参数
    void init();
};
#endif // LINEING_H
