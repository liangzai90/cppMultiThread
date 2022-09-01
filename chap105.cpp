//chap105.cpp
// thread  使用成员函数作为线程入口并封装线程基类接口
// g++ -std=c++11 -v  chap105.cpp -lpthread 

#include <thread>
#include <iostream>
#include <string>

using namespace std;
class MyThread{

    public:
    //入口线程函数
    void Main(){
        cout <<"MyThread Main" <<name <<":"<<age<<endl;
    }
    string name;
    int age=  100;
};


class XThread
{
public:
    virtual void Start()
    {
        is_exit_ = false;
        th_ = std::thread(&XThread::Main, this);        
    }

    virtual void Stop(){
        is_exit_ = true;
        Wait();
    }

    virtual void Wait(){
        if(th_.joinable())
        {
            th_.join();
        }
    }

    bool is_exit() {return is_exit_;}

private:
    virtual void Main() = 0;
    std::thread th_;
    bool is_exit_ =  false;
};

class TestXThread  : public XThread{
public:
    void Main() override
    {
        cout <<"TestXThread Main begin"<<endl;
        while(!is_exit())
        {
            this_thread::sleep_for(std::chrono::milliseconds(100));
            cout <<"."<<flush;
        }
        cout <<endl<<"TestXThread Main end"<<endl;
    }
    string name;
};

int main()
{
    try
    {
        /* code */
        TestXThread testTh;
        testTh.name = "TestXThread name ";
        testTh.Start();
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        //testTh.Wait();//主线程在此处阻塞，子线程一直在运行
        testTh.Stop();//子线程主动退出...

        //如果不调用Wait()或Stop()，主线程退出的时候，子线程还未退出，会在主线程停止的时候抛出异常
        getchar();
    }
    catch(const std::exception& e)
    {
        std::cerr <<" what: "<< e.what() << '\n';
    }
    catch(...)
    {
        cout <<"unknown exception!"<<endl;        
    }
    


    // MyThread myth;
    // myth.name = "Test name 001";
    // myth.age = 20;
    // thread th(&MyThread::Main, &myth);
    // th.join();

    return 0;
}
