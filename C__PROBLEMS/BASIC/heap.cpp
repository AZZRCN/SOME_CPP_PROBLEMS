#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>

// 基本堆类，默认为最小堆
template<typename T>
class Heap {
protected:
    std::vector<T> data;  // 存储堆数据
    size_t heap_size;     // 当前堆大小
    std::function<bool(const T&, const T&)> comp;  // 比较函数
    // 上浮操作
    void sift_up(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (comp(data[idx], data[parent])) {
                std::swap(data[idx], data[parent]);
                idx = parent;
            } else {
                break;
            }
        }
    }
    // 下沉操作
    void sift_down(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;
            if (left < heap_size && comp(data[left], data[smallest])) {
                smallest = left;
            }
            if (right < heap_size && comp(data[right], data[smallest])) {
                smallest = right;
            }
            if (smallest != idx) {
                std::swap(data[idx], data[smallest]);
                idx = smallest;
            } else {
                break;
            }
        }
    }
public:
    // 构造函数：默认是最小堆
    Heap() : heap_size(0), comp([](const T& a, const T& b) { return a < b; }) {}
    // 可以传入比较器构造最大堆
    explicit Heap(std::function<bool(const T&, const T&)> cmp)
        : heap_size(0), comp(cmp) {}
    // 插入元素
    void push(const T& value) {
        if (heap_size < data.size()) {
            data[heap_size++] = value;
        } else {
            data.push_back(value);
            heap_size++;
        }
        sift_up(heap_size - 1);
    }
    // 弹出堆顶
    void pop() {
        if (heap_size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        std::swap(data[0], data[--heap_size]);
        sift_down(0);
    }
    // 获取堆顶
    const T& top() const {
        if (heap_size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        return data[0];
    }
    // 判断是否为空
    bool empty() const {
        return heap_size == 0;
    }
    // 获取堆大小
    size_t size() const {
        return heap_size;
    }
};









#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <iostream>

template<typename T>
class Heap2 {
protected:
    std::vector<T> data;  // 存储数据
    size_t heap_size;     // 当前堆大小
    std::function<bool(const T&, const T&)> comp;

    // 上浮
    void sift_up(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (comp(data[idx], data[parent])) {
                std::swap(data[idx], data[parent]);
                idx = parent;
            } else {
                break;
            }
        }
    }

    // 下沉
    void sift_down(int idx) {
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;

            if (left < heap_size && comp(data[left], data[smallest]))
                smallest = left;
            if (right < heap_size && comp(data[right], data[smallest]))
                smallest = right;

            if (smallest != idx) {
                std::swap(data[idx], data[smallest]);
                idx = smallest;
            } else {
                break;
            }
        }
    }

    // 扩容函数
    void expand() {
        size_t new_cap = data.empty() ? 1 : data.size() * 2;
        data.resize(new_cap);
    }

public:
    // 默认构造函数（最小堆）
    Heap2()
        : heap_size(0), comp([](const T& a, const T& b) { return a < b; }) {}

    // 自定义比较器构造函数
    explicit Heap2(std::function<bool(const T&, const T&)> cmp)
        : heap_size(0), comp(cmp) {}

    // 使用初始数组构造堆
    Heap2(const std::vector<T>& arr, std::function<bool(const T&, const T&)> cmp = {})
        : data(arr), heap_size(arr.size()), comp(cmp ? cmp : [](const T& a, const T& b) { return a < b; }) {
        data.resize(heap_size * 2);  // 动态扩容预留空间
        for (int i = heap_size / 2 - 1; i >= 0; --i) {
            sift_down(i);
        }
    }

    // 插入元素（自动扩容）
    void push(const T& value) {
        if (heap_size == data.size()) {
            expand();
        }
        data[heap_size++] = value;
        sift_up(heap_size - 1);
    }

    // 弹出堆顶
    void pop() {
        if (heap_size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        std::swap(data[0], data[--heap_size]);
        sift_down(0);
    }

    // 获取堆顶
    const T& top() const {
        if (heap_size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        return data[0];
    }

    // 判断是否为空
    bool empty() const {
        return heap_size == 0;
    }

    // 获取当前堆大小
    size_t size() const {
        return heap_size;
    }

    // 获取完整数据（仅调试用）
    const std::vector<T>& raw_data() const {
        return data;
    }

    // 合并两个堆（operator+）
    friend Heap2 operator+(const Heap2& h1, const Heap2& h2) {
        Heap2 merged(h1.comp);
        merged.data = h1.data;
        merged.heap_size = h1.heap_size;
        merged.data.resize(h1.data.size() + h2.data.size());

        for (size_t i = 0; i < h2.heap_size; ++i) {
            merged.push(h2.data[i]);
        }

        return merged;
    }

    // 合并另一个堆（merge 函数）
    void merge(const Heap2& other) {
        for (size_t i = 0; i < other.heap_size; ++i) {
            push(other.data[i]);
        }
    }
};