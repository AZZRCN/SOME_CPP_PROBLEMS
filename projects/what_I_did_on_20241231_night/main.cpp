#include <bits/stdc++.h>
using namespace std;
/**
 * 1.系统安全高于一切
 * 2.文件安全高于时间
 * 3.内存安全高于浪费
*/
bool bigger_05(const double& x){
    return x>0.5;
}
bool bigger_equal_05(const double& x){
    return x>=0.5;
}
bool less_05(const double& x){
    return x<0.5;
}
bool less_equal_05(const double& x){
    return x<=0.5;
}
long long _round(const double& x){
    return (long long)round(x);
}
enum{
    N_NEW_LINE = -2,
    R_NEW_LINE = -3,
    // LINE_OVERFLOW = -17,
    // HEIGHT_OVERFLOW = -18,
    // BUFFER_OVERFLOW = -19,
};
class font{
    public:
    FILE* f;
    int c;
    void open(const char* path){f = fopen(path,"rb");}
    void reset(){fseek(f,0,SEEK_SET);}
    void close(){fclose(f);}
    font(const char* path){open(path);}
    //-1 is eof
    //-2 is newline
    //others is char
    int get(){
        switch (c = fgetc(f)){
        case '\n':return N_NEW_LINE;break;
        case '\r':return R_NEW_LINE;break;
        case EOF:return EOF;
        default:return c;break;
        }
    }
    bool eof(){return feof(f);}
    void go_to_next_line(){while(!eof()&&(get()!=N_NEW_LINE));}
    ~font(){close();}
};
void read_font_config(int& width,int& height,const char* path){
    FILE* _f = fopen(path,"r");
    fscanf(_f,"%d%d",&width,&height);
    fclose(_f);
}
template<
int width
,
int height
>
class Buffer{
    public:
    char buf[height][width];
    int cur_x=0,cur_y=0;
    void pos_reset(){cur_x=0;cur_y=0;}
    void pos_set(int x=0,int y=0){cur_x=x;cur_y=y;}
    void data_reset(){memset(buf,0,sizeof(buf));}
    void data_set(const char& c){memset(buf,c,sizeof(buf));}
    void reset(){pos_reset();data_reset();}
    void out(){
        for(int i = 0; i < height; i++){
            fwrite(buf[i],sizeof(char),width,stdout);putchar('\n');
        }
    }
    void out_marked(){
        putchar('\\');
        for(int i = 0; i < width; i++){
            putchar('0'+(i%10));
        }
        putchar('\n');
        for(int i = 0; i < height; i++){
            putchar('0'+(i%10));
            fwrite(buf[i],sizeof(char),width,stdout);
            putchar('\n');
        }
    }
    void out_marked_split(int box_size){
        putchar('\\');
        for(int i = 0; i < width; i++){
            if(i%box_size==0){
                putchar(' ');
            }
            putchar('0'+(i%10));
        }
        putchar('\n');
        for(int i = 0; i < height; i++){
            if(i%box_size==0){
                putchar('\n');
            }
            putchar('0'+(i%10));
            for(int j = 0; j < width; j++){
                if(j%box_size==0){
                    putchar(' ');
                }
                putchar(buf[i][j]);
            }
            putchar('\n');
        }
    }
    char* operator[](const int&_){return buf[_];}
    bool next_line(){
        if(cur_y>=height)return false;
        cur_y++;
        cur_x = 0;
        return true;
    }
    const bool x_overflow(){return cur_x>=width;}
    const bool y_overflow(){return cur_y>=height;}
    const bool overflow(){return x_overflow()&&y_overflow();}
    //1 is success
    //-1 is overflow the line
    //-2 is overflow the buffer
    int put(char c){
        if(x_overflow()){
            if(y_overflow()){
                return -2;
            }
            next_line();
            buf[cur_y][cur_x++]=c;
            return -1;
        }
        buf[cur_y][cur_x++]=c;
        return 1;
    }
    void cls(){
        system("cls");
    }
    //由于其特殊性
    //所以允许横向被截断
    void load_font(const int& x,const int& y,font&f,int removed_bg = '.'){
        int c;
        for(int i = y; i < height&&!f.eof(); i++){
            for(int j = x; (j < width)&&(!f.eof())&&((c = f.get())!=N_NEW_LINE); j++){
                if(c==R_NEW_LINE)break;
                if(c==removed_bg)continue;
                buf[i][j]=c;
            }
            if(f.eof())return;
            if(c!=N_NEW_LINE){
                f.go_to_next_line();
            }
        }
    }
    void load_font(const int& x,const int& y,const char* path,int removed_bg = '.'){
        font f(path);
        load_font(x,y,f,removed_bg);
    }
    void draw_line(const int& x1,const int& y1,const int& x2,const int& y2,const char& c){
        if(x1>x2){
            return (void)draw_line(x2,y2,x1,y1,c);
        }
        const double X1 = x1;
        const double Y1 = y1;
        const double X2 = x2;
        const double Y2 = y2;
        const double k = (Y2-Y1)/(X2-X1);
        double ans;
        for(int i = 0; i <= (x2-x1); i++){
            ans = k*i;
            buf[y1+_round(ans)][x1+i]=c;
        }
    }
    void put_str(int x,int y,string path,string str){
        int a,b;
        read_font_config(a,b,path.c_str());
        if(path.back()!='\\')path.push_back('\\');
        path.push_back('a');
        for(char c : str){
            path.back()=c;
            load_font(x,y,path.c_str());
            x += a;
        }
    }
    // void draw_line_no_end_x_point(const int& x1,const int& y1,const int& x2,const int& y2,const char& c){
    //     if(x1>x2){
    //         return (void)draw_line(x2,y2,x1-1,y1,c);
    //     }
    //     return (void)draw_line(x1,y1,x2-1,y2,c);
    // }
};
Buffer<100,10> buf;
int main(){
    buf.data_set('.');
    buf.put_str(0,0,"FT","AAAAAAAA!");
    buf.out_marked();
}