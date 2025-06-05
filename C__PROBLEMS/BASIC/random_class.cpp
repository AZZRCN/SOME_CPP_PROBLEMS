#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <stdexcept>

class Rand {
private:
    std::mt19937_64 gen;

public:
    // 构造函数必须传入种子
    explicit Rand(uint64_t seed) : gen(seed) {}

    // 整数范围 [a, b]
    int32_t Int32(int32_t a = 0, int32_t b = INT32_MAX) {
        return std::uniform_int_distribution<int32_t>(a, b)(gen);
    }

    int64_t Int64(int64_t a = 0, int64_t b = INT64_MAX) {
        return std::uniform_int_distribution<int64_t>(a, b)(gen);
    }

    // 浮点数
    float Float() {
        return std::uniform_real_distribution<float>(0.0f, 1.0f)(gen);
    }

    double Double() {
        return std::uniform_real_distribution<double>(0.0, 1.0)(gen);
    }

    double Real(double a, double b) {
        return std::uniform_real_distribution<>(a, b)(gen);
    }

    // 布尔值
    bool Bool(double p = 0.5) {
        return std::bernoulli_distribution(p)(gen);
    }

    // 字符串
    std::string String(size_t len = 8,
                       const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
        std::string result;
        std::uniform_int_distribution<> dist(0, charset.size() - 1);
        for (size_t i = 0; i < len; ++i)
            result += charset[dist(gen)];
        return result;
    }

    // 向量 & 矩阵
    std::vector<int> VectorInt(size_t size, int min_val = 0, int max_val = 100) {
        std::vector<int> result(size);
        std::uniform_int_distribution<> dist(min_val, max_val);
        for (size_t i = 0; i < size; ++i)
            result[i] = dist(gen);
        return result;
    }

    std::vector<double> VectorDouble(size_t size, double min_val = 0.0, double max_val = 1.0) {
        std::vector<double> result(size);
        std::uniform_real_distribution<> dist(min_val, max_val);
        for (size_t i = 0; i < size; ++i)
            result[i] = dist(gen);
        return result;
    }

    std::vector<std::vector<int>> MatrixInt(size_t rows, size_t cols, int min_val = 0, int max_val = 100) {
        std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
        std::uniform_int_distribution<> dist(min_val, max_val);
        for (auto& row : result)
            for (auto& val : row)
                val = dist(gen);
        return result;
    }

    // 正态分布
    double Normal(double mean = 0.0, double stddev = 1.0) {
        return std::normal_distribution<>(mean, stddev)(gen);
    }

    // 指数分布
    double Exponential(double lambda = 1.0) {
        return std::exponential_distribution<>(lambda)(gen);
    }

    // 打乱容器
    template<typename T>
    void Shuffle(std::vector<T>& vec) const {
        std::shuffle(vec.begin(), vec.end(), gen);
    }

    // 随机选一个元素
    template<typename T>
    const T& Choice(const std::vector<T>& vec) {
        if (vec.empty()) throw std::invalid_argument("Choice from empty vector");
        return vec[Int32(0, (int)vec.size() - 1)];
    }

    // 抽取 N 个不重复元素
    template<typename T>
    std::vector<T> Sample(const std::vector<T>& vec, size_t n) {
        if (n > vec.size()) throw std::invalid_argument("Sample size exceeds population");

        std::vector<T> copy = vec;
        std::shuffle(copy.begin(), copy.end(), gen);
        return std::vector<T>(copy.begin(), copy.begin() + n);
    }

    // 权重采样（按权重选择索引）
    int WeightedChoice(const std::vector<double>& weights) {
        std::discrete_distribution<> dist(weights.begin(), weights.end());
        return dist(gen);
    }

    // 排列
    std::vector<int> Permutation(int n) {
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = i;
        Shuffle(res);
        return res;
    }
};