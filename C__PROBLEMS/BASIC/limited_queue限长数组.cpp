#include <bits/stdc++.h>
using namespace std;
template <typename T, std::size_t n>
class limited_queue {
private:
    std::array<T, n+1> data_;  // 多1个空间用于区分队列满/空状态
    std::size_t front_ = 0;
    std::size_t rear_ = 0;
    
    // 禁用动态内存分配
    using value_type = T;

public:
    // 默认构造函数
    limited_queue() = default;
    
    // 拷贝构造/赋值禁用（简化实现）
    limited_queue(const limited_queue&) = delete;
    limited_queue& operator=(const limited_queue&) = delete;

    // 检查队列是否已满
    bool full() const {
        return (rear_ + 1) % (n + 1) == front_;
    }

    // 检查队列是否为空
    bool empty() const {
        return rear_ == front_;
    }

    // 获取当前元素数量
    std::size_t size() const {
        return (rear_ - front_ + n + 1) % (n + 1);
    }

    // 入队操作
    bool push(const T& value) {
        if (full()) return false;
        data_[rear_] = value;
        rear_ = (rear_ + 1) % (n + 1);
        return true;
    }

    // 移动入队操作
    bool push(T&& value) {
        if (full()) return false;
        data_[rear_] = std::move(value);
        rear_ = (rear_ + 1) % (n + 1);
        return true;
    }

    // 构造入队（完美转发）
    template <typename... Args>
    bool emplace(Args&&... args) {
        if (full()) return false;
        data_[rear_] = T(std::forward<Args>(args)...);
        rear_ = (rear_ + 1) % (n + 1);
        return true;
    }

    // 出队操作
    bool pop() {
        if (empty()) return false;
        front_ = (front_ + 1) % (n + 1);
        return true;
    }

    // 获取队首元素
    T& front() {
        if (empty()) throw std::out_of_range("Queue is empty");
        return data_[front_];
    }

    // 获取队尾元素
    T& back() {
        if (empty()) throw std::out_of_range("Queue is empty");
        return data_[(rear_ - 1 + n + 1) % (n + 1)];
    }
};

// 使用示例
int main() {
    limited_queue<int, 4> q;  // 实际存储4个元素的队列
    
    // 基础操作测试
    std::cout << "Empty: " << q.empty() << "\n";
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << "Full: " << q.full() << "\n";
    
    q.push(5);
    std::cout << "Full: " << q.full() << "\n";
    
    std::cout << "Size: " << q.size() << "\n";
    std::cout << "Front: " << q.front() << "\n";
    
    q.pop();
    std::cout << "New front: " << q.front() << "\n";
    
    // 使用emplace构造元素
    q.emplace(42);
    std::cout << "Back: " << q.back() << "\n";
    
    return 0;
}