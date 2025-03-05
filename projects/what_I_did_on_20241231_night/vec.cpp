#include <stdio.h>
#include <stdlib.h>
template <typename _Ty>
class Vector {
private:
    _Ty* data_;  // 数据指针
    size_t size_;  // 向量大小
    size_t capacity_;  // 向量容量
    class str_err {
        public:
        const char* message;
        str_err(const char* msg) : message(msg) {}
        const char* what() {
            return message;
        }
    };
public:
    /**
     * 构造函数
     */
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    /**
     * 析构函数
     */
    ~Vector() {
        delete[] data_;
    }

    /**
     * 复制构造函数
     * @param other 被复制的向量
     */
    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = new _Ty[capacity_];
        for (size_t i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    /**
     * 移动构造函数
     * @param other 被移动的向量
     */
    Vector(Vector&& other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
        other.data_ = nullptr;
    }

    /**
     * 赋值运算符
     * @param other 被赋值的向量
     * @return *this
     */
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = new _Ty[capacity_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }

    /**
     * 移动赋值运算符
     * @param other 被移动赋值的向量
     * @return *this
     */
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
        }
        return *this;
    }

    /**
     * 下标运算符
     * @param index 下标
     * @return 下标对应的元素
     */
    _Ty& operator[](size_t index) {
        if (index >= size_) {
            throw str_err("Index out of range");
        }
        return data_[index];
    }

    /**
     * const 下标运算符
     * @param index 下标
     * @return 下标对应的元素
     */
    const _Ty& operator[](size_t index) const {
        if (index >= size_) {
            throw str_err("Index out of range");
        }
        return data_[index];
    }

    /**
     * 向量大小
     * @return 向量大小
     */
    size_t size() const {
        return size_;
    }

    /**
     * 向量容量
     * @return 向量容量
     */
    size_t capacity() const {
        return capacity_;
    }

    /**
     * 添加元素
     * @param value 添加的元素
     */
    void push_back(const _Ty& value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            _Ty* newData = new _Ty[capacity_];
            for (size_t i = 0; i < size_; i++) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
        }
        data_[size_++] = value;
    }

    /**
     * 删除元素
     * @param index 删除的元素下标
     */
    void erase(size_t index) {
        if (index >= size_) {
            throw str_err("Index out of range");
        }
        for (size_t i = index; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];
        }
        size_--;
    }
    
    /**
     * 调整向量大小
     * @param newSize 新的大小
     */
    void resize(size_t newSize) {
        if (newSize > capacity_) {
            capacity_ = newSize * 2;
            _Ty* newData = new _Ty[capacity_];
            for (size_t i = 0; i < size_; i++) {
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
        }
        size_ = newSize;
    }
};
int main(){
    Vector<int> v;
    v.resize(5);
    v[1]=0;
    printf("%d",v[1]);
}
//Simple one
/*
template <typename _Ty>
    class Vector {
    private:
        _Ty* data_;  // 数据指针
        size_t size_;  // 向量大小
        size_t capacity_;  // 向量容量
    public:
        Vector() : data_(nullptr), size_(0), capacity_(0) {}
        ~Vector() {
            delete[] data_;
        }
        _Ty& operator[](size_t index) {
            if (index >= size_) {
                throw str_err("Index out of range");
            }
            return data_[index];
        }
        void push_back(const _Ty& value) {
            if (size_ == capacity_) {
                capacity_ *= 2;
                _Ty* newData = new _Ty[capacity_];
                for (size_t i = 0; i < size_; i++) {
                    newData[i] = data_[i];
                }
                delete[] data_;
                data_ = newData;
            }
            data_[size_++] = value;
        }
    };
*/