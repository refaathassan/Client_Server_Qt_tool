#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
class MyServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit MyServerHandler(qint32 ID=0,QObject *parent = nullptr);
    void OnDisconnect(void);
    void OnReadyRead(void);
    void SendMassage(QString massage);
    void Operation(QString massage);
signals:
private:
    qint32 ID;
    QTcpSocket * soc;
    // QThread interface
protected:
    void run();
};

#endif // MYSERVERHANDLER_H
