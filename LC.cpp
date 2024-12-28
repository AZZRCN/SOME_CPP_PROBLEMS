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
// template <typename T>
// std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
//     os << "{";
//     const size_t en = vec.size();
//     for(int i = 0; i < en; i++){
//         cout << vec[i];
//         if(i+1<en){
//             cout << ',';
//         }
//     }
//     os << "}";
//     return os;
// }
class Solution {
public:
    string toLowerCase(string s) {
        for(char&c :s){
            c |= 32;
        }
        return s;
    }
};
// template <typename t1,typename t2>
// std::ostream& operator<<(std::ostream& os, const std::map<t1,t2>& mp) {
//     os << "{";
//     int pos = 0;
//     const int en = mp.size();
//     for(pair<t1,t2> i:mp){
//         cout << "{" << i.first << "," << i.second << "}";
//         if(pos + 1 < en){
//             pos++;
//             cout << ",\n";
//         }
//     }
//     os << "}";
//     return os;
// }