// Threads
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
using namespace std;
static int x = 0, y = 0;
mutex m, n, p, q, r, s, u, v;
condition_variable cv;
bool ready = false;
queue<int> t;
atomic<int> w;
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
    lock.release();      // Now unique_lock is not rsponsible
    return;
} 
void doWork7()
{
    unique_lock<mutex> lock(r);
    cv.wait(lock, [] {
        return ready;
    });
    cout << "Worker can now proceed\n";
}
void doWork8()
{
    {
        lock_guard<mutex> lock(r);
        ready = true;
    }
    cv.notify_one();
}
void doWork9()
{
    {
        lock_guard<mutex> lock(s);
        t.push(10);
    }
    cv.notify_one();
}
void doWork10()
{
    unique_lock<mutex> lock(s);
    cv.wait(lock, [] {
        return !t.empty();
    });
    int value = t.front(); t.pop();
    cout << value << endl;
}
// To avoid deadlock
void doWork11()
{
    scoped_lock lock(u, v);
    return;
}
void doWork12()
{
    for(int i=0 ; i<10 ; i++) w++;
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
    thread t11(doWork7);
    thread t12(doWork8);
    t11.join();
    t12.join();
    thread t13(doWork9);
    thread t14(doWork10);
    t13.join();
    t14.join();
    thread t15(doWork12);
    thread t16(doWork12);
    t15.join();
    t16.join();
    cout<<w<<endl;
    return 0;
}