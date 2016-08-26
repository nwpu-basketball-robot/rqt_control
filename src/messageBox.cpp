#include <messageBox.h>
#include <armControl.h>
#include <ros/ros.h>

void MessageBox::init(){
        connect(armControl::rqtArmControl::ui_armWidget.killProcess, SIGNAL(clicked(bool)), this, SLOT(questionMessage()));
}

void MessageBox::criticalMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("critical"),
                                    MESSAGE,
                                    QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
//    if (reply == QMessageBox::Abort)
//        criticalLabel->setText(tr("Abort"));
//    else if (reply == QMessageBox::Retry)
//        criticalLabel->setText(tr("Retry"));
//    else
//        criticalLabel->setText(tr("Ignore"));
}

void MessageBox::informationMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("information"), MESSAGE);
//    if (reply == QMessageBox::Ok)
//        informationLabel->setText(tr("OK"));
//    else
//        informationLabel->setText(tr("Escape"));
}

void MessageBox::questionMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("question"),
                                    MESSAGE,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
         ROS_ERROR("Yes");
    else if (reply == QMessageBox::No)
         ROS_ERROR("No");
    else
         ROS_ERROR("Cancel");
}

void MessageBox::warningMessage()
{
    QMessageBox msgBox(QMessageBox::Warning, tr("warning"),
                       MESSAGE, 0, this);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
//    if (msgBox.exec() == QMessageBox::AcceptRole)
//        warningLabel->setText(tr("Save Again"));
//    else
//        warningLabel->setText(tr("Continue"));

}
