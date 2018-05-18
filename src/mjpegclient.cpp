#include "mjpegclient.h"
MjpegClient::MjpegClient()
{
    connect(&sock,SIGNAL(readyRead()),this,SLOT(recvMjpeg()));
}
void MjpegClient::run()
{
    imageBuffer.clear();
    imageBuffer.append(0xFF);
    imageBuffer.append(0xD8);
    QString str("GET /?action=stream");
    QByteArray qba = str.toLocal8Bit();
    qba += 0x0A;
    qba += 0x0A;
    sock.write(qba);
}
void MjpegClient::recvMjpeg()
{
    char lastByte='\0';
    QByteArray buffer;
    buffer = sock.readAll();
    //qDebug()<<"buffer:"<<buffer<<endl;
    for(int i = 0;i<buffer.count();i++)
    {
        if(enRecv) imageBuffer.append(buffer[i]);
        if(lastByte == (char)0xFF)
        {
            if(buffer[i] == (char)0xD8)
            {
                //qDebug()<<"SOI"<<endl;
                enRecv = true;
            }else if(buffer[i] == (char)0xD9)
            {
                //qDebug()<<"EOI"<<endl;
                //qDebug()<<"img:"<<imageBuffer<<endl;
                enRecv = false;
                QPixmap map;
                map.loadFromData(imageBuffer,"JPEG");
                if(!map.isNull())
                    emit getImage(map);
                imageBuffer.clear();
                imageBuffer.append(0xFF);
                imageBuffer.append(0xD8);
            }
        }
        lastByte = buffer[i];
    }
}

bool MjpegClient::init_connect(QString host, int port){
    sock.connectToHost(host, port);

    if(sock.waitForConnected()){
        return true;
    }else{
        qDebug()<<"init_connect failed";
        return false;
    }
}

void MjpegClient::disconnect(){
    sock.disconnectFromHost();
}
