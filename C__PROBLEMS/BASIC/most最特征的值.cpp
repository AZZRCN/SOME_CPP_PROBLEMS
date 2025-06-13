template <typename T>
T compare(const T& first, const T& second, bool (*op)(const T&, const T&)) {
    return op(first, second) ? first : second;
}
template<typename t>
t min(const t& first,const t& second){
    return ((first<second)?first:second);
}
template<typename t,typename ...Args>
t min(const t& first,const t& second,Args... args){
    return min(min(first,second),args...);
}
template<typename t>
t max(const t& first,const t& second){
    return ((first>second)?first:second);
}
template<typename t,typename ...Args>
t max(const t& first,const t& second,Args... args){
    return max(max(first,second),args...);
}


template<typename t,typename ...Args>t Mmax(const t& first,const t& second,Args... args){return max(max(first,second),args...);}
template<typename t,typename ...Args>t Mmin(const t& first,const t& second,Args... args){return min(min(first,second),args...);}
// template<typename t,typename >
// t inf()
#include <iostream>
int main(){
    std::cout << min(1,2,3,4,5,6,7,8,9,(int)'c');
}