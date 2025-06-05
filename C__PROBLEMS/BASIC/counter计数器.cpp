#include <bits/stdc++.h>
using namespace std;
template<typename _Ty>
class counterV1/*计数器*/{
    public:
    unordered_map<_Ty,size_t> um;
    __forceinline __fastcall void operator+(const _Ty x){add(x);}
    __forceinline __fastcall void operator-(const _Ty x){del(x);}
    __forceinline void clear() const {um.clear();}
    __forceinline bool empty() const {return um.empty();}
    void merge(const counterV1<_Ty>&c){for(pair<_Ty,size_t>&i:c.um){add(i.first,i.second);}}
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
    void print(){for(pair<_Ty,size_t> i:um){cout << i.first << " " < < i.second << endl;}}
    friend std::ostream& operator<<(std::ostream& os, const counterV1& c) {for(const auto& pair : c.um) {os << pair.first << " " << pair.second << std::endl;}return os;}
};
// template<typename Ty>
// class counterV2{
//     std::unordered_map<Ty,size_t> um;
// public:
//     __forceinline __fastcall counterV2& operator+=(const Ty&x){add(x);return*this;}
//     __forceinline __fastcall counterV2& operator-=(const Ty&x){del(x);return*this;}
//     __forceinline void clear()noexcept{um.clear();} __forceinline bool empty()const noexcept{return um.empty();}
//     __forceinline size_t size()const noexcept{return um.size();}
//     void merge(const counterV2&c){for(const auto&[k,v]:c.um)add(k,v);}
//     __forceinline bool contains(const Ty&x)const noexcept{return um.find(x)!=um.end();}
//     __forceinline __fastcall void add(const Ty&x){if(auto it=um.find(x);it!=um.end())++it->second;else um.emplace(x,1);}
//     __forceinline __fastcall void add(const Ty&x,size_t t){if(auto it=um.find(x);it!=um.end())it->second+=t;else um.emplace(x,t);}
//     __forceinline __fastcall void del(const Ty&x){if(auto it=um.find(x);it!=um.end()){if(it->second>1)--it->second;else um.erase(it);}}
//     __forceinline __fastcall void del(const Ty&x,size_t t){if(auto it=um.find(x);it!=um.end()){it->second>t?it->second-=t:um.erase(it);}}
//     __forceinline size_t count(const Ty&x)const noexcept{return um.count(x)?um.at(x):0;}
//     __forceinline size_t total()const noexcept{size_t r=0;for(const auto&[_,v]:um)r+=v;return r;}
//     Ty most()const{if(um.empty())throw std::runtime_error("Empty");auto it=um.begin();for(auto p=it;p!=um.end();++p)if(p->second>it->second)it=p;return it->first;}
//     std::vector<Ty> most_repeat()const{std::vector<Ty> r;if(um.empty())return r;size_t m=um.begin()->second;for(const auto&[k,v]:um){if(v>m){m=v;r.clear();}if(v>=m)if(v>m)r={k};else r.push_back(k);}return r;}
//     std::vector<Ty> keys()const{std::vector<Ty> r;r.reserve(um.size());for(const auto&[k,_]:um)r.push_back(k);return r;}
//     friend std::ostream& operator<<(std::ostream& os,const counterV2& c){for(const auto&[k,v]:c.um)os<<k<<" "<<v<<"\n";return os;}
// };
template<typename Ty>
class counterV2{
    std::unordered_map<Ty,size_t> um;
public:
    __forceinline __fastcall counterV2& operator+(const Ty&x){add(x);return*this;}
    __forceinline __fastcall counterV2& operator-(const Ty&x){del(x);return*this;}
    __forceinline void clear()noexcept{um.clear();} __forceinline bool empty()const noexcept{return um.empty();}
    __forceinline size_t size()const noexcept{return um.size();}
    void merge(const counterV2&c){for(const auto&[k,v]:c.um)add(k,v);}
    __forceinline bool contains(const Ty&x)const noexcept{return um.find(x)!=um.end();}
    __forceinline __fastcall void add(const Ty&x){if(auto it=um.find(x);it!=um.end())++it->second;else um.emplace(x,1);}
    __forceinline __fastcall void add(const Ty&x,size_t t){if(auto it=um.find(x);it!=um.end())it->second+=t;else um.emplace(x,t);}
    __forceinline __fastcall void del(const Ty&x){if(auto it=um.find(x);it!=um.end()){if(it->second>1)--it->second;else um.erase(it);}}
    __forceinline __fastcall void del(const Ty&x,size_t t){if(auto it=um.find(x);it!=um.end()){it->second>t?it->second-=t:um.erase(it);}}
    __forceinline size_t count(const Ty&x)const noexcept{return um.count(x)?um.at(x):0;}
    __forceinline size_t total()const noexcept{size_t r=0;for(const auto&[_,v]:um)r+=v;return r;}
    Ty most()const{if(um.empty())throw std::runtime_error("Empty");auto it=um.begin();for(auto p=it;p!=um.end();++p)if(p->second>it->second)it=p;return it->first;}
    std::vector<Ty> most_repeat()const{std::vector<Ty> r;if(um.empty())return r;size_t m=um.begin()->second;for(const auto&[k,v]:um){if(v>m){m=v;r.clear();}if(v>=m)if(v>m)r={k};else r.push_back(k);}return r;}
    std::vector<Ty> keys()const{std::vector<Ty> r;r.reserve(um.size());for(const auto&[k,_]:um)r.push_back(k);return r;}
    friend std::ostream& operator<<(std::ostream& os,const counterV2& c){for(const auto&[k,v]:c.um)os<<k<<" "<<v<<"\n";return os;}
};



