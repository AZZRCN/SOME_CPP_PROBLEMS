#include "buf.cpp"
#include <bits/stdc++.h>
using namespace std;
int main() {
    buffer<30,80> buf;
    buf.fill('_');
    class_draw_advanced_func f(15,45,-15,15,[](const double& x){return make_pair(sin(x)*5,cos(x)*5);},'#',0.001);
    // buf.draw_link(9,0);
    // buf.draw_normal_func(5,15,-15,15,[](const double& x){return sin(x);},'#',0.001);
    while(!f.is_end()) {
        buf.draw_advanced_func(f);
    }
    buf.out_grid();
    return 0;
}