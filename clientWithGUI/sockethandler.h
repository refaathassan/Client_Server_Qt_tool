#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
class SocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit SocketHandler(QObject *parent = nullptr);
    void MakeConnect(QString ip,qint32 port);
    void MakeDisconnect(void);
    void WriteToSocket(QString data);

private:
    QString ip;
    qint32 port;
    QTcpSocket socket;
    void OnConnect(void);
    void OnDisconnect(void);
    void OnError(QAbstractSocket::SocketError socketError);
    void OnTrigger(QAbstractSocket::SocketState socketState);
    void OnReadyRead(void);

signals:
    void Connect(void);
    void Disconnect(void);
    void Error(QAbstractSocket::SocketError socketErro);
    void Trigger(QAbstractSocket::SocketState socketState);
    void ReadyRead(QString str);
};

#endif // SOCKETHANDLER_H
