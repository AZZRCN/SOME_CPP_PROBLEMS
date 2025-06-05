#include <bits/stdc++.h>
using namespace std;




#include <vector>
#include <algorithm>
using namespace std;

// 01 背包函数
template<typename T = int>
T zero_one_knapsack(const vector<T>& w, const vector<T>& v, T cap) {
    vector<T> dp(cap + 1);
    for(size_t i=0;i<w.size();++i)
        for(T j=cap;j>=w[i];--j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[cap];
}

// 完全背包函数
template<typename T = int>
T unbounded_knapsack(const vector<T>& w, const vector<T>& v, T cap) {
    vector<T> dp(cap + 1);
    for(size_t i=0;i<w.size();++i)
        for(T j=w[i];j<=cap;++j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[cap];
}

// 多重背包函数（暴力法）(还可以的解法)
template<typename T = int>
T bounded_knapsack(const vector<T>& w, const vector<T>& v, const vector<int>& k, T cap) {
    vector<T> dp(cap + 1);
    for(size_t i=0;i<w.size();++i)
        for(T j=cap;j>=w[i];--j)
            for(int cnt=1;cnt<=k[i]&&cnt*w[i]<=j;++cnt)
                dp[j] = max(dp[j], dp[j - cnt*w[i]] + cnt*v[i]);
    return dp[cap];
}


#include<vector>
#include<algorithm>
using namespace std;using vi=vector<int>;
//01
int zok(vi&w,vi&v,int c){vector<int>d(c+1);for(int i=0;i<w.size();++i)
for(int j=c;j>=w[i];--j)d[j]=max(d[j],d[j-w[i]]+v[i]);return d[c];}
//无限制
int ubk(vi&w,vi&v,int c){vector<int>d(c+1);for(int i=0;i<w.size();++i)
for(int j=w[i];j<=c;++j)d[j]=max(d[j],d[j-w[i]]+v[i]);return d[c];}
//限制
int bdk(vi&w,vi&v,vi&k,int c){
vector<int>d(c+1);for(int i=0;i<w.size();++i)
for(int j=c;j>=w[i];--j)
for(int cnt=1;cnt<=k[i]&&cnt*w[i]<=j;++cnt)
d[j]=max(d[j],d[j-cnt*w[i]]+cnt*v[i]);return d[c];}



//最终版

#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// ================== 01 背包 ==================

/**
 * @brief 01 背包 · 普通二维 DP 版本
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 最大总价值
 */
int zero_one_2d(const vi& w, const vi& v, int cap) {
    int n = w.size();
    vvi dp(n + 1, vi(cap + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= cap; ++j)
            if (j >= w[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
    return dp[n][cap];
}

/**
 * @brief 01 背包 · 一维空间优化版
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 最大总价值
 */
int zero_one_1d(const vi& w, const vi& v, int cap) {
    vi dp(cap + 1);
    for (size_t i = 0; i < w.size(); ++i)
        for (int j = cap; j >= w[i]; --j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[cap];
}

/**
 * @brief 01 背包 · 输出具体选中的物品索引
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return pair<最大价值, 选中的物品索引列表>
 */
pair<int, vi> zero_one_path(const vi& w, const vi& v, int cap) {
    int n = w.size();
    vi dp(cap + 1);
    vector<vector<bool>> choose(n, vector<bool>(cap + 1));

    for (int i = 0; i < n; ++i)
        for (int j = cap; j >= w[i]; --j)
            if (dp[j] < dp[j - w[i]] + v[i]) {
                dp[j] = dp[j - w[i]] + v[i];
                choose[i][j] = true;
            }

    int j = cap;
    vi path;
    for (int i = n - 1; i >= 0; --i)
        if (choose[i][j]) {
            j -= w[i];
            path.push_back(i);
        }
    reverse(path.begin(), path.end());
    return {dp[cap], path};
}

/**
 * @brief 01 背包 · 统计恰好装满时的方案数
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 恰好装满的方案数
 */
int zero_one_count(const vi& w, const vi& v, int cap) {
    vi dp(cap + 1);
    dp[0] = 1;
    for (size_t i = 0; i < w.size(); ++i)
        for (int j = cap; j >= w[i]; --j)
            dp[j] += dp[j - w[i]];
    return dp[cap];
}

// ================== 完全背包 ==================

/**
 * @brief 完全背包 · 普通 DP 版本
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 最大总价值
 */
int unbounded_knapsack(const vi& w, const vi& v, int cap) {
    vi dp(cap + 1);
    for (size_t i = 0; i < w.size(); ++i)
        for (int j = w[i]; j <= cap; ++j)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[cap];
}

/**
 * @brief 完全背包 · 严格装满背包
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 最大总价值（若无法装满返回 -1）
 */
int unbounded_strict_full(const vi& w, const vi& v, int cap) {
    vi dp(cap + 1, -1);
    dp[0] = 0;
    for (size_t i = 0; i < w.size(); ++i)
        for (int j = w[i]; j <= cap; ++j)
            if (dp[j - w[i]] != -1)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[cap];
}

/**
 * @brief 完全背包 · 统计装满时的方案数
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param cap 背包容量
 * @return 恰好装满 cap 的方案数
 */
int unbounded_count(const vi& w, const vi& v, int cap) {
    vi dp(cap + 1);
    dp[0] = 1;
    for (size_t i = 0; i < w.size(); ++i)
        for (int j = w[i]; j <= cap; ++j)
            dp[j] += dp[j - w[i]];
    return dp[cap];
}

// ================== 多重背包 ==================

/**
 * @brief 多重背包 · 暴力枚举次数
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param k 每个物品最多选几次
 * @param cap 背包容量
 * @return 最大总价值
 */
int bounded_brute_force(const vi& w, const vi& v, const vector<int>& k, int cap) {
    vi dp(cap + 1);
    for (size_t i = 0; i < w.size(); ++i) {
        for (int j = cap; j >= w[i]; --j) {
            for (int cnt = 1; cnt <= k[i] && cnt * w[i] <= j; ++cnt)
                dp[j] = max(dp[j], dp[j - cnt * w[i]] + cnt * v[i]);
        }
    }
    return dp[cap];
}

/**
 * @brief 多重背包 · 二进制优化法
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param k 每个物品最多选几次
 * @param cap 背包容量
 * @return 最大总价值
 */
int bounded_binary_optimized(const vi& w, const vi& v, const vector<int>& k, int cap) {
    vi dp(cap + 1);
    for (size_t i = 0; i < w.size(); ++i) {
        int cnt = k[i], num = 1;
        while (cnt >= num) {
            int now_w = w[i] * num, now_v = v[i] * num;
            for (int j = cap; j >= now_w; --j)
                dp[j] = max(dp[j], dp[j - now_w] + now_v);
            cnt -= num;
            num <<= 1;
        }
        if (cnt > 0) {
            int now_w = w[i] * cnt, now_v = v[i] * cnt;
            for (int j = cap; j >= now_w; --j)
                dp[j] = max(dp[j], dp[j - now_w] + now_v);
        }
    }
    return dp[cap];
}

/**
 * @brief 多重背包 · 单调队列优化法（O(NW) 高级算法）
 * @param w 物品重量数组
 * @param v 物品价值数组
 * @param k 每个物品最多选几次
 * @param cap 背包容量
 * @return 最大总价值
 */
int bounded_monotonic_queue(const vi& w, const vi& v, const vector<int>& k, int cap) {
    vi dp(cap + 1);

    for (size_t i = 0; i < w.size(); ++i) {
        int weight = w[i], value = v[i], count = k[i];
        for (int r = 0; r < weight; ++r) {
            deque<int> dq;
            for (int j = r; j <= cap; j += weight) {
                int val = dp[j] - (j / weight) * value;
                while (!dq.empty() && val >= dq.back()) dq.pop_back();
                dq.push_back(val);
                if (dq.front() < j - weight * count) dq.pop_front();
                dp[j] = dq.front() + (j / weight) * value;
            }
        }
    }
    return dp[cap];
}