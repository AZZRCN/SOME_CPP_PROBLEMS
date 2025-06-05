#include <bits/stdc++.h>
using namespace std;
template<typename...Ts>class fs{tuple<Ts...>d;public:fs(Ts...values):d(values...){};fs()=default;
template<size_t I>decltype(auto)get(){return get<I>(d);};};
template<typename...Ts>fs<Ts...>make_fs(Ts&&...args){return{forward<Ts>(args)...};};
int main(){
    
}