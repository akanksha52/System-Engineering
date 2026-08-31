// Threads
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
static int x = 0, y = 0;
mutex m, n, p, q;
// Value of x is not sure.
void doWork1()
{
    for(int i=0 ; i<1e6 ; i++) x++;
    return;
} 
// Value of x is sure.
void doWork2()
{
    for(int i=0 ; i<1e6 ; i++) 
    {
        m.lock();
        y++;
        m.unlock();
    }
    return;
} 
// Why mutex is not safe
void demo()
{
    throw "Custom Exception";
}
void doWork3()
{
    m.lock();
    cout<<"doWork3\n";
    demo();
    m.unlock();
    return;
} 
// Why lock_guard is not safe
void medo()
{
    throw "Custom Exception";
}
void doWork4()
{
    lock_guard<mutex> lock(n);
    cout<<"doWork4\n";
    demo();
    n.unlock();
    return;
} 
void doWork5()
{
    p.lock();
    if(!p.try_lock()) 
    {
        cout<<"Unlocking P"<<endl;
        p.unlock();
    }
    else cout<<"Lock is unlocked"<<endl;
    return;
} 
void doWork6()
{
    unique_lock<mutex> lock(m);
    lock.unlock();
    lock.release()      // Now unique_lock is not rsponsible
    return;
} 
int main()
{
    thread t1(doWork1);
    thread t2(doWork1);
    t1.join();
    t2.join();
    cout<<x<<endl;
    thread t3(doWork2);
    thread t4(doWork2);
    t3.join();
    t4.join();
    cout<<y<<endl;
    // thread t7(doWork4);
    // thread t8(doWork4);
    // t7.join();
    // t8.join();
    // thread t5(doWork3);
    // thread t6(doWork3);
    // t5.join();
    // t6.join();
    // thread t7(doWork4);
    // thread t8(doWork4);
    // t7.join();
    // t8.join();
    thread t9(doWork5);
    thread t10(doWork5);
    t9.join();
    t10.join();
    return 0;
}