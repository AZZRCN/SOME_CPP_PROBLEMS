//ai写的
//但是失败了，不要用
//已通过:https://leetcode.cn/problems/spiral-matrix/submissions/616901090/
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> ans;
        auto &row0 = matrix[0];
        // 将答案直接寄生在 matrix[0] 的末尾
        row0.reserve(row0.size() + matrix.size()*matrix[0].size());
        auto write_ptr = back_inserter(row0); // 指向 matrix[0] 的末尾
        int u = 0, d = matrix.size()-1, l = 0, r = matrix[0].size()-1;
        while (true) {
            for (int i=l; i<=r; ++i){*write_ptr++ = matrix[u][i];}if(++u > d){break;}
            for (int i=u; i<=d; ++i){*write_ptr++ = matrix[i][r];}if(--r < l){break;}
            for (int i=r; i>=l; --i){*write_ptr++ = matrix[d][i];}if(--d < u){break;}
            for (int i=d; i>=u; --i){*write_ptr++ = matrix[i][l];}if(++l > r){break;}
        }
        // 截取 matrix[0] 的原始数据末尾作为结果
        return vector<int>(
            row0.begin() + row0.size() - (ans.size()), 
            row0.end()
        );
    }
};