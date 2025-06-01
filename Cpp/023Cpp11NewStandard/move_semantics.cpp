//
// Created by Lee ChenZe on 5/31/25.
//
#include <iostream>
#include <string>

using namespace std;

class Buffer {
private:
    char* m_data;
    size_t m_size;

public:
    // 构造函数
    Buffer(size_t size) : m_size(size) {
        m_data = new char[m_size];
        memset(m_data, 0, m_size);
        cout << "构造: 分配 " << m_size << " 字节\n";
    }

    // 析构函数
    ~Buffer() {
        delete[] m_data;
        cout << "析构: 释放 " << m_size << " 字节\n";
    }

    // 拷贝构造函数（深拷贝）
    Buffer(const Buffer& other) : m_size(other.m_size) {
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
        cout << "拷贝构造\n";
    }

    // 拷贝赋值函数
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        delete[] m_data;
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
        cout << "拷贝赋值\n";
        return *this;
    }

    // ✅ 移动构造函数（偷资源）
    Buffer(Buffer&& other) noexcept : m_data(other.m_data), m_size(other.m_size) {
        other.m_data = nullptr;
        other.m_size = 0;
        cout << "移动构造\n";
    }

    // ✅ 移动赋值函数（偷资源）
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this;
        delete[] m_data;
        m_data = other.m_data;
        m_size = other.m_size;
        other.m_data = nullptr;
        other.m_size = 0;
        cout << "移动赋值\n";
        return *this;
    }
};

Buffer createBuffer() {
    Buffer buf(100);  // 创建临时对象
    return move(buf);       // 返回右值，会触发移动构造
}

void move_semantics() {
    cout << endl << "========================move_semantics========================" << endl;

    Buffer a = createBuffer(); // 移动构造
    Buffer b(200);
    b = createBuffer();        // 移动赋值

    cout << endl << "========================move_semantics========================" << endl;
}
