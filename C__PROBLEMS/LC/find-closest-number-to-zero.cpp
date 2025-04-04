#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestNumber(const vector<int>& nums) {
        int ans = nums.front();
        for(int i : nums){
            if((abs(i)<abs(ans))||(abs(i)==abs(ans)&&i>ans)){
                ans = i;
            }
        }
        return ans;
    }
};
Solution s;
int main(){
    cout << s.findClosestNumber({-4,-2,-1,1,-1,4,8});
}