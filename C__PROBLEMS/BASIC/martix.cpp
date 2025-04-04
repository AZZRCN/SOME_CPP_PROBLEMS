#include <array>
#include <stdexcept>

template<size_t M, size_t N>
struct MatrixSize { 
    static constexpr size_t rows = M;
    static constexpr size_t cols = N;
};

template<typename T, size_t M, size_t N>
class Matrix {
private:
    std::array<std::array<T, N>, M> data;
    
    template<size_t P>
    static constexpr size_t __min(size_t a, size_t b) {
        return a < b ? a : b;
    }

public:
    // 构造函数
    Matrix() = default;
    
    Matrix(std::initializer_list<std::initializer_list<T>> list) {
        size_t i = 0;
        for (auto& row : list) {
            size_t j = 0;
            for (auto& val : row) {
                if (i < M && j < N) data[i][j] = val;
                ++j;
            }
            ++i;
        }
    }

    // 矩阵乘法（编译期维度检查）
    template<size_t P>
    Matrix<T, M, P> operator*(const Matrix<T, N, P>& rhs) const {
        Matrix<T, M, P> result;
        for (size_t i = 0; i < M; ++i) {
            for (size_t k = 0; k < N; ++k) {
                for (size_t j = 0; j < P; ++j) {
                    result[i][j] += data[i][k] * rhs[k][j];
                }
            }
        }
        return result;
    }

    // 快速幂（仅限方阵）
    template<size_t K = M>
    requires(K == N)
    Matrix<T, M, N> pow(uint64_t exponent) const {
        Matrix<T, M, N> result = identity();
        Matrix<T, M, N> base = *this;
        while (exponent > 0) {
            if (exponent & 1) result = result * base;
            base = base * base;
            exponent >>= 1;
        }
        return result;
    }

    // 生成单位阵
    static Matrix<T, M, N> identity() requires(M == N) {
        Matrix<T, M, N> mat;
        for (size_t i = 0; i < __min(M, N); ++i) {
            mat[i][i] = T(1);
        }
        return mat;
    }

    // 元素访问
    auto& operator[](size_t i) { return data[i]; }
    const auto& operator[](size_t i) const { return data[i]; }

    // 类型转换
    template<size_t P, size_t Q>
    operator Matrix<T, P, Q>() const {
        Matrix<T, P, Q> result;
        for (size_t i = 0; i < __min(M, P); ++i) {
            for (size_t j = 0; j < __min(N, Q); ++j) {
                result[i][j] = data[i][j];
            }
        }
        return result;
    }
};

/* 使用示例 */
int main() {
    // 定义3x3矩阵
    Matrix<int, 3, 3> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // 矩阵快速幂
    auto pow_mat = mat.pow(3);
    
    // 矩阵乘法（自动推导尺寸）
    Matrix<int, 3, 2> m1 = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    Matrix<int, 2, 4> m2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };
    
    auto m3 = m1 * m2; // 结果类型为Matrix<int, 3, 4>
}