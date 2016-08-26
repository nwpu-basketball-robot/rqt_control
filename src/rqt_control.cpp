#include "rqt_control.h"
#include "lineingSet.h"
#include "armControl.h"
#include "view.h"
#include "status.h"
#include <pluginlib/class_list_macros.h>

namespace rqt_Control_ {
//构造函数
rqtControl::rqtControl(QObject *parent)
    : rqt_gui_cpp::Plugin()
    , rqtWidget(0)
{
    // give QObjects reasonable names
    setObjectName("rqt_control");
}

//解析函数
rqtControl::~rqtControl()
{
    delete rqtWidget;
}

//初始化Plugin
void rqtControl::initPlugin(qt_gui_cpp::PluginContext& context)
{
    // access standalone command line arguments
    //QStringList argv = context.argv();
    // create QWidget
    rqtWidget = new MainWindow();
    // extend the widget with all attributes and children from UI file
    ui_rqtWidget.setupUi(rqtWidget);
    // add widget to the user interface
    context.addWidget(rqtWidget);
    //运行init()
    init();
}

void rqtControl::shutdownPlugin()
{
    // TODO unregister all publishers here
}

void rqtControl::saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const
{
    // TODO save intrinsic configuration, usually using:
    // instance_settings.setValue(k, v)
}

void rqtControl::restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings)
{
    // TODO restore intrinsic configuration, usually using:
    // v = instance_settings.value(k)
}

//初始化，建立操作对象
void rqtControl::init(){
    //新建LineingSet对象
    new LineingSet(0, ui_rqtWidget);
    //新建armControl对象
    new armControl(0, ui_rqtWidget);
    //新建view对象
    new view(0, ui_rqtWidget);
    //新建status对象
    new status(0, ui_rqtWidget);
}


////0~4 backInfor
//bool  rqtControl::shovelSrvCallBack(basketball_msgs::basketball_shovel_srv::Request &req,
//                                       basketball_msgs::basketball_shovel_srv::Response &rep)
//{
//    rqtControl::changeCurrentShovelControlType(req.order_type) ;
//    if(req.order_type == 4){
//        rep.is_successed = pubShootCmd(0x01) ;
//    }else{
//        rep.is_successed = pubShovelCmd(0x01,uint8_t(current_control_type_+1)) ;
//    }
//    QString message = QString::number(rep.is_successed, 10);
//    ROS_INFO("request: shooel [%ld]state start",(long int)req.order_type);
//    ROS_INFO("sending back response: [%d]", rep.is_successed);
//    switch (req.order_type) {
//    case 0:
//        ui_rqtWidget.textRaise->setText(message);
//        break ;
//    case 1:
//        ui_rqtWidget.textDescend->setText(message); //铲子落地
//        break ;
//    case 2:
//        ui_rqtWidget.textDown->setText(message);//铲子将球送入装置后落地
//        break ;
//    case 3:
//        ui_rqtWidget.textTackles->setText(message);
//        break ;
//    case 4:
//        ui_rqtWidget.textShoot->setText(message);
//        break;
//    default:
//        break;
//    }
//    return true ;
//}

//bool rqtControl::pubShovelCmd(const uint8_t func , const uint8_t control_id)
//{
//    basketball_msgs::robot_message robot_cmd_msg ;
//    robot_cmd_msg.data.resize(7 , 0) ;
//    uint8_t *data_ptr = robot_cmd_msg.data.data() ;
//    int data_len = 2 ;
//    data_ptr[0] = data_ptr[1] = 0xff ;//zhang tou
//    data_ptr[2] = shovel_cmd_id_ ;//she bei ID
//    data_ptr[3] = (u_int8_t)(data_len>>8) ;//data.len
//    data_ptr[4] = (u_int8_t)(data_len & 0xff) ;//data.len
//    data_ptr[5] = func ;//data.content
//    data_ptr[6] = control_id ;//opeate ID
//    publisher.publish(robot_cmd_msg) ;
//    return true ;
//}

//bool rqtControl::pubShootCmd(const uint8_t func)
//{
//    basketball_msgs::robot_message robot_cmd_msg ;
//    robot_cmd_msg.data.resize(6 , 0) ;
//    uint8_t *data_ptr = robot_cmd_msg.data.data() ;
//    int data_len = 1 ;
//    data_ptr[0] = data_ptr[1] = 0xff ;
//    data_ptr[2] = shoot_cmd_id_ ;
//    data_ptr[3] = (u_int8_t)(data_len>>8) ;
//    data_ptr[4] = (u_int8_t)(data_len & 0xff) ;
//    data_ptr[5] = func ;
//    publisher.publish(robot_cmd_msg) ;
//    rqtControl::waitForShootOver();
//    return true ;
//}

//void rqtControl::changeCurrentShovelControlType(int control_type)
//{
//    switch (control_type) {
//    case 0:
//        current_control_type_ = SHOVEL_ON ; //铲子最高点
//        break ;
//    case 1:
//        current_control_type_ = SHOVEL_DOWN ; //铲子落地
//        break ;
//    case 2:
//        current_control_type_ = SHOVEL_CATCHBALL ; //铲子将球送入装置后落地
//        break ;
//    case 3:
//        current_control_type_ = SHOVEL_AFTER_CATCH_DOWN ;
//        break ;
//    case 4:
//        current_control_type_ =  SHOOT;
//        break ;
//    }
//}

} // namespace
PLUGINLIB_DECLARE_CLASS(rqt_Control_, rqtControl, rqt_Control_::rqtControl, rqt_gui_cpp::Plugin)
