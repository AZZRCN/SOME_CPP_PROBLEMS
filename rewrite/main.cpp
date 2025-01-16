#include <stdlib.h>
#include "io.cpp"
#include "dbg.cpp"
#include "Book.cpp"
#include "saver.cpp"
#include "reader.cpp"
// #include "io.h" // 引入改进后的 out 类定义
out o;
saver s;
reader r;
#define err(cond) if(cond){throw str_err("Hit An Err Because condition " #cond);}

int main() {
    int n = 10;
    s.save("data.bin",n);
    r.read("data.bin",n);
    printf("%d",n);
    return 0;
}