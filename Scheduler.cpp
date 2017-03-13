//
// Created by Dipayan Bhattacharya on 2/22/17.
//
#include <iostream>
#include <thread>

using namespace std;

volatile int id_to_run;
mutex mtx;
condition_variable cv;

void doWork(int id) {
    unique_lock<mutex> lck(mtx);
    while(true) {
        while (id != id_to_run) {
            cv.wait(lck);
        }
        cout << "I am " << id << endl;
        if (id_to_run > 0) {
            id_to_run--;
        } else {
            id_to_run = 4;
        }
        cv.notify_all();
    }
}


int main(int argc, char **argv) {
    id_to_run = 4;
    thread *threads[5];
    for(int i=0;i<5;i++) {
        threads[i] = new thread(doWork, i);
    }
    for(int i=0;i<5;i++) {
        threads[i]->join();
    }
    cout<<"Done running!\n";
}