#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAbstractSocket>
#include <QMetaEnum>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setDeviceController();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_IpAddress_textChanged(const QString &arg1)
{
    QString state = "0";
    if(arg1=="...")
    {
        state = "";
    }
    else
    {
        QHostAddress address(arg1);

        if(QAbstractSocket::IPv4Protocol == address.protocol()){
            state="1";
        }

    }
    ui->IpAddress->setProperty("state",state);
    style()->polish(ui->IpAddress);
}


void MainWindow::on_pushButton_clicked()
{
    if(_controller.IsConnected()){
        _controller.Disconnect();
    }else{
        auto ip = ui->IpAddress->text();
        auto port = ui->Port->value();
        _controller.ConnectToDevice(ip,port);
    }


}

void MainWindow::device_connected()
{
    ui->listWidget->addItem("Connected To Device");
    ui->pushButton->setText("Disconnect");
    ui->groupBox_2->setEnabled(true);
}

void MainWindow::device_disconnected()
{
    ui->listWidget->addItem("Disconnected from Device");
    ui->pushButton->setText("Connect");
    ui->groupBox_2->setEnabled(false);
}

void MainWindow::device_stateChanged(QAbstractSocket::SocketState state)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->listWidget->addItem(metaEnum.valueToKey(state));
}

void MainWindow::device_errorOccurred(QAbstractSocket::SocketError error)
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->listWidget->addItem(metaEnum.valueToKey(error));
}

void MainWindow::setDeviceController()
{
    connect(&_controller,&DeviceController::connected,this,&MainWindow::device_connected);
    connect(&_controller,&DeviceController::disconnected,this,&MainWindow::device_disconnected);
    connect(&_controller,&DeviceController::stateChanged,this,&MainWindow::device_stateChanged);
    connect(&_controller,&DeviceController::errorOccurred,this,&MainWindow::device_errorOccurred);
    connect(&_controller,&DeviceController::readData,this,&MainWindow::readServerSendingData);
}

void MainWindow::readServerSendingData(QByteArray data)
{
    ui->listWidget->addItem(QString(data));
}



void MainWindow::on_btn_Send_clicked()
{
    auto data = ui->SendData->text().trimmed();
    _controller.send(data);
}

