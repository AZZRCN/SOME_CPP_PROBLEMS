#include <cctype>



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