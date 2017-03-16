/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageUsername;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *inputUsername;
    QWidget *pagePassword;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *inputPassword;
    QSpacerItem *horizontalSpacer_4;
    QWidget *pageLoading;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_7;
    QProgressBar *progressBar_loading;
    QSpacerItem *horizontalSpacer_8;
    QWidget *pageRoot;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_auto;
    QPushButton *pushButton_manual;
    QPushButton *pushButton_settings;
    QPushButton *pushButton_exit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QWidget *pageAuto;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer_4;
    QStackedWidget *stackedWidget_2;
    QWidget *pageMissionView;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_selectMission;
    QPushButton *pushButton_pauseContinue;
    QPushButton *pushButton_return_3;
    QPushButton *pushButton_abort;
    QFrame *frame_positioning;
    QFrame *frame_cameraView;
    QPushButton *pushButton_manualOverride;
    QWidget *pageMissionSelect;
    QGridLayout *gridLayout_8;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_searchAndRescue;
    QPushButton *pushButton_compete;
    QPushButton *pushButton_searchAndDestroy;
    QPushButton *pushButton_discoMission;
    QPushButton *pushButton_return;
    QSpacerItem *verticalSpacer_3;
    QWidget *pageManual;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_back;
    QPushButton *pushButton_up;
    QPushButton *pushButton_forward;
    QPushButton *pushButton_left;
    QPushButton *pushButton_right;
    QFrame *frame_frontCamera;
    QFrame *frame_bottomCamera;
    QPushButton *pushButton_down;
    QPushButton *pushButton_return_2;
    QWidget *pageSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName(QStringLiteral("MainFrame"));
        MainFrame->resize(459, 300);
        centralWidget = new QWidget(MainFrame);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("background: white;"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageUsername = new QWidget();
        pageUsername->setObjectName(QStringLiteral("pageUsername"));
        gridLayout_2 = new QGridLayout(pageUsername);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        inputUsername = new QLineEdit(pageUsername);
        inputUsername->setObjectName(QStringLiteral("inputUsername"));
        inputUsername->setMaxLength(64);

        gridLayout_2->addWidget(inputUsername, 0, 1, 1, 1);

        stackedWidget->addWidget(pageUsername);
        pagePassword = new QWidget();
        pagePassword->setObjectName(QStringLiteral("pagePassword"));
        gridLayout_3 = new QGridLayout(pagePassword);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(101, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        inputPassword = new QLineEdit(pagePassword);
        inputPassword->setObjectName(QStringLiteral("inputPassword"));

        gridLayout_3->addWidget(inputPassword, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        stackedWidget->addWidget(pagePassword);
        pageLoading = new QWidget();
        pageLoading->setObjectName(QStringLiteral("pageLoading"));
        gridLayout_6 = new QGridLayout(pageLoading);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        progressBar_loading = new QProgressBar(pageLoading);
        progressBar_loading->setObjectName(QStringLiteral("progressBar_loading"));
        progressBar_loading->setValue(24);

        gridLayout_6->addWidget(progressBar_loading, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        stackedWidget->addWidget(pageLoading);
        pageRoot = new QWidget();
        pageRoot->setObjectName(QStringLiteral("pageRoot"));
        gridLayout_4 = new QGridLayout(pageRoot);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 6, 1, 1, 1);

        pushButton_auto = new QPushButton(pageRoot);
        pushButton_auto->setObjectName(QStringLiteral("pushButton_auto"));

        gridLayout_4->addWidget(pushButton_auto, 1, 1, 1, 1);

        pushButton_manual = new QPushButton(pageRoot);
        pushButton_manual->setObjectName(QStringLiteral("pushButton_manual"));

        gridLayout_4->addWidget(pushButton_manual, 2, 1, 1, 1);

        pushButton_settings = new QPushButton(pageRoot);
        pushButton_settings->setObjectName(QStringLiteral("pushButton_settings"));

        gridLayout_4->addWidget(pushButton_settings, 4, 1, 1, 1);

        pushButton_exit = new QPushButton(pageRoot);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        gridLayout_4->addWidget(pushButton_exit, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        stackedWidget->addWidget(pageRoot);
        pageAuto = new QWidget();
        pageAuto->setObjectName(QStringLiteral("pageAuto"));
        gridLayout_7 = new QGridLayout(pageAuto);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_4, 1, 0, 1, 1);

        stackedWidget_2 = new QStackedWidget(pageAuto);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        pageMissionView = new QWidget();
        pageMissionView->setObjectName(QStringLiteral("pageMissionView"));
        gridLayout_9 = new QGridLayout(pageMissionView);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_selectMission = new QPushButton(pageMissionView);
        pushButton_selectMission->setObjectName(QStringLiteral("pushButton_selectMission"));

        gridLayout_9->addWidget(pushButton_selectMission, 1, 0, 1, 1);

        pushButton_pauseContinue = new QPushButton(pageMissionView);
        pushButton_pauseContinue->setObjectName(QStringLiteral("pushButton_pauseContinue"));

        gridLayout_9->addWidget(pushButton_pauseContinue, 1, 1, 1, 1);

        pushButton_return_3 = new QPushButton(pageMissionView);
        pushButton_return_3->setObjectName(QStringLiteral("pushButton_return_3"));

        gridLayout_9->addWidget(pushButton_return_3, 3, 0, 1, 1);

        pushButton_abort = new QPushButton(pageMissionView);
        pushButton_abort->setObjectName(QStringLiteral("pushButton_abort"));

        gridLayout_9->addWidget(pushButton_abort, 3, 1, 1, 1);

        frame_positioning = new QFrame(pageMissionView);
        frame_positioning->setObjectName(QStringLiteral("frame_positioning"));
        frame_positioning->setFrameShape(QFrame::StyledPanel);
        frame_positioning->setFrameShadow(QFrame::Raised);

        gridLayout_9->addWidget(frame_positioning, 0, 1, 1, 1);

        frame_cameraView = new QFrame(pageMissionView);
        frame_cameraView->setObjectName(QStringLiteral("frame_cameraView"));
        frame_cameraView->setFrameShape(QFrame::StyledPanel);
        frame_cameraView->setFrameShadow(QFrame::Raised);

        gridLayout_9->addWidget(frame_cameraView, 0, 0, 1, 1);

        pushButton_manualOverride = new QPushButton(pageMissionView);
        pushButton_manualOverride->setObjectName(QStringLiteral("pushButton_manualOverride"));

        gridLayout_9->addWidget(pushButton_manualOverride, 2, 0, 1, 2);

        stackedWidget_2->addWidget(pageMissionView);
        pageMissionSelect = new QWidget();
        pageMissionSelect->setObjectName(QStringLiteral("pageMissionSelect"));
        gridLayout_8 = new QGridLayout(pageMissionSelect);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_10, 4, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_9, 4, 0, 1, 1);

        pushButton_searchAndRescue = new QPushButton(pageMissionSelect);
        pushButton_searchAndRescue->setObjectName(QStringLiteral("pushButton_searchAndRescue"));

        gridLayout_8->addWidget(pushButton_searchAndRescue, 4, 1, 1, 2);

        pushButton_compete = new QPushButton(pageMissionSelect);
        pushButton_compete->setObjectName(QStringLiteral("pushButton_compete"));

        gridLayout_8->addWidget(pushButton_compete, 3, 1, 1, 2);

        pushButton_searchAndDestroy = new QPushButton(pageMissionSelect);
        pushButton_searchAndDestroy->setObjectName(QStringLiteral("pushButton_searchAndDestroy"));

        gridLayout_8->addWidget(pushButton_searchAndDestroy, 5, 1, 1, 2);

        pushButton_discoMission = new QPushButton(pageMissionSelect);
        pushButton_discoMission->setObjectName(QStringLiteral("pushButton_discoMission"));

        gridLayout_8->addWidget(pushButton_discoMission, 6, 1, 1, 2);

        pushButton_return = new QPushButton(pageMissionSelect);
        pushButton_return->setObjectName(QStringLiteral("pushButton_return"));

        gridLayout_8->addWidget(pushButton_return, 8, 1, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_3, 2, 1, 1, 1);

        stackedWidget_2->addWidget(pageMissionSelect);

        gridLayout_7->addWidget(stackedWidget_2, 0, 0, 1, 1);

        stackedWidget->addWidget(pageAuto);
        pageManual = new QWidget();
        pageManual->setObjectName(QStringLiteral("pageManual"));
        gridLayout_5 = new QGridLayout(pageManual);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        pushButton_back = new QPushButton(pageManual);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));

        gridLayout_5->addWidget(pushButton_back, 4, 2, 1, 1);

        pushButton_up = new QPushButton(pageManual);
        pushButton_up->setObjectName(QStringLiteral("pushButton_up"));

        gridLayout_5->addWidget(pushButton_up, 2, 0, 1, 1);

        pushButton_forward = new QPushButton(pageManual);
        pushButton_forward->setObjectName(QStringLiteral("pushButton_forward"));

        gridLayout_5->addWidget(pushButton_forward, 2, 2, 1, 1);

        pushButton_left = new QPushButton(pageManual);
        pushButton_left->setObjectName(QStringLiteral("pushButton_left"));

        gridLayout_5->addWidget(pushButton_left, 3, 1, 1, 1);

        pushButton_right = new QPushButton(pageManual);
        pushButton_right->setObjectName(QStringLiteral("pushButton_right"));

        gridLayout_5->addWidget(pushButton_right, 3, 3, 1, 1);

        frame_frontCamera = new QFrame(pageManual);
        frame_frontCamera->setObjectName(QStringLiteral("frame_frontCamera"));
        frame_frontCamera->setFrameShape(QFrame::StyledPanel);
        frame_frontCamera->setFrameShadow(QFrame::Raised);

        gridLayout_5->addWidget(frame_frontCamera, 1, 0, 1, 2);

        frame_bottomCamera = new QFrame(pageManual);
        frame_bottomCamera->setObjectName(QStringLiteral("frame_bottomCamera"));
        frame_bottomCamera->setFrameShape(QFrame::StyledPanel);
        frame_bottomCamera->setFrameShadow(QFrame::Raised);

        gridLayout_5->addWidget(frame_bottomCamera, 1, 2, 1, 2);

        pushButton_down = new QPushButton(pageManual);
        pushButton_down->setObjectName(QStringLiteral("pushButton_down"));

        gridLayout_5->addWidget(pushButton_down, 3, 0, 1, 1);

        pushButton_return_2 = new QPushButton(pageManual);
        pushButton_return_2->setObjectName(QStringLiteral("pushButton_return_2"));

        gridLayout_5->addWidget(pushButton_return_2, 4, 0, 1, 1);

        stackedWidget->addWidget(pageManual);
        pageSettings = new QWidget();
        pageSettings->setObjectName(QStringLiteral("pageSettings"));
        stackedWidget->addWidget(pageSettings);

        gridLayout->addWidget(stackedWidget, 0, 2, 1, 1);

        MainFrame->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainFrame);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QStringLiteral("background: white;"));
        MainFrame->setStatusBar(statusBar);

        retranslateUi(MainFrame);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QMainWindow *MainFrame)
    {
        MainFrame->setWindowTitle(QApplication::translate("MainFrame", "MainFrame", Q_NULLPTR));
        inputUsername->setPlaceholderText(QApplication::translate("MainFrame", "username", Q_NULLPTR));
        inputPassword->setPlaceholderText(QApplication::translate("MainFrame", "password", Q_NULLPTR));
        pushButton_auto->setText(QApplication::translate("MainFrame", "Autonomous", Q_NULLPTR));
        pushButton_manual->setText(QApplication::translate("MainFrame", "Manual Override", Q_NULLPTR));
        pushButton_settings->setText(QApplication::translate("MainFrame", "Settings", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("MainFrame", "Exit", Q_NULLPTR));
        pushButton_selectMission->setText(QApplication::translate("MainFrame", "Select Mission", Q_NULLPTR));
        pushButton_pauseContinue->setText(QApplication::translate("MainFrame", "Pause", Q_NULLPTR));
        pushButton_return_3->setText(QApplication::translate("MainFrame", "Return", Q_NULLPTR));
        pushButton_abort->setText(QApplication::translate("MainFrame", "Stop", Q_NULLPTR));
        pushButton_manualOverride->setText(QApplication::translate("MainFrame", "Manual Override", Q_NULLPTR));
        pushButton_searchAndRescue->setText(QApplication::translate("MainFrame", "Search and Rescue", Q_NULLPTR));
        pushButton_compete->setText(QApplication::translate("MainFrame", "Compete", Q_NULLPTR));
        pushButton_searchAndDestroy->setText(QApplication::translate("MainFrame", "Search and Destroy", Q_NULLPTR));
        pushButton_discoMission->setText(QApplication::translate("MainFrame", "Disco Mission", Q_NULLPTR));
        pushButton_return->setText(QApplication::translate("MainFrame", "Return", Q_NULLPTR));
        pushButton_back->setText(QApplication::translate("MainFrame", "Backwards (S)", Q_NULLPTR));
        pushButton_up->setText(QApplication::translate("MainFrame", "Up (\342\206\221)", Q_NULLPTR));
        pushButton_forward->setText(QApplication::translate("MainFrame", "Forward (W)", Q_NULLPTR));
        pushButton_left->setText(QApplication::translate("MainFrame", "Left (A)", Q_NULLPTR));
        pushButton_right->setText(QApplication::translate("MainFrame", "Right (D)", Q_NULLPTR));
        pushButton_down->setText(QApplication::translate("MainFrame", "Down (\342\206\223)", Q_NULLPTR));
        pushButton_return_2->setText(QApplication::translate("MainFrame", "Return", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
