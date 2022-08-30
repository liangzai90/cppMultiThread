// chap101.cpp
// 第一个c++ 多线程例子
// g++ -std=c++11 -v  chap101.cpp -lpthread 

#include <iostream>
#include <thread>

using namespace std;

void ThreadMain()
{
    cout <<"begin sub thread main "<<this_thread::get_id()<<endl;
    for(int i=0;i<10;i++){
        cout << "in thread "<< i<<endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1000ms;
        //this_thread::sleep_for(chrono::milliseconds(2000)); // 2000ms;
    }
    cout <<"end sub thread main "<<this_thread::get_id()<<endl;
}


int main(int argc, char* argv[])
{
    cout <<"main thread ID "<<this_thread::get_id()<<endl;

    //thread creat and start
    thread  th(ThreadMain);
    cout <<"begin wait sub thread "<<endl;
    //end and wait thread quit
    th.join();
    cout <<"end wait sub thread "<<endl;

    return 0;
}