#ifndef VIEW_H
#define VIEW_H
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>
#include <basketball_catchone_srv/CatchOneBall.h>
#include <object_detect/volleyballdata.h>
#include <object_detect/cylinderdata.h>
#include <basketball_msgs/robot_message.h>
#include <QMainWindow>
#include <QCloseEvent>
#include <QProcess>
#include <QTimer>
#include <cstdlib>
#include <ros/ros.h>

class view : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    //构造函数
    explicit view(QObject *parent, Ui_MainWindow &ui);

protected:
    //关闭窗口时杀掉所打开的进程
    void closeEvent(QCloseEvent *);

public slots:
    //执行找篮球信息
    void findBall();
    //找排球、柱子
    void findVolleyBallAndCylinder();
    //找边线
    void findLine();
    //开始找球
    void startFindBall();
    //重置找球
    void reset();
    //杀掉找球进程
    void killPy();
    //执行所选的状态
    void runFun();
//    //显示进程Id
//    void showPID();
//    //判断进程是否允许
//    void isRunning();
    //显示找篮球进程输出信息
    void showPCLPro();
    //显示找排球、柱子进程输出信息
    void showVACPro();
    //显示找边线进程输出信息
    void showLinPro();
    //显示找篮球进程错误信息
    void showPCLProError();
    //显示找排球、柱子进程错误信息
    void showVACProError();
    //显示找边线进程错误信息
    void showLinProError();

private:
    Ui_MainWindow ui_rqtWidget ;
    //声明ros节点
    ros::NodeHandle nh;
    //声明请求服务
    ros::ServiceClient findBallClient;
    //声明请求找排球服务
    ros::ServiceClient findVolleyballClient;
    //声明请求找柱子服务
    ros::ServiceClient findCylinderClient;
    //声明请求找边线的服务
    ros::ServiceClient findLineClient;
    //标记是否点击过开始找球
    bool findBallClicked;
    //声明找篮球控制的子进程
    QProcess *pClPro;
    //声明找排球、柱子的进程
    QProcess *VACPro;
    //声明找边线的进程
    QProcess *linPro;
//    //声明显示进程信息的子进程
//    QProcess *ps;
    //声明计时器
    QTimer timer;
    //定义找球信息结构体
    struct findBallMessage{
        QString messageX;
        QString messageY;
        QString messageZ;
        QString messageTheta;
    };
    //初始化参数
    void init();
};
#endif // VIEW_H
