#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int abs(const int& v){
        return (v>>31)?((~v)+1):(v);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        #define check(i,j,k) if(abs(nums[i]+nums[j]+nums[k]-target)<abs(closet-target))
        // #define ucheck(i,j,k) if(abs(nums[i]+nums[j]+nums[k]-target)>abs(closet-target))
        sort(nums.begin(),nums.end());
        // unique(nums.begin(),nums.end());
        const int e0 = nums.size()-0;
        const int e1 = nums.size()-1;
        const int e2 = nums.size()-2;
        int closet = 1e9;
        for(int i = 0; i < e2;i++){
            if(nums[i]+nums[i+1]+nums[i+2]>target&&abs(nums[i]+nums[i+1]+nums[i+2]-target)>abs(closet-target)){
                break;
            }
            for(int j = i+1; j < e1; j++){
                if(nums[i]+nums[j]+nums[j+1]>target&&abs(nums[i]+nums[j]+nums[j+1]-target)>abs(closet-target)){
                    break;
                }
                for(int k = j+1; k < e0; k++){
                    check(i,j,k){
                        closet = nums[i]+nums[j]+nums[k];
                        if(closet == target){
                            return target;
                        }
                    }
                }
            }
        }
        return closet;
    }
};