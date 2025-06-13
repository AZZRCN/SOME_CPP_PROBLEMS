#ifndef ____buffer____
#define ____buffer____
#include "class.cpp"
using std::pair;
template<typename func>
class class_draw_advanced_func;
class pos;
// class advanced_pos{public:double y,x;advanced_pos(){y=0;x=0;};advanced_pos(double _y,double _x){y = _y; x = _x;};};
//按照一般二维函数调用习惯(y,x),用不惯自己改定义
template<size_t height=0,size_t width=0>
class buffer{
public:
    //extern using

    const size_t __width = width;
    const size_t __height = height;
private:
    //data
    unsigned char data[height][width];
    //a elem for valid_request
    unsigned char __foringrone;
public:
    //fill
    void fill(const unsigned char& val);
    //structer
    buffer();

    //visit

    //
    unsigned char& operator[](const pos& p);
    //for advanced request(for system_user/coder)
    __forceinline unsigned char& __g(const pos& p);
    //for advanced request(for system_user/coder)
    __forceinline unsigned char& __g(const size_t& y,const size_t& x);
    //for igrone request(warning->catch but irgrone)
    __forceinline unsigned char& i__g(const pos& p);
    //for igrone request(warning->catch but irgrone)
    __forceinline unsigned char& i__g(const size_t& y,const size_t& x);
    //for normal request(warning->error)
    __forceinline unsigned char& n__g(const pos& p);
    //for normal request(warning->error)
    __forceinline unsigned char& n__g(const size_t& y,const size_t& x);
    const void out();
    const void out_grid();
    //math_drawing
    void draw_link(const size_t& y,const size_t& x,
        const unsigned char& width_char = '-',
        const unsigned char& height_char = '|',
        const unsigned char& point_char = '+');
    //math

    /**
    //FOR func(x)->y
     * @param f is (double) -> double || (x->y)
    */
    template<typename func>
    void draw_normal_func(
        const double& buf_start_y,const double& buf_start_x,
        const double& val_start,const double& val_end,
        const func& f,const unsigned char& c = '.',
        const double& precision = 0.1);
    /**
    //FOR range w ,func(w)->pair(y,x)
     * @param f is (double)->pair<double,double> || f(w)->{y,x};
    */
    template<typename func>
    void draw_advanced_func(
        const double& buf_start_y,const double& buf_start_x,
        const double& w_val_start,const double& w_val_end,
        const func& f,const unsigned char& c = '.',
        const double& precision = 0.1);
    /**
        //FOR range w ,func(w)->pair(y,x)
     * @param f is (double)->pair<double,double> || f(w)->{y,x};
    */
    template<typename func>
    void draw_advanced_func(class_draw_advanced_func<func>& val);
};
#endif