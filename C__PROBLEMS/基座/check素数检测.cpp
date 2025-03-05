#include <bits/stdc++.h>
using namespace std;
// 快速模乘 (适用64位架构)
inline uint64_t mod_mult(uint64_t a, uint64_t b, uint64_t mod) {
    return uint64_t((__int128)a * b % mod);
}

// 快速模幂
uint64_t mod_pow(uint64_t a, uint64_t exp, uint64_t mod) {
    uint64_t res = 1;
    for (a %= mod; exp; exp >>= 1, a = mod_mult(a, a, mod)) {
        if (exp & 1) res = mod_mult(res, a, mod);
    }
    return res;
}

// 终极素数检测
bool is_prime(uint64_t n) {
    // 处理小数字和偶数
    if (n <= 3) return n > 1;
    if (n % 2 == 0) return false;
    
    // 预处理：快速排除小因子
    const uint64_t small_primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    for (auto p : small_primes) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    
    // 米勒-拉宾确定性测试
    uint64_t d = n - 1;
    unsigned s = 0;
    while (d % 2 == 0) d /= 2, ++s;
    
    const uint64_t a_list[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (auto a : a_list) {
        uint64_t x = mod_pow(a, d, n);
        if (x == 1 || x == n-1) continue;
        
        bool composite = true;
        for (unsigned i = 0; i < s-1; ++i) {
            x = mod_mult(x, x, n);
            if (x == n-1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}
int main(){
    freopen("D:\\out","r",stdin);
    uint64_t i;
    double t;
    cin >> t;
    while(!cin.eof()){
        cin >> i;
        if(!is_prime(i)){
            cout<<i;
            return 0;
        }
    }
    cout <<"successful";
}