//
// Created by Dipayan Bhattacharya on 2/22/17.
//
#include <iostream>
#include <thread>
#include <sstream>

using namespace std;

mutex mtx;

void safe_cout(string ss) {
    mtx.lock();
    cout<<ss;
    mtx.unlock();
}

void foo() {
    int a = 0;
    while(a < 5) {
        safe_cout("foo\n");
        a++;
    }
}

void bar() {
    int b = 0;
    while(b < 5) {
        safe_cout("bar\n");
        b++;
    }
}

int main(int argc, char **argv) {
    thread first(foo);
    thread second(bar);
    safe_cout("Threads are executing!\n");
    first.join();
    second.join();
    safe_cout("Threads finished processing");
    return 0;
}
