#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/Portability.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/RollingFileAppender.hh>

#include<iostream>
#include<string>
using  std::cout;
using  std::endl;
using  std::string;
using namespace log4cpp;
class Mulogger
{
public:
static Mulogger* getinstance()
{
    if(pMlog==nullptr)
    {
        pMlog=new Mulogger();
    }
    return pMlog;
}
void warn(const char* msg,const char *func)
{
    
    root.warn("%s %s %d %s",__FILE__,func,__LINE__,msg);
}
template<typename...Args>
void error(Args...args)
{
    root.error(args...);
}
void debug(const char* msg,const char *func)
{
    root.debug("%s %s %d %s",__FILE__,func,__LINE__,msg);
}
void info(const char* msg,const char *func)
{
    root.info("%s %s %d %s",__FILE__,func,__LINE__,msg);
}
void destroy()
{
    Category::shutdown();
    delete pMlog;
    pMlog==nullptr;
}
private:
Mulogger()
:root(Category::getRoot())
{
    playoutOs = new PatternLayout();
    playoutOs->setConversionPattern("%d %p %c %x %m%n"); //这里调整输出到终端日志打印模式
    playoutFile = new PatternLayout();
    playoutFile->setConversionPattern("%d %p %c %x %m%n"); //这里调整输出到文件日志打印模式

    osAppender = new OstreamAppender("osAppender", &cout);
    osAppender->setLayout(playoutOs);
    rollfileAppender = new RollingFileAppender("fileAppender", "myLog.txt", 5 * 1024, 3);
    rollfileAppender->setLayout(playoutFile);

    root.setPriority(Priority::DEBUG);
    root.addAppender(osAppender);
    root.addAppender(rollfileAppender);

}
~Mulogger()
{

}
private:
static Mulogger* pMlog;
OstreamAppender *osAppender;
RollingFileAppender *rollfileAppender;
PatternLayout *playoutOs;
PatternLayout *playoutFile;
Category &root;
};
Mulogger *Mulogger::pMlog=nullptr;
//注意这里就改动了error作为演示，现在error可以像printf一样使用
int main(int argc,char *argv[])
{
    cout<<"hello world"<<endl;
    Mulogger* myLog=Mulogger::getinstance();
    /* for(int i=0;i<1000;++i)
    {
        myLog->warn("message", __FUNCTION__);
        myLog->error("message", __FUNCTION__);
        myLog->info("message", __FUNCTION__);
        myLog->debug("message", __FUNCTION__);

    }
    */
    myLog->warn("message",__FUNCTION__);
    myLog->error("%s %s %d message ",__FILE__,__FUNCTION__,__LINE__);
    myLog->info("message",__FUNCTION__);
    myLog->debug("message",__FUNCTION__);
    myLog->destroy();
}