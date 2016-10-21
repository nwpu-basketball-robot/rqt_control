#include "status.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

//执行构造函数
status::status(QObject *parent ,Ui_MainWindow &ui):
    ui_rqtWidget(ui)
  ,rqt_gui_cpp::Plugin()
{
    // give QObjects reasonable names
    setObjectName("status");
    qRegisterMetaType<QTextCursor>("QTextCorsor");
    //初始化进程
    statusPro = new QProcess();
    //执行初始化函数
    init();
}

//初始化
void status::init()
{
    //实例化发布移动
    move_publisher = nh.advertise<basketball_msgs::robot_message>("/robot_cmd", 100);
    //实例化里程数据
    move_subscriber = nh.subscribe("/RecvData/1", 100, &status::TwistCallBack, this);
    //实例化请求状态机
    statusClient = nh.serviceClient<basketball_msgs::ControlState>("/Control_State");
    //关联statusPro与showOut(），输出statusPro进程的输出信息
    connect(statusPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showOut()));
    //关联statusPro与showError（)，输出statusPro进程的错误信息
    connect(statusPro,SIGNAL(readyReadStandardError()),this,SLOT(showError()));
    //关联clearMileage与clearMileage()，清零里程
    connect(ui_rqtWidget.clearMileage, SIGNAL(clicked(bool)), this, SLOT(clearMileage()), Qt::DirectConnection);
    //关联按钮startStatus与startStatus(），运行所选的的状态
    //    connect(ui_rqtWidget.startStatus, SIGNAL(clicked(bool)),this,SLOT(startStatus()));
    //关联killStatus与killStatus(），杀掉运行的状态
    connect(ui_rqtWidget.killStatus, SIGNAL(clicked(bool)),this,SLOT(killStatus()));
    //关联status1与statusControl(），运行状态1
    connect(ui_rqtWidget.status1, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联status2与statusControl(），运行状态2
    connect(ui_rqtWidget.status2, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联status3与statusControl(），运行状态3
    connect(ui_rqtWidget.status3, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联status4与statusControl(），运行状态4
    connect(ui_rqtWidget.status4, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联status5与statusControl(），运行状态5
    connect(ui_rqtWidget.status5, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联status6与statusControl(），运行状态6
    connect(ui_rqtWidget.status6, SIGNAL(clicked(bool)), this, SLOT(statusControl()));

    //mirror左手边
    //关联mirror_status1与statusControl(），运行状态1
    connect(ui_rqtWidget.mirror_status1, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联mirror_status2与statusControl(），运行状态2
    connect(ui_rqtWidget.mirror_status2, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联mirror_status3与statusControl(），运行状态3
    connect(ui_rqtWidget.mirror_status3, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联mirror_status4与statusControl(），运行状态4
    connect(ui_rqtWidget.mirror_status4, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联mirror_status5与statusControl(），运行状态5
    connect(ui_rqtWidget.mirror_status5, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
    //关联mirror_status6与statusControl(），运行状态6
    connect(ui_rqtWidget.mirror_status6, SIGNAL(clicked(bool)), this, SLOT(statusControl()));
}

//clear Mileage
//清零里程
void status::clearMileage(){
    //声明消息
    basketball_msgs::robot_message robot_cmd_msg ;
    //消息协议
    robot_cmd_msg.data.resize(6 , 0) ;
    uint8_t *data_ptr = robot_cmd_msg.data.data() ;
    data_ptr[0] = data_ptr[1] = 0xff ;//zhang tou
    data_ptr[2] = 0x01 ;//she bei ID
    data_ptr[3] = 0x00 ;//data.len
    data_ptr[4] = 0x01 ;//data.len
    data_ptr[5] = 0x03 ;//data.conten
    //发布消息
    move_publisher.publish(robot_cmd_msg) ;
}

//里程的回执函数，显示里程数据
void  status::TwistCallBack(const basketball_msgs::robot_state::ConstPtr &rState){
    //判断里程是否清零
    if(rState->data.size() == 1){
        ui_rqtWidget.textStatus-> append("Clear Mileage Success!");
    }
    //显示数据
    ui_rqtWidget.textMileageX -> setText(QString::number(rState->data[0]));
    ui_rqtWidget.textMileageY -> setText(QString::number(rState->data[1]));
    ui_rqtWidget.textMileageYaw -> setText(QString::number(rState->data[2]));
}

/*
//开始状态进程
//使用controlStatus.py
void status::startStatus(){
    //守护进程初始化函数
    //createDeamon();
    //1种
    //if(vfork()==0){
    //    printf("sasdsd\n");
    //    char* argv[] = {"rosrun basketball_strage control_state.py","char*"};
    //    execv("./", argv);
    //}

    // 2种
    //system("rosrun baskestball_strage control_state.py");

    //3种
    //if(daemon(0,0) == -1){
    //    perror("daemon error");
    //}
    //开始进程
    statusPro->start("rosrun basketball_strage control_state.py");
    //thread_* th = new thread_(statusPro, "rosrun basketball_strage control_state.py");
    //th->start();

    if(!(statusPro -> waitForStarted())){
        ROS_ERROR("start failed\n");
    }
    //让startStatus失效
    ui_rqtWidget.startStatus -> setEnabled(false);
    //输出信息
    ui_rqtWidget.textStatus -> append("Status start!");
}
*/

/*
//创建守护进程
void status::createDeamon(){
    int pid;
    // 处理SIGCHLD信号。处理SIGCHLD信号并不是必须的。
    // 但对于某些进程，特别是服务器进程往往在请求到来时生成子进程处理请求。
    // 如果父进程不等待子进程结束，子进程将成为僵尸进程（zombie）从而占用系统资源。
    if(signal(SIGCHLD,SIG_IGN) == SIG_ERR){
        printf("Cant signal in init_daemon.");
        exit(1);
    }
    pid = fork();
    //是父进程，结束父进程
    if(pid == 0)
        exit(0);
    //如果创建进程失败
    else if(pid< 0){
        perror("fail to fork1");
        exit(1);//fork失败，退出
    }
    //是第一子进程，后台继续执行
    //第一子进程成为新的会话组长和进程组长
    //并与控制终端分离
    pid = setsid();
    if(pid < -1){
        perror("SETSID ERROR");
        exit(-1);//fork失败，退出
    }
}
*/

//选择运行状态
void status::statusControl(){
    //获取点击过的按钮
    QPushButton* btn= qobject_cast<QPushButton*>(sender());
    btn->setEnabled(false);
    //状态名
    QString name = NULL;
    QString message = NULL;
    //状态编号
    int order = 0;
    //判断所运行的状态
    if (btn->objectName() == "status1") {
        //run status 1
        name = "pass_ball_first";
        order = 0;
        statusPro->start("rosrun basketball_strage  pass_ball_first.py");
    }
    // run status 2
    else if ( btn->objectName() ==  "status2"){
        name = "pass_ball_second";
        order = 1;
        statusPro->start("rosrun basketball_strage pass_ball_second.py");
    }
    // run status 3
    else if ( btn->objectName() ==   "status3"){
        name = "pass_ball_third";
        order = 2;
        statusPro->start("rosrun basketball_strage pass_ball_third.py ");
    }
    // run status 4
    else if ( btn->objectName() ==   "status4"){
        name = "shoot_ball_first";
        order = 3;
        statusPro->start("rosrun basketball_strage shoot_ball_first.py");
    }
    // run status 5
    else  if ( btn->objectName() ==   "status5"){
        name = "shoot_ball_second";
        order = 4;
        statusPro->start("rosrun basketball_strage shoot_ball_second.py");
    }
    // run status 6
    else  if ( btn->objectName() ==   "status6"){
        name = "shoot_ball_third";
        order = 5;
        statusPro->start("rosrun basketball_strage shoot_ball_third.py ");
    }

    //mirror左手边
    if (btn->objectName() == "mirror_status1") {
        //run status 1
        name = "mirror_pass_ball_first";
        order = 0;
        statusPro->start("rosrun basketball_strage  mirror_pass_ball_first.py");
    }
    // run status 2
    else if ( btn->objectName() ==  "mirror_status2"){
        name = "mirror_pass_ball_second";
        order = 1;
        statusPro->start("rosrun basketball_strage mirror_pass_ball_second.py");
    }
    // run status 3
    else if ( btn->objectName() ==   "mirror_status3"){
        name = "mirror_pass_ball_third";
        order = 2;
        statusPro->start("rosrun basketball_strage mirror_pass_ball_third.py ");
    }
    // run status 4
    else if ( btn->objectName() ==   "mirror_status4"){
        name = "mirror_shoot_ball_first";
        order = 3;
        statusPro->start("rosrun basketball_strage mirror_shoot_ball_first.py");
    }
    // run status 5
    else  if ( btn->objectName() ==   "mirror_status5"){
        name = "mirror_shoot_ball_second";
        order = 4;
        statusPro->start("rosrun basketball_strage mirror_shoot_ball_second.py");
    }
    // run status 6
    else  if ( btn->objectName() ==   "mirror_status6"){
        name = "mirror_shoot_ball_third";
        order = 5;
        statusPro->start("rosrun basketball_strage mirror_shoot_ball_third.py ");
    }


    if(statusPro->waitForStarted()){
        message = "  :Success";
    }else{
        message = "  :Fail";
        btn->setEnabled(true);
    }

    ui_rqtWidget.textStatus -> append(name + message);
    //运行所选定的状态
    //    runStatus(name, order);
    return;
}

/*
//运行所选的状态
void status::runStatus(QString name, int order){
    //声明消息
    basketball_msgs::ControlState srv;
    //赋值所要运行的状态
    srv.request.control_type = order;
    bool isSuccess = statusClient.call(srv);
    //判断是否发布成功
    if(isSuccess){
        //输出执行结果
        //        ui_rqtWidget.textStatus->append(name +":  "+ (srv.response.result?"Success":"Fail"));
        ui_rqtWidget.textStatus -> append(name + ": " + "Success!");
        ROS_INFO("Successed to call service!");
    }else{
        //输出执行结果
        ui_rqtWidget.textStatus->append(name +":  "+ "Wrong!");
        ROS_ERROR("Failed to call service!");
    }
    return;
}
*/

//杀掉运行的状态
void status::killStatus(){
    statusPro -> kill();
    //    ui_rqtWidget.startStatus -> setEnabled(true);
    ui_rqtWidget.status1 -> setEnabled(true);
    ui_rqtWidget.status2 -> setEnabled(true);
    ui_rqtWidget.status3 -> setEnabled(true);
    ui_rqtWidget.status4 -> setEnabled(true);
    ui_rqtWidget.status5 -> setEnabled(true);
    ui_rqtWidget.status6 -> setEnabled(true);

    //mirror左手边
    ui_rqtWidget.mirror_status1 -> setEnabled(true);
    ui_rqtWidget.mirror_status2 -> setEnabled(true);
    ui_rqtWidget.mirror_status3 -> setEnabled(true);
    ui_rqtWidget.mirror_status4 -> setEnabled(true);
    ui_rqtWidget.mirror_status5 -> setEnabled(true);
    ui_rqtWidget.mirror_status6 -> setEnabled(true);

    while(statusPro->waitForFinished()){
        ui_rqtWidget.textStatus -> append("Status end!");
        return;
    }
    ui_rqtWidget.textStatus -> append("Status fail!");
    return;
}

//输出运行的状态信息
void status::showOut(){
    QByteArray ba = statusPro->readAllStandardOutput();
    ui_rqtWidget.textStatus->append(ba);
}

//输出运行的状态的错误信息
void status::showError(){
    QByteArray ba = statusPro->readAllStandardError();
    ui_rqtWidget.textStatus->append("Error: " + ba);
}

//关闭窗口时，关闭运行的进程
void status::closeEvent(QCloseEvent *event)
{
    statusPro->kill();
    delete statusPro;
    if(!statusPro->waitForFinished())
        return;
    event->accept();
}