#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <ostream>

template<typename Ty>
class counter_qwen {
    std::unordered_map<Ty, size_t> um;

public:
    // 增加元素
    counter_qwen& operator+(const Ty& x) { add(x); return *this; }
    counter_qwen& operator-(const Ty& x) { del(x); return *this; }

    void add(const Ty& x) {
        ++um[x];
    }

    void add(const Ty& x, size_t t) {
        um[x] += t;
    }

    // 删除元素
    void del(const Ty& x) {
        auto it = um.find(x);
        if (it != um.end()) {
            if (it->second > 1)
                --it->second;
            else
                um.erase(it);
        }
    }

    void del(const Ty& x, size_t t) {
        auto it = um.find(x);
        if (it != um.end()) {
            if (it->second > t)
                it->second -= t;
            else
                um.erase(it);
        }
    }

    // 查询
    size_t count(const Ty& x) const {
        auto it = um.find(x);
        return it == um.end() ? 0 : it->second;
    }

    size_t total() const {
        size_t sum = 0;
        for (const auto& [k, v] : um)
            sum += v;
        return sum;
    }

    // 清空 & 状态
    void clear() noexcept { um.clear(); }
    bool empty() const noexcept { return um.empty(); }
    size_t size() const noexcept { return um.size(); }

    // 合并另一个 counter
    void merge(const counter_qwen& other) {
        for (const auto& [k, v] : other.um)
            um[k] += v;
    }

    // 是否包含某元素
    bool contains(const Ty& x) const noexcept {
        return um.find(x) != um.end();
    }

    // 返回最多的一个元素
    Ty most() const {
        if (um.empty())
            throw std::runtime_error("Empty counter");
        const auto* max_it = &(*um.begin());
        for (const auto& kv : um)
            if (kv.second > max_it->second)
                max_it = &kv;
        return max_it->first;
    }

    // 所有最大频次的元素
    std::vector<Ty> most_repeat() const {
        std::vector<Ty> res;
        if (um.empty()) return res;

        size_t max_count = 0;
        for (const auto& [k, v] : um) {
            if (v > max_count) {
                max_count = v;
                res.clear();
                res.push_back(k);
            } else if (v == max_count) {
                res.push_back(k);
            }
        }
        return res;
    }

    // 所有键
    std::vector<Ty> keys() const {
        std::vector<Ty> result;
        result.reserve(um.size());
        for (const auto& [k, _] : um)
            result.push_back(k);
        return result;
    }

    // 输出流支持
    friend std::ostream& operator<<(std::ostream& os, const counter_qwen& c) {
        for (const auto& [k, v] : c.um)
            os << k << " " << v << "\n";
        return os;
    }
};


#include <unordered_map>
#include <vector>
#include <stdexcept>

template<typename Ty>class counter_qwen_compressed {
std::unordered_map<Ty, size_t> um;public:using const_iterator = typename std::unordered_map<Ty, size_t>::const_iterator;
    counter_qwen_compressed& operator+(const Ty& x) { { if (auto it = um.find(x); it != um.end()) { ++it->second; } else { um[x] = 1; } } return *this; }
    counter_qwen_compressed& operator-(const Ty& x) { { if (auto it = um.find(x); it != um.end()) { { if (it->second > 1) { --it->second; } else { um.erase(it); } } } }return *this; }
    size_t elem_count(const Ty& x) const noexcept { { auto it = um.find(x); return it == um.end() ? 0 : it->second; } }
    size_t total_count() const noexcept { { size_t r = 0; for (const auto& [_, v] : um) { r += v; } return r; } }
    void clear() noexcept { { um.clear(); } }
    bool empty() const noexcept { { return um.empty(); } }
    size_t elem_vals_count() const noexcept { { return um.size(); } }
    void merge(const counter_qwen_compressed& other) { { for (const auto& [k, v] : other.um) { um[k] += v; } } }
    bool contains(const Ty& x) const noexcept { { return um.find(x) != um.end(); } }
    std::vector<Ty> most_repeat() const { { std::vector<Ty> res; if (um.empty()){return res;} size_t m = 0; for (const auto& [k, v] : um) {
            { if (v > m) { m = v; res.clear(); res.push_back(k); } else if (v == m) { res.push_back(k); } } } return res; } }
    std::vector<Ty> keys() const { { std::vector<Ty> result; result.reserve(um.size()); for (const auto& [k, _] : um) { result.push_back(k); } return result; } }
    const_iterator begin() const noexcept { return um.begin(); }
    const_iterator end()  const noexcept { return um.end(); }
};