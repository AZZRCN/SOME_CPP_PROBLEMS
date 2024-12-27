#ifndef NULL
#define NULL 0
#endif
#ifndef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
#ifdef TREE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
#ifdef LIST
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
template<typename a,typename b,typename c>
class pair_3{
    public:
    a first;
    b second;
    c third;
    __forceinline pair_3(a o1,b o2,c o3){
        first = o1;
        second = o2;
        third = o3;
    }
   
};












#define fast __forceinline __fastcall
fast void set(const void* _Dist,const void* _Val,size_t size){
    unsigned char* Dist = (unsigned char*)_Dist, * Val = (unsigned char*)_Val;
    while(size--){
        *(Dist++) = *(Val++);
    }
}
fast void set(unsigned char* Dist,unsigned char* Val,size_t size){
    while(size--){
        *(Dist++) = *(Val++);
    }
}
fast void set(void* _Dist,void* _Val,size_t repeat,size_t each_size){
    unsigned char* Dist = (unsigned char*)_Dist, * Val = (unsigned char*)_Val;
    while(repeat--){
        set(Dist,Val,each_size);
        Dist += each_size;
    }
}

template<typename _Ty,int size>
class arr{
    public:
    _Ty data[size];
    fast _Ty& operator[](const size_t x){
        return *(data+x-1);
    }
    fast void set(_Ty _val){
        ::set(data,&_val,size,sizeof(_Ty));
    }
    _Ty* begin(){
        return data+0;
    }
    _Ty* end(){
        return data+size;
    }
    fast void print(){
        for(_Ty*i = begin();i!=end();i++){
            cout << *i << " ";
        }
        cout << endl;
    }
    template<typename t>
    fast void sort(t cmp){
        ::sort(begin(),end(),cmp);
    }
};
int main(){
    less<int>();
    arr<int,5> a;
    a[1]=5;
    a[2]=6;
    a[3]=7;
    a[4]=8;
    a[5]=9;
    // a.set(10);
    // cout << a[1];
    a.sort(less<int>());
    a.print();
    a.sort(greater<int>());
    a.print();
}