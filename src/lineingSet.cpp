#include "lineingSet.h"

LineingSet::LineingSet(QObject *parent ,Ui_MainWindow &ui):
    ui_rqtWidget(ui)
{
    setObjectName("lineingSet");
    init();
}

void LineingSet::init(){
    //信号和槽 当滑动条的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件的显示文本
    connect(ui_rqtWidget.HMax, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
    connect(ui_rqtWidget.HMin, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
    connect(ui_rqtWidget.SMax, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
    connect(ui_rqtWidget.SMin, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
    connect(ui_rqtWidget.VMax, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
    connect(ui_rqtWidget.VMin, SIGNAL(valueChanged(int)), this, SLOT(showSliderEditValue(int)));
}

//当滑动条的值发生改变时，即产生一个valueChanged(int)信号 设置QLineEdit控件的显示文本
void LineingSet::showSliderEditValue(int value)
{
    QSlider* slider= qobject_cast<QSlider*>(sender());

    if(slider->objectName() == "HMax"){
        ui_rqtWidget.HMaxEdit -> setText(QString("%1").arg(value));
    }else if(slider->objectName() == "HMin"){
        ui_rqtWidget.HMinEdit -> setText(QString("%1").arg(value));
    }else if(slider->objectName() == "SMax"){
        ui_rqtWidget.SMaxEdit -> setText(QString("%1").arg(value));
    }else if(slider->objectName() == "SMin"){
        ui_rqtWidget.SMinEdit -> setText(QString("%1").arg(value));
    }else if(slider->objectName() == "VMax"){
        ui_rqtWidget.VMaxEdit -> setText(QString("%1").arg(value));
    }else if(slider->objectName() == "VMin"){
        ui_rqtWidget.VMinEdit -> setText(QString("%1").arg(value));
    }
}
