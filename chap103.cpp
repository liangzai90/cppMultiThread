//chap103.cpp
// thread 全局函数作为线程入口分析参数传递内存操作
// g++ -std=c++11 -v  chap103.cpp -lpthread 


#include <thread>
#include <iostream>
#include <string>
using namespace std;

class Para{
public:
    Para() {cout <<"Create Para"<<endl;}
    Para(const Para& p){cout <<"Copy Para"<<endl;}
    ~Para() {cout <<"Drop Para"<<endl;}
    string name;
};

void ThreadMain(int p1, float p2, string str, Para p4)
{
    this_thread::sleep_for(chrono::milliseconds(500));
    cout <<"ThreadMian "<<p1 <<" "<<p2 <<" "<< str <<" "<<p4.name<<endl;
}


int main(int argc, char* argv[])
{
    thread th;
    {
        float f1 = 12.1f;
        Para p4;
        p4.name = "test Para class";

        //所有的参数做复制
        th = thread(ThreadMain, 101, f1, "Test string Para", p4);
        //1. thread 创建的时候，存下来，拷贝了一次p
        //2. ThreadMain 调用的时候又拷贝了一次
    }
    th.join();

    return 0;
}