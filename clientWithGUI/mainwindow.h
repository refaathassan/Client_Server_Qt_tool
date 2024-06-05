#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaEnum>

#include <QMetaEnum>
#include "sockethandler.h"
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
    void OnConnectDe(void);
    void OnDisconnectDe(void);
    void OnErrorDe(QAbstractSocket::SocketError socketError);
    void OnTriggerDe(QAbstractSocket::SocketState socketState);
    void OnReadyReadDe(QString str);
private slots:


    void on_PbDisconnect_clicked();

    void on_PbConnect_clicked();

    void on_PbSend_clicked();

private:
    Ui::MainWindow *ui;
    SocketHandler handler;
};
#endif // MAINWINDOW_H
