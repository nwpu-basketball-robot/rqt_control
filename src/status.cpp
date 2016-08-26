#include "status.h"

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
    connect(ui_rqtWidget.startStatus, SIGNAL(clicked(bool)),this,SLOT(startStatus()));
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

//开始状态进程
void status::startStatus(){
    //开始进程
    statusPro->start("rosrun basketball_strage control_state.py");
    //让startStatus失效
    ui_rqtWidget.startStatus -> setEnabled(false);
    //输出信息
    ui_rqtWidget.textStatus -> append("Status start!");
}

//选择运行状态
void status::statusControl(){
    //获取点击过的按钮
    QPushButton* btn= qobject_cast<QPushButton*>(sender());
    //状态名
    QString name = NULL;
    //状态编号
    int order = 0;
    //判断所运行的状态
    if (btn->objectName() == "status1") {
        //run status 1
        name = "pass_ball_first";
        order = 1;
    }
    // run status 2
    else if ( btn->objectName() ==  "status2"){
        name = "pass_ball_second";
        order = 2;
    }
    // run status 3
    else if ( btn->objectName() ==   "status3"){
        name = "pass_ball_third";
        order = 3;
    }
    // run status 4
    else if ( btn->objectName() ==   "status4"){
        name = "shoot_ball_first";
        order = 4;
    }
    // run status 5
    else  if ( btn->objectName() ==   "status5"){
        name = "shoot_ball_second";
        order = 5;
    }
    // run status 6
    else  if ( btn->objectName() ==   "status6"){
        name = "shoot_ball_third";
        order = 6;
    }
    //运行所选定的状态
    runStatus(name, order);
    return;
}

//通过进程直接运行状态
//void status::runStatus(QString name, int order){
//        QString message = NULL;
//        // 进程old结束
//        statusPro->kill();
//        //进程启动
//        statusPro -> start("rosrun basketball_strage " + name +".py ");
//        // 等待进程启动
//        if(statusPro->waitForStarted()){
//            message = "  :Success";
//        }else{
//            message = "  :Fail";
//        }
//        ui_rqtWidget.textStatus -> append(name + message);
//}

//运行所选的状态
void status::runStatus(QString name, int order){
    //声明消息
    basketball_msgs::ControlState srv;
    //赋值所要运行的状态
    srv.request.control_type = order;
    //判断是否发布成功
    if(statusClient.call(srv))
        //输出执行结果
        ui_rqtWidget.textStatus->append(name +":  "+ (srv.response.result?"Success":"Fail"));
    else{
        //输出执行结果
        ui_rqtWidget.textStatus->append(name +":  "+ "Wrong!");
        ROS_ERROR("Failed to call service");
    }
    return;
}

//杀掉运行的状态
void status::killStatus(){
    statusPro -> kill();
    ui_rqtWidget.startStatus -> setEnabled(true);
    ui_rqtWidget.textStatus -> append("Status end!");
}

//输出运行的状态信息
void status::showOut(){
    QByteArray ba = statusPro->readAllStandardOutput();
    ui_rqtWidget.textStatus->append(ba);
}

//输出运行的状态的错误信息
void status::showError(){
    QByteArray ba = statusPro->readAllStandardError();
    ui_rqtWidget.textStatus->append("error: " + ba);
}

//关闭窗口时，关闭运行的进程
void status::closeEvent(QCloseEvent *event)
{
    statusPro->kill();
    if(!statusPro->waitForFinished(100))
        return;
    event->accept();
}
