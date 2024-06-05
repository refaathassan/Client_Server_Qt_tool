#include "myserverhandler.h"

MyServerHandler::MyServerHandler(qint32 ID, QObject *parent): QThread{parent},ID{ID}
{

}

void MyServerHandler::OnDisconnect()
{
    if(soc->isOpen())
    {
        soc->close();
        //qDebug()<"client => "<<ID<<"  Disconnected  "<<Qt::endl;
    }
}

void MyServerHandler::OnReadyRead()
{
    QByteArray B_arrary=soc->readAll();
    QString str=QString(B_arrary);
    qint32 length=str.split("/")[0].split(':')[1].toInt();
    QString data=str.right(length);
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObj=json.object();
    qint32 dataSize=jsonObj["size"].toInt();
    QString realdata=jsonObj["FileData"].toString();
    if(dataSize==realdata.size())
    {
        Operation(realdata);
    }
    //qDebug()<"Recieved data => "<<B_arrary<<Qt::endl;
    //Operation(QString(B_arrary));
}

void MyServerHandler::SendMassage(QString massage)
{
    if(soc->isOpen())
    {
        QJsonObject news;
        news["file-type"]="massage";
        news["size"]=massage.toUtf8().size();
        news["FileData"]=massage;
        QByteArray byte=QJsonDocument(news).toJson(QJsonDocument::Compact);
        QString str=QString("JsonSize:%1/").arg(byte.size());
        byte.prepend(str.toUtf8());
        soc->write(byte);
    }
}

void MyServerHandler::Operation(QString massage)
{
    if(massage=="hello")
    {
        SendMassage("massage reply..............");
    }
}

void MyServerHandler::run()
{
    qDebug()<<"client=>  "<<ID<<"   is running in thread=> "<<QThread::currentThreadId()<<Qt::endl;
    soc=new QTcpSocket;
    soc->setSocketDescriptor(ID);
    connect(soc,&QTcpSocket::readyRead,this,&MyServerHandler::OnReadyRead,Qt::DirectConnection);
    connect(soc,&QTcpSocket::disconnected,this,&MyServerHandler::OnDisconnect,Qt::DirectConnection);
    SendMassage("Hello From My Server...........");
    exec();
}
