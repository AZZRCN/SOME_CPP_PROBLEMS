#include "alloctor.cpp"
#include "io.cpp"
template<typename _ty=int,typename alloc = alloctor<_ty>>
class vector{
    public:
    alloc all;
    _ty& operator[](size_t pos){
        return all.operator[](pos);
    }
    void resize(size_t size){
        all.resize(size);
    }
    void malloc(size_t size){
        all.mal(size);
    }
    ~vector(){
        // all.~alloctor();
    }
};
int main(){
    vector<> v;
    out o;
    v.resize(11);
    for(int i = 1; i<= 10; i++){
        v[i] = i;
    }
    for(int i = 1; i <= 10; i++){
        o(v[i]);
    }
}