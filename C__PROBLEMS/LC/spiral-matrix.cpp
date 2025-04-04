#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ans;
    int u,l,d,r;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        u = 0;
        l = 0;
        d = matrix.size()-1;
        r = matrix[0].size()-1;
        int step = 0;
        while(u<=d&&l<=r){
            switch (step)
            {
            case 0:
                for(int i = l; i <= r; i++){
                    ans.push_back(matrix[u][i]);
                }
                step=1;
                u++;
                break;
            case 1:
                for(int i = u; i <= d; i++){
                    ans.push_back(matrix[i][r]);
                }
                r--;
                step=2;
                break;
            case 2:
                for(int i = r; i >= l; i--){
                    ans.push_back(matrix[d][i]);
                }
                step=3;
                d--;
                break;
            case 3:
                for(int i = d; i >= u; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
                step=0;
                break;
            default:
                break;
            }
        }
        return ans;
    }
};