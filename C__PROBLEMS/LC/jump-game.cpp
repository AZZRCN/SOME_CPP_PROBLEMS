#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0;
        const int target = nums.size()-1;
        for(int i = 0; i <= ans && ans < target; i++){
            ans = max(ans,i+nums[i]);
        }
        return ans>=target;
    }
};