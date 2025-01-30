#include <iostream>
using namespace std;
// 计算前导零的数量
constexpr int rcount0(int n) {
    int ret = 0;
    if (n & 0xffff0000) { ret += 16; n >>= 16; }
    if (n & 0xff00) { ret += 8; n >>= 8; }
    if (n & 0xf0) { ret += 4; n >>= 4; }
    if (n & 0xc) { ret += 2; n >>= 2; }
    if (n & 0x2) { ret += 1; n >>= 1; }
    if (n & 0x1) { ret += 1; n >>= 1; }
    return ret;
}

// Sparse Table
template <int data_size>
class ST {
public:
    static constexpr int lowest = rcount0(data_size) - 1;  // 最低层级
    static constexpr int limit_cur = data_size - 1;  // 数据限制

    int data[lowest + 1][data_size];  // 数据存储
    int data_cur = 0;  // 当前数据索引

    // 插入数据
    void operator<<(const int& _val) {
        data[lowest][data_cur++] = _val;
    }

    // 构建Sparse Table
    void build() {
        int level = lowest - 1;
        for (int limit = 1; level >= 0; (limit <<= 1), (level--)) {
            for (int i = 0; i < data_size - limit; i++) {
                if (i + limit < data_size) {
                    data[level][i] = std::max(data[level + 1][i], data[level + 1][i + limit]);
                }
            }
        }
    }

    // 打印Sparse Table
    void print() {
        for (int i = 0; i <= lowest; i++) {
            for (int j = 0; j < data_size - (1 << i); j++) {
                printf("%d ", data[lowest-i][j]);
            }
            printf("\n");
        }
    }

    // 查询区间最大值
    int query(int l, int r) {
        int level = lowest;
        int limit = 1;
        while (level >= 0 && limit <= r - l) {
            level--;
            limit <<= 1;
        }
        return std::max(data[level][l], data[level][r - limit + 1]);
    }
};
ST<8> st;
int main(){
    for(int i = 1; i <= 7; i++){
        st<<i;
    }
    st.build();
    st.print();
}