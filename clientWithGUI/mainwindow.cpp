#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&handler,&SocketHandler::Connect,this,&MainWindow::OnConnectDe);
    connect(&handler,&SocketHandler::Disconnect,this,&MainWindow::OnDisconnectDe);
    connect(&handler,&SocketHandler::Error,this,&MainWindow::OnErrorDe);
    connect(&handler,&SocketHandler::Trigger,this,&MainWindow::OnTriggerDe);
    connect(&handler,&SocketHandler::ReadyRead,this,&MainWindow::OnReadyReadDe);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnConnectDe()
{
    ui->LwReceive->addItem("the Socket is Connected..........");
}

void MainWindow::OnDisconnectDe()
{
   ui->LwReceive->addItem("the Socket is Disconnected..........");
}

void MainWindow::OnErrorDe(QAbstractSocket::SocketError socketError)
{
    QMetaEnum me=QMetaEnum::fromType<QAbstractSocket::SocketError>();
    ui->LwReceive->addItem(me.valueToKey(socketError));
}

void MainWindow::OnTriggerDe(QAbstractSocket::SocketState socketState)
{
    QMetaEnum me=QMetaEnum::fromType<QAbstractSocket::SocketState>();
    ui->LwReceive->addItem(me.valueToKey(socketState));
}

void MainWindow::OnReadyReadDe(QString str)
{
    ui->LwReceive->addItem(QString("the data Recived=> %1").arg(str));
}





void MainWindow::on_PbDisconnect_clicked()
{
    handler.MakeDisconnect();
}


void MainWindow::on_PbConnect_clicked()
{
    handler.MakeConnect(ui->LeIp->text(),ui->LePort->text().toInt());
}


void MainWindow::on_PbSend_clicked()
{
    // Variable for id
   // QString id = "4";

    //Construct the GET request string with the id variable
    // QString request = "GET /student1?id="+id+" HTTP/1.1\r\n";
    // request += "Host: localhost:3000\r\n";
    // request += "Connection: close\r\n";
    // request += "\r\n";
    // QJsonObject payload;
    // payload["id"] = "5";
    // payload["name"] = "Mohamed";

    // // Convert the payload to a JSON document
    // QJsonDocument doc(payload);

    // // Convert the JSON document to a QByteArray
    // QByteArray jsonData = doc.toJson();

    // Construct the POST request string
    // QString request = "POST /student1 HTTP/1.1\r\n";
    // request += "Host: localhost:3000\r\n";
    // request += "Connection: close\r\n";
    // request += "Content-Type: application/json\r\n";
    // request += "Content-Length: " + QString::number(jsonData.length()) + "\r\n";
    // request += "\r\n";
    // request += jsonData;
    // handler.WriteToSocket(request);
    handler.WriteToSocket(ui->LeSend->text());
}

