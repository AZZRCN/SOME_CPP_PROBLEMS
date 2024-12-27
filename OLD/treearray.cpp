#ifndef __builtin_ctz
/*
int __builtin_ctzl(unsigned long x) {
    int r = 63;
    x &= ~x + 1;
    if (x & 0x00000000FFFFFFFF) r -= 32;
    if (x & 0x0000FFFF0000FFFF) r -= 16;
    if (x & 0x00FF00FF00FF00FF) r -= 8;
    if (x & 0x0F0F0F0F0F0F0F0F) r -= 4;
    if (x & 0x3333333333333333) r -= 2;
    if (x & 0x5555555555555555) r -= 1;
    return r;
}
*/
int __builtin_ctz(int v) {
    int c = 0;
    // 使用位操作找到第一个非零位  
    if ((v & 0x0000FFFF) == 0) { v >>= 16; c += 16; }
    if ((v & 0x000000FF) == 0) { v >>= 8;  c += 8; }
    if ((v & 0x0000000F) == 0) { v >>= 4;  c += 4; }
    if ((v & 0x00000003) == 0) { v >>= 2;  c += 2; }
    if ((v & 0x00000001) == 0) { v >>= 1;  c += 1; }

    // 此时v必定为1，因为前面的if语句确保了v的最低位为1  
    // 由于前面的操作已经排除了v为0的情况，所以这里不需要再判断v是否为0  

    return c;
}
#endif
template<int x = 0>
class treeArray {
public:
    //这里提供low_bit,请自己改
    /*
    * int low_bit(int x){
    *   return ((x)&(-x));
    * }
    * next就是向前跳
    * 为n-low_bit(n);
    * next_2就是向后跳
    * 为n+low_bit(n);
    * 
    * 作者心路历程
    * 确实像是二叉树，但又不是
    * 太好了！不用考虑分不够的情况
    * 欸，好像用啊
    * 不管了，能使
    */
    int next(int n) {
        return ((n) & (n - 1));
    }
    int next_2(int n) {
        int ans = 0;
        ans += __builtin_ctz(n);
        n >>= __builtin_ctz(n);
        ans += __builtin_ctz(~n);
        n >>= __builtin_ctz(~n);
        n |= 1;
        n <<= ans;
        return n;
    }
    int array[x + 1];
    void change(int pos, int delta_value) {//1,1means array[1]+=1
        while (pos <= x) {
            array[pos] += delta_value;
            pos = next_2(pos);
        }
    }
    void change(int L, int R, int delta_value) {//1,1means array[1]+=1
        change(L, delta_value);
        change(R + 1, -delta_value);
    }
    int search(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += array[pos];
            pos = next(pos);
        }
        return ret;
    }
    int search(int L, int R) {
        return search(R) - search(L - 1);
    }
    void init() {
        memset(array, 0, sizeof(array));
    }
};