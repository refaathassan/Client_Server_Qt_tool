/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LePort;
    QPushButton *PbConnect;
    QPushButton *PbDisconnect;
    QLineEdit *LeIp;
    QGroupBox *groupBox_2;
    QListWidget *LwReceive;
    QPushButton *pushButton_5;
    QLineEdit *LeSend;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *PbSend;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(929, 632);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(550, 0, 331, 161));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 121, 31));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.738636, y2:0.744, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(16, 255, 122, 255));"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 70, 121, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.738636, y2:0.744, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(16, 255, 122, 255));"));
        LePort = new QLineEdit(groupBox);
        LePort->setObjectName("LePort");
        LePort->setGeometry(QRect(142, 70, 171, 31));
        PbConnect = new QPushButton(groupBox);
        PbConnect->setObjectName("PbConnect");
        PbConnect->setGeometry(QRect(30, 120, 111, 31));
        PbDisconnect = new QPushButton(groupBox);
        PbDisconnect->setObjectName("PbDisconnect");
        PbDisconnect->setGeometry(QRect(170, 120, 111, 31));
        LeIp = new QLineEdit(groupBox);
        LeIp->setObjectName("LeIp");
        LeIp->setGeometry(QRect(142, 20, 171, 31));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 0, 541, 601));
        LwReceive = new QListWidget(groupBox_2);
        LwReceive->setObjectName("LwReceive");
        LwReceive->setGeometry(QRect(120, 20, 411, 441));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(-290, 920, 111, 31));
        LeSend = new QLineEdit(groupBox_2);
        LeSend->setObjectName("LeSend");
        LeSend->setGeometry(QRect(120, 470, 411, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 30, 101, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.738636, y2:0.744, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(16, 255, 122, 255));"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 470, 101, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.738636, y2:0.744, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(16, 255, 122, 255));"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 510, 411, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PbSend = new QPushButton(layoutWidget);
        PbSend->setObjectName("PbSend");

        horizontalLayout->addWidget(PbSend);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 929, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_4, &QPushButton::clicked, LwReceive, qOverload<>(&QListWidget::clear));
        QObject::connect(groupBox_2, &QGroupBox::clicked, LeSend, qOverload<>(&QLineEdit::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "connection", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Enter IP</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Enter Port</p></body></html>", nullptr));
        LePort->setText(QString());
        PbConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        PbDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        LeIp->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Communication", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Receive:</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Send:</p></body></html>", nullptr));
        PbSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
