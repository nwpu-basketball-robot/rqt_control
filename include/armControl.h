#ifndef  ARMCONTROL_H
#define ARMCONTROL_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ros/ros.h>
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>
#include <basketball_msgs/basketball_shovel_srv.h>
#include <basketball_msgs/basketball_shoot_srv.h>
#include <basketball_msgs/robot_message.h>
#include <QtGui>
#include <QMainWindow>

class armControl : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    //构造函数
    explicit armControl( QObject *parent, Ui_MainWindow &ui);

public slots:
    //选择铲子操作方式
    void shovelControl();
    //执行铲子所选定方式的动作
    void shovelMove(int order, QString name);
    //弹射
    void shoot();

private:
    Ui_MainWindow ui_rqtWidget ;
    ros::NodeHandle nh;
    ros::ServiceClient shovelClient;
    ros::ServiceClient shootClient;
    //初始化，服务
    void init();
};
#endif // ARMCONTROL_H
