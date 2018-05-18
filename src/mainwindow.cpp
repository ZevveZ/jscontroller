#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("");
    connect(ui->btnconn,SIGNAL(clicked(bool)),this,SLOT(connclicked(bool)));
    connect(ui->btndisconn, SIGNAL(clicked(bool)), this, SLOT(disconnclicked(bool)));
    connect(&mclient,SIGNAL(getImage(QPixmap)),this,SLOT(showImage(QPixmap)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showImage(QPixmap img)
{
    //qDebug()<<"show"<<endl;
    img.scaled(ui->label->size(), Qt::IgnoreAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(img);
}

void MainWindow::connclicked(bool)
{
    ui->btnconn->setEnabled(false);
    ui->btndisconn->setEnabled(true);

    QString host = ui->hostline->text();
    int port = ui->portline->text().toInt();

    jsclient.host=host;
    jsclient.port=5000;
    jsclient.start();

    if(mclient.init_connect(host, port)){
        mclient.run();
    }

}
void MainWindow::disconnclicked(bool){
    ui->btnconn->setEnabled(true);
    ui->btndisconn->setEnabled(false);

    if(jsclient.isRunning())
        jsclient.terminate();

    mclient.disconnect();
}
