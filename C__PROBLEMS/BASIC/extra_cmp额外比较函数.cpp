#include <iostream>
#include <algorithm>
#include <initializer_list>
#include <type_traits>

// 检查所有类型是否一致
template<typename T, typename... Ts>
constexpr bool all_same_v = std::conjunction_v<std::is_same<T, Ts>...>;

// 最大值函数
template<typename T, typename... Ts>
T maximum(T first, Ts... rest) {
    static_assert(sizeof...(rest) >= 1, "At least two arguments are required.");
    static_assert(all_same_v<T, Ts...>, "All arguments must be of the same type.");

    std::initializer_list<T> list = {first, rest...};
    return *std::max_element(list.begin(), list.end());
}

// 最小值函数
template<typename T, typename... Ts>
T minimum(T first, Ts... rest) {
    static_assert(sizeof...(rest) >= 1, "At least two arguments are required.");
    static_assert(all_same_v<T, Ts...>, "All arguments must be of the same type.");

    std::initializer_list<T> list = {first, rest...};
    return *std::min_element(list.begin(), list.end());
}
int main() {
    std::cout << maximum(3, 5, 2, 8, 1) << std::endl;  // 输出 8
    std::cout << minimum(3.5, 2.1, 4.0) << std::endl; // 输出 2.1

    // 以下调用会触发编译错误（参数类型不一致）
    // std::cout << maximum(3, 4.5) << std::endl;

    return 0;
}