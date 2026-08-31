// Threads
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
static bool isFinished = false;
void doWork()
{
    using namespace std::chrono_literals;
    cout<<"Started thread is: "<<std::this_thread::get_id()<<endl;
    while(!isFinished)
    {
        cout<<"Working \n";
        std::this_thread::sleep_for(2s);
    }
    return;
} 
int main()
{
    thread worker(doWork);
    cin.get();
    isFinished = true;
    worker.join();
    cout<<"Finished"<<endl;
    cout<<"Main thread is: "<< std::this_thread::get_id()<<endl;
    return 0;
}