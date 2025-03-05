#include <stdexcept>
template <typename _Ty>
class Stack {
private:
    struct Node {
        _Ty data;
        Node* next;
    };

    Node* top_;  // 栈顶指针
    size_t size_;  // 栈大小

public:
    /**
     * 构造函数
     */
    Stack() : top_(nullptr), size_(0) {}

    /**
     * 析构函数
     */
    ~Stack() {
        while (top_) {
            Node* temp = top_;
            top_ = top_->next;
            delete temp;
        }
    }

    /**
     * 入栈
     * @param value 入栈值
     */
    void push(const _Ty& value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top_;
        top_ = newNode;
        size_++;
    }

    /**
     * 出栈
     * @return 出栈值
     */
    _Ty pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        _Ty value = top_->data;
        Node* temp = top_;
        top_ = top_->next;
        delete temp;
        size_--;
        return value;
    }

    /**
     * 获取栈顶元素
     * @return 栈顶元素
     */
    _Ty& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return top_->data;
    }

    /**
     * 判断栈是否为空
     * @return true 如果栈为空，false 否则
     */
    bool empty() const {
        return top_ == nullptr;
    }

    /**
     * 获取栈大小
     * @return 栈大小
     */
    size_t size() const {
        return size_;
    }
};