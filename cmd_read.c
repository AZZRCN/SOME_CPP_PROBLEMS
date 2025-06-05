#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>
// #define memory_equal(name,val,type) (*(unsigned type*)&name == (unsigned type)val)
enum FCASE_FLAGS{
    //-1到-128为错误预留(你还是节约用吧)
    ERR_VIRTUAL_KEY_INPUT    = -1,
    //-129到-255为正常码
    LEFT         = -129,//L75
    RIGHT        = -130,//R77
    UP           = -131,//U72
    DOWN         = -132,//D80
    BACKSPACE    = -133,
    CTRL_A       = -134,
    CTRL_B       = -135,
    CTRL_C       = -136,
    CTRL_D       = -137,
    CTRL_E       = -138,
    CTRL_F       = -139,
    CTRL_G       = -140,
    CTRL_H       = -141,
    CTRL_I       = -142,
    CTRL_J       = -143,
    CTRL_K       = -144,
    CTRL_L       = -145,
    CTRL_M       = -146,
    CTRL_N       = -147,
    CTRL_O       = -148,
    CTRL_P       = -149,
    CTRL_Q       = -150,
    CTRL_R       = -151,
    CTRL_S       = -152,
    CTRL_T       = -153,
    CTRL_U       = -154,
    CTRL_V       = -155,
    CTRL_W       = -156,
    CTRL_X       = -157,
    CTRL_Y       = -158,
    CTRL_Z       = -159,
    //ASCII下虚拟码的第二位(或第一位)
    LEFT_ASCII   = 75,
    RIGHT_ASCII  = 77,
    UP_ASCII     = 72,
    DOWN_ASCII   = 80,
    CTRL_A_ASCII = 1,
    CTRL_B_ASCII = 2,
    CTRL_C_ASCII = 3,
    CTRL_D_ASCII = 4,
    CTRL_E_ASCII = 5,
    CTRL_F_ASCII = 6,
    CTRL_G_ASCII = 7,
    CTRL_H_ASCII = 127,//重要!
    CTRL_I_ASCII = 9,
    CTRL_J_ASCII = 10,
    CTRL_K_ASCII = 11,
    CTRL_L_ASCII = 12,
    CTRL_M_ASCII = 13,
    CTRL_N_ASCII = 14,
    CTRL_O_ASCII = 15,
    CTRL_P_ASCII = 16,
    CTRL_Q_ASCII = 17,
    CTRL_R_ASCII = 18,
    CTRL_S_ASCII = 19,
    CTRL_T_ASCII = 20,
    CTRL_U_ASCII = 21,
    CTRL_V_ASCII = 22,
    CTRL_W_ASCII = 23,
    CTRL_X_ASCII = 24,
    CTRL_Y_ASCII = 25,
    CTRL_Z_ASCII = 26,
    BACKSPACE_ASCII = 8,
    //特殊标记
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
    case BACKSPACE_ASCII:   return BACKSPACE;
    case CTRL_A_ASCII:      return CTRL_A;
    case CTRL_B_ASCII:      return CTRL_B;
    case CTRL_C_ASCII:      return CTRL_C;
    case CTRL_D_ASCII:      return CTRL_D;
    case CTRL_E_ASCII:      return CTRL_E;
    case CTRL_F_ASCII:      return CTRL_F;
    case CTRL_G_ASCII:      return CTRL_G;
    case CTRL_H_ASCII:      return CTRL_H;
    case CTRL_I_ASCII:      return CTRL_I;
    case CTRL_J_ASCII:      return CTRL_J;
    case CTRL_K_ASCII:      return CTRL_K;
    case CTRL_L_ASCII:      return CTRL_L;
    case CTRL_M_ASCII:      return CTRL_M;
    case CTRL_N_ASCII:      return CTRL_N;
    case CTRL_O_ASCII:      return CTRL_O;
    case CTRL_P_ASCII:      return CTRL_P;
    case CTRL_Q_ASCII:      return CTRL_Q;
    case CTRL_R_ASCII:      return CTRL_R;
    case CTRL_S_ASCII:      return CTRL_S;
    case CTRL_T_ASCII:      return CTRL_T;
    case CTRL_U_ASCII:      return CTRL_U;
    case CTRL_V_ASCII:      return CTRL_V;
    case CTRL_W_ASCII:      return CTRL_W;
    case CTRL_X_ASCII:      return CTRL_X;
    case CTRL_Y_ASCII:      return CTRL_Y;
    case CTRL_Z_ASCII:      return CTRL_Z;
    
    default:
        return c1;
    }
}
#define arr_length 100
#define arr_size 10
int pos = 0;
char arr[arr_size][arr_length];//内存指针
char* write[arr_size];//写入指针(实际数据的下一个)
int x,y;
COORD cosolesize(){
    CONSOLE_SCREEN_BUFFER_INFO _t;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&_t);
    return _t.dwSize;
}
//<p>test</p>
void line_clear(){
    x = cosolesize().X;
    putchar('\r');
    for(int i = 1; i <= x; i++){
        putchar(' ');
    }
    putchar('\r');
}
__forceinline const int dec_len(int x){
    int ans = 0;
    while(x){
        ans++;x/=10;
    }
    return ans;
}
__forceinline const int dec_len_for_output(int x){
    int ans = 0;
    do{
        ans++;x/=10;
    }while(x);
    return ans;
}
void reload(){
    line_clear();
    int used = 0;
    if(pos>0){
        putchar('<');
        used++;
    }
    printf("%d",pos);
    used += dec_len_for_output(pos);
    if(pos<(arr_size-1)){
        putchar('>');
        used++;
    }
    putchar('|');
    // printf("%s",arr[pos]);
    char* t = arr[pos];
    while(*t&&x-used>4){
        putchar(*(t++));
        used++;
    }
    if(*t){
        putchar('.');
        putchar('.');
        putchar('.');
    }
}
void add(char c){
    if(write[pos]-arr[pos]<arr_length){
        *(write[pos]++)=c;
        *write[pos]='\0';
    }
}
void sub(){
    if(write[pos]>arr[pos]){
        *(--write[pos])='\0';
    }
}
#define is_digit(x) ((x>='0')&&(x<='9'))
#define is_char(x) ((x>=32)&&(x<=126))
struct read_struct{
        HANDLE hInput;
        INPUT_RECORD*ibufs;
};
void init(struct read_struct *i){
    i->hInput = GetStdHandle(STD_INPUT_HANDLE);
    // if (i->hInput == INVALID_HANDLE_VALUE) {
        // cerr << "获取标准输入句柄失败！" << endl;
    // }
    i->ibufs = (INPUT_RECORD*)malloc(128*sizeof(INPUT_RECORD));
}
struct vec{
    void* data;
    int count;
};
void resize(struct vec *i,int single_size,int length){
    i->data = malloc(single_size*length);
    i->count = length;
}
struct vec* get(struct read_struct *i){
    DWORD eventsRead;
    struct vec *ret = (struct vec*)malloc(sizeof(struct vec));
    resize(ret,sizeof(char),128);
    char*write = (char*)ret->data;
    // 检查输入缓冲区中是否有事件
    if (PeekConsoleInput(i->hInput, i->ibufs, 128, &eventsRead) && eventsRead > 0) {
        DWORD count;
        // 读取输入事件
        ReadConsoleInput(i->hInput, i->ibufs, eventsRead, &count);
        for (DWORD j = 0; j < count; j++) {
            if (i->ibufs[j].EventType == KEY_EVENT &&
                i->ibufs[j].Event.KeyEvent.bKeyDown) {
                    *(write++)=i->ibufs->Event.KeyEvent.uChar.AsciiChar;
            }
        }
    }
    ret->count = write-(char*)ret->data;
    return ret;
}
int main(){
    int c;
    for(int i = 0; i < arr_size; i++){
        write[i]=arr[i];
    }
    while (c!='q'){
        reload();
        switch ((c = fcase())){
            case LEFT:
                if(pos>0){
                    pos--;
                }
                break;
            case RIGHT:
                if(pos < 9){
                    pos++;
                }
                break;
            case BACKSPACE:
                sub();
                break;
            default:
                if(is_char(c)){
                    add(c);
                    break;
                }
                break;
        }

    }
    // struct read_struct r;
    // init(&r);
    // struct vec* v;
    // while(1){
    //     v = get(&r);
    //     for(int i = 0; i < v->count; i++){
    //         if(((char*)v->data)[i] == 8){
    //             putchar(8);
    //             putchar(' ');
    //             putchar(8);
    //         }
    //         else{
    //             putchar('*');
    //         }
    //         // putchar(((char*)v->data)[i]);
    //         // putchar(' ');
    //         // putchar(8);
    //     }
    //     // Sleep(100);
    // }
}