//chap104.cpp
// thread 线程函数传递指针和引用
// g++ -std=c++11 -v  chap104.cpp -lpthread 



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
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout <<"ThreadMian "<<p1 <<" "<<p2 <<" "<< str <<" "<<p4.name<<endl;
}

//传递指针 对象
void ThreadMainPtr(Para* p)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout <<"ThreadMainPtr name = "<< p->name << endl;
}

//传递引用对象 
void ThreadMainRef(Para& p)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout <<"ThreadMainRef name = "<< p.name << endl;
}

int main(int argc, char* argv[])
{

    {
        //传递指针
        // Para p;
        // p.name = "test ThreadMainPtr name";
        // thread th(ThreadMainPtr, & p); //错误，线程访问的p空间会提前释放
        // th.detach();
    }

    {
        //传递引用
        Para p ;
        p.name = "test ref";
        thread  th(ThreadMainRef, ref(p));
        th.join();
    }

    getchar();
    return 0;
}




