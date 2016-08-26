#include "view.h"

//构造函数
view::view(QObject *parent, Ui_MainWindow &ui):
    ui_rqtWidget(ui)
  ,rqt_gui_cpp::Plugin()
{
    // give QObjects reasonable names
    setObjectName("view");
    //初始化图像开启进程
    pClPro = new QProcess;
    vollPro = new QProcess;
    cylPro = new QProcess;
    linPro = new QProcess;
    //初始化
    init();
}
//初始化函数
void view::init()
{
    //请求球数据
    findBallClient = nh.serviceClient<basketball_catchone_srv::CatchOneBall>("/oneball_data");
    //可点击startFindBall
    findBallClicked = true;
//    //初始化显示运行的进程的进程
//    ps = new QProcess;
    //设置计时器间隔时间0.5秒
    timer.setInterval(500);
    //计时器开始后运行findBall()
    connect(&timer,SIGNAL(timeout()), this, SLOT(findBall()));
//    //运行"ps"后，显示控制台输出信息，运行findBall(）
//    connect(ps,SIGNAL(readyReadStandardOutput()),this,SLOT(isRunning()));
    connect(pClPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showPCLPro()));
    connect(vollPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showVollPro()));
    connect(cylPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showCylPro()));
    connect(linPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showLinPro()));
    connect(pClPro,SIGNAL(readyReadStandardError()),this,SLOT(showPCLProError()));
    connect(vollPro,SIGNAL(readyReadStandardError()),this,SLOT(showVollProError()));
    connect(cylPro,SIGNAL(readyReadStandardError()),this,SLOT(showCylProError()));
    connect(linPro,SIGNAL(readyReadStandardError()),this,SLOT(showLinProError()));
    //点击startFindBall，运行startFindBall()，打开图像，不运行算法
    connect(ui_rqtWidget.startFindBall, SIGNAL(clicked(bool)), this, SLOT(startFindBall()));
    //点击runFun1,运行runFun()，运行找球函数
    connect(ui_rqtWidget.runFun1, SIGNAL(clicked(bool)), this, SLOT(runFun()));
    //点击重置，运行reset(），重置到图像开启状态
    connect(ui_rqtWidget.reset, SIGNAL(clicked(bool)), this, SLOT(reset()));
    //点击killFindBall，运行killPy(），杀掉所有图像进程
    connect(ui_rqtWidget.killFindBall, SIGNAL(clicked(bool)), this, SLOT(killPy()));
    //关联findVolleyBall与findVolleyBall，开启排球服务
    connect(ui_rqtWidget.findVolleyBall, SIGNAL(clicked(bool)), this, SLOT(findVolleyball()));
    //关联findCylinder与findCylinder，开启找柱子服务
    connect(ui_rqtWidget.findCylinder, SIGNAL(clicked(bool)), this, SLOT(findCylinder()));
    //关联findLine与findLine(），开启找边线服务
    connect(ui_rqtWidget.findLine, SIGNAL(clicked(bool)), this, SLOT(findLine()));
}

//start findBall，运行图像，并开始计时器
void view::startFindBall(){
    //判断是否点过startFindBall
    if(findBallClicked){
        //运行开启图像进程
        pClPro -> start("rosrun basketball_catchone_srv findBall");
        //确认已点过startFindBall
        findBallClicked = false;
        //开始计时器
        timer.start();
        //输出信息
        ROS_INFO("start findBall");
    }else{
        //若点击过,则使startsFindBall失效
        ui_rqtWidget.startFindBall -> setEnabled(false);
    }
}

//find ball
//开始找球函数
void view::findBall(){
//    //查找后台进程
//    showPID();
//    //通过查找后台判断图像是否在运行
//    //显示图像运行信息
//    ui_rqtWidget.basketball -> setText("Break! ! !");

    //判断是否点击funFun1
    //运行找球函数
    if(!ui_rqtWidget.runFun1 -> isEnabled()){
        //声明找球服务
        basketball_catchone_srv::CatchOneBall srv;
        //请求服务
        findBallClient.call(srv);
        //声明找球信息结构体
        findBallMessage message = {"","","",""};
        //赋值
        message.messageX = QString::number(srv.response.x);
        message.messageY = QString::number(srv.response.y);
        message.messageZ = QString::number(srv.response.z);
        message.messageTheta = QString::number(srv.response.theta);
        ui_rqtWidget.textCheckOnX->setText(message.messageX);
        ui_rqtWidget.textCheckOnY->setText(message.messageY);
        ui_rqtWidget.textCheckOnZ->setText(message.messageZ);
        ui_rqtWidget.textCheckOnTheta->setText(message.messageTheta);
        //判断是否找到球
        if(srv.response.has_ball)
        {
            ui_rqtWidget.textIsFind->setText("succeed find");
        }
        else{
            ui_rqtWidget.textIsFind->setText("no ball");
        }
    }
}

//运行找球函数,使runFun1失效,在findBall()函数中释放参数
void view::runFun(){
    //使runFun1失效
    ui_rqtWidget.runFun1->setEnabled(false);
}

////查询图像进程是否存在
//void view::showPID(){
//    QStringList args;
//    args<<"-c";
//    args<<"ps | grep find*";
//    ps->start("sh",args);
//}

////ps有输出时才运行,显示ps输出,判断图像进程是否存在
//void view::isRunning(){
//    // 得到sh -c "ps | grep findBall“ 的输出结果
//    ui_rqtWidget.basketball -> setText("RUNNING"+QString::number(qrand() % 100));
//    return;
//}

//reset findBall
//重置图像服务到打开图像状态
void view::reset(){
    //判断是否点击过startFindBall
    if(!findBallClicked){
        //若点击过
        findBallClicked = true;
        //关掉图像进程
        pClPro->kill();
        //重启计时器
        if(!timer.isActive()){
            timer.start();
        }else{
            //取消计时器与findBall()的联系
            disconnect(&timer,SIGNAL(timeout()), this, SLOT(findBall()));
        }
        //重新将计时器与findBall()函数联系
        connect(&timer,SIGNAL(timeout()), this, SLOT(findBall()));
        //恢复runFun1
        ui_rqtWidget.runFun1->setEnabled(true);
        //打开图像
        startFindBall();
        //向控制台输出信息
        ROS_INFO("reset success!");
    }
}

//找排球
void view::findVolleyball(){
    // 开启找排球进程
    vollPro->start("rosrun volleyball_detect findvolleyball");
}
//找柱子
void view::findCylinder(){
    //开启找柱子进程
    cylPro->start("rosrun cylinder_detector findcylinder");
}
//找边线
void view::findLine(){
    //开启找边线进程
    linPro->start("rosrun lineing findline");
}

//kill py status
//关掉图像进程
void view::killPy(){
    //关掉图像
    pClPro->kill();
    vollPro->kill();
    cylPro->kill();
    linPro->kill();
    //取消计时器与findBall()的联系
    disconnect(&timer,SIGNAL(timeout()), this, SLOT(findBall()));
    //关掉计时器
    timer.stop();
    //恢复runFun1
    ui_rqtWidget.runFun1->setEnabled(true);
    //恢复startFindBall
    ui_rqtWidget.startFindBall -> setEnabled(true);
    //向控制台输出消息
    ROS_INFO("end Process!");
}

//显示找篮球进程输出信息
void view::showPCLPro(){
    QByteArray sp = pClPro->readAllStandardOutput();
    ui_rqtWidget.basketball-> setText(sp);
    return;
}

//显示找排球进程输出信息
void view::showVollPro(){
    QByteArray sv = vollPro -> readAllStandardOutput();
    ui_rqtWidget.volleyball -> setText(sv);
    return;
}

//显示找柱子进程输出信息
void view::showCylPro(){
    QByteArray sc = cylPro -> readAllStandardOutput();
    ui_rqtWidget.cylinder -> setText(sc);
    return;
}
//显示找边线进程输出信息
void view::showLinPro(){
    QByteArray sl = linPro -> readAllStandardOutput();
    ui_rqtWidget.line -> setText(sl);
    return;
}

//显示找篮球进程错误信息
void view::showPCLProError(){
    QByteArray spe = pClPro->readAllStandardError();
    ui_rqtWidget.basketball-> setText(spe);
    return;
}

//显示找排球进程错误信息
void view::showVollProError(){
    QByteArray sve = vollPro -> readAllStandardError();
    ui_rqtWidget.volleyball -> setText(sve);
    return;
}

//显示找柱子进程错误信息
void view::showCylProError(){
    QByteArray sce= cylPro -> readAllStandardError();
    ui_rqtWidget.cylinder -> setText(sce);
    return;
}
//显示找边线进程错误信息
void view::showLinProError(){
    QByteArray sle = linPro -> readAllStandardError();
    ui_rqtWidget.line -> setText(sle);
    return;
}

//关闭窗口时杀掉所打开的进程
void view::closeEvent(QCloseEvent *event)
{
    //关闭图像进程
    pClPro->kill();
//    ps ->kill();
    pClPro->kill();
    vollPro->kill();
    cylPro->kill();
    linPro->kill();
    //关闭计时器
    timer.stop();
    //删除计时器
    delete &timer;
    if(!pClPro->waitForFinished(100) || !vollPro->waitForFinished(100)
            || !cylPro->waitForFinished(100) || !linPro->waitForFinished(100))
        return;
    event->accept();
}
