#include <bits/stdc++.h>
using namespace std;

using namespace std;
using ull = unsigned long long;

class HighPrecisionMatrix {
public:
    static constexpr ull BASE = 1'000'000'000; // 10^9进制
    static constexpr int BASE_DIGITS = 9;

    // 核心乘法逻辑（矩阵法）
    static vector<ull> matrix_style_multiply(const vector<ull>& a,
                                        const vector<ull>& b) {
        const size_t m = a.size(), n = b.size();
        vector<ull> res;

        // 矩阵乘法累加
        for(size_t i=0; i<m; ++i) {
            for(size_t j=0; j<n; ++j) {
                const size_t pos = i + j;
                if(pos >= res.size()) res.resize(pos+2, 0);
                res[pos] += a[i] * b[j];
            }
        }

        // 统一进位处理
        for(size_t k=0; k<res.size(); ++k) {
            if(res[k] >= BASE) {
                if(k+1 >= res.size()) res.push_back(0);
                res[k+1] += res[k]/BASE;
                res[k] %= BASE;
            }
        }

        // 安全截断前导零
        size_t last_non_zero = res.empty() ? 0 : res.size()-1;
        while(last_non_zero > 0 && res[last_non_zero] == 0)
            last_non_zero--;
        res.resize(last_non_zero+1);

        return res.empty() ? vector<ull>{0} : res;
    }
    // 实用工具函数：字符串转大数
    static vector<ull> str_to_bigint(const string& s) {
        vector<ull> res;
        for(int i=s.size(); i>0; i-=BASE_DIGITS) {
            const int start = max(i-BASE_DIGITS, 0);
            res.push_back(stoull(s.substr(start, i-start)));
        }
        return res;
    }

    // 实用工具函数：大数转字符串
    static string bigint_to_str(const vector<ull>& num) {
        stringstream ss;
        ss << (num.empty() ? 0 : num.back());
        for(int i=num.size()-2; i>=0; --i) {
            ss << setw(BASE_DIGITS) << setfill('0') << num[i];
        }
        return ss.str();
    }
};

/* 使用示例 */
int main() {
    // 解析大数
    // __gnu_cxx::new_allocator<_Tp>::deallocate
    auto a = HighPrecisionMatrix::str_to_bigint("123456789123456789");
    auto b = HighPrecisionMatrix::str_to_bigint("987654321987654321");
    
    // 执行矩阵式乘法
    auto result = HighPrecisionMatrix::matrix_style_multiply(a, b);
    
    // 输出结果
    cout << HighPrecisionMatrix::bigint_to_str(result) << endl;
    // 输出：121932631356500531347203169112635269
}