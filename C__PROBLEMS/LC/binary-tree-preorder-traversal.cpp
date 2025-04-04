
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> ans;
    void f(TreeNode* p){
        ans.push_back(p->val);
        if(p->left!=nullptr){
            f(p->left);
        }
        if(p->right!=nullptr){
            f(p->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root!=nullptr)f(root);
        return ans;
    }
};