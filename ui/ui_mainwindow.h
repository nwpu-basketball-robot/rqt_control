/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QToolBox *toolBox;
    QWidget *SHOW;
    QHBoxLayout *horizontalLayout;
    QWidget *armControl;
    QPushButton *descend;
    QPushButton *raise;
    QLabel *armControlLable;
    QPushButton *shoot;
    QFrame *armControlLine;
    QPushButton *down;
    QPushButton *tackles;
    QPushButton *downToUp;
    QPushButton *keepToDown;
    QLineEdit *textStatus;
    QWidget *view;
    QLineEdit *textCheckOnX;
    QLineEdit *textCheckOnY;
    QLineEdit *textCheckOnTheta;
    QLineEdit *textCheckOnZ;
    QPushButton *startFindBall;
    QFrame *viewLine;
    QLabel *viewLabel;
    QLineEdit *textIsFind;
    QPushButton *killFindBall;
    QPushButton *reset;
    QPushButton *runFun1;
    QPushButton *findVolleyBall;
    QPushButton *findCylinder;
    QPushButton *findLine;
    QLineEdit *basketball;
    QLineEdit *volleyball;
    QLineEdit *line;
    QLineEdit *cylinder;
    QWidget *status;
    QPushButton *status2;
    QPushButton *status1;
    QLabel *statusLable;
    QPushButton *status5;
    QFrame *statusLine;
    QPushButton *status3;
    QPushButton *status4;
    QPushButton *clearMileage;
    QPushButton *status6;
    QLineEdit *textMileageX;
    QLineEdit *textMileageY;
    QLineEdit *textMileageYaw;
    QPushButton *killStatus;
    QPushButton *startStatus;
    QWidget *TEST;
    QWidget *SET;
    QWidget *lineing;
    QLabel *lineingLable;
    QFrame *lineLine;
    QSlider *HMax;
    QSlider *HMin;
    QLabel *H;
    QSlider *SMin;
    QLabel *S;
    QSlider *SMax;
    QSlider *VMin;
    QLabel *V;
    QSlider *VMax;
    QLineEdit *HMaxEdit;
    QLineEdit *HMinEdit;
    QLineEdit *VMinEdit;
    QLineEdit *SMinEdit;
    QLineEdit *VMaxEdit;
    QLineEdit *SMaxEdit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1040, 742);
        toolBox = new QToolBox(MainWindow);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(50, 35, 921, 631));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        toolBox->setPalette(palette);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        toolBox->setFont(font);
        SHOW = new QWidget();
        SHOW->setObjectName(QStringLiteral("SHOW"));
        SHOW->setGeometry(QRect(0, 0, 921, 538));
        QFont font1;
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        SHOW->setFont(font1);
        SHOW->setCursor(QCursor(Qt::OpenHandCursor));
        horizontalLayout = new QHBoxLayout(SHOW);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        armControl = new QWidget(SHOW);
        armControl->setObjectName(QStringLiteral("armControl"));
        descend = new QPushButton(armControl);
        descend->setObjectName(QStringLiteral("descend"));
        descend->setGeometry(QRect(0, 70, 140, 27));
        raise = new QPushButton(armControl);
        raise->setObjectName(QStringLiteral("raise"));
        raise->setGeometry(QRect(0, 40, 140, 27));
        armControlLable = new QLabel(armControl);
        armControlLable->setObjectName(QStringLiteral("armControlLable"));
        armControlLable->setGeometry(QRect(110, 5, 81, 20));
        QFont font2;
        font2.setPointSize(11);
        armControlLable->setFont(font2);
        shoot = new QPushButton(armControl);
        shoot->setObjectName(QStringLiteral("shoot"));
        shoot->setGeometry(QRect(0, 130, 297, 27));
        armControlLine = new QFrame(armControl);
        armControlLine->setObjectName(QStringLiteral("armControlLine"));
        armControlLine->setGeometry(QRect(-10, 20, 297, 16));
        armControlLine->setFrameShape(QFrame::HLine);
        armControlLine->setFrameShadow(QFrame::Sunken);
        down = new QPushButton(armControl);
        down->setObjectName(QStringLiteral("down"));
        down->setGeometry(QRect(0, 100, 140, 27));
        tackles = new QPushButton(armControl);
        tackles->setObjectName(QStringLiteral("tackles"));
        tackles->setGeometry(QRect(150, 40, 140, 27));
        downToUp = new QPushButton(armControl);
        downToUp->setObjectName(QStringLiteral("downToUp"));
        downToUp->setGeometry(QRect(150, 70, 140, 27));
        keepToDown = new QPushButton(armControl);
        keepToDown->setObjectName(QStringLiteral("keepToDown"));
        keepToDown->setGeometry(QRect(150, 100, 140, 27));
        textStatus = new QLineEdit(armControl);
        textStatus->setObjectName(QStringLiteral("textStatus"));
        textStatus->setGeometry(QRect(0, 250, 297, 27));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textStatus->setPalette(palette1);

        horizontalLayout->addWidget(armControl);

        view = new QWidget(SHOW);
        view->setObjectName(QStringLiteral("view"));
        textCheckOnX = new QLineEdit(view);
        textCheckOnX->setObjectName(QStringLiteral("textCheckOnX"));
        textCheckOnX->setGeometry(QRect(0, 100, 140, 27));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textCheckOnX->setPalette(palette2);
        textCheckOnY = new QLineEdit(view);
        textCheckOnY->setObjectName(QStringLiteral("textCheckOnY"));
        textCheckOnY->setGeometry(QRect(150, 130, 140, 27));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textCheckOnY->setPalette(palette3);
        textCheckOnTheta = new QLineEdit(view);
        textCheckOnTheta->setObjectName(QStringLiteral("textCheckOnTheta"));
        textCheckOnTheta->setGeometry(QRect(150, 160, 140, 27));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textCheckOnTheta->setPalette(palette4);
        textCheckOnZ = new QLineEdit(view);
        textCheckOnZ->setObjectName(QStringLiteral("textCheckOnZ"));
        textCheckOnZ->setGeometry(QRect(0, 130, 140, 27));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textCheckOnZ->setPalette(palette5);
        startFindBall = new QPushButton(view);
        startFindBall->setObjectName(QStringLiteral("startFindBall"));
        startFindBall->setGeometry(QRect(0, 40, 150, 27));
        viewLine = new QFrame(view);
        viewLine->setObjectName(QStringLiteral("viewLine"));
        viewLine->setGeometry(QRect(0, 20, 297, 16));
        viewLine->setFrameShape(QFrame::HLine);
        viewLine->setFrameShadow(QFrame::Sunken);
        viewLabel = new QLabel(view);
        viewLabel->setObjectName(QStringLiteral("viewLabel"));
        viewLabel->setGeometry(QRect(140, 5, 41, 20));
        textIsFind = new QLineEdit(view);
        textIsFind->setObjectName(QStringLiteral("textIsFind"));
        textIsFind->setGeometry(QRect(0, 160, 140, 27));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textIsFind->setPalette(palette6);
        killFindBall = new QPushButton(view);
        killFindBall->setObjectName(QStringLiteral("killFindBall"));
        killFindBall->setGeometry(QRect(0, 360, 297, 27));
        reset = new QPushButton(view);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(150, 100, 140, 27));
        runFun1 = new QPushButton(view);
        runFun1->setObjectName(QStringLiteral("runFun1"));
        runFun1->setGeometry(QRect(0, 70, 297, 27));
        findVolleyBall = new QPushButton(view);
        findVolleyBall->setObjectName(QStringLiteral("findVolleyBall"));
        findVolleyBall->setGeometry(QRect(0, 190, 150, 27));
        findCylinder = new QPushButton(view);
        findCylinder->setObjectName(QStringLiteral("findCylinder"));
        findCylinder->setGeometry(QRect(0, 230, 150, 27));
        findLine = new QPushButton(view);
        findLine->setObjectName(QStringLiteral("findLine"));
        findLine->setGeometry(QRect(0, 270, 150, 27));
        basketball = new QLineEdit(view);
        basketball->setObjectName(QStringLiteral("basketball"));
        basketball->setGeometry(QRect(150, 40, 140, 27));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        basketball->setPalette(palette7);
        volleyball = new QLineEdit(view);
        volleyball->setObjectName(QStringLiteral("volleyball"));
        volleyball->setGeometry(QRect(150, 190, 140, 27));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        volleyball->setPalette(palette8);
        line = new QLineEdit(view);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(150, 270, 140, 27));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        line->setPalette(palette9);
        cylinder = new QLineEdit(view);
        cylinder->setObjectName(QStringLiteral("cylinder"));
        cylinder->setGeometry(QRect(150, 230, 140, 27));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        cylinder->setPalette(palette10);

        horizontalLayout->addWidget(view);

        status = new QWidget(SHOW);
        status->setObjectName(QStringLiteral("status"));
        status->setMouseTracking(false);
        status2 = new QPushButton(status);
        status2->setObjectName(QStringLiteral("status2"));
        status2->setGeometry(QRect(0, 200, 297, 35));
        status1 = new QPushButton(status);
        status1->setObjectName(QStringLiteral("status1"));
        status1->setGeometry(QRect(0, 160, 297, 35));
        statusLable = new QLabel(status);
        statusLable->setObjectName(QStringLiteral("statusLable"));
        statusLable->setGeometry(QRect(120, 5, 51, 20));
        status5 = new QPushButton(status);
        status5->setObjectName(QStringLiteral("status5"));
        status5->setGeometry(QRect(0, 360, 297, 35));
        statusLine = new QFrame(status);
        statusLine->setObjectName(QStringLiteral("statusLine"));
        statusLine->setGeometry(QRect(-10, 20, 297, 16));
        statusLine->setFrameShape(QFrame::HLine);
        statusLine->setFrameShadow(QFrame::Sunken);
        status3 = new QPushButton(status);
        status3->setObjectName(QStringLiteral("status3"));
        status3->setGeometry(QRect(0, 240, 297, 35));
        status4 = new QPushButton(status);
        status4->setObjectName(QStringLiteral("status4"));
        status4->setGeometry(QRect(0, 320, 297, 35));
        clearMileage = new QPushButton(status);
        clearMileage->setObjectName(QStringLiteral("clearMileage"));
        clearMileage->setGeometry(QRect(0, 70, 297, 27));
        status6 = new QPushButton(status);
        status6->setObjectName(QStringLiteral("status6"));
        status6->setGeometry(QRect(0, 400, 297, 35));
        textMileageX = new QLineEdit(status);
        textMileageX->setObjectName(QStringLiteral("textMileageX"));
        textMileageX->setGeometry(QRect(0, 100, 140, 27));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textMileageX->setPalette(palette11);
        textMileageY = new QLineEdit(status);
        textMileageY->setObjectName(QStringLiteral("textMileageY"));
        textMileageY->setGeometry(QRect(150, 100, 140, 27));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textMileageY->setPalette(palette12);
        textMileageYaw = new QLineEdit(status);
        textMileageYaw->setObjectName(QStringLiteral("textMileageYaw"));
        textMileageYaw->setGeometry(QRect(0, 130, 297, 27));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        textMileageYaw->setPalette(palette13);
        killStatus = new QPushButton(status);
        killStatus->setObjectName(QStringLiteral("killStatus"));
        killStatus->setGeometry(QRect(150, 40, 140, 27));
        startStatus = new QPushButton(status);
        startStatus->setObjectName(QStringLiteral("startStatus"));
        startStatus->setGeometry(QRect(0, 40, 140, 27));

        horizontalLayout->addWidget(status);

        toolBox->addItem(SHOW, QStringLiteral("SHOW"));
        TEST = new QWidget();
        TEST->setObjectName(QStringLiteral("TEST"));
        TEST->setGeometry(QRect(0, 0, 100, 30));
        toolBox->addItem(TEST, QStringLiteral("TEST"));
        SET = new QWidget();
        SET->setObjectName(QStringLiteral("SET"));
        SET->setGeometry(QRect(0, 0, 100, 30));
        lineing = new QWidget(SET);
        lineing->setObjectName(QStringLiteral("lineing"));
        lineing->setGeometry(QRect(0, 0, 238, 259));
        lineingLable = new QLabel(lineing);
        lineingLable->setObjectName(QStringLiteral("lineingLable"));
        lineingLable->setGeometry(QRect(90, 10, 51, 17));
        lineLine = new QFrame(lineing);
        lineLine->setObjectName(QStringLiteral("lineLine"));
        lineLine->setGeometry(QRect(7, 20, 221, 20));
        lineLine->setFrameShape(QFrame::HLine);
        lineLine->setFrameShadow(QFrame::Sunken);
        HMax = new QSlider(lineing);
        HMax->setObjectName(QStringLiteral("HMax"));
        HMax->setGeometry(QRect(30, 40, 161, 29));
        HMax->setLayoutDirection(Qt::RightToLeft);
        HMax->setMinimum(0);
        HMax->setMaximum(179);
        HMax->setValue(0);
        HMax->setSliderPosition(0);
        HMax->setTracking(false);
        HMax->setOrientation(Qt::Horizontal);
        HMax->setInvertedControls(false);
        HMax->setTickPosition(QSlider::NoTicks);
        HMin = new QSlider(lineing);
        HMin->setObjectName(QStringLiteral("HMin"));
        HMin->setGeometry(QRect(30, 60, 160, 29));
        HMin->setMaximum(179);
        HMin->setSliderPosition(0);
        HMin->setOrientation(Qt::Horizontal);
        HMin->setInvertedAppearance(false);
        HMin->setInvertedControls(false);
        HMin->setTickPosition(QSlider::NoTicks);
        H = new QLabel(lineing);
        H->setObjectName(QStringLiteral("H"));
        H->setGeometry(QRect(10, 60, 16, 17));
        SMin = new QSlider(lineing);
        SMin->setObjectName(QStringLiteral("SMin"));
        SMin->setGeometry(QRect(30, 140, 160, 29));
        SMin->setMaximum(255);
        SMin->setOrientation(Qt::Horizontal);
        SMin->setTickPosition(QSlider::NoTicks);
        S = new QLabel(lineing);
        S->setObjectName(QStringLiteral("S"));
        S->setGeometry(QRect(10, 140, 16, 17));
        SMax = new QSlider(lineing);
        SMax->setObjectName(QStringLiteral("SMax"));
        SMax->setGeometry(QRect(30, 120, 160, 29));
        SMax->setLayoutDirection(Qt::RightToLeft);
        SMax->setMaximum(255);
        SMax->setOrientation(Qt::Horizontal);
        SMax->setTickPosition(QSlider::NoTicks);
        VMin = new QSlider(lineing);
        VMin->setObjectName(QStringLiteral("VMin"));
        VMin->setGeometry(QRect(30, 220, 160, 29));
        VMin->setMaximum(255);
        VMin->setOrientation(Qt::Horizontal);
        VMin->setInvertedAppearance(false);
        VMin->setInvertedControls(false);
        VMin->setTickPosition(QSlider::NoTicks);
        VMin->setTickInterval(10);
        V = new QLabel(lineing);
        V->setObjectName(QStringLiteral("V"));
        V->setGeometry(QRect(10, 220, 16, 17));
        VMax = new QSlider(lineing);
        VMax->setObjectName(QStringLiteral("VMax"));
        VMax->setGeometry(QRect(30, 200, 160, 29));
        VMax->setLayoutDirection(Qt::RightToLeft);
        VMax->setMaximum(255);
        VMax->setOrientation(Qt::Horizontal);
        VMax->setTickPosition(QSlider::NoTicks);
        HMaxEdit = new QLineEdit(lineing);
        HMaxEdit->setObjectName(QStringLiteral("HMaxEdit"));
        HMaxEdit->setGeometry(QRect(190, 40, 41, 21));
        HMinEdit = new QLineEdit(lineing);
        HMinEdit->setObjectName(QStringLiteral("HMinEdit"));
        HMinEdit->setGeometry(QRect(190, 60, 41, 21));
        VMinEdit = new QLineEdit(lineing);
        VMinEdit->setObjectName(QStringLiteral("VMinEdit"));
        VMinEdit->setGeometry(QRect(190, 220, 41, 21));
        SMinEdit = new QLineEdit(lineing);
        SMinEdit->setObjectName(QStringLiteral("SMinEdit"));
        SMinEdit->setGeometry(QRect(190, 140, 41, 21));
        VMaxEdit = new QLineEdit(lineing);
        VMaxEdit->setObjectName(QStringLiteral("VMaxEdit"));
        VMaxEdit->setGeometry(QRect(190, 200, 41, 21));
        SMaxEdit = new QLineEdit(lineing);
        SMaxEdit->setObjectName(QStringLiteral("SMaxEdit"));
        SMaxEdit->setGeometry(QRect(190, 120, 41, 21));
        toolBox->addItem(SET, QStringLiteral("SET"));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        descend->setText(QApplication::translate("MainWindow", "1-descend", 0));
        raise->setText(QApplication::translate("MainWindow", "0-\346\224\276-\344\275\216", 0));
        armControlLable->setText(QApplication::translate("MainWindow", "armControl", 0));
        shoot->setText(QApplication::translate("MainWindow", "shoot", 0));
        down->setText(QApplication::translate("MainWindow", "2-down", 0));
        tackles->setText(QApplication::translate("MainWindow", "3-\351\253\230-\344\275\216", 0));
        downToUp->setText(QApplication::translate("MainWindow", "4-\344\275\216-\351\253\230", 0));
        keepToDown->setText(QApplication::translate("MainWindow", "5-keepToDown", 0));
        textStatus->setPlaceholderText(QApplication::translate("MainWindow", "status:", 0));
        textCheckOnX->setPlaceholderText(QApplication::translate("MainWindow", "x:", 0));
        textCheckOnY->setPlaceholderText(QApplication::translate("MainWindow", "y:", 0));
        textCheckOnTheta->setPlaceholderText(QApplication::translate("MainWindow", "theta:", 0));
        textCheckOnZ->setPlaceholderText(QApplication::translate("MainWindow", "z:", 0));
        startFindBall->setText(QApplication::translate("MainWindow", "startFindBall", 0));
        viewLabel->setText(QApplication::translate("MainWindow", "view", 0));
        textIsFind->setPlaceholderText(QApplication::translate("MainWindow", "isFind:", 0));
        killFindBall->setText(QApplication::translate("MainWindow", "killFindBall", 0));
        reset->setText(QApplication::translate("MainWindow", "reset", 0));
        runFun1->setText(QApplication::translate("MainWindow", "runFun1", 0));
        findVolleyBall->setText(QApplication::translate("MainWindow", "findVolleyBall", 0));
        findCylinder->setText(QApplication::translate("MainWindow", "findCylinder", 0));
        findLine->setText(QApplication::translate("MainWindow", "findLine", 0));
        basketball->setPlaceholderText(QApplication::translate("MainWindow", "basketBall:", 0));
        volleyball->setPlaceholderText(QApplication::translate("MainWindow", "volleyBall:", 0));
        line->setPlaceholderText(QApplication::translate("MainWindow", "line:", 0));
        cylinder->setText(QString());
        cylinder->setPlaceholderText(QApplication::translate("MainWindow", "cylinder:", 0));
        status2->setText(QApplication::translate("MainWindow", "\344\274\240\347\220\2032", 0));
        status1->setText(QApplication::translate("MainWindow", "\344\274\240\347\220\2031", 0));
        statusLable->setText(QApplication::translate("MainWindow", "status", 0));
        status5->setText(QApplication::translate("MainWindow", "\346\212\225\347\220\2032", 0));
        status3->setText(QApplication::translate("MainWindow", "\344\274\240\347\220\2033", 0));
        status4->setText(QApplication::translate("MainWindow", "\346\212\225\347\220\2031", 0));
        clearMileage->setText(QApplication::translate("MainWindow", "clear Mileage", 0));
        status6->setText(QApplication::translate("MainWindow", "\346\212\225\347\220\2033", 0));
        textMileageX->setPlaceholderText(QApplication::translate("MainWindow", "x:", 0));
        textMileageY->setPlaceholderText(QApplication::translate("MainWindow", "z:", 0));
        textMileageYaw->setPlaceholderText(QApplication::translate("MainWindow", "yaw:", 0));
        killStatus->setText(QApplication::translate("MainWindow", "killStatus", 0));
        startStatus->setText(QApplication::translate("MainWindow", "startStatus", 0));
        toolBox->setItemText(toolBox->indexOf(SHOW), QApplication::translate("MainWindow", "SHOW", 0));
        toolBox->setItemText(toolBox->indexOf(TEST), QApplication::translate("MainWindow", "TEST", 0));
        lineingLable->setText(QApplication::translate("MainWindow", "lineing", 0));
        H->setText(QApplication::translate("MainWindow", "H", 0));
        S->setText(QApplication::translate("MainWindow", "S", 0));
        V->setText(QApplication::translate("MainWindow", "V", 0));
        HMaxEdit->setText(QString());
        HMinEdit->setText(QString());
        VMinEdit->setText(QString());
        SMinEdit->setText(QString());
        VMaxEdit->setText(QString());
        SMaxEdit->setText(QString());
        toolBox->setItemText(toolBox->indexOf(SET), QApplication::translate("MainWindow", "SET", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
