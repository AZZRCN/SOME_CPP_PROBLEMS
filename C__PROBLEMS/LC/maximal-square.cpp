#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int so(vector<vector<int>>& grid) {
    //     int ret = grid[0][0];
    //     const int width = grid[0].size();
    //     const int height = grid.size();
    //     for(int i = 1; i < width; i++){
    //         if(grid[0][i]){
    //             ret = max(ret,grid[0][i]);
    //         }
    //     }
    //     for(int i = 1; i < height; i++){
    //         if(grid[i][0]){
    //             ret = max(ret,grid[i][0]);
    //         }
    //     }
    //     for(int i = 1; i < height; i++){
    //         for(int j = 1; j < width; j++){
    //             if(grid[i][j]){
    //                 grid[i][j] = min(grid[i][j-1],grid[i-1][j]) + 1;
    //                 ret = max(ret,grid[i][j]);
    //             }
    //         }
    //     }
    //     return ret*ret;
    // }
    // int maximalSquare(vector<vector<char>>& grid){
    //     const int width = grid[0].size();
    //     const int height = grid.size();
    //     vector<vector<int>>v;
    //     for(int i = 0; i < height; i++){
    //         v.push_back(vector<int>());
    //         for(int j = 0; j < width; j++){
    //             v[i].push_back(grid[i][j]-'0');
    //         }
    //     }
    //     return so(v);
    // }
};
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/maximal-square/solutions/234964/zui-da-zheng-fang-xing-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。