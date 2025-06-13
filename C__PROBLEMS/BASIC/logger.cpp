#include <bits/stdc++.h>
using namespace std;
struct DateTime {int year,month,day,hour,minute,second,millisecond;};
DateTime getCurrentDateTime() {
    auto now = std::chrono::system_clock::now(); // 获取当前时间点
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);// 转换为系统时间
    std::tm now_tm = *std::localtime(&now_time_t);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;// 获取毫秒部分
    DateTime currentDateTime;
    currentDateTime.year = now_tm.tm_year + 1900; // tm_year是从1900年起的偏移
    currentDateTime.month = now_tm.tm_mon + 1;    // tm_mon是从0开始的
    currentDateTime.day = now_tm.tm_mday;
    currentDateTime.hour = now_tm.tm_hour;
    currentDateTime.minute = now_tm.tm_min;
    currentDateTime.second = now_tm.tm_sec;
    currentDateTime.millisecond = static_cast<int>(milliseconds.count());
    return currentDateTime;
}
struct log_outer{public:FILE* f;~log_outer(){fclose(f);}log_outer(const char* s){f = fopen(s,"a");}log_outer(FILE* _f){f = _f;}log_outer(void){f = stdout;}
void operator<<(const char* msg){DateTime dt = getCurrentDateTime();fprintf(f,"[%04d-%02d-%02d %02d:%02d:%02d:%03d] INFO: %s\n",dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,dt.millisecond,msg);}
void out(const char* msg,const char* level){DateTime dt = getCurrentDateTime();fprintf(f,"[%04d-%02d-%02d %02d:%02d:%02d:%03d] %s: %s\n",dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,dt.millisecond,level,msg);}
};