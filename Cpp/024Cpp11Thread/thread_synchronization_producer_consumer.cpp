//
// Created by Lee ChenZe on 6/3/25.
//

#include <iostream>
#include <string>
// 线程类头文件。
#include <thread>
// 互斥锁类的头文件。
#include <mutex>
// deque容器的头文件。
#include <deque>
// queue容器的头文件。
#include <queue>
// 条件变量的头文件。
#include <condition_variable>

using namespace std;

class AA
{
    // 互斥锁。
    mutex m_mutex;
    // 条件变量。
    condition_variable m_cond;
    // 缓存队列，底层容器用deque。
    queue<string, deque<string>> m_q;
public:
    // 生产数据，num指定数据的个数。
    void incache(int num)
    {
        // 申请加锁。
        lock_guard<mutex> lock(m_mutex);
        for (int ii=0 ; ii<num ; ii++)
        {
            // 超女编号。
            static int bh = 1;
            // 拼接出一个数据。
            string message = to_string(bh++) + "号超女";
            // 把生产出来的数据入队。
            m_q.push(message);
        }
        // 唤醒一个被当前条件变量阻塞的线程。
        // m_cond.notify_one();
        // 唤醒全部被当前条件变量阻塞的线程。
        m_cond.notify_all();
    }

    // 消费者线程任务函数。
    void outcache()
    {
        while (true)
        {
            // 把互斥锁转换成unique_lock<mutex>，并申请加锁。
            unique_lock<mutex> lock(m_mutex);

            // 如果队列空，进入循环，否则直接处理数据。必须用循环，不能用if
            // while (m_q.empty()) {
            //     // 等待生产者的唤醒信号。
            //     m_cond.wait(lock);
            // }
            // 如果不用while循环，还可以使用条件变量wait函数的重载版本。
            // 这是另一种写法，和while循环是一样的，也就是说，重载版本的wait函数中会有一个while循环。
            m_cond.wait(lock,[this]{return !m_q.empty();});
            
            // 数据元素出队。
            string message = m_q.front();  m_q.pop();
            // 这行日志放到锁作用域块中，避免日志显示顺序错乱。
            cout << "线程：" << this_thread::get_id() << "，" << message << endl;
            // 手动解锁，就不需要锁的作用域块 {} 了
            lock.unlock();
            // 处理出队的数据（把数据消费掉）。
            // 假设处理数据需要1毫秒。
            this_thread::sleep_for(chrono::milliseconds(1));

        }
    }
};

void thread_synchronization_producer_consumer(){

    cout << endl << "========================thread_synchronization_producer_consumer========================" << endl;

    AA aa;

    // 创建消费者线程t1。
    thread t1(&AA::outcache, &aa);
    // 创建消费者线程t2。
    thread t2(&AA::outcache, &aa);
    // 创建消费者线程t3。
    thread t3(&AA::outcache, &aa);

    // 休眠2秒。
    this_thread::sleep_for(chrono::seconds(2));
    // 生产3个数据。
    aa.incache(3);

    // 休眠3秒。
    this_thread::sleep_for(chrono::seconds(3));
    // 生产5个数据。
    aa.incache(5);

    // 回收子线程的资源。
    t1.join();
    t2.join();
    t3.join();

    cout << endl << "========================thread_synchronization_producer_consumer========================" << endl;
}