#include <bits/stdc++.h>
using namespace std;

vector<double> vec_v1;
string result_v1;

void processStringV1(const string& str) {
    bool pn = true, numStarted = false, hasDot = false;
    char pendingSign = '\0';
    double integerPart = 0, decimalPart = 0;
    int decimalDigits = 0;

    auto commitNumber = [&]() {
        if (!numStarted) return;
        vec_v1.push_back(pn ? (integerPart + decimalPart) : -(integerPart + decimalPart));
        result_v1 += '#';
        integerPart = decimalPart = 0;
        numStarted = hasDot = false;
        decimalDigits = 0;
    };

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (isdigit(c)) {
            if (pendingSign != '\0') {
                pn = (pendingSign == '+');
                pendingSign = '\0';
            }
            
            if (hasDot) {
                decimalPart += (c - '0') * pow(10, -++decimalDigits);
            } else {
                integerPart = integerPart * 10 + (c - '0');
            }
            numStarted = true;
        } else if (c == '.') {
            if (numStarted && hasDot) {  // 遇到连续的小数点
                commitNumber();         // 提交前一个数字
                // 开启新数字的.x模式
                numStarted = true;
                hasDot = true;
                integerPart = 0;
            } else {
                if (!numStarted) {     // 处理.x格式
                    integerPart = 0;
                    numStarted = true;
                }
                hasDot = true;
            }
        } else if (c == '+' || c == '-') {
            commitNumber();
            if (pendingSign != '\0') result_v1 += pendingSign;
            pendingSign = c;
        } else {
            commitNumber();
            if (pendingSign != '\0') {
                result_v1 += pendingSign;
                pendingSign = '\0';
            }
            result_v1 += c;
        }
    }
    commitNumber();
    if (pendingSign != '\0') result_v1 += pendingSign;
}

// 测试样例
int main() {
    vec_v1.clear();
    result_v1.clear();
    processStringV1("12.3.4a.56-b.7c8..9");
    
    cout << "版本1检测数字：\n";
    cout << fixed << setprecision(1);
    for (double num : vec_v1) cout << num << endl;
    
    cout << "处理结果：\n" << result_v1 << endl;
}