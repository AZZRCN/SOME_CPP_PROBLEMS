#include <bits/stdc++.h>
using namespace std;
using ll = long long;














//LL
vector<int> vec;
string result;
void processString(const string& str) {
    ll temp = 0;
    bool pn = true;
    bool numStarted = false;
    char pendingSign = '\0';

    auto commitNumber = [&]() {
        if (!numStarted) return;
        vec.push_back(pn ? temp : -temp);
        result += '#';
        temp = 0;
        numStarted = false;
    };

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isdigit(c)) {
            if (pendingSign != '\0') {
                pn = (pendingSign == '+');
                pendingSign = '\0';
            } else {
                pn = true;  // 默认无符号为正
            }
            temp = temp * 10 + (c - '0');
            numStarted = true;
        } else if (c == '+' || c == '-') {
            commitNumber();  // 提交之前的数字
            
            // 处理符号
            if (pendingSign != '\0') {
                result += pendingSign;
            }
            pendingSign = c;
        } else {
            commitNumber();  // 提交之前的数字
            
            // 处理普通字符
            if (pendingSign != '\0') {
                result += pendingSign;
                pendingSign = '\0';
            }
            result += c;
        }
    }

    commitNumber();  // 提交末尾数字
    if (pendingSign != '\0') {
        result += pendingSign;
    }
}

int main() {
    processString("-0++-a123B+-456C7D--+E8++9F");
    cout << "Detected numbers:\n";
    for (auto num : vec) cout << num << endl;
    cout << "Processed string:\n" << result << endl;
}