#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include "joystickclient.h"
#include "mjpegclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void showImage(QPixmap img);
    void connclicked(bool);
    void disconnclicked(bool);
private:
    Ui::MainWindow *ui;
    MjpegClient mclient;
    JoystickClient jsclient;

};

#endif // MAINWINDOW_H
