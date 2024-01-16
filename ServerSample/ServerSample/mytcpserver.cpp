#include "mytcpserver.h"

MyTCPServer::MyTCPServer(int port, QObject *parent)
    : QObject{parent}
{
    _server = new QTcpServer(this);
    connect(_server,&QTcpServer::newConnection,this,&MyTCPServer::onClientConnecting);

    _isConnected = _server->listen(QHostAddress::Any,port);
    if(!_isConnected){
        qDebug()<<"Server Could not start";
    }else{
        qDebug()<<"Server started...";
    }
}

void MyTCPServer::onClientConnecting()
{
    qDebug() <<"a client connected to server...";
    auto socket = _server->nextPendingConnection();
    _socketsList.append(socket);
    connect(socket,&QTcpSocket::readyRead,this,&MyTCPServer::readyRead);
    connect(socket,&QTcpSocket::disconnected,this,&MyTCPServer::clientDisconnected);
    emit newClientConnected();
}

void MyTCPServer::readyRead()
{
    auto socket = qobject_cast<QTcpSocket *> (sender());
    auto data = socket->readAll();
    emit clientDataReady(QString(data));
}

void MyTCPServer::clientDisconnected()
{
    emit client_Disconnected();
}


