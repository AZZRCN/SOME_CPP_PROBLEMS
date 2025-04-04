#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    inline static int collect(int x){
        int ans = 0;
        while(x){ans+=x%10;x/=10;}
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        int arr[55];
        memset(arr,0,sizeof(arr));
        for(int i = lowLimit; i <= highLimit; i++){
            arr[collect(i)]++;
        }
        int ans = 0;
        for(int i = 1; i <= 50; i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};
Solution s;
int main(){
    cout << s.countBalls(5,15);
}