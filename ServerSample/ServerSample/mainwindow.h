#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytcpserver.h"

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
    void on_btn_startserver_clicked();
    void new_client_connected();
    void new_client_disconnected();
    void client_data_recieved(QString data);
private:
    Ui::MainWindow *ui;
    MyTCPServer* _server;
};
#endif // MAINWINDOW_H
