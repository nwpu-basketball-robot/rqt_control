#!/bin/bash 
password="密码"

function main()
{
	echo $password | sudo -S chmod +777 "/dev/ttyUSB0";
	gnome-terminal -x bash -c "roslaunch basketball_bringup start_robot.launch;exec bash;";
	sleep 1;
	gnome-terminal -x bash -c "rosrun rqt_control rqtControl.py; exec bash;";
}
main;
exit 0;

