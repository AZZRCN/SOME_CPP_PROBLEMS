#include <bits/stdc++.h>
using namespace std;
int main(){
    FILE* I = fopen("OFTEN_USE_PRIME_1000","r");
    FILE* O = fopen("OFTEN_USE_PRIME_1000.cpp","w");
    putchar('{');
    int x;
    while(fscanf(I,"%d",&x) != EOF){
        fprintf(O,"%d,",x);
    }
    putchar('}');
}