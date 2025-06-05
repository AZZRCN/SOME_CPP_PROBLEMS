#include <bits/stdc++.h>
using namespace std;

namespace sort_vector {

//==============================================================================
// 版本1：SortVector 基类与其衍生类
//==============================================================================

template <typename T, typename F>
class SortVector_V1 {
protected:
    vector<T> data;
    F score_func;
    bool prepared = false;

    virtual void prepare_impl() = 0;

public:
    SortVector_V1(F f) : score_func(f) {}
    virtual ~SortVector_V1() = default;

    void push(const T& value) { data.push_back(value); prepared = false; }
    size_t size() { return data.size(); }
    void prepare() { if (!prepared) { prepare_impl(); prepared = true; } }

    template <typename InputIt>
    void insert(InputIt first, InputIt last) { 
        data.insert(data.end(), first, last); prepared = false; 
    }

    virtual const T& at(size_t pos) = 0;
    virtual vector<T> top_k(size_t k) = 0;
};

template <typename T, typename F>
class Normal_SortVector_V1 : public SortVector_V1<T, F> {
    void prepare_impl() override {
        vector<size_t> indices(this->data.size());
        iota(indices.begin(), indices.end(), 0);
        
        stable_sort(indices.begin(), indices.end(), [this](size_t a, size_t b) {
            return this->score_func(this->data[a]) > this->score_func(this->data[b]);
        });
        
        vector<T> sorted;
        for (auto i : indices) sorted.push_back(move(this->data[i]));
        this->data = move(sorted);
    }

public:
    using SortVector_V1<T, F>::SortVector_V1;
    
    const T& at(size_t pos) override { 
        this->prepare(); 
        return pos < this->data.size() ? this->data[pos] : this->data[0]; 
    }
    
    vector<T> top_k(size_t k) override { 
        this->prepare(); 
        return {this->data.begin(), this->data.begin() + min(k, this->data.size())}; 
    }
};

template <typename T, typename F>
class Unique_SortVector_V1 : public SortVector_V1<T, F> {
    void prepare_impl() override {
        vector<pair<T, size_t>> scored;
        for (size_t i = 0; i < this->data.size(); ++i) {
            scored.emplace_back(this->data[i], i);
        }
        
        sort(scored.begin(), scored.end());
        scored.erase(unique(scored.begin(), scored.end()), scored.end());
        
        sort(scored.begin(), scored.end(), [this](auto& a, auto& b) {
            return this->score_func(a.first) > this->score_func(b.first);
        });
        
        this->data.clear();
        for (const auto& p : scored) {
            this->data.push_back(p.first);
        }
    }

public:
    using SortVector_V1<T, F>::SortVector_V1;
    
    const T& at(size_t pos) override { 
        this->prepare(); 
        return pos < this->data.size() ? this->data[pos] : this->data[0]; 
    }
    
    vector<T> top_k(size_t k) override { 
        this->prepare(); 
        return {this->data.begin(), this->data.begin() + min(k, this->data.size())}; 
    }
};

//==============================================================================
// 版本2：直接使用索引排序的简洁实现
//==============================================================================

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
        std::unordered_set<T> seen;
        for (size_t i = 0; i < raw_data_.size(); i++) {
            if (seen.insert(raw_data_[i]).second) {
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

//==============================================================================
// 版本3：增强版基于索引的排序容器，支持特征值类型和直方图
//==============================================================================

template<typename T, typename ScoreType = double>
class Enhanced_SortVector {
protected:
    std::vector<T> data_;
    std::vector<size_t> indices_;

public:
    Enhanced_SortVector() = default;
    
    // 使用可调用对象提取特征值
    template<typename ExtractorFunc>
    void prepare(const std::vector<T>& data, ExtractorFunc extractor, bool greater = true) {
        // 存储原始数据
        data_ = data;
        
        // 提取所有特征值
        std::vector<ScoreType> scores;
        scores.reserve(data.size());
        for (const auto& item : data) {
            scores.push_back(extractor(item));
        }
        
        // 创建索引并排序
        indices_.resize(data.size());
        std::iota(indices_.begin(), indices_.end(), 0);
        
        if (greater) {
            // 默认从大到小排序
            std::sort(indices_.begin(), indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] > scores[b]; });
        } else {
            // 从小到大排序
            std::sort(indices_.begin(), indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] < scores[b]; });
        }
    }
    
    // 获取排序后的元素
    std::vector<T> get_sorted() const {
        std::vector<T> sorted;
        sorted.reserve(indices_.size());
        for (size_t idx : indices_) {
            sorted.push_back(data_[idx]);
        }
        return sorted;
    }
    
    // 获取前N个元素
    std::vector<T> get_top(size_t n) const {
        std::vector<T> top;
        n = std::min(n, indices_.size());
        top.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            top.push_back(data_[indices_[i]]);
        }
        return top;
    }
    
    // 获取原始数据的大小
    size_t size() const {
        return data_.size();
    }
    
    // 根据排序后的索引访问原始元素
    const T& operator[](size_t index) const {
        return data_[indices_[index]];
    }
};

