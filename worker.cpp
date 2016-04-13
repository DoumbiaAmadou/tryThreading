#include "worker.h"
#include <QDebug>

void Worker::run()
{
    while (true) {
         qDebug()<<"wait...."<<m_queue.isEmpty() ;

         if(!m_queue.isEmpty()){
             QString s = m_queue.dequeue() ;
             if( s.contains("processing"))
                 processing();
             else
                 if( s.contains("loading"))
                     loading();
                 else
                     if( s.contains("configuring"))
                         configuring();
                     else {
                         qDebug()<< "Nothing to do" ;
                     }
         }else     exec();
    }
}

void Worker::configuring()
{
    qDebug()<<"Configuring...." ;
    msleep(1000);
    qDebug()<<"Configuring...." ;
    msleep(1000);
    qDebug()<<"Configuring...." ;
    msleep(1000);
    qDebug()<<"Configuring End" ;
}

void Worker::loading()
{
    qDebug()<<"loading...." ;
    msleep(1000);
    qDebug()<<"loading...." ;
    msleep(1000);
    qDebug()<<"loading...." ;
    msleep(1000);
    qDebug()<<"loading End" ;
}

void Worker::processing()
{
    qDebug()<<"processing...." ;
    msleep(1000);
    qDebug()<<"processing...." ;
    msleep(1000);
    qDebug()<<"processing...." ;
    msleep(1000);
    qDebug()<<"processing End" ;
}

Worker::Worker():QThread(0)
{
    connect(this ,SIGNAL(AddCmd(QString )) ,this , SLOT(doAddCmd(QString)));
    moveToThread(this);
     start();
}

Worker::~Worker()
{

}

void Worker::doAddCmd(QString s)
{
    m_queue.enqueue(s);
    qDebug()<<"m_queue SIZE ()"<<m_queue.size() ;
    quit();
}

