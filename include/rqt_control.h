#ifndef  RQTCONTROL_H
#define RQTCONTROL_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <rqt_gui_cpp/plugin.h>
#include <QWidget>

namespace rqt_Control_ {

class rqtControl
        : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    //构造函数
    explicit rqtControl(QObject *parent = 0);
    //析构函数
    ~rqtControl() ;
    //初始化 执行顺序：rqtControl() -> initPlugin() -> restoreSettings() -> saveSettings() -> shutdownPlugin()
    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, qt_gui_cpp::Settings& instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, const qt_gui_cpp::Settings& instance_settings);

private:
    MainWindow *rqtWidget;
    Ui_MainWindow ui_rqtWidget;
    //初始化，建立操作对象
    void init();
};
} // namespace
#endif //  RQTCONTROL_H
