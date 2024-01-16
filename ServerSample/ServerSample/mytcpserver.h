#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class MyTCPServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTCPServer(int port,QObject *parent = nullptr);
private slots:
    void onClientConnecting();
    void readyRead();
    void clientDisconnected();
private:
    QTcpServer *_server;
    QList<QTcpSocket*> _socketsList;
    bool _isConnected;
signals:
    void newClientConnected();
    void clientDataReady(QString data);
    void client_Disconnected();

};

#endif // MYTCPSERVER_H
