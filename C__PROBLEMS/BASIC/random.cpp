#include <iostream>
#include <vector>
#include <string>
#include <random>

//重要!!
// 全局随机引擎（线程安全可用 thread_local）
thread_local std::mt19937_64 gen(std::random_device{}());

// 设置种子
void set_seed(uint64_t seed) {
    gen.seed(seed);
}












// [a, b] 范围内的 32 位整数
int32_t rand_int32(int32_t a = 0, int32_t b = INT32_MAX) {
    return std::uniform_int_distribution<int32_t>(a, b)(gen);
}

// [a, b] 范围内的 64 位整数
int64_t rand_int64(int64_t a = 0, int64_t b = INT64_MAX) {
    return std::uniform_int_distribution<int64_t>(a, b)(gen);
}

// [0.0, 1.0) 的 float
float rand_float() {
    return std::uniform_real_distribution<float>(0.0f, 1.0f)(gen);
}

// [0.0, 1.0) 的 double
double rand_double() {
    return std::uniform_real_distribution<double>(0.0, 1.0)(gen);
}

// [a, b) 的浮点数
double rand_real(double a, double b) {
    return std::uniform_real_distribution<>(a, b)(gen);
}

// 随机布尔值（概率 p 为 true）
bool rand_bool(double p = 0.5) {
    return std::bernoulli_distribution(p)(gen);
}

// 随机字符串（长度 len，字符集 charset）
std::string rand_string(size_t len = 8,
                        const std::string& charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
    std::string result;
    std::uniform_int_distribution<> dist(0, charset.size() - 1);
    for (size_t i = 0; i < len; ++i)
        result += charset[dist(gen)];
    return result;
}

// 随机 vector<int>
std::vector<int> rand_vector_int(size_t size, int min_val = 0, int max_val = 100) {
    std::vector<int> result(size);
    std::uniform_int_distribution<> dist(min_val, max_val);
    for (size_t i = 0; i < size; ++i)
        result[i] = dist(gen);
    return result;
}

// 随机 vector<double>
std::vector<double> rand_vector_double(size_t size, double min_val = 0.0, double max_val = 1.0) {
    std::vector<double> result(size);
    std::uniform_real_distribution<> dist(min_val, max_val);
    for (size_t i = 0; i < size; ++i)
        result[i] = dist(gen);
    return result;
}

// 随机矩阵 (rows x cols)
std::vector<std::vector<int>> rand_matrix_int(size_t rows, size_t cols, int min_val = 0, int max_val = 100) {
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));
    std::uniform_int_distribution<> dist(min_val, max_val);
    for (auto& row : result)
        for (auto& val : row)
            val = dist(gen);
    return result;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    set_seed(10);
    cout << rand_int32(-10,10);
}