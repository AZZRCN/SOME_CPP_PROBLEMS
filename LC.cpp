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
template<typename a,typename b,typename c>
class pair_3{
    public:
    a first;
    b second;
    c third;
    __forceinline pair_3(a o1,b o2,c o3){
        first = o1;
        second = o2;
        third = o3;
    }
};
template<int size>
class Darr{
    public:
    int d[size+1];
    int data[size+1];
    void init(){
        
    }
};
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
    }
};