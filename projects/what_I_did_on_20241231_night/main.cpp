#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
// int console_x,console_y;
int map_x,map_y;
COORD getsize(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
    return csbi.dwSize;
}
vector<vector<char>> map;
vector<char> operator"" _tovecchar(const char* s,size_t size){
    vector<char> v;
    char const* p = s;
    while(*p!='\0'){
        v.push_back(*(p++));
    }
    return v;
}
void init(){
    //. is unpassable
    #define _(x) map.push_back(x##_tovecchar)
    _(".........................................................................................");
    _(".222 000 222 555   H H   A   PP   PP   Y Y    N N  EEE  W W W    Y Y  EEE   A   RRR    !.");
    _(".  2 0 0   2 5     H H  A A  P P  P P  Y Y    N N  E    W W W    Y Y  E    A A  R R    !.");
    _(".222 0 0 222 555   HHH  AAA  PP   PP    Y     NNN  EEE  W W W     Y   EEE  AAA  RRR    !.");
    _(".2   0 0 2     5   H H  A A  P    P     Y     N N  E     W W      Y   E    A A  RR      .");
    _(".222 000 222 555   H H  A A  P    P     Y     N N  EEE   W W      Y   EEE  A A  R R    !.");
    _("..................  ..................................................................  .");
    _(".                                                                                       .");
    _(".........................................................................................");
    #undef _
    // COORD size = getsize();
    // console_x = size.X;
    // console_y = size.Y;
    map_y = map.size();
    map_x = map[0].size();
}
class player{public:
    int x,y;
    player(void){x=0;y=0;} void set(int _x,int _y){x = _x;y = _y;}
    bool go_up(){if(y>0&&map[y-1][x]!='.'){y--;return true;} else{return false;}}
    bool go_down(){if(y<map_y-1&&map[y+1][x]!='.'){y++;return true;} else{return false;}}
    bool go_left() {if (x>0&&map[y][x-1]!='.') {x--;return true;} else {return false;}}
    bool go_right() {if (x<map_x-1&&map[y][x+1]!='.') {x++;return true;} else {return false;}}
};
player p;
template<int x,int y>
class Buffer{
    public:
    char buf[y][x];
    void pos_set(){
        _x=0;
        _y=0;
    }
    void data_set(){
        memset(buf,0,sizeof(buf));
    }
    void set(){
        pos_set();
        data_set();
    }
    void out(){
        for(int i = 0; i < y; i++){fwrite(buf[i],sizeof(char),x,stdout);putchar('\n');}
    }
    char* operator[](int _){
        return buf[_];
    }
    int _x=0,_y=0;
    void next_line(){
        _y++;
        _x = 0;
    }
    void put(char c){
        buf[_y][_x++]=c;
    }
};
Buffer<41,11> buf;
void print(int x,int y,int x_around = 3,int y_around = 3){
    // system("cls");//clear
    int begin_y,end_y;
    int begin_x,end_x;
    begin_y = y-y_around;
    end_y = y+y_around;
    begin_x = x-x_around;
    end_x = x+x_around;
    buf.pos_set();
    for(int i = begin_y; i <= end_y; i++){
        for(int j = begin_x; j <= end_x; j++){
            if(i == p.y&&j==p.x){
                // putchar('*');
                buf.put('*');
                continue;
            }
            if(i<0||i>=map_y||j<0||j>=map_x){
                // putchar('#');
                buf.put('#');
                continue;
            }
            else{
                // putchar(map[i][j]);
                buf.put(map[i][j]);
                continue;
            }
        }
        // putchar('\n');
        buf.next_line();
    }
    system("cls");
    buf.out();
}
enum FCASE_FLAGS{
    ERR_VIRTUAL_KEY_INPUT    = -1,
    LEFT         = -129,//L75
    RIGHT        = -130,//R77
    UP           = -131,//U72
    DOWN         = -132,//D80
    BACKSPACE    = -133,
    LEFT_ASCII   = 75,
    RIGHT_ASCII  = 77,
    UP_ASCII     = 72,
    DOWN_ASCII   = 80,
    VIRTUAL_KEY = 224
};
int fcase(){
    int c1,c2;
    switch (c1=getch()){
    case VIRTUAL_KEY:
        //警告:224在windows下才正常工作，是虚拟按键码的第一个部分
        switch (getch()){
        case LEFT_ASCII:    return LEFT;
        case RIGHT_ASCII:   return RIGHT;
        case UP_ASCII:      return UP;
        case DOWN_ASCII:    return DOWN;
        default:            return ERR_VIRTUAL_KEY_INPUT;
        }
        break;
    default:
        return c1;
    }
}
int main(){
    init();
    p.set(1,1);
    int c = 1;
    while((c = fcase())!='q'){
        if(c == LEFT&&p.go_left()){
            goto success;
        }
        if(c == RIGHT&&p.go_right()){
            goto success;
        }
        if(c == UP&&p.go_up()){
            goto success;
        }
        if(c == DOWN&&p.go_down()){
            goto success;
        }
        goto fail;
        success:
        print(p.x,p.y,20,5);
        continue;
        fail:
        NULL;
    }
    return 0;
}