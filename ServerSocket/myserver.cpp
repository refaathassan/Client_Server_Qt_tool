#include "myserver.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer{parent},qin(stdin),qout(stdout)
{}

void MyServer::StartServer()
{
    qout<<"enter server to listen.........."<<Qt::endl;
    qout.flush();
    port=qin.readLine().toInt();
    this->listen(QHostAddress::Any,port);
    if(this->isListening())
    {
        qout<<" server is  listen to =>  "<<port<<Qt::endl;
    }
    else
    {
         qout<<"server can not listen......"<<Qt::endl;
    }
}

void MyServer::incomingConnection(qintptr handle)
{
    qDebug()<<"client  "<<handle<<"  connected "<<Qt::endl;
    MyServerHandler* hand=new MyServerHandler(handle,this);
    connect(hand,&QThread::finished,hand,&QThread::deleteLater);
    hand->start();
}
