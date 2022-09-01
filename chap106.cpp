//chap106.cpp
// thread lambda临时函数作为线程入口
// g++ -std=c++11 -v  chap106.cpp -lpthread 

/**
lambda 函数，其基本格式如下

[捕捉列表](参数)mutable -> 返回值类型 {函数体}

 */

#include <thread>
#include <iostream>
#include <string>
using namespace std;

class TestLambda 
{
public:
    void Start()
    {
        thread th([this](){cout <<"name = "<<name <<endl;});
        th.join();
    }
    string name = "test lambda";
};

int main(int argc, char* argv[])
{

    // 一个简单的lambda表达式
    thread th(
        [](int i, int j){cout <<"test lambda. i:"<< i <<",j:"<< j <<endl;},
        1234,
        5678
    );
    th.join();

    // 
    TestLambda test;
    test.Start();

    return 0;
}
