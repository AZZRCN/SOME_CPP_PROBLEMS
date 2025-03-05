#include <cctype>

template<typename T>
class FastInEx {
public:
    FastInEx() { load(); }

    const T& read() {
        parse();
        return value;
    }

private:
    static const int BUF_SIZE = 1 << 16;
    char buffer[BUF_SIZE];
    char* ptr;
    T value;

    void load() {
        // 批量读取优化
        static char* end = buffer + fread(buffer, 1, BUF_SIZE, stdin);
        ptr = buffer;
    }

    void next() {
        if (++ptr == buffer + BUF_SIZE) load();
    }

    void parse() {
        value = 0;
        bool sign = false;

        // 跳过非数字字符
        while (!isdigit(*ptr) && *ptr != '-') next();

        // 符号处理
        if constexpr (std::is_signed_v<T>) {
            if (*ptr == '-') {
                sign = true;
                next();
            }
        }

        // 主解析循环
        while (isdigit(*ptr)) {
            value = value * 10 + (*ptr - '0');
            next();
        }

        if constexpr (std::is_signed_v<T>) {
            if (sign) value = -value;
        }
    }
};

// 特化版本声明
template class FastInEx<int>;
template class FastInEx<long>;
template class FastInEx<long long>;
#include <bits/stdc++.h>
using namespace std;
// 使用示例：
int main() {
    FastInEx<int> in;
    const auto& num = in.read();  // 返回const引用避免拷贝
    printf("%d\n", num);
}