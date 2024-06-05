#include "sockethandler.h"

SocketHandler::SocketHandler(QObject *parent)
    : QObject{parent}
{
    connect(&socket,&QTcpSocket::connected,this,&SocketHandler::OnConnect);
    connect(&socket,&QTcpSocket::disconnected,this,&SocketHandler::OnDisconnect);
    connect(&socket,&QTcpSocket::errorOccurred,this,&SocketHandler::OnError);
    connect(&socket,&QTcpSocket::stateChanged,this,&SocketHandler::OnTrigger);
    connect(&socket,&QTcpSocket::readyRead,this,&SocketHandler::OnReadyRead);
}

void SocketHandler::MakeConnect(QString ip, qint32 port)
{
    if(socket.isOpen())
    {
        if(this->ip==ip&&this->port==port)
        {
            return;
        }
        else
        {
           socket.close();
           this->ip=ip;
           this->port=port;
           socket.connectToHost(this->ip,this->port);

        }
    }
    else
    {
        this->ip=ip;
        this->port=port;
        socket.connectToHost(this->ip,this->port);
    }
}

void SocketHandler::MakeDisconnect()
{
    if(socket.isOpen())
    {
        socket.close();
    }
}

void SocketHandler::WriteToSocket(QString data)
{
    if(socket.isOpen())
    {
        QJsonObject news;
        news["file-type"]="massage";
        news["size"]=data.toUtf8().size();
        news["FileData"]=data;
        QByteArray byte=QJsonDocument(news).toJson(QJsonDocument::Compact);
        QString str=QString("JsonSize:%1/").arg(byte.size());
        byte.prepend(str.toUtf8());
        socket.write(byte);
    }

}

void SocketHandler::OnConnect()
{
    emit Connect();
}

void SocketHandler::OnDisconnect()
{
    emit disconnect();
}

void SocketHandler::OnError(QAbstractSocket::SocketError socketError)
{
    emit Error(socketError);
}

void SocketHandler::OnTrigger(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit Trigger(socketState);
}

void SocketHandler::OnReadyRead()
{
    QByteArray arr= socket.readAll();
    // Parse the JSON response
    //QJsonParseError jsonError;
    //QJsonDocument jsonResponse = QJsonDocument::fromJson(arr);
    // if (jsonError.error == QJsonParseError::NoError && jsonResponse.isObject())
    // {
        // QJsonObject jsonObject = jsonResponse.object();
        // // Extract id and name
        // QString id = jsonObject["id"].toString();
        // QString name = jsonObject["name"].toString();
        // emit ReadyRead(QString("id :  "+id+"   name  : "+name));
    //}
    QString str=QString(arr);
    qint32 length=str.split("/")[0].split(':')[1].toInt();
    QString data=str.right(length);
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObj=json.object();
    qint32 dataSize=jsonObj["size"].toInt();
    QString realdata=jsonObj["FileData"].toString();
    if(dataSize==realdata.size())
    {
        emit ReadyRead(realdata);
    }
    //QString data=QString(arr);


}
