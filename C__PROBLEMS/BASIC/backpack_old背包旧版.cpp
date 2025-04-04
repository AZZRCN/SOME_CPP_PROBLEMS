#include <vector>
#include <algorithm>
#include <cmath>

// 基础物品模板
template <typename W, typename V>
struct Item {
    W weight;
    V value;
    Item(W w, V v) : weight(w), value(v) {}
    Item(){}
};

// 多重背包物品特化
template <typename W, typename V>
struct BoundedItem : Item<W,V> {
    int quantity;
    BoundedItem(W w, V v, int q) : Item<W,V>(w,v), quantity(q) {}
};

// 抽象基类
template <typename W, typename V>
class KnapsackSolver {
public:
    virtual V solve(W capacity) = 0;
    virtual ~KnapsackSolver() = default;
};

// 01背包实现
template <typename W, typename V>
class ZeroOneKnapsack : public KnapsackSolver<W,V> {
    std::vector<Item<W,V>> items;
public:
    explicit ZeroOneKnapsack(const std::vector<Item<W,V>>& its) : items(its) {}

    V solve(W capacity) override {
        std::vector<V> dp(capacity + 1, 0);
        for (const auto& item : items) {
            for (W j = capacity; j >= item.weight; --j) {
                dp[j] = std::max(dp[j], dp[j - item.weight] + item.value);
            }
        }
        return dp[capacity];
    }
};

// 完全背包实现
template <typename W, typename V>
class UnboundedKnapsack : public KnapsackSolver<W,V> {
    std::vector<Item<W,V>> items;
public:
    explicit UnboundedKnapsack(const std::vector<Item<W,V>>& its) : items(its) {}

    V solve(W capacity) override {
        std::vector<V> dp(capacity + 1, 0);
        for (W j = 1; j <= capacity; ++j) {
            for (const auto& item : items) {
                if (j >= item.weight) {
                    dp[j] = std::max(dp[j], dp[j - item.weight] + item.value);
                }
            }
        }
        return dp[capacity];
    }
};

// 多重背包实现（二进制优化）
template <typename W, typename V>
class BoundedKnapsack : public KnapsackSolver<W,V> {
    std::vector<BoundedItem<W,V>> items;
public:
    explicit BoundedKnapsack(const std::vector<BoundedItem<W,V>>& its) : items(its) {}

    V solve(W capacity) override {
        // 二进制展开
        std::vector<Item<W,V>> expanded;
        for (const auto& item : items) {
            int k = 1;
            int remain = item.quantity;
            while (k <= remain) {
                expanded.emplace_back(item.weight * k, item.value * k);
                remain -= k;
                k *= 2;
            }
            if (remain > 0) {
                expanded.emplace_back(item.weight * remain, item.value * remain);
            }
        }
        
        // 01背包解法
        ZeroOneKnapsack<W,V> solver(expanded);
        return solver.solve(capacity);
    }
};

// 多维度费用背包
template <typename W1, typename W2, typename V>
class MultiDimensionalKnapsack : public KnapsackSolver<std::pair<W1,W2>,V> {
    std::vector<Item<std::pair<W1,W2>, V>> items;
public:
    explicit MultiDimensionalKnapsack(
        const std::vector<Item<std::pair<W1,W2>, V>>& its) : items(its) {}

    V solve(std::pair<W1,W2> capacity) override {
        std::vector<std::vector<V>> dp(
            capacity.first + 1, 
            std::vector<V>(capacity.second + 1, 0)
        );
        for (const auto& item : items) {
            auto [w1, w2] = item.weight;
            for (int i = capacity.first; i >= w1; --i) {
                for (int j = capacity.second; j >= w2; --j) {
                    dp[i][j] = std::max(dp[i][j], 
                        dp[i - w1][j - w2] + item.value);
                }
            }
        }
        return dp[capacity.first][capacity.second];
    }
};
