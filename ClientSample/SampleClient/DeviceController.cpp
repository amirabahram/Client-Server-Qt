#include "DeviceController.h"

DeviceController::DeviceController(QObject *parent)
    : QObject{parent}
{
    connect(&_socket,&QTcpSocket::connected,this,&DeviceController::connected);
    connect(&_socket,&QTcpSocket::disconnected,this,&DeviceController::disconnected);
    connect(&_socket,&QTcpSocket::errorOccurred,this,&DeviceController::errorOccurred);
    connect(&_socket,&QTcpSocket::stateChanged,this,&DeviceController::socket_stateChanged);
    connect(&_socket,&QTcpSocket::readyRead,this,&DeviceController::readReady);
}

void DeviceController::ConnectToDevice(QString ip, int port)
{
    if(_socket.isOpen()){
        if(ip ==_ip && port ==_port){
            return;
        }
        _socket.close();
    }
    _ip = ip;
    _port = port;
    _socket.connectToHost(_ip,_port);
}

void DeviceController::Disconnect()
{
    _socket.close();
}

QAbstractSocket::SocketState DeviceController::GetState()
{
    return _socket.state();
}

bool DeviceController::IsConnected()
{
    return _socket.state()== QAbstractSocket::ConnectedState;
}

void DeviceController::send(QString data)
{
    _socket.write(data.toUtf8());
}

void DeviceController::socket_stateChanged(QAbstractSocket::SocketState state)
{
    if(state == QAbstractSocket::UnconnectedState){
        _socket.close();
    }
    emit stateChanged(state);
}

void DeviceController::readReady()
{
    auto data = _socket.readAll();
    emit readData(data);
}
