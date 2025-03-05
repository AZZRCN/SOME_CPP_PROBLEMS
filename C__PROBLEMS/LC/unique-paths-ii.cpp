#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0])return 0;//密码的玩呢？
        const int width = grid[0].size();
        const int height = grid.size();
        grid[0][0]=1;
        for(int i = 1; i < width; i++){
            if(grid[0][i]){
                grid[0][i]=0;
            } else {
                grid[0][i] = grid[0][i-1];
            }
        }
        for(int i = 1; i < height; i++){
            if(grid[i][0]){
                grid[i][0]=0;
            } else {
                grid[i][0] = grid[i-1][0];
            }
        }
        for(int i = 1; i < height; i++){
            for(int j = 1; j < width; j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                } else {
                    grid[i][j] = grid[i][j-1]+grid[i-1][j];
                }
            }
        }
        return grid[height-1][width-1];
    }
};
Solution s;
int main(){
    vector<vector<int>> v = {{1}};
    s.uniquePathsWithObstacles(v);
}