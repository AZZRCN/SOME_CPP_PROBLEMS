#include <bits/stdc++.h>
using namespace std;
class ms_timer{public:
    std::chrono::_V2::system_clock::time_point start,end;bool flag = false;//is clocking?
    void operator()(){
        if(!flag){start = std::chrono::high_resolution_clock::now();flag = true;}
        else{end = std::chrono::high_resolution_clock::now();flag = false;}
    }
    int64_t res(){return std::chrono::duration_cast<chrono::milliseconds>(end - start).count();}
};