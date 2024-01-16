/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QLineEdit *IpAddress;
    QSpinBox *Port;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *clearButton;
    QGroupBox *groupBox_2;
    QLineEdit *SendData;
    QLabel *label_3;
    QPushButton *btn_Send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#IpAddress[state=\"0\"]{\n"
"	background-color: rgb(224, 27, 36);\n"
"}\n"
"#IpAddress[state=\"1\"]{\n"
"	background-color: rgb(87, 227, 137);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 19, 461, 211));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 40, 101, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 80, 80, 21));
        IpAddress = new QLineEdit(groupBox);
        IpAddress->setObjectName("IpAddress");
        IpAddress->setGeometry(QRect(160, 40, 281, 28));
        IpAddress->setClearButtonEnabled(true);
        Port = new QSpinBox(groupBox);
        Port->setObjectName("Port");
        Port->setGeometry(QRect(161, 80, 101, 29));
        Port->setMinimum(1024);
        Port->setMaximum(65536);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 130, 106, 30));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(510, 40, 256, 461));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(515, 510, 251, 30));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setEnabled(false);
        groupBox_2->setGeometry(QRect(10, 240, 461, 221));
        SendData = new QLineEdit(groupBox_2);
        SendData->setObjectName("SendData");
        SendData->setGeometry(QRect(150, 40, 261, 28));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 40, 51, 21));
        btn_Send = new QPushButton(groupBox_2);
        btn_Send->setObjectName("btn_Send");
        btn_Send->setGeometry(QRect(150, 90, 106, 30));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(clearButton, &QPushButton::clicked, listWidget, qOverload<>(&QListWidget::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ip Address", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        IpAddress->setInputMask(QCoreApplication::translate("MainWindow", "000.000.000.000;_", nullptr));
        IpAddress->setProperty("state", QVariant(QString()));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Send Data", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        btn_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
