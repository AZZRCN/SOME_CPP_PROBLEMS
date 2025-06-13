#ifndef ____class_draw_advanced_func____
#define ____class_draw_advanced_func____
#include <bits/stl_pair.h>
#include <stdio.h>
#include <math.h>
using std::pair;
template<typename func>
class class_draw_advanced_func{
    public:
    const double buf_start_y;
    const double buf_start_x;
    const double w_val_start;
    const double w_val_end;
    const func f;
    const unsigned char c = '.';
    const double precision = 0.1;
    // const size_t steps = floor((w_val_end-w_val_start)/precision);
    const size_t steps;
    pair<double,double> t;
    size_t step_count = 0;
    class_draw_advanced_func(double _buf_start_y, double _buf_start_x,
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
#endif