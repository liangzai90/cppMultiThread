//chap102.cpp
// thread 线程的生命周期
// g++ -std=c++11 -v  chap102.cpp -lpthread 

#include <iostream>
#include <thread>

using namespace std;

bool is_exit = false;
void ThreadMain()
{
    cout <<"begin sub thread main "<<this_thread::get_id()<<endl;
    for(int i=0;i<10;i++){
        if(is_exit) break;
        cout << "in thread "<< i<<endl;
        this_thread::sleep_for(chrono::seconds(1)); // 1000ms;
        //this_thread::sleep_for(chrono::milliseconds(2000)); // 2000ms;
    }
    cout <<"end sub thread main "<<this_thread::get_id()<<endl;
}


int main(int argc, char* argv[])
{
   {
       //thread th(ThreadMain);//出错，thread对象被销毁，子线程还在运行
   }

   {
        //thread th(ThreadMain);
        //th.detach();// 子线程 与 主线程分离，守护线程
   }

   {
      thread th(ThreadMain);
      this_thread::sleep_for(chrono::seconds(3)); ///1000ms
      is_exit = true;//通知子线程退出 
      cout <<"主线程阻塞，等待子线程退出"<<endl;
      th.join(); //主线程阻塞，等待子线程退出
      cout <<"子线程已退出!"<<endl;
   }
    

    getchar();
    return 0;
}