template<typename T, typename ScoreType = double, typename Hash = std::hash<T>, typename Equal = std::equal_to<T>>
class Enhanced_UniqueVector : public Enhanced_SortVector<T, ScoreType> {
public:
    // 使用可调用对象提取特征值，自动推导lambda类型
    template<typename ExtractorFunc>
    void prepare(const std::vector<T>& data, ExtractorFunc extractor, bool greater = true) {
        // 清空旧数据
        this->data_.clear();
        this->indices_.clear();
        
        // 使用unordered_set去重
        std::unordered_set<T, Hash, Equal> unique_items;
        for (const auto& item : data) {
            unique_items.insert(item);
        }
        
        // 存储去重后的数据
        this->data_.assign(unique_items.begin(), unique_items.end());
        
        // 提取特征值
        std::vector<ScoreType> scores;
        scores.reserve(this->data_.size());
        for (const auto& item : this->data_) {
            scores.push_back(extractor(item));
        }
        
        // 创建索引并排序
        this->indices_.resize(this->data_.size());
        std::iota(this->indices_.begin(), this->indices_.end(), 0);
        
        if (greater) {
            // 默认从大到小排序
            std::sort(this->indices_.begin(), this->indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] > scores[b]; });
        } else {
            // 从小到大排序
            std::sort(this->indices_.begin(), this->indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] < scores[b]; });
        }
    }
};

template<typename T, typename ScoreType = double, typename Hash = std::hash<T>, typename Equal = std::equal_to<T>>
class Enhanced_HistogramVector : public Enhanced_SortVector<T, ScoreType> {
private:
    std::vector<size_t> histogram_;  // 存储每个元素的出现次数

public:
    // 使用可调用对象提取特征值
    template<typename ExtractorFunc>
    void prepare(const std::vector<T>& data, ExtractorFunc extractor, bool greater = true) {
        // 清空旧数据
        this->data_.clear();
        this->indices_.clear();
        histogram_.clear();
        
        // 使用unordered_map统计频次
        std::unordered_map<T, size_t, Hash, Equal> item_count;
        for (const auto& item : data) {
            item_count[item]++;
        }
        
        // 存储去重后的数据
        this->data_.reserve(item_count.size());
        for (const auto& [item, count] : item_count) {
            this->data_.push_back(item);
            histogram_.push_back(count);
        }
        
        // 提取特征值
        std::vector<ScoreType> scores;
        scores.reserve(this->data_.size());
        for (const auto& item : this->data_) {
            scores.push_back(extractor(item));
        }
        
        // 创建索引并排序
        this->indices_.resize(this->data_.size());
        std::iota(this->indices_.begin(), this->indices_.end(), 0);
        
        if (greater) {
            // 默认从大到小排序
            std::sort(this->indices_.begin(), this->indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] > scores[b]; });
        } else {
            // 从小到大排序
            std::sort(this->indices_.begin(), this->indices_.end(), 
                [&scores](size_t a, size_t b) { return scores[a] < scores[b]; });
        }
    }
    
    // 获取元素的频次
    size_t get_count(size_t sorted_index) const {
        return histogram_[this->indices_[sorted_index]];
    }
    
    // 获取排序后的频次列表
    std::vector<size_t> get_sorted_histogram() const {
        std::vector<size_t> sorted_histogram;
        sorted_histogram.reserve(this->indices_.size());
        for (size_t idx : this->indices_) {
            sorted_histogram.push_back(histogram_[idx]);
        }
        return sorted_histogram;
    }
};

//==============================================================================
// 版本4：最精简版核心类 (继承式设计)
//==============================================================================

template<typename T, typename F>
class SortVector {
protected:
    vector<T> data;        // 原始数据
    vector<size_t> indices; // 排序索引
    F key_func;            // 特征提取函数
    bool prepared = false; // 是否已排序
    
public:
    SortVector(F f) : key_func(f) {}
    
    // 添加新元素
    void push(const T& x) { 
        data.push_back(x); 
        prepared = false; 
    }
    
    // 准备排序，惰性计算
    virtual void prepare() { 
        if(prepared) return;
        
        indices.resize(data.size());
        iota(indices.begin(), indices.end(), 0);
        
        // 按特征值从大到小排序
        sort(indices.begin(), indices.end(), [this](size_t i, size_t j) { 
            return key_func(data[i]) > key_func(data[j]); 
        });
        
        prepared = true;
    }
    
