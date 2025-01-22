#include <bits/stdc++.h>
using namespace std;
list<int> l;
bool check(){
    const int e = l.size();
    const int h = e/2;
    list<int>::iterator L=l.begin(),R=prev(l.end());
    for(int i = 0; i < h; i++){
        if(*(L++)!=*(R--)){
            return false;
        }
    }
    return true;
}
std::list<int> addTwoNumbers(const std::list<int>& l1, const std::list<int>& l2) {
    std::list<int> ans;
    int carry = 0;
    auto it1 = l1.begin();
    auto it2 = l2.begin();

    while (it1 != l1.end() || it2 != l2.end()) {
        int a = (it1 != l1.end()) ? *it1 : 0;
        int b = (it2 != l2.end()) ? *it2 : 0;
        int temp = a + b + carry;
        carry = temp > 9 ? 1 : 0;
        ans.push_back(temp % 10);

        if (it1 != l1.end()) ++it1;
        if (it2 != l2.end()) ++it2;
    }

    if (carry) {
        ans.push_back(carry);
    }

    return ans;
}
std::list<int> addTwoNumbersWithReverse(const std::list<int>& l1) {
    std::list<int> l2(l1);
    l2.reverse();  // 逆序 l2
    return addTwoNumbers(l1, l2);
}
int main(){
    
}