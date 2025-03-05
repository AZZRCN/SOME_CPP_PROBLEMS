#include <bits/stdc++.h>
using namespace std;
template<typename T>
T create(std::initializer_list<typename T::value_type> init) {
    return T(init);
}

int main() {
    // 直接传递初始化列表
    std::vector<int> v = create<std::vector<int>>({1, 2, 3});

    // 输出 vector 中的元素以验证结果
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}