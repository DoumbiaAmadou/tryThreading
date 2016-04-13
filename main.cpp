#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QThread>
#include "worker.h"
using namespace std ;
QTextStream qtin(stdin);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qDebug()<<"la liste des choses à faire ! ";
    QString s ="";
    Worker * w = new Worker() ;

    while(!s.contains("exit")){
        s= qtin.readLine();
        QThread::usleep(100);
        qDebug()<<"<<"<<s;

        emit w->AddCmd(s);
    }

}
