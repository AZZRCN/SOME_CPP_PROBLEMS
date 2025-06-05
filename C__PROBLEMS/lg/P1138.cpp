// #include <vector>
// #include <algorithm>
// #include <numeric>
// #include <functional>
// #include <unordered_set>
// #include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wsign-compare"
template<typename T, typename F>
class Normal_SortVector_V2 {
private:
    std::vector<T> raw_data_;
    std::vector<size_t> indices_;
    F key_func_;
    
public:
    Normal_SortVector_V2(F f) : key_func_(f) {}
    
    void prepare() {
        indices_.resize(raw_data_.size());
        std::iota(indices_.begin(), indices_.end(), 0);
        std::sort(indices_.begin(), indices_.end(), 
            [this](size_t i, size_t j) { 
                return key_func_(raw_data_[i]) > key_func_(raw_data_[j]); 
            });
    }
    
    const T& at(size_t pos) const { return raw_data_[indices_[pos]]; }
    void push(const T& x) { raw_data_.push_back(x); }
    size_t size() const { return raw_data_.size(); }
};

template<typename T, typename F>
class Unique_SortVector_V2 {
private:
    std::vector<T> raw_data_;
    std::vector<size_t> indices_;
    std::unordered_map<long long, size_t> value_count_;
    F key_func_;
    
public:
    Unique_SortVector_V2(F f) : key_func_(f) {}
    
    void prepare() {
        // 构建唯一值映射
        value_count_.clear();
        for (size_t i = 0; i < raw_data_.size(); i++) {
            value_count_[key_func_(raw_data_[i])]++;
        }
        
        // 只保留唯一值的索引
        indices_.clear();
        std::unordered_set<long long> seen;
        for (size_t i = 0; i < raw_data_.size(); i++) {
            long long key = key_func_(raw_data_[i]);
            if (seen.insert(key).second) {
                indices_.push_back(i);
            }
        }
        
        // 排序
        std::sort(indices_.begin(), indices_.end(), 
            [this](size_t i, size_t j) { 
                return key_func_(raw_data_[i]) > key_func_(raw_data_[j]); 
            });
    }
    
    const T& at(size_t pos) const { return raw_data_[indices_[pos]]; }
    void push(const T& x) { raw_data_.push_back(x); }
    size_t size() const { return indices_.size(); }
};

// 工厂函数
template<typename T, typename F>
Normal_SortVector_V2<T, F> _Vector(F key_func) {
    return Normal_SortVector_V2<T, F>(key_func);
}

template<typename T, typename F>
Unique_SortVector_V2<T, F> _UniqueVector(F key_func) {
    return Unique_SortVector_V2<T, F>(key_func);
}
const auto f = [](const int&a){return -a;};
Unique_SortVector_V2<int,decltype(f)> u(f);
int main(){
	int n,k,t;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> t;
		u.push(t);
	}
	u.prepare();
	if(u.size()<k){
		puts("NO RESULT");
		return 0;
	}
	cout << u.at(k-1);
}