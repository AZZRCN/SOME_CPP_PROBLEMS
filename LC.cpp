#define private public
#define protected public
#ifndef NULL
#define NULL 0
#endif
#ifndef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
#ifdef TREE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
#ifdef LIST
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <map>
#include <set>
#include <bitset>
// #include <windows.h>
using namespace std;
#include <cstdint>
#include <iostream>

struct int128 {
    int64_t high;
    int64_t low;

    // 构造函数
    int128() : high(0), low(0) {}
    int128(int64_t high, int64_t low) : high(high), low(low) {}

    // 运算符重载
    int128 operator+(const int128& other) const {
        int128 result;
        result.low = low + other.low;
        result.high = high + other.high + (result.low < low);
        return result;
    }

    int128 operator-(const int128& other) const {
        int128 result;
        result.low = low - other.low;
        result.high = high - other.high - (result.low > low);
        return result;
    }

    int128 operator*(const int128& other) const {
        int128 result;
        result.low = low * other.low;
        result.high = high * other.low + low * other.high + (result.low >> 63);
        return result;
    }

    int128 operator/(const int128& other) const {
        int128 result;
        result.low = low / other.low;
        result.high = high / other.low + (low % other.low != 0);
        return result;
    }

    int128 operator%(const int128& other) const {
        int128 result;
        result.low = low % other.low;
        result.high = high % other.low;
        return result;
    }

    int128 operator<<(const int64_t& shift) const {
        int128 result;
        result.low = low << shift;
        result.high = high << shift | (low >> (64 - shift));
        return result;
    }

    int128 operator>>(const int64_t& shift) const {
        int128 result;
        result.low = low >> shift | (high << (64 - shift));
        result.high = high >> shift;
        return result;
    }

    // 输出运算符重载
    friend std::ostream& operator<<(std::ostream& os, const int128& num) {
        os << num.high << " " << num.low;
        return os;
    }
};
int main(){
    int128 n(1,1);
    cout << n;
    n = n*n;
    cout << n;
}