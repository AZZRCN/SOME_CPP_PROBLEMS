#include <utility>
#include <algorithm>
#ifndef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
template <typename WT, typename VT>
class Backpack {
// private:
public:
    struct Item {
        WT weight;
        VT value;
        __forceinline Item(const WT& w, const VT& v) 
            : weight(w), value(v) {}
    };

    const Item* items;
    int item_count;
    WT* quantities; // 仅用于多重背包

    __forceinline void zero_one(const WT& cap, VT* dp) const {
        for (int i = 0; i < item_count; ++i) {
            const WT& w = items[i].weight;
            const VT& v = items[i].value;
            for (WT j = cap; j >= w; --j) {
                dp[j] = std::max(dp[j], dp[j - w] + v);
            }
        }
    }

    __forceinline void unbounded(const WT& cap, VT* dp) const {
        for (WT j = 1; j <= cap; ++j) {
            for (int i = 0; i < item_count; ++i) {
                if (j >= items[i].weight) {
                    dp[j] = std::max(dp[j], 
                        dp[j - items[i].weight] + items[i].value);
                }
            }
        }
    }

    __forceinline void multi_knap(const WT& cap, VT* dp) const {
        for (int i = 0; i < item_count; ++i) {
            WT w_base = items[i].weight;
            VT v_base = items[i].value;
            int cnt = static_cast<int>(quantities[i]);

            for (int k = 1; cnt > 0; k <<= 1) {
                int amount = std::min(k, cnt);
                WT w = w_base * amount;
                VT v = v_base * amount;

                for (WT j = cap; j >= w; --j)
                    dp[j] = std::max(dp[j], dp[j - w] + v);

                cnt -= amount;
            }
        }
    }

public:
    // 初始化普通背包
    __forceinline Backpack(const std::pair<WT, VT>* ptr, int cnt)
        : items(reinterpret_cast<const Item*>(ptr)), 
          item_count(cnt), quantities(nullptr) {}

    // 初始化多重背包
    __forceinline Backpack(const std::pair<WT, VT>* ptr, 
                          const WT* quant, int cnt)
        : items(reinterpret_cast<const Item*>(ptr)), 
          item_count(cnt), quantities(const_cast<WT*>(quant)) {}

    __forceinline VT solve_zero_one(const WT& capacity) const {
        VT* dp = new VT[capacity + 1]{};
        zero_one(capacity, dp);
        VT result = dp[capacity];
        delete[] dp;
        return result;
    }

    __forceinline VT solve_unbounded(const WT& capacity) const {
        VT* dp = new VT[capacity + 1]{};
        unbounded(capacity, dp);
        VT result = dp[capacity];
        delete[] dp;
        return result;
    }

    __forceinline VT solve_multi(const WT& capacity) const {
        VT* dp = new VT[capacity + 1]{};
        multi_knap(capacity, dp);
        VT result = dp[capacity];
        delete[] dp;
        return result;
    }

    // 二维费用背包
    __forceinline static VT solve_2d(
        const std::pair<WT, WT>* items, 
        const VT* values, 
        int count,
        const std::pair<WT, WT>& capacity) 
    {
        VT** dp = new VT*[capacity.first + 1];
        for (WT i = 0; i <= capacity.first; ++i)
            dp[i] = new VT[capacity.second + 1]{};

        for (int k = 0; k < count; ++k) {
            WT w1 = items[k].first;
            WT w2 = items[k].second;
            VT v = values[k];

            for (WT i = capacity.first; i >= w1; --i) {
                for (WT j = capacity.second; j >= w2; --j) {
                    dp[i][j] = std::max(dp[i][j], 
                        dp[i - w1][j - w2] + v);
                }
            }
        }

        VT result = dp[capacity.first][capacity.second];
        for (WT i = 0; i <= capacity.first; ++i)
            delete[] dp[i];
        delete[] dp;
        return result;
    }
};

// // 使用示例
// int example() {
//     // 01背包示例
//     std::pair<int, double> items1[] = {{2, 3.5}, {3, 4.1}};
//     Backpack<int, double> bp1(items1, 2);
//     double max1 = bp1.solve_zero_one(10);

//     // 多重背包示例
//     std::pair<int, int> items2[] = {{3,4}, {2,5}};
//     int quant[] = {2,3};
//     Backpack<int, int> bp2(items2, quant, 2);
//     int max2 = bp2.solve_multi(15);

//     // 二维背包示例
//     std::pair<int, double> items3[] = {{2,1.5}, {3,2.1}};
//     float values[] = {3.2f, 4.5f};
//     auto max3 = Backpack<int, float>::solve_2d(
//         items3, values, 2, {5, 4.0});

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
pair<int,int> is[100];
int main(){
    int limit,n;
    cin >> limit >> n;
    for(int i = 0; i < n; i++){
        cin >> is[i].first >> is[i].second;
    }
    Backpack<int,int> bp(is,n);
    cout << bp.solve_zero_one(limit);
}