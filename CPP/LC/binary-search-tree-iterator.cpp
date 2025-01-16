#include <bits/stdc++.h>
using namespace std;
#ifndef TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif
class BSTIterator {
public:
    vector<int> v;
    int cur = 0;
    BSTIterator(TreeNode* root) {
        init(root);
    }
    void init(TreeNode* p){
        if(p==nullptr){
            return;
        }
        init(p->left);
        v.push_back(p->val);
        init(p->right);
    }
    int next() {
        return v[cur++];
    }
    bool hasNext() {
        return cur<v.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */