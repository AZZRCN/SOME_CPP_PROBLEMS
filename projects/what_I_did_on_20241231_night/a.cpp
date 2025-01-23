#include <windows.h>
#include <bits/stdc++.h>
#include "buffer.cpp"
#include "arr.cpp"
using namespace std;
#include <stdio.h>


Buffer<10,10> buf;
int main(){
    buf.load_from_file_with_newline("FONT_BRIGHT\\A");
    buf.out();
}