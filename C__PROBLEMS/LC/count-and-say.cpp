#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string st = "1";
    string tmp;
    char last;
    int count;
    void push(){
        tmp = tmp + to_string(count) + last;
    }
    void make(){
        tmp.clear();
        count = 0;
        last = st.front();
        for(char c:st){
            if(c!=last){
                push();
                count = 0;
                last = c;
            }
            count++;
        }
        push();
        st = tmp;
    }
    string countAndSay(int n) {
        while(--n>0){
            make();
        }
        return st;
    }
};