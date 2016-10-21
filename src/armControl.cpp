#include "armControl.h"

//执行构造函数
armControl::armControl(QObject *parent , Ui_MainWindow &ui):
    ui_rqtWidget(ui)
  ,rqt_gui_cpp::Plugin()
{
    // give QObjects reasonable names
    setObjectName("armControl");
    //运行初始化函数
	init();
}

//初始化函数
void armControl::init(){
    //初始化shovelClient，接受运行铲子的反馈信息
	shovelClient = nh.serviceClient<basketball_msgs::basketball_shovel_srv>("/cmd_shovel");
    //初始化shootClient，接受运行弹射的反馈信息
	shootClient = nh.serviceClient<basketball_msgs::basketball_shoot_srv>("/cmd_shoot");
	
	//由于后来type所对应的铲子动作改变了，所以英文没有对应

	//铲子把球放入弹射装置，随后再达到最低点，type = 0
    connect(ui_rqtWidget.raise, SIGNAL(clicked(bool)), this , SLOT(shovelControl())) ;
    //铲子将球抬在空中，type = 1
	connect(ui_rqtWidget.descend, SIGNAL(clicked(bool)), this, SLOT(shovelControl()));
    //从持球位置铲子把球放入弹射装置，并且放下， type = 2
	connect(ui_rqtWidget.down, SIGNAL(clicked(bool)), this, SLOT(shovelControl()));
    //铲子从最高点到最低点， type = 3
	connect(ui_rqtWidget.tackles, SIGNAL(clicked(bool)), this, SLOT(shovelControl()));
    //铲子从最低点到最高点， type = 4
	connect(ui_rqtWidget.downToUp, SIGNAL(clicked(bool)), this, SLOT(shovelControl()));
    //铲子从持球位置到最低点， type = 5
	connect(ui_rqtWidget.keepToDown, SIGNAL(clicked(bool)), this, SLOT(shovelControl()));
	//控制弹射
    connect(ui_rqtWidget.shoot, SIGNAL(clicked(bool)), this, SLOT(shoot()));
}

//Test shovel
//选定铲子运行方案
void armControl::shovelControl(){
    QPushButton* btn= qobject_cast<QPushButton*>(sender());
    QString name = NULL;
    if ( btn->objectName() == "raise") {
        //铲子把球放入弹射装置，随后再达到最低点
        name = "0-raise: ";
        shovelMove(0, name);
    }
    // 铲子将球抬在空中
    else if ( btn->objectName() ==  "descend"){
        name = "1-descend: ";
        shovelMove(1, name);
    }
    // 从持球位置铲子把球放入弹射装置，并且放下
    else if ( btn->objectName() ==   "down"){
        name = "2-down: ";
        shovelMove(2, name);
    }
    // 铲子从最高点到最低点
    else if ( btn->objectName() ==   "tackles"){
        name = "3-tackles: ";
        shovelMove(3, name);
    }
    // 铲子最低点从到最高点
    else  if ( btn->objectName() ==   "downToUp"){
        name = "4-downToUp: ";
        shovelMove(4, name);
    }
    // 铲子从持球位置到最低点
    else  if ( btn->objectName() ==   "keepToDown"){
        name = "5-keepToDown: ";
        shovelMove(5, name);
    }
    return;
}

//shovel move
//执行所选的铲子运行动作
void armControl::shovelMove(int order, QString name){
    //声明铲子消息
	basketball_msgs::basketball_shovel_srv srv;
    //赋值铲子执行方式
	srv.request.order_type = order;
    //请求服务
	if(shovelClient.call(srv))
        printf("%d\n",srv.response.is_successed);
    else
        ROS_ERROR("Failed to call service");
    //接受执行结果
	QString message = QString::number(srv.response.is_successed,10);
    //显示到界面
    ui_rqtWidget.textStatus->append(name + message);
    return;
}

//shoot ball
//弹射
void armControl::shoot(){
    //定义弹射消息
	basketball_msgs::basketball_shoot_srv srv;
    //赋值弹射，这个随意些，电子部分未处理
	srv.request.order_type = 6;
	//请求服务
    shootClient.call(srv);
    //接受执行结果
	QString message = QString::number(srv.response.is_successed,10);
    //显示到界面
    ui_rqtWidget.textStatus->append("shoot: " + message);
    return;
}
