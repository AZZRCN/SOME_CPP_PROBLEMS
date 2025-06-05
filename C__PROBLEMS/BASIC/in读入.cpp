#include <iostream>
#include <string>
#include <cstdio>
#include <type_traits>
using namespace std;

class in {
public:
    // 通用输入运算符重载
    template<typename T>
    in& operator>>(T& value) {
        if constexpr (std::is_integral_v<T>) {    // 处理整数类型
            if constexpr (std::is_signed_v<T>) {
                std::scanf("%lld", static_cast<long long*>(static_cast<void*>(&value)));
            } else {
                std::scanf("%llu", static_cast<unsigned long long*>(static_cast<void*>(&value)));
            }
        } else if constexpr (std::is_floating_point_v<T>) { // 处理浮点类型
            std::scanf("%lf", static_cast<double*>(static_cast<void*>(&value)));
        } else if constexpr (std::is_same_v<T, std::string>) { // 处理string类型
            std::cin >> value;
        }
        return *this;
    }

    // 特化处理C风格字符串（带长度保护）
    in& operator>>(char* str) {
        std::scanf("%s", str);
        return *this;
    }

    // 可选：带缓冲区长度检查的版本
    in& get(char* str, size_t max_len) {
        std::scanf("%*s"); // 清除缓冲区
        std::scanf(("%" + std::to_string(max_len-1) + "s").c_str(), str);
        str[max_len-1] = '\0';
        return *this;
    }
};
class inV2 {
public:
    template<typename T>inV2& operator>>(T& value) {
        if constexpr (std::is_integral_v<T>) {
            if constexpr (std::is_signed_v<T>) {std::scanf("%lld", static_cast<long long*>(static_cast<void*>(&value)));}
            else{std::scanf("%llu", static_cast<unsigned long long*>(static_cast<void*>(&value)));}
        } else if constexpr (std::is_floating_point_v<T>) {std::scanf("%lf", static_cast<double*>(static_cast<void*>(&value)));
        } else if constexpr (std::is_same_v<T, std::string>) {std::cin >> value;}
        return *this;
    }
    inV2& operator>>(char* str) {std::scanf("%s", str);return *this;}
};
class inV2_simple {
public:
    template<typename T>inV2_simple& operator>>(T& value) {
        if constexpr (std::is_integral_v<T>) {
            if constexpr (std::is_signed_v<T>)
            {std::scanf("%lld", static_cast<long long*>(static_cast<void*>(&value)));}
            else{std::scanf("%llu", static_cast<unsigned long long*>(static_cast<void*>(&value)));}
        }
        return *this;
    }
};
class inV2_simple_simple {public:
    template<typename T>inV2_simple_simple& operator>>(T& value){return *this;}
    inV2_simple_simple& operator>>(int& value){std::scanf("%d", &value);return *this;}
    inV2_simple_simple& operator>>(long long& value){std::scanf("%lld", &value);return *this;}
};
// 用法示例
int main() {
    in input;
    
    int a;
    double b;
    char str1[100];
    std::string str2;

    input >> a >> b >> str1 >> str2;
    
    std::cout << "Int: " << a 
              << "\nDouble: " << b
              << "\nC-String: " << str1
              << "\nstd::string: " << str2;
}