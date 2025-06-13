#ifndef ____buffer__class____
#define ____buffer__class____
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <bits/stl_pair.h>
using std::pair;
#include "class/class_draw_advanced_func.cpp"
#include "class/pos.cpp"
#include "buf.cpp"

template<size_t height,size_t width>
unsigned char& buffer<height,width>::operator[](const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){throw;}return data[p.y][p.x];}

template<size_t height,size_t width>
void buffer<height,width>::fill(const unsigned char& val){memset(data,val,height*width);}

template<size_t height,size_t width>
buffer<height,width>::buffer(){fill(' ');}

template<size_t height,size_t width>
__forceinline unsigned char& buffer<height,width>::__g(const pos& p){return data[p.y][p.x];}
template<size_t height,size_t width>
__forceinline unsigned char& buffer<height,width>::__g(const size_t& y,const size_t& x){return data[y][x];}
// template<size_t height,size_t width>
__forceinline unsigned char&
buffer<>::
i__g(const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){return __foringrone;}return data[p.y][p.x];}
template<size_t height,size_t width>
__forceinline unsigned char& buffer<height,width>::i__g(const size_t& y,const size_t& x){if(y>=height||y<0||x>=width||x<0){return __foringrone;}return data[y][x];}
template<size_t height,size_t width>
__forceinline unsigned char& buffer<height,width>::n__g(const pos& p){if(p.y>=height||p.y<0||p.x>=width||p.x<0){throw;}return data[p.y][p.x];}
template<size_t height,size_t width>
__forceinline unsigned char& buffer<height,width>::n__g(const size_t& y,const size_t& x){if(y>=height||y<0||x>=width||x<0){throw;}return data[y][x];}

template<size_t height,size_t width>
const void buffer<height,width>::out(){for(int i = 0; i < height; i++){for(int j = 0; j < width; j++){printf("%c",__g(i,j));}printf("\n");}}
template<size_t height,size_t width>
const void buffer<height,width>::out_grid(){for(int i = 0; i < height; i++){for(int j = 0; j < width; j++){printf("%c ",__g(i,j));}printf("\n");}}

template<size_t height,size_t width>
void buffer<height,width>::draw_link(const size_t& y,const size_t& x,
    const unsigned char& width_char = '-',
    const unsigned char& height_char = '|',
    const unsigned char& point_char = '+'){
    for(int i = 0; i < width; i++){n__g(y,i)=width_char;}
    for(int i = 0; i < height; i++){n__g(i,x)=height_char;}
    n__g(y,x)=point_char;
}

template<size_t height,size_t width>
template<typename func>
void buffer<height,width>::draw_normal_func(
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
template<size_t height,size_t width>
template<typename func>
void buffer<height,width>::draw_advanced_func(
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
template<size_t height,size_t width>
template<typename func>
void buffer<height,width>::draw_advanced_func(class_draw_advanced_func<func>& val){
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
#endif