#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include <QTcpSocket>
class DeviceController : public QObject
{
    Q_OBJECT
public:
    explicit DeviceController(QObject *parent = nullptr);
    void ConnectToDevice(QString ip,int port);
    void Disconnect();
    QAbstractSocket::SocketState GetState();
    bool IsConnected();
    void send(QString data);

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);
    void readData(QByteArray data);
private slots:
    void socket_stateChanged(QAbstractSocket::SocketState state);
    void readReady();
private:
    QTcpSocket _socket;
    QString _ip;
    int _port;
};

#endif // DEVICECONTROLLER_H
