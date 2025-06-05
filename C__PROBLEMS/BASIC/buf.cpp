#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bits/stl_pair.h>
using std::pair;
template<typename func>
class class_draw_advanced_func_const{
    public:
    const double buf_start_y;
    const double buf_start_x;
    const double w_val_start;
    const double w_val_end;
    // const func f;//why wtf???BRO?
    const typename lambda[](const double& x)->pair<double,double> f;
    //it's always double->double,double!
    const unsigned char c = '.';
    const double precision = 0.1;
    // const size_t steps = floor((w_val_end-w_val_start)/precision);
    const size_t steps;
    pair<double,double> t;
    size_t step_count = 0;
    class_draw_advanced_func_const(double _buf_start_y, double _buf_start_x,
                            double _w_val_start, double _w_val_end,
                            func _f,unsigned char _c='#',double _precision=0.1)
    : buf_start_y(_buf_start_y),
        buf_start_x(_buf_start_x),
        w_val_start(_w_val_start),
        w_val_end(_w_val_end),
        f(_f),
        steps(static_cast<size_t>(std::floor((w_val_end - w_val_start) / precision))),
        t(0.0, 0.0),
        step_count(0),
        c(_c),
        precision(_precision)
    {}
    bool is_end(){
        return step_count>steps;
    }
};
class pos{public:size_t y,x;pos(){y=0;x=0;};pos(size_t _y,size_t _x){y = _y; x = _x;};};
// class advanced_pos{public:double y,x;advanced_pos(){y=0;x=0;};advanced_pos(double _y,double _x){y = _y; x = _x;};};
//按照一般二维函数调用习惯(y,x),用不惯自己改定义
template<size_t height=0,size_t width=0>
class buffer{
public:
    const size_t __width = width;
    const size_t __height = height;
private:
    unsigned char data[height][width];
    unsigned char __foringrone;
public:
    unsigned char& operator[](const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){throw;}return data[p.y][p.x];}
    void fill(const unsigned char& val){memset(data,val,height*width);}
    buffer(){fill(' ');}
    void clear(){fill(' ');}
    //for advanced request(for system_user/coder)
    __forceinline unsigned char& __g(const pos& p){return data[p.y][p.x];}
    __forceinline unsigned char& __g(const size_t& y,const size_t& x){return data[y][x];}
    //for igrone request(warning->catch but irgrone)
    __forceinline unsigned char& i__g(const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){return __foringrone;}return data[p.y][p.x];}
    __forceinline unsigned char& i__g(const size_t& y,const size_t& x){if(y>=height||y<0||x>=width||x<0){return __foringrone;}return data[y][x];}
    //for normal request(warning->error)
    __forceinline unsigned char& n__g(const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){throw;}return data[p.y][p.x];}
    __forceinline unsigned char& n__g(const size_t& y,const size_t& x){if(y>=height||y<0||x>=width||x<0){throw;}return data[y][x];}
    const void out(){for(int i = 0; i < height; i++){for(int j = 0; j < width; j++){printf("%c",__g(i,j));}printf("\n");}}
    const void out_grid(){for(int i = 0; i < height; i++){for(int j = 0; j < width; j++){printf("%c ",__g(i,j));}printf("\n");}}
    //math
    void draw_link(const size_t& y,const size_t& x,
        const unsigned char& width_char = '-',
        const unsigned char& height_char = '|',
        const unsigned char& point_char = '+'){
        for(int i = 0; i < width; i++){i__g(y,i)=width_char;}
        for(int i = 0; i < height; i++){i__g(i,x)=height_char;}
        i__g(y,x)=point_char;
    }
    //math
    //FOR func(x)->y
    /**
     * @param f is (double) -> double || (x->y)
    */
    template<typename func>
    void draw_normal_func(
        const double& buf_start_y,const double& buf_start_x,
        const double& val_start,const double& val_end,
        const func& f,const unsigned char& c = '.',
        const double& precision = 0.1){
        const size_t steps = floor((val_end-val_start)/precision);
        for(int i = 1; i < steps; i++){
            i__g(round(buf_start_y-f(val_start+i*precision)),round(buf_start_x+val_start+i*precision)) = c;
        }
        i__g(round(buf_start_y+f(val_start)),round(buf_start_x+val_start));
        i__g(round(buf_start_y+f(val_end)),round(buf_start_x+val_end));
    }
    //FOR range w ,func(w)->pair(y,x)
    /**
     * @param f is (double)->pair<double,double> || f(w)->{y,x};
    */
    template<typename func>
    void draw_advanced_func(
        const double& buf_start_y,const double& buf_start_x,
        const double& w_val_start,const double& w_val_end,
        const func& f,const unsigned char& c = '.',
        const double& precision = 0.1){
        const size_t steps = floor((w_val_end-w_val_start)/precision);
        pair<double,double> t;
        for(int i = 1; i < steps; i++){
            t=f(w_val_start+i*precision);
            i__g(round(buf_start_y-t.first),round(buf_start_x+t.second)) = c;
        }
        t = f(w_val_start);
        i__g(round(buf_start_y-t.first),round(buf_start_x+t.second));
        t = f(w_val_end);
        i__g(round(buf_start_y-t.first),round(buf_start_x+t.second));
    }
    template<typename func>
    void draw_advanced_func(class_draw_advanced_func_const<func>& val){
        if(val.is_end()){
            return;
        }
        if(val.step_count == 0){
            val.t = val.f(val.w_val_start);
            i__g(round(val.buf_start_y-val.t.first),round(val.buf_start_x+val.t.second));
            val.step_count++;
            return;
        }
        if(val.step_count == val.steps){
            val.t = val.f(val.w_val_end);
            i__g(round(val.buf_start_y-val.t.first),round(val.buf_start_x+val.t.second));
            val.step_count++;
            return;
        }
        val.t=val.f(val.w_val_start+val.step_count*val.precision);
        i__g(round(val.buf_start_y-val.t.first),round(val.buf_start_x+val.t.second)) = val.c;
        val.step_count++;
    }
};







#include <bits/stdc++.h>
using namespace std;
#define cls system("cls")
int main() {
    buffer<10,10> buf;
    buf.clear();
    buf.draw_link(3,3,'=','|','*');
    buf.out_grid();
    return 0;
}