    // 获取排序后位置的元素
    virtual const T& at(size_t pos) { 
        prepare(); 
        return data[indices[pos]]; 
    }
    
    // 获取容器大小
    virtual size_t size() const { 
        return data.size(); 
    }
    
    // 插入多个元素
    template<typename Iter>
    void insert(Iter first, Iter last) {
        data.insert(data.end(), first, last);
        prepared = false;
    }
    
    // 获取前k个元素
    virtual vector<T> top_k(size_t k) {
        prepare();
        vector<T> result;
        k = min(k, indices.size());
        for(size_t i = 0; i < k; i++)
            result.push_back(data[indices[i]]);
        return result;
    }
};

template<typename T, typename F>
class UniqueVector : public SortVector<T, F> {
private:
    unordered_set<T> unique_set;
    vector<size_t> unique_indices;
    
public:
    using SortVector<T, F>::SortVector;
    
    // 重写prepare实现去重功能
    void prepare() override {
        if(this->prepared) return;
        
        // 先构建唯一值集合
        unique_set.clear();
        unique_indices.clear();
        
        for(size_t i = 0; i < this->data.size(); i++) {
            if(unique_set.insert(this->data[i]).second) {
                unique_indices.push_back(i);
            }
        }
        
        // 对唯一元素索引排序
        sort(unique_indices.begin(), unique_indices.end(), [this](size_t i, size_t j) {
            return this->key_func(this->data[i]) > this->key_func(this->data[j]);
        });
        
        this->prepared = true;
    }
    
    // 获取排序后位置的元素
    const T& at(size_t pos) override {
        prepare();
        return this->data[unique_indices[pos]];
    }
    
    // 获取去重后的大小
    size_t size() override {
        prepare();
        return unique_indices.size();
    }
    
    // 获取前k个元素
    vector<T> top_k(size_t k) override {
        prepare();
        vector<T> result;
        k = min(k, unique_indices.size());
        for(size_t i = 0; i < k; i++)
            result.push_back(this->data[unique_indices[i]]);
        return result;
    }
};

//==============================================================================
// 工厂函数：为所有版本提供统一的创建接口
//==============================================================================

// V1版本工厂函数
template<typename T, typename F>
Normal_SortVector_V1<T, F> V1_Vector(F key_func) {
    return Normal_SortVector_V1<T, F>(key_func);
}

template<typename T, typename F>
Unique_SortVector_V1<T, F> V1_UniqueVector(F key_func) {
    return Unique_SortVector_V1<T, F>(key_func);
}

// V2版本工厂函数
template<typename T, typename F>
Normal_SortVector_V2<T, F> V2_Vector(F key_func) {
    return Normal_SortVector_V2<T, F>(key_func);
}

template<typename T, typename F>
Unique_SortVector_V2<T, F> V2_UniqueVector(F key_func) {
    return Unique_SortVector_V2<T, F>(key_func);
}

// V3版本工厂函数
template<typename T, typename ScoreType = double>
Enhanced_SortVector<T, ScoreType> V3_Vector() {
    return Enhanced_SortVector<T, ScoreType>();
}

template<typename T, typename ScoreType = double>
Enhanced_UniqueVector<T, ScoreType> V3_UniqueVector() {
    return Enhanced_UniqueVector<T, ScoreType>();
}

template<typename T, typename ScoreType = double>
Enhanced_HistogramVector<T, ScoreType> V3_HistogramVector() {
    return Enhanced_HistogramVector<T, ScoreType>();
}

// V4版本工厂函数（最精简版）
template<typename T, typename F>
SortVector<T, F> _Vector(F key_func) {
    return SortVector<T, F>(key_func);
}

template<typename T, typename F>
UniqueVector<T, F> _UniqueVector(F key_func) {
    return UniqueVector<T, F>(key_func);
}

} // namespace sort_vector

//==============================================================================
// 使用示例
//==============================================================================

/*
// 使用V1版本
auto v1 = sort_vector::V1_Vector<int>([](const int& x){ return -x; });
v1.push(5); v1.push(3); v1.push(7);
cout << v1.at(0) << endl; // 输出7

// 使用V2版本
auto v2 = sort_vector::V2_Vector<int>([](const int& x){ return -x; });
v2.push(5); v2.push(3); v2.push(7);
v2.prepare();
cout << v2.at(0) << endl; // 输出7

// 使用V3版本
auto v3 = sort_vector::V3_Vector<int>();
vector<int> data = {5, 3, 7};
v3.prepare(data, [](const int& x){ return -x; });
cout << v3[0] << endl; // 输出7

// 使用V4版本（最精简）
auto v4 = sort_vector::_Vector<int>([](const int& x){ return -x; });
v4.push(5); v4.push(3); v4.push(7);
cout << v4.at(0) << endl; // 输出7
*/