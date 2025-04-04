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
// template<int size>
// class Darr{
//     public:
//     int d[size+1];
//     int data[size+1];
//     bool pushed = false;
//     void init(){
//         memset(d,0,sizeof(d));
//         memset(data,0,sizeof(data));
//     }
//     int& operator[](int x){
//         if(!pushed){
//             return d[x];
//         }
//         else{
//             return data[x];
//         }
//     }
//     void push(){
//         int carry = 0;
//         for(int i = 1; i <= size; i++){
//             carry += d[i];
//             data[i]=carry;
//         }
//         pushed = true;
//     }
// };
// class Solution {
// public:
//     Darr<100000000> d;
//     int countDays(int days, vector<vector<int>>& meetings) {
//         for(vector<int>& i:meetings){
//             sizeof(d);
//         }
//     }
// };

// template<typename _Ty>
// // using _Ty = int;
// class LIS{//the first at 0
//     public:
//     vector<_Ty> datas;
//     unordered_map<_Ty,long long> converter;
//     bool done = false;
//     void insert(_Ty x){
//         if(done){
//             throw std::out_of_range("The operation had done and can't insert.");//严格
//             // done = false; //宽松
//         }
//         datas.push_back(x);
//     }
//     void pull(void){
//         if(done){
//             return;
//         }
//         sort(datas.begin(),datas.end());
//         const int end = datas.size();
//         converter.clear();
//         for(int i = 0; i < end; i++){
//             converter.insert(make_pair(datas[i],i));
//         }
//         done = true;
//     }
//     long long search(_Ty x){
//         if(done == false){
//             throw std::out_of_range("Hadn't do pull() !");
//         }
//         typename unordered_map<_Ty,long long>::iterator it = converter.find(x);
//         return ((it==converter.end())?(-1):(it->second));
//     }
// };