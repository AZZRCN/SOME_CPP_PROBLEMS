#ifndef AZZR_PAIRS
#define AZZR_PAIRS
#include "function_.cpp"
#include "io.cpp"
template<typename T1, typename T2>
class pair {
public:
    T1 first;
    T2 second;
    // 构造函数
    pair() : first(T1()), second(T2()) {}
    pair(const T1& f, const T2& s) : first(f), second(s) {}
    // 拷贝构造函数
    pair(const pair& other) : first(other.first), second(other.second) {}
    // 移动构造函数
    pair(pair&& other) : first(move(other.first)), second(move(other.second)) {}
    // 赋值运算符
    pair& operator=(const pair& other) {
        first = other.first;
        second = other.second;
        return *this;
    }
    // 移动赋值运算符
    pair& operator=(pair&& other) {
        first = move(other.first);
        second = move(other.second);
        return *this;
    }
    // 相等运算符
    bool operator==(const pair& other) const {
        return first == other.first && second == other.second;
    }
    // 不等运算符
    bool operator!=(const pair& other) const {
        return !(*this == other);
    }
    // 小于运算符
    bool operator<(const pair& other) const {
        if (first < other.first) return true;
        if (first > other.first) return false;
        return second < other.second;
    }
    // 大于运算符
    bool operator>(const pair& other) const {
        return other < *this;
    }
    // 小于或等于运算符
    bool operator<=(const pair& other) const {
        return !(*this > other);
    }
    // 大于或等于运算符
    bool operator>=(const pair& other) const {
        return !(*this < other);
    }
    // 输出运算符
    friend out& operator<<(out& os, const pair& p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }
    // 交换函数
    void swap(pair& other) {
        swap(first, other.first);
        swap(second, other.second);
    }
};
//Why?仁济AI
/*
😊
Your implementation is almost correct, but not quite.
The issue is that you're trying to use a variable template (bool is_same_pair_v)
with a partial specialization, which is not allowed in C++.
Variable templates can only be fully specialized, not partially specialized.
To fix this, you can use a class template with a static member variable instead:
*/
template<typename _Tp>
struct is_same_pair {
    static constexpr bool value = false;
};
template<typename _Tp1, typename _Tp2>
struct is_same_pair<pair<_Tp1, _Tp2>> {
    static constexpr bool value = false;
};
template<typename _Tp>
struct is_same_pair<pair<_Tp, _Tp>> {
    static constexpr bool value = true;
};
template<typename _Tp>
bool is_same_pair_v;
template<typename _Tp1, typename _Tp2>
bool is_same_pair_v<pair<_Tp1,_Tp2>> = false;
template<typename _Tp>
bool is_same_pair_v<pair<_Tp,_Tp>> = true;
#endif