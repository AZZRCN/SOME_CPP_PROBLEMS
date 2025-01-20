/* v1
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> pi;
void prefix_function(string s) {
    int n = (int)s.length();
    pi.resize(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])j = pi[j - 1];
        if (s[i] == s[j])j++;
        pi[i] = j;
    }
}
int kmp(string _data, string _cat)
{
    _data = _cat + '#' + _data;
    prefix_function(_data);
    const int l = _cat.length();
    const int r = _data.length();
    for (int i = l + 1; i < r; i++) {
        if (pi[i] == l) {
            return 1 + i - (2 * l);
        }
    }
    return -1;
}*/
/*v2
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int kmp(string _data, string _cat)
{
    vector<int> pi;
    _data = _cat + '#' + _data;
    const int l = _cat.length(), r = _data.length();
    pi.resize(r);
    for (int i = 1; i < r; i++) {
        pi[i] = pi[i - 1];
        while (pi[i] > 0 && _data[i] != _data[pi[i]])pi[i] = pi[pi[i] - 1];
        if (_data[i] == _data[pi[i]])pi[i]++;
        if (pi[i] == l)return (i + 1) - (2 * l);
    }
    return -1;
}
int kmp_using(string& _data, const string& _cat) {
    _data = _cat + '#' + _data;
    const int l = _cat.length(), r = _data.length();
    vector<int> pi(r);
    for (int i = 1; i < r; i++) {
        pi[i] = pi[i - 1];
        while (pi[i] > 0 && _data[i] != _data[pi[i]]) { pi[i] = pi[pi[i] - 1]; }
        if (_data[i] == _data[pi[i]]) { pi[i]++; }
        if (pi[i] == l) { return (i + 1) - (2 * l); }
    }
    return -1;
}
*/
//final
#include <string>
#include <vector>
int kmp_using(std::string&_data,const std::string&_cat){
_data=_cat+'#'+_data;const int l=_cat.length(),r=_data.
length();std::vector<int>pi(r);for(int i=1;i<r;i++){pi\
[i]=pi[i-1];while(pi[i]>0&&_data[i]!=_data[pi[i]]){pi[\
i]=pi[pi[i]-1];}if(_data[i]==_data[pi[i]]){pi[i]++;}if\
(pi[i]==l){return (i+1)-(2*l);}}return -1;}