#include <bits/stdc++.h>
using namespace std;

vector<double> vec_v2;
string result_v2;

void processStringV2(const string& str) {
    bool numStarted = false, hasDot = false;
    bool positive = true;
    char pendingSign = '\0';
    long integerPart = 0;
    double decimalPart = 0;
    int decimalDigits = 0;

    auto commitNumber = [&]() {
        if (numStarted) {
            double value = integerPart + decimalPart;
            if (!positive) value = -value;
            vec_v2.push_back(value);
            result_v2 += '#';
            
            // Reset states
            numStarted = false;
            hasDot = false;
            integerPart = 0;
            decimalPart = 0;
            decimalDigits = 0;
            positive = true;
            pendingSign = '\0';
        }
    };

    auto handlePendingSign = [&]() {
        if (pendingSign != '\0') {
            result_v2 += pendingSign;
            pendingSign = '\0';
        }
    };

    for (int i = 0; i < str.size(); ++i) {
        char c = str[i];
        
        if (isdigit(c)) {
            // Process sign
            if (pendingSign != '\0') {
                positive = (pendingSign == '+');
                pendingSign = '\0';
            }
            
            if (!numStarted) numStarted = true;
            
            if (hasDot) {
                decimalPart += (c - '0') * pow(10, -++decimalDigits);
            } else {
                integerPart = integerPart * 10 + (c - '0');
            }
        }
        // 修改小数点处理逻辑
        else if (c == '.' && !hasDot) {
            bool hasDigitsAfter = false;
            
            // 仅检测紧接的下一个字符
            int j = i + 1;
            if (j < str.size() && isdigit(str[j])) {
                hasDigitsAfter = true;
            }

            if (numStarted) {
                if (hasDigitsAfter) {
                    hasDot = true;
                } else {
                    commitNumber();
                    result_v2 += '.';
                }
            } else {
                result_v2 += '.';
            }
        }
        else if (c == '+' || c == '-') {
            if (numStarted || pendingSign != '\0') {
                commitNumber();
                result_v2 += c;
            } else {
                pendingSign = c;
            }
        }
        else {
            commitNumber();
            handlePendingSign();
            result_v2 += c;
        }
    }
    
    commitNumber();
    handlePendingSign();
}

// int main() {
//     vec_v2.clear();
//     result_v2.clear();
//     processStringV2(".123");
    
//     cout << "检测数字：\n";
//     cout << fixed << setprecision(1);
//     for (double num : vec_v2) cout << num << endl;
    
//     cout << "结果字符串：\n" << result_v2 << endl;
//     return 0;
// }
int main() {
    vec_v2.clear();
    result_v2.clear();
    processStringV2("12.3.4a.56-b.7c8..9");
    
    cout << "版本2检测数字：\n";
    cout << fixed << setprecision(1);
    for (double num : vec_v2) cout << num << endl;
    
    cout << "处理结果：\n" << result_v2 << endl;
}