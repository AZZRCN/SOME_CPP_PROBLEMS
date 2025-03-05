#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int width = grid[0].size();
        const int height = grid.size();
        for(int i = 1; i < width; i++){
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1; i < height; i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < height; i++){
            for(int j = 1; j < width; j++){
                grid[i][j] += min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[height-1][width-1];
    }
};