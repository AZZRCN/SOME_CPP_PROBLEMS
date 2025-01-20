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
// #include "AVL.cpp"
using namespace std;
class Solution {
public:
    size_t minTimeToType(string word) {
        size_t ans = 0;
        char p = 'a';
        for(char target:word){
            ans += min(abs(target-p),26-abs(target-p));
            p = target;
        }
        return ans+word.size();
        //ABCDEFGHIJKLM
        //NOPQRSTUVWXYZ
    }
};