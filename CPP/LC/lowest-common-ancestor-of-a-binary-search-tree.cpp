#define private public
#define protected public
#ifndef NULL
#define NULL 0
#endif
#ifndef __forceinline
#define __forceinline inline __attribute__((__always_inline__))
#endif
#define TREE
// #define LIST
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
// #include "AVL.cpp"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*p, TreeNode*q) {
        if(p->val>q->val){swap(p,q);}
        start:
        if(root->val<p->val){
            root = root->right;
            goto start;
        }
        if(root->val>q->val){
            root = root->left;
            goto start;
        }
        return root;
    }
};