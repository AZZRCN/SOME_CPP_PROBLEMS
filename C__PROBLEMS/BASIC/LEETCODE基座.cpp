#include <bits/stdc++.h>
using namespace std;
#ifndef __fastcall
#define __fastcall __attribute__((__fastcall__))
#define __forceinline inline __attribute__((__always_inline__))
#endif
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};