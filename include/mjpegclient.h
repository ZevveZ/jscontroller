#ifndef MJPEGCLIENT_H
#define MJPEGCLIENT_H
#include<QtNetwork>
#include<QDebug>
#include<QPixmap>
#include<QtNetwork/QTcpSocket>
#include<QObject>
#include<QtNetwork/QTcpServer>
#include<QFile>

class MjpegClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket sock;
    QByteArray imageBuffer;
    bool enRecv = false;
public:
    MjpegClient();
    bool init_connect(QString host, int port);
    void disconnect();
    void run();
public slots:
    void recvMjpeg();
signals:
    void getImage(QPixmap img);
};

#endif // MJPEGCLIENT_H
