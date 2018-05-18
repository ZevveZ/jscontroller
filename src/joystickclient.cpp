#include "joystickclient.h"
#include <QDebug>
#include<QtNetwork>

Extreme3DProService& JoystickClient::es = Extreme3DProService::GetInstance();

JoystickClient::JoystickClient()
{
    if(!es.Initialize()){
        qDebug()<<"Initialize Joystick failed";
        return;
    }

    sock = NULL;

    connect(this, SIGNAL(finished()), this, SLOT(disconnect()));
}

JoystickClient::~JoystickClient(){
    if(isRunning())
        terminate();

    if(sock){
        delete sock;
    }
}

void JoystickClient::run(){
    while (es.GetNumberConnected() < 1);

    if(init_connect(host, port)==false) return;

    while(true){
        auto& a = es.GetIDs();
        if (a.size() <= 0)
            continue;
        check(a[0]);
        usleep(10000);  //delay can't be too long, otherwise GetIDs may wrong
    }
}

void JoystickClient::check(int id){
    int x, y;
    if(!es.GetX(id, x))
        x=0;
    if(!es.GetY(id, y))
        y=0;
    //qDebug()<<"x="<<x<<" y="<<y;
    send(x, y);
}

bool JoystickClient::init_connect(QString host, int port){
    if(sock==NULL){
        sock = new QTcpSocket();
    }

    sock->connectToHost(host, port);
    if(sock->waitForConnected()){
        return true;
    }else{
        qDebug()<<"init_connect failed";
        return false;
    }
}

void JoystickClient::send(int x, int y){
    struct{
        int x;
        int y;
    }axis_xy={x,y};
    if(sock->write((char *)&axis_xy, sizeof(axis_xy))!=sizeof(axis_xy)){
        qDebug()<<"send failed";
    }
    sock->flush();
}

void JoystickClient::disconnect(){
    sock->disconnectFromHost();
    qDebug()<<"disconnect";
}
