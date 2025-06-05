#include <bits/stdc++.h>
using namespace std;
#ifndef __forceinline
#define freopen
#endif
class PrimeFactors {
private:
    std::vector<unsigned long long> factors;

public:
    std::vector<unsigned long long> getFactors(unsigned long long n) {
        assert(n > 0 && "n must be positive!");
        
        factors.clear();
        
        // 处理2的因子
        while (n % 2 == 0) {
            factors.push_back(2);
            n = n / 2;
        }
        
        // 处理其他奇数因子
        for (unsigned long long i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n = n / i;
            }
        }
        
        // 如果n大于2，说明n本身是质数
        if (n > 2) {
            factors.push_back(n);
        }
        
        return factors;
    }
};