#include "thread_.h"
#include <ros/ros.h>
thread_::thread_(QProcess* process, QString commod){
    qprocess = process;
    cmd = commod;
}

void thread_::run(){
    qprocess->start(cmd);
}
