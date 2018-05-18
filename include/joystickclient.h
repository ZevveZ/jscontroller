#ifndef JOYSTICKCLIENT_H
#define JOYSTICKCLIENT_H

#include <QThread>
#include "Extreme3DProService.hpp"
#include<QtNetwork/QTcpSocket>

using JoystickLibrary::Extreme3DProService;

class JoystickClient : public QThread
{
    Q_OBJECT
public:
    JoystickClient();
    ~JoystickClient();

    QString host;
    int port;
protected:
    void run();
private:
    static Extreme3DProService& es;
    void check(int id);
    void send(int x, int y);
    bool init_connect(QString host, int port);

    QTcpSocket *sock;
private slots:
    void disconnect();
};

#endif // JOYSTICKCLIENT_H
