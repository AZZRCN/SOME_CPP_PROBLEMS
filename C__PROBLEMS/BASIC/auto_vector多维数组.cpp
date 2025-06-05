#include <vector>
#include <stdexcept>
#include <iostream>
#include <numeric>
#include <cstdint>

// =================== V1 原始递归模板版本 ===================
template<size_t degs>
class auto_vector {
private:
    std::vector<auto_vector<degs-1>> data;
public:
    void malloc(const std::vector<int>& dims) {
        if (dims.size() != degs) throw std::runtime_error("Dim mismatch");
        data.resize(dims[0]);
        std::vector<int> next(dims.begin()+1, dims.end());
        for(auto& v : data) v.malloc(next);
    }
    
    auto_vector<degs-1>& operator[](size_t idx) {
        if(idx >= data.size()) throw std::out_of_range("Index overflow");
        return data[idx];
    }
};

template<>
class auto_vector<1> {
private:
    std::vector<int> data;
public:
    void malloc(const std::vector<int>& dims) {
        if(dims.size() != 1) throw std::runtime_error("Dim mismatch");
        data.resize(dims[0]);
    }
    
    int& operator[](size_t idx) {
        if(idx >= data.size()) throw std::out_of_range("Index overflow");
        return data[idx];
    }
};

// =================== V2 完整功能版本 ===================
template <typename T, size_t NDims>
class auto_array_v2 {
private:
    std::vector<T> data;
    std::vector<size_t> dims;
    
    size_t index(const std::vector<size_t>& pos) const {
        size_t idx = 0, stride = 1;
        for(size_t i=0; i < NDims; ++i) {
            if(pos[i] >= dims[i]) throw std::out_of_range("Index error");
            idx += pos[i] * stride;
            stride *= dims[i];
        }
        return idx;
    }

public:
    template<typename... Args>
    explicit auto_array_v2(Args... args) : dims{size_t(args)...} {
        static_assert(sizeof...(args) == NDims, "Dim count mismatch");
        data.resize(std::accumulate(dims.begin(), dims.end(), 1, 
            std::multiplies<size_t>()));
    }
    
    T& operator()(const std::vector<size_t>& pos) { return data[index(pos)]; }
    template<typename... Args>
    T& operator()(Args... args) {
        return data[index({size_t(args)...})];
    }
};

// =================== V3 简洁版本 ===================
template <typename T, size_t N>
class auto_array_v3 {
    std::vector<T> data;
    std::vector<size_t> dims;
    
    size_t idx(const std::vector<size_t>& pos) const {
        size_t i = 0, s = 1;
        for(size_t n=0; n < N; ++n) {
            if(pos[n] >= dims[n]) throw std::out_of_range("Out of bounds");
            i += pos[n] * s;
            s *= dims[n];
        }
        return i;
    }

public:
    template<typename... Args>
    explicit auto_array_v3(Args... args) : dims{size_t(args)...} {
        data.resize(std::accumulate(dims.begin(), dims.end(), 1, 
            std::multiplies<size_t>()));
    }
    
    T& operator[](const std::vector<size_t>& pos) { return data[idx(pos)]; }
};

// =================== V4 迭代器优化版 ===================
template <typename T, size_t N>
class auto_array_v4 {
    std::vector<T> data;
    std::vector<size_t> dims;
    
    size_t calc(const std::vector<size_t>& p) const {
        size_t i=0, s=1;
        for(size_t n=0; n<N; ++n) {
            if(p[n] >= dims[n]) throw std::out_of_range("Access error");
            i += p[n] * s;
            s *= dims[n];
        }
        return i;
    }

public:
    template<typename... Args>
    explicit auto_array_v4(Args... args) : dims{size_t(args)...} {
        data.resize(std::accumulate(dims.begin(), dims.end(), 1, 
            std::multiplies<size_t>()));
    }
    
    T& operator[](const std::vector<size_t>& p) { return data[calc(p)]; }

    // 扁平迭代器实现
    class iterator {
        size_t pos = 0;
        const auto_array_v4* arr;
    public:
        iterator(const auto_array_v4* a, size_t p = 0) : arr(a), pos(p) {}
        T& operator*() { return arr->data[pos]; }
        iterator& operator++() { ++pos; return *this; }
        bool operator!=(const iterator& o) const { return pos != o.pos; }
    };
    
    iterator begin() const { return {this}; }
    iterator end() const { return {this, data.size()}; }
};

// =================== V5 极简压缩版 ===================
template <typename T, uint8_t N>
struct auto_array_v5 {
    using dim_t = int32_t;
    std::vector<T> data;
    std::vector<dim_t> dims;
    
    void init(const std::vector<dim_t>& d) {
        dims = d;
        data.resize(std::accumulate(dims.begin(), dims.end(), 1, 
            std::multiplies<dim_t>()));
    }
    
    T& get(const std::vector<dim_t>& p) {
        uint32_t idx = 0, s = 1;
        for(uint8_t i=0; i<N; ++i) {
            idx += p[i] * s;
            s *= dims[i];
        }
        return data[idx];
    }
};

// =================== 使用示例 ===================
int main() {
    // V1 使用示例
    auto_vector<3> v1; v1.malloc({2,3,4});
    v1[0][1][2] = 42;
    
    // V2 使用示例
    auto_array_v2<int, 3> v2(2,3,4);
    v2({0,1,2}) = 42;
    v2(0,1,2) = 42;
    
    // V3 使用示例
    auto_array_v3<int, 3> v3(2,3,4);
    v3[{0,1,2}] = 42;
    
    // V4 使用示例
    auto_array_v4<int, 3> v4(2,3,4);
    for(auto v : v4) v = 42;
    
    // V5 使用示例
    auto_array_v5<int, 3> v5;
    v5.init({2,3,4});
    v5.get({0,1,2}) = 42;

    return 0;
}


#include <vector>
#include <numeric>
#include <stdexcept>

template <typename T, uint8_t N>
struct auto_array_v5_qwen {
    using dim_t = int32_t;
    std::vector<T> data;
    std::vector<dim_t> dims;

    void init(const std::vector<dim_t>& d) {
        if (d.size() != N)
            throw std::invalid_argument("Dimension size mismatch");
        dims = d;
        data.resize(std::accumulate(dims.begin(), dims.end(), 1, std::multiplies<dim_t>()));
    }

    T& get(const std::vector<dim_t>& p) {
        if (p.size() != N)
            throw std::invalid_argument("Index dimension mismatch");
        uint32_t idx = 0, s = 1;
        for (uint8_t i = 0; i < N; ++i) {
            if (p[i] < 0 || p[i] >= dims[i])
                throw std::out_of_range("Index out of bounds");
            idx += p[i] * s;
            s *= dims[i];
        }
        return data[idx];
    }

    const T& get(const std::vector<dim_t>& p) const {
        if (p.size() != N)
            throw std::invalid_argument("Index dimension mismatch");
        uint32_t idx = 0, s = 1;
        for (uint8_t i = 0; i < N; ++i) {
            if (p[i] < 0 || p[i] >= dims[i])
                throw std::out_of_range("Index out of bounds");
            idx += p[i] * s;
            s *= dims[i];
        }
        return data[idx];
    }
};