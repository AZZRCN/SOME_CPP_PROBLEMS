#include <stdio.h>
int main(){
    unsigned long long n;
    scanf("%lld",&n);
    printf("%lld",((n&0xffff)<<16)|((n>>16)&0xffff));
}