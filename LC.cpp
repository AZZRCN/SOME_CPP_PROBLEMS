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
using namespace std;
int main(){
    // puts("/**\n * Definition for a binary tree node.\n * struct TreeNode {\n *     int val;\n *     TreeNode *left;\n *     TreeNode *right;\n *     TreeNode() : val(0), left(nullptr), right(nullptr) {}\n *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}\n *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}\n * };\n */\nclass BSTIterator {\npublic:\n    BSTIterator(TreeNode* root) {\n        \n    }\n    \n    int next() {\n        \n    }\n    \n    bool hasNext() {\n        \n    }\n};\n\n/**\n * Your BSTIterator object will be instantiated and called as such:\n * BSTIterator* obj = new BSTIterator(root);\n * int param_1 = obj->next();\n * bool param_2 = obj->hasNext();\n */");
    // string str;
    // vector<string> out;
    // while((getline(cin,str),str!="exit")){
    //     if((str[0]=='/'||str[0]==' ')&&str[1]=='*'){
    //         out .push_back( str.substr(min(3ULL,str.size())));
    //     }
    //     else{
    //         out.push_back(str);
    //     }
    // }
    // for(string i:out){
    //     cout << i << endl;
    // }
    // throw out_of_range("ABC");
    vector<int> v;
}