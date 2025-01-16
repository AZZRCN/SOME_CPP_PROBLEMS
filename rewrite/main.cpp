#include <stdlib.h>
#include "io.cpp"
#include "dbg.cpp"
#include "Book.cpp"
#include "io.h" // 引入改进后的 out 类定义
out o;

#define err(cond) if(cond){throw str_err("Hit An Err Because condition " #cond);}

int main() {
    // 使用 out 对象进行输出
    o << "Hello, World!" << '\n';
    o << 42 << '\n';
    o << 3.14 << '\n';
    o << 'A' << '\n';

    // 使用可变参数函数
    o.set_split("\n");
    o(1, "This is a test", 42, 3.14);

    // 使用 memory_print 方法
    int arr[] = {1, 2, 3, 4, 5};
    o.memory_print(arr,arr+5,arr+3,arr+5);
    o.fls();

    return 0;
}