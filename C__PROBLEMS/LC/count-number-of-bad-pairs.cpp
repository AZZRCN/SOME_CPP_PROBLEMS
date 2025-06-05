#include <bits/stdc++.h>
using namespace std;
#ifndef __fastcall
#define __fastcall __attribute__((__fastcall__))
#define __forceinline inline __attribute__((__always_inline__))
#endif
template<typename _Ty>
class counter/*计数器*/{
    public:
    unordered_map<_Ty,size_t> um;
    __forceinline __fastcall void operator+(const _Ty x){add(x);}
    __forceinline __fastcall void operator-(const _Ty x){del(x);}
    __forceinline void clear() const {um.clear();}
    __forceinline bool empty() const {return um.empty();}
    void merge(const counter<_Ty>&c){for(pair<_Ty,size_t>&i:c.um){add(i.first,i.second);}}
    bool contains(const _Ty x){return um.find(x) != um.end();}
    __forceinline __fastcall const void add(const _Ty x)             {typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){it->second++;}else{um.insert(make_pair<const _Ty&,size_t>(x,1));}}
    __forceinline __fastcall const void add(const _Ty x,size_t times){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){it->second += times;}else{um.insert(make_pair<const _Ty&,size_t>(x,times));}}
    __forceinline __fastcall const void del(const _Ty x)             {typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){if(it->second > 0){it->second--;}else{um.erase(it);}}}
    __forceinline __fastcall const void del(const _Ty x,size_t times){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){if(it->second > times){it->second -= times;}else{um.erase(it);}}}
    //count a element
    __forceinline size_t count(const _Ty&x){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);return ((it != um.end()) ? (it->second) : (0));}
    //count the elements
    __forceinline __fastcall size_t size() const {return um.size();}
    //the number of all elements
    __forceinline size_t total() const {size_t ret = 0;for(const pair<_Ty,size_t>&i:um){ret += i.second;}return ret;}
    _Ty most()/*最多元素(随机顺序,只返回一个)*/{_Ty maxn;size_t max_;for(pair<_Ty,size_t> i:um){if(i.second>max_){max_ = i.second;maxn = i.first;}}return maxn;}
    vector<_Ty> most_repeat()/*最多元素(随机顺序,返回多个)*/{vector<_Ty> maxn;size_t max_;for(pair<_Ty,size_t>&i:um)
    {if(i.second>max_){maxn.clear();maxn.push_back(i.first);max_ = i.second;continue;}if(i.second == max_){maxn.push_back(i.first);}}return maxn;}
    vector<_Ty> all_key()/*所有元素,乱序*/{vector<_Ty> v;for(pair<const _Ty,size_t>&i:um){v.push_back(i.first);}return v;}
    void print(){for(pair<_Ty,size_t> i:um){cout << i.first << " " << i.second << endl;}}
    friend std::ostream& operator<<(std::ostream& os, const counter& c) {for(const auto& pair : c.um) {os << pair.first << " " << pair.second << std::endl;}return os;}
};
class Solution {
public:
    //总体-统计好数对
    /*
    i->j->limit
    if j > i && [j]-[i]=j-i
    good++;
    */
    long long countBadPairs(vector<int>& nums) {
        const unsigned long long total = nums.size()*(nums.size()-1)/2;
        long long good = 0;
        counter<int> c;
        for(int i = 0 ; i < nums.size(); i++){
            nums[i]-=i;
            if(c.contains(nums[i])){
                good += c.count(nums[i]);
            }
            c+nums[i];
        }
        return total - good;
    }
};