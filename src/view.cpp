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
    VACPro = new QProcess;
    linPro = new QProcess;
    CydPro = new QProcess;
    //初始化
    init();
}
//初始化函数
void view::init()
{
    //实例化请求找篮球数据
    findBallClient = nh.serviceClient<basketball_catchone_srv::CatchOneBall>("/oneball_data");
    //实例化请求找排球服务
    findVolleyballClient = nh.serviceClient<object_detect::volleyballdata>("/volleyball_data");
    //实例化请求找柱子服务
    findCylinderClient = nh.serviceClient<object_detect::cylinderdata>("/cylinder_data");
    //实例化请求找边线的服务
    findLineClient = nh.serviceClient<lineing::CatchOneLine>("/line_data");
    //实例化请求找柱子2服务
    findCylinderFindClient = nh.serviceClient<cylinder_find::cylinder_find>("/cylinder_data_theta");

    //可点击startFindBall
    findBallClicked = true;
//    //初始化显示运行的进程的进程
//    ps = new QProcess;
    //设置计时器间隔时间0.5秒
    timer.setInterval(500);
    //计时器开始后运行runFun()
    connect(&timer,SIGNAL(timeout()), this, SLOT(runFun()));
//    //运行"ps"后，显示控制台输出信息，运行findBall(）
//    connect(ps,SIGNAL(readyReadStandardOutput()),this,SLOT(isRunning()));
    connect(pClPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showPCLPro()));
    connect(VACPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showVACPro()));
    connect(linPro,SIGNAL(readyReadStandardOutput()),this,SLOT(showLinPro()));

    connect(pClPro,SIGNAL(readyReadStandardError()),this,SLOT(showPCLProError()));
    connect(VACPro,SIGNAL(readyReadStandardError()),this,SLOT(showVACProError()));
    connect(linPro,SIGNAL(readyReadStandardError()),this,SLOT(showLinProError()));

    //点击startFindBasketBall，运行startFindBall()，打开图像，不运行算法
    connect(ui_rqtWidget.startFindBasketBall, SIGNAL(clicked(bool)), this, SLOT(startFindBall()));
    //点击runBasketBall,运行selectFun()，运行找篮球函数
    connect(ui_rqtWidget.runBasketBall, SIGNAL(clicked(bool)), this, SLOT(selectFun()));
    //点击重置，运行reset(），重置到图像开启状态
    connect(ui_rqtWidget.reset, SIGNAL(clicked(bool)), this, SLOT(reset()));

    //关联startVolleyBallAndCylinder与startFindVolleyBallAndCylinder()，开启排球、柱子服务
    connect(ui_rqtWidget.startVolleyBallAndCylinder, SIGNAL(clicked(bool)), this, SLOT(startFindVolleyBallAndCylinder()));
    //点击runVolleyBall,运行selectFun()，运行找排球函数
    connect(ui_rqtWidget.runVolleyBall, SIGNAL(clicked(bool)), this, SLOT(selectFun()));
    //点击runCylinder,运行selectFun()，运行找柱子函数
    connect(ui_rqtWidget.runCylinder, SIGNAL(clicked(bool)), this, SLOT(selectFun()));

    //关联startFindLine与startFindLine(），开启找边线服务
    connect(ui_rqtWidget.startFindLine, SIGNAL(clicked(bool)), this, SLOT(startFindLine()));
    //点击runFindLine,运行selectFun()，运行找边线函数
    connect(ui_rqtWidget.runFindLine, SIGNAL(clicked(bool)), this, SLOT(selectFun()));

    //关联startCylinderFind与startCylinderFind()，开启找柱子角度服务
    connect(ui_rqtWidget.startCylinderFind, SIGNAL(clicked()),this, SLOT(selectFun()));
    //点击runCylinderFind，运行selectFun()，运行找柱子角度函数
    connect(ui_rqtWidget.runCylinderFind,SIGNAL(clicked()),this,SLOT(selectFun()));

    //点击killFindBall，运行killPy(），杀掉所有图像进程s
    connect(ui_rqtWidget.killFindBall, SIGNAL(clicked(bool)), this, SLOT(killPy()));
}

//start findBall，开始运行找篮球图像，并开始计时器
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
        ui_rqtWidget.startFindBasketBall -> setEnabled(false);
    }
}

//开始找排球、柱子
void view::startFindVolleyBallAndCylinder(){
    // 开启找排球、柱子进程
    VACPro->start("rosrun object_detect findobject");
    ui_rqtWidget.startVolleyBallAndCylinder -> setEnabled(false);
}

//开始找边线
void view::startFindLine(){
    //开启找边线进程
    linPro->start("rosrun lineing findline");
    ui_rqtWidget.startFindLine -> setEnabled(false);
}

//开始运行找柱子角度
void view::startCylinderFind(){
    //开启找柱子角度进程
    CydPro -> start("rosrun cylinder_find cylinder_find");
    ui_rqtWidget.startCylinderFind -> setEnabled(false);
}

//执行所选状态
void view::runFun(){
//    //查找后台进程
//    showPID();
//    //通过查找后台判断图像是否在运行
//    //显示图像运行信息
//    ui_rqtWidget.basketball -> setText("Break! ! !");

    //判断是否点击runBasketBall,运行找篮球函数
    if(!ui_rqtWidget.runBasketBall -> isEnabled()){
        runBasketBall();
    }
    //判断是否点击过runVolleyBall，运行找排球函数
    if(!ui_rqtWidget.runVolleyBall -> isEnabled()){
        runVolleyBall();
    }
    //判断是否点击过runCylider，运行找柱子函数
    if(!ui_rqtWidget.runCylinder -> isEnabled()){
        runCylinder();
    }
    //判断是否点击过runFindLine，运行找边线函数
    if(!ui_rqtWidget.runFindLine -> isEnabled()){
        runFindLine();
    }
    //判断是否点击过runCylinderFind，运行找柱子2函数
    if(!ui_rqtWidget.runCylinderFind -> isEnabled()){
        runCylinderFind();
    }
    return;
}

//选择所要执行的函数
void view::selectFun(){
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    //找篮球
    if(btn -> objectName() == "runBasketBall"){
        //使runBasketBall失效
        ui_rqtWidget.runBasketBall->setEnabled(false);
        return;
    //找排球
    }else if(btn -> objectName() == "runVolleyBall"){
        ui_rqtWidget.runVolleyBall -> setEnabled(false);
        return;
    //找柱子
    }else if(btn -> objectName() == "runCylinder"){
        ui_rqtWidget.runCylinder -> setEnabled(false);
        return;
    //找边线
    }else if(btn -> objectName() == "runFindLine"){
        ui_rqtWidget.runFindLine -> setEnabled(false);
        return;
    //找柱子2
    }else if(btn -> objectName() == "startCylinderFind"){
        ui_rqtWidget.runCylinderFind -> setEnabled(false);
    }
}

//找篮球函数
void view::runBasketBall(){
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
    return;
}

//找排球函数
void view::runVolleyBall(){
    //声明排球服务
    object_detect::volleyballdata srv;
    //传递的参数赋值
    srv.request.ball_or_cylinder = false;
    //请求服务
    findVolleyballClient.call(srv);
    //获取返回值
    QString message = NULL;
    message = srv.response.if_volleyball?"Have Volleyball":"No Volleyball";
    //界面显示
    ui_rqtWidget.textVolleyball -> setText(message);
    return;
}

//找柱子函数
void view::runCylinder(){
    //声明柱子服务
    object_detect::cylinderdata srv;
    //传递的参数赋值
    srv.request.ball_or_cylinder = true;
    //请求服务
    findCylinderClient.call(srv);
    //获取返回值
    QString message = NULL;
    message = srv.response.has_cylinder?"Have Cylinder":"NO Cylinder";
    //界面显示
    ui_rqtWidget.textCylinder -> setText(message);
    return;
}

//找边线函数
void view::runFindLine(){
    //声明边线服务
    lineing::CatchOneLine srv;
    //请求服务
    findLineClient.call(srv);
    //获取返回值
    QString message = NULL;
    message = QString::number(srv.response.distance)
            + QString::number(srv.response.theta)
            + QString::number(srv.response.ArriveAtHome);
    //界面显示
    ui_rqtWidget.textLine -> setText(message);
    return;
}

//找柱子2函数
void view::runCylinderFind(){
    //声明柱子2服务
    cylinder_find::cylinder_find srv;
    //请求服务
    findCylinderFindClient.call(srv);
    //获取返回值
    QString message = NULL;
    message = QString::number(srv.response.theta);
    //界面显示
    ui_rqtWidget.textCylinderFind -> setText(message);
    return;
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
            //取消计时器与runFun()的联系
            disconnect(&timer,SIGNAL(timeout()), this, SLOT(runFun()));
        }
        //重新将计时器与runFun()函数联系
        connect(&timer,SIGNAL(timeout()), this, SLOT(runFun()));
        //恢复runBasketBall
        ui_rqtWidget.runBasketBall->setEnabled(true);
        //打开图像
        startFindBall();
        //向控制台输出信息
        ROS_INFO("reset success!");
    }
}

//kill py status
//关掉图像进程
void view::killPy(){
    //恢复按钮
    findBallClicked = true;
    //关掉图像
    pClPro->kill();
    VACPro->kill();
    linPro->kill();
    //取消计时器与runFun()的联系
    disconnect(&timer,SIGNAL(timeout()), this, SLOT(runFun()));
    //关掉计时器
    timer.stop();

    //恢复startFindBall
    ui_rqtWidget.startFindBasketBall -> setEnabled(true);
    //恢复startVolleyBallAndCylinder
    ui_rqtWidget.startVolleyBallAndCylinder -> setEnabled(true);
    //恢复startFindLine
    ui_rqtWidget.startFindLine -> setEnabled(true);

    //恢复runBasketBall
    ui_rqtWidget.runBasketBall -> setEnabled(true);
    //恢复runVolleyBall
    ui_rqtWidget.runVolleyBall -> setEnabled(true);
    //恢复runCylinder
    ui_rqtWidget.runCylinder -> setEnabled(true);
    //恢复runFindLine
    ui_rqtWidget.runFindLine -> setEnabled(true);
    //向控制台输出消息
    ROS_INFO("end Process!");
}

//显示找篮球进程输出信息
void view::showPCLPro(){
    QByteArray sp = pClPro->readAllStandardOutput();
    ui_rqtWidget.basketball-> setText(sp);
    return;
}

//显示找排球、柱子进程输出信息
void view::showVACPro(){
    QByteArray sv = VACPro -> readAllStandardOutput();
    ui_rqtWidget.volleyAndCylinder -> setText(sv);
    return;
}


//显示找边线进程输出信息
void view::showLinPro(){
    QByteArray sl = linPro -> readAllStandardOutput();
    ui_rqtWidget.findLine -> setText(sl);
    return;
}

//显示找篮球进程错误信息
void view::showPCLProError(){
    QByteArray spe = pClPro->readAllStandardError();
    ui_rqtWidget.basketball-> setText(spe);
    return;
}

//显示找排球、柱子进程错误信息
void view::showVACProError(){
    QByteArray sve = VACPro -> readAllStandardError();
    ui_rqtWidget.volleyAndCylinder -> setText(sve);
    return;
}

//显示找边线进程错误信息
void view::showLinProError(){
    QByteArray sle = linPro -> readAllStandardError();
    ui_rqtWidget.findLine -> setText(sle);
    return;
}

//关闭窗口时杀掉所打开的进程
void view::closeEvent(QCloseEvent *event)
{
    //关闭图像进程
    pClPro->kill();
//    ps ->kill();
    pClPro->kill();
    VACPro->kill();
    linPro->kill();
    //关闭计时器
    timer.stop();
    //删除计时器
    delete &timer;
    if(!pClPro->waitForFinished(100) || !VACPro->waitForFinished(100) || !linPro->waitForFinished(100))
        return;
    event->accept();
}
