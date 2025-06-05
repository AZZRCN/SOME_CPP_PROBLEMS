#include <bits/stdc++.h>
using namespace std;
template<size_t s>
string bit2str(bitset<s>& bs,const size_t len = s,const size_t max_zero_process = 10){
    vector<int> data = {0};
    auto multi = [](vector<int>& v,int val){
        int carry=0;
        for(int i = 0; i < v.size(); i++){
            v[i] = v[i]*val+carry;
            carry = v[i]/10;
            v[i] %= 10;
        }
        while(carry){
            v.push_back(carry%10);
            carry/=10;
        }
        return;
    };
    auto add1 = [](vector<int>& v){
        for(int i = 0; i < v.size(); i++){
            if(v[i]==9){
                v[i]=0;
            }
            else{
                v[i]++;
                return;
            }
        }
        if(v.back()==0){
            // if(v.size()==1){
            //     v[0]=1;
            // }
            // else{
                v.push_back(1);
            // }
        }
        return;
    };
    int cnt = 0;
    for(int i = len-1; i >= 0; i--){
        cnt++;
        if(bs[i] == 1){
            multi(data,1<<cnt);
            add1(data);
            cnt = 0;
            continue;
        }
        if(cnt == max_zero_process){
            multi(data,1<<max_zero_process);
            cnt = 0;
            continue;
        }
    }
    multi(data,1<<cnt);
    string ans;
    for(int i = data.size()-1 ; i>=0; i--){
        ans.push_back(data[i]|0x30);
    }
    return ans;
}
// 示例主函数
int main() {
    // 示例 1: 二进制 1000 -> 8
    std::bitset<32> bits1;
    bits1.set(3);
    std::cout << "Example 1: " << bit2str(bits1) << std::endl; // 输出: 8

    // 示例 2: 全 1 的 bitset
    std::bitset<1024> bits2;
    bits2.set();
    std::cout << "Example 2: " << bit2str(bits2, 1024) << std::endl; // 输出: 2^1024 - 1

    // 示例 3: 全 0 的 bitset
    std::bitset<1024> bits3;
    std::cout << "Example 3: " << bit2str(bits3, 1024) << std::endl; // 输出: 0
bitset<8> test1;test1=128;
bitset<8> test2;test2=8;
bitset<8> test3;test3=2;
bitset<8> test4;test4=0;
bitset<8> test5;test5=255;
;
cout << bit2str(test1) << "\n"; // 输出 "128"
cout << bit2str(test2) << "\n"; // 输出 "8"
cout << bit2str(test3) << "\n"; // 输出 "2"
cout << bit2str(test4) << "\n"; // 输出 "0"
cout << bit2str(test5) << "\n"; // 输出 "255"
}