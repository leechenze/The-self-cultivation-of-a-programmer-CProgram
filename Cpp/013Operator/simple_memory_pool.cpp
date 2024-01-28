//
// Created by Lee ChenZe on 1/27/24.
//

// 包含头文件。
#include <iostream>

// 指定缺省的命名空间。
using namespace std;

// 超女类CGirl4。
class CGirl4 {
public:
    // 编号。
    int m_bh;
    // 胸围。
    int m_xw;
    // 内存池的起始地址。
    static char *m_pool;

    // 个初始化内存池的函数。
    static bool initpool() {
        // 向系统申请18字节的内存。
        m_pool = (char *) malloc(18);
        // 如果申请内存失败，返回false。
        if (m_pool == 0) return false;
        // 把内存池中的内容初始化为0。
        memset(m_pool, 0, 18);
        cout << "内存池的起始地址是：" << (void *) m_pool << endl;
        return true;
    }

    // 释放内存池。
    static void freepool() {
        // 如果内存池为空，不需要释放，直接返回。
        if (m_pool == 0) return;
        // 把内存池归还给系统。
        free(m_pool);
        cout << "内存池已释放。\n";
    }

    CGirl4(int bh, int xw) {
        m_bh = bh, m_xw = xw;
        cout << "调用了构造函数CGirl4()\n";
    }

    ~CGirl4() { cout << "调用了析构函数~CGirl4()\n"; }

    // 参数必须是size_t（unsigned long long），返回值必须是void*。
    void *operator new(size_t size) {
        // 判断第一个位置是否空闲。
        if (m_pool[0] == 0) {
            cout << "分配了第一块内存：" << (void *) (m_pool + 1) << endl;
            // 把第一个位置标记为已分配。
            m_pool[0] = 1;
            // 返回第一个用于存放对象的址。
            return m_pool + 1;
        }
        // 判断第二个位置是否空闲。
        if (m_pool[9] == 0) {
            cout << "分配了第二块内存：" << (void *) (m_pool + 9) << endl;
            // 把第二个位置标记为已分配。
            m_pool[9] = 1;
            // 返回第二个用于存放对象的址。
            return m_pool + 9;
        }

        // 如果以上两个位置都不可用，那就直接系统申请内存。

        // 申请内存。
        void *ptr = malloc(size);
        cout << "申请到的内存的地址是：" << ptr << endl;
        return ptr;
    }

    // 参数必须是void *，返回值必须是void。
    void operator delete(void *ptr) {
        // 如果传进来的地址为空，直接返回。
        if (ptr == 0) return;

        // 如果传进来的地址是内存池的第一个位置。
        if (ptr == m_pool + 1) {
            cout << "释放了第一块内存。\n";
            // 把第一个位置标记为空闲。
            m_pool[0] = 0;
            return;
        }

        // 如果传进来的地址是内存池的第二个位置。
        if (ptr == m_pool + 9) {
            cout << "释放了第二块内存。\n";
            // 把第二个位置标记为空闲。
            m_pool[9] = 0;
            return;
        }

        // 如果传进来的地址不属于内存池，把它归还给系统。
        // 释放内存。
        free(ptr);
    }
};

// 初始化内存池的指针。
char *CGirl4::m_pool = 0;

int simple_memory_pool() {
    cout << endl;

    // 初始化内存池。
    if (CGirl4::initpool() == false) {
        cout << "初始化内存池失败。\n";
        return -1;
    }

    // 将使用内存池的第一个位置。
    CGirl4 *p1 = new CGirl4(3, 8);
    cout << "p1的地址是：" << p1 << "，编号：" << p1->m_bh << "，胸围：" << p1->m_xw << endl;

    // 将使用内存池的第二个位置。
    CGirl4 *p2 = new CGirl4(4, 7);
    cout << "p2的地址是：" << p2 << "，编号：" << p2->m_bh << "，胸围：" << p2->m_xw << endl;

    // 将使用系统的内存。
    CGirl4 *p3 = new CGirl4(6, 9);
    cout << "p3的地址是：" << p3 << "，编号：" << p3->m_bh << "，胸围：" << p3->m_xw << endl;

    // 将释放内存池的第一个位置。
    delete p1;

    // 将使用内存池的第一个位置。
    CGirl4 *p4 = new CGirl4(5, 3);
    cout << "p4的地址是：" << p4 << "，编号：" << p4->m_bh << "，胸围：" << p4->m_xw << endl;

    // 将释放内存池的第二个位置。
    delete p2;
    // 将释放系统的内存。
    delete p3;
    // 将释放内存池的第一个位置。
    delete p4;

    // 释放内存池。
    CGirl4::freepool();

    cout << endl << endl << "==================simple_memory_pool==================" << endl;
}