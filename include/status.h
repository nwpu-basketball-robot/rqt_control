#ifndef STATUS_H
#define STATUS_H
#include "thread_.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>
#include <basketball_msgs/robot_message.h>
#include <basketball_msgs/ControlState.h>
#include <basketball_msgs/robot_state.h>
#include <geometry_msgs/Twist.h>
#include <QMetaType>
#include <QCloseEvent>
#include <QProcess>
#include <ros/ros.h>

class status : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    //构造函数
    explicit status(QObject *parent, Ui_MainWindow &ui);
protected:
    //关闭窗口时杀掉所有进程
    void closeEvent(QCloseEvent *);

public slots:
    //运行所选的状态
    void startStatus();
    //创建守护进程
    void createDeamon();
    //选择所要运行的状态
    void statusControl();
    //运行所选的状态
    void runStatus(QString name, int order);
    //清零里程计
    void clearMileage();
    //回执状态信息
    void TwistCallBack(const basketball_msgs::robot_state::ConstPtr &rState);
    //杀掉所运行的状态
    void killStatus();
    //显示窗口输出
    void showOut();
    //显示错误信息
    void showError();

private:
    Ui_MainWindow ui_rqtWidget;
    //声明运行状态机的进程
    QProcess *statusPro;
    //声明ros节点
    ros::NodeHandle nh;
    //声明发布移动
    ros::Publisher move_publisher;
    //声明介绍移动
    ros::Subscriber move_subscriber;
    //声明请求服务
    ros::ServiceClient statusClient;
    //初始化参数
    void init();
};
#endif // STATUS_H
