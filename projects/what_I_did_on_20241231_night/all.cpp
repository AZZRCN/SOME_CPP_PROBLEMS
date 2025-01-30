#include <stdlib.h>
#include "type.cpp"
#include <type_traits>
#include "..\..\rewrite\io.cpp"
using namespace std;
// template<typename... t>
// constexpr size_t multi(const t... x){
//     return (x*...);
// }
out o;
//all,and deall at once
class all{
    private:
    class node{public:node* prev;void* val;};
    node *tail;
    public:
    all(){
        tail = (node*)malloc(sizeof(node));
        tail->prev = nullptr;
        tail->val = nullptr;
    }
    // template<typename _Ty,typename... Sizes>
    // void operator()(_Ty& x,Sizes... sizes){
    //     o(sizeof(remove_pointer_t<_Ty>)*multi(sizes...));
    //     return;
    //     node* tmp = (node*)malloc(sizeof(node));
    //     if(tail->prev!=nullptr){
    //         tmp->prev = tail->prev;
    //         tail->prev = tmp;
    //     }else{
    //         tail->prev = tmp;
    //         tmp->prev = nullptr;
    //     }
    //     tmp->val = (_Ty)malloc(sizeof(remove_pointer_t<_Ty>)*multi(sizes...));
    //     x = (_Ty)tmp->val;
    // }
    template<typename _Ty>
    void operator()(_Ty& x,size_t size){
        node* tmp = (node*)malloc(sizeof(node));
        if(tail->prev!=nullptr){
            tmp->prev = tail->prev;
            tail->prev = tmp;
        }else{
            tail->prev = tmp;
            tmp->prev = nullptr;
        }
        tmp->val = malloc(size);
        x = (_Ty)tmp->val;
    }
    ~all(){
        node* t;
        while(tail->prev!=nullptr){
            free(tail->prev->val);
            t = tail->prev->prev;
            free(tail->prev);
            tail->prev = t;
        }
        free(tail);
    }
};
all alloctor;
int main(){
    int* n;
    alloctor(n,10);
}