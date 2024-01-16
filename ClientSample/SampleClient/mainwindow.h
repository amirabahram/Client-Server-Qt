#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include <QStyle>
#include "DeviceController.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_IpAddress_textChanged(const QString &arg1);
    void on_pushButton_clicked();
    void device_connected();
    void device_disconnected();
    void device_stateChanged(QAbstractSocket::SocketState);
    void device_errorOccurred(QAbstractSocket::SocketError);
    void setDeviceController();
    void readServerSendingData(QByteArray data);

    void on_btn_Send_clicked();

private:
    Ui::MainWindow *ui;
    DeviceController _controller;

};
#endif // MAINWINDOW_H
