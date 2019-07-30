#include<pthread.h>
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;
class MutexLock
{
public:
    MutexLock()
    {
        pthread_mutex_init(&_mutex,NULL);
    }
    void lock();
    void unlock();
private:
    pthread_mutex_t _mutex;
};
class Condition
{
public:
    void init()//初次用时，需要手动调用进行初始化
    {
            pthread_mutex_init(&_mutex,NULL);
            pthread_cond_init(&_cond,NULL);
    }
    void wait();
    void notify();
    void notifyall();
private:
    static pthread_cond_t _cond;
    static pthread_mutex_t _mutex;
    static int countWait;
};
void MutexLock::lock()
{
    pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
    pthread_mutex_unlock(&_mutex);
}
int Condition::countWait=0;
pthread_cond_t Condition::_cond;
pthread_mutex_t Condition::_mutex;
void Condition::wait()
{
    cout<<"this is wait"<<endl;
    pthread_mutex_lock(&_mutex);
    countWait++;
    pthread_cond_wait(&_cond,&_mutex);
    cout<<"收到信号"<<endl;
    countWait--;
    pthread_mutex_unlock(&_mutex);
}
void Condition::notify()
{
    //cout<<"this is notify"<<endl;
    pthread_cond_signal(&_cond);
}
void Condition::notifyall()
{
label:
    pthread_mutex_lock(&_mutex);
    if(countWait!=0)
    {
        pthread_mutex_unlock(&_mutex);
        notify();
        goto label;
    }
    else 
    {
        return;
    }
}
void* threadFunc(void *p)
{
    Condition cond;
    cout<<"before wait"<<endl;
    cond.wait();
    return NULL;
}

int main()
{
    Condition myCond;
    myCond.init();
    pthread_t mythreadOne,mythreadTwo;
    pthread_create(&mythreadOne,NULL,threadFunc,NULL);
    pthread_create(&mythreadTwo,NULL,threadFunc,NULL);

    sleep(1);
    myCond.notifyall();
    //myCond.notify();
    //myCond.notify();
    pthread_join(mythreadOne,NULL);
    pthread_join(mythreadTwo,NULL);
    return 0;
}