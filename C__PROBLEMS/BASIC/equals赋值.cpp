#include <iostream>
#include <type_traits>
#include <stdexcept>

template<typename Tp>
void f(const Tp& _val) {
    // Base case: do nothing
}

template<typename Tp, typename First, typename... Rest>
void f(const Tp& _val, First& first, Rest&... rest) {
    static_assert(std::is_same_v<Tp, First>, "Type mismatch detected");
    first = _val;
    f(_val, rest...);
}

int main() {
    try {
        int a, b, c;
        double d, e;
        std::string f, g, h;

        f(42, a, b, c);
        f(3.14, d, e);
        f("Hello", f, g, h);

        // 测试类型不匹配
        // f(42, a, b, c, d); // 编译错误: Type mismatch detected

        // 测试传递非左值引用
        // f(42, 5, b, c); // 编译错误: cannot bind non-lvalue to reference of type 'int&'

        // 测试传递常量
        // const int x = 10;
        // f(42, x); // 编译错误: binding reference of type 'int&' to 'const int' discards qualifiers

        // 测试传递不同类型
        // f(42, a, b, c, f); // 编译错误: Type mismatch detected

        // 测试空参数列表
        // f(42); // 正常，base case

        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        std::cout << "d: " << d << ", e: " << e << std::endl;
        std::cout << "f: " << f << ", g: " << g << ", h: " << h << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}