#ifndef WORKER_H
#define WORKER_H
#include<QQueue>
#include<QString>
#include<QThread>


class Worker : public  QThread
{
 Q_OBJECT

   QQueue<QString> m_queue;

private :
   void run();

 void  processing();
 void  loading();
 void  configuring();
public:
    Worker();
    ~Worker();
signals :
    void AddCmd(QString s );
private slots :
    void doAddCmd(QString s);
};



#endif // WORKER_H
