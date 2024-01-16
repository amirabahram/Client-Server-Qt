#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpserver.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_startserver_clicked()
{
    if(_server == nullptr){
        auto port = ui->spinBox->value();
        _server = new MyTCPServer(port);
        connect(_server,&MyTCPServer::newClientConnected,this,
                &MainWindow::new_client_connected);

    }

}

void MainWindow::new_client_connected()
{
    ui->lstConsole->addItem("New Client Connected!");
    connect(_server,&MyTCPServer::client_Disconnected,this,&MainWindow::new_client_disconnected);
    connect(_server,&MyTCPServer::clientDataReady,this,&MainWindow::client_data_recieved);


}

void MainWindow::new_client_disconnected()
{
    ui->lstConsole->addItem("Client Disconnected");
}

void MainWindow::client_data_recieved(QString data)
{
    ui->lstConsole->addItem(data);
}

