//
// Created by Lee ChenZe on 6/3/25.
//
#include <iostream>
#include <string>
#include <thread>                      // 线程类头文件。
#include <mutex>                      // 互斥锁类的头文件。
#include <deque>                      // deque容器的头文件。
#include <queue>                      // queue容器的头文件。
#include <condition_variable>  // 条件变量的头文件。
#include <functional>
using namespace std;

void show(const string& message) {  // 处理业务的普通函数
    cout << "处理数据：" << message << endl;
}

struct BB {  // 处理业务的类成员函数
    void show(const string& message) {
        cout << "处理表白数据：" << message << endl;
    }
};

class AA
{
    mutex m_mutex;                                    // 互斥锁。
    condition_variable m_cond;                  // 条件变量。
    queue<string, deque<string>> m_q;   // 缓存队列，底层容器用deque。
    function<void(const string&)> m_callback;  // 回调函数对象。
public:
    // 注册回调函数，回调函数只有一个参数（消费者接收到的数据）。
    template<typename Fn, typename ...Args>
    void callback(Fn && fn, Args&&...args) {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., std::placeholders::_1);  // 绑定回调函数。
    }

    void incache(int num)     // 生产数据，num指定数据的个数。
    {
        lock_guard<mutex> lock(m_mutex);   // 申请加锁。
        for (int ii = 0; ii < num; ii++)
        {
            static int bh = 1;           // 超女编号。
            string message = to_string(bh++) + "号超女";    // 拼接出一个数据。
            m_q.push(message);     // 把生产出来的数据入队。
        }
        //m_cond.notify_one();     // 唤醒一个被当前条件变量阻塞的线程。
        m_cond.notify_all();          // 唤醒全部被当前条件变量阻塞的线程。
    }

    void outcache() {    // 消费者线程任务函数。
        while (true) {
            // 把互斥锁转换成unique_lock<mutex>，并申请加锁。
            unique_lock<mutex> lock(m_mutex);

            // 1）把互斥锁解开；2）阻塞，等待被唤醒；3）给互斥锁加锁。
            m_cond.wait(lock, [this] { return !m_q.empty(); });

            // 数据元素出队。
            string message = m_q.front();  m_q.pop();
            cout << "线程：" << this_thread::get_id() << "，" << message << endl;
            lock.unlock();      // 手工解锁。

            // 处理出队的数据（把数据消费掉）。
            if (m_callback) m_callback(message);  // 回调函数，把收到的数据传给它。
        }
    }
};

void callback_function_implementation() {
    cout << endl << "========================callback_function_implementation========================" << endl;

    AA aa;
    // aa.callback(show);                   // 把普通函数show()注册为回调函数。
    BB bb;
    aa.callback(&BB::show, &bb);    // 把类成员函数BB::show()注册为回调函数。

    thread t1(&AA::outcache, &aa);     // 创建消费者线程t1。
    thread t2(&AA::outcache, &aa);     // 创建消费者线程t2。
    thread t3(&AA::outcache, &aa);     // 创建消费者线程t3。

    this_thread::sleep_for(chrono::seconds(2));    // 休眠2秒。
    aa.incache(2);      // 生产2个数据。

    this_thread::sleep_for(chrono::seconds(3));    // 休眠3秒。
    aa.incache(5);      // 生产5个数据。

    t1.join();   // 回收子线程的资源。
    t2.join();
    t3.join();

    cout << endl << "========================callback_function_implementation========================" << endl;
}
