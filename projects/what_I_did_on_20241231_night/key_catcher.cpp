#include <conio.h>
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