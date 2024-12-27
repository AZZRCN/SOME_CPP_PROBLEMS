#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
static unsigned long long mod = 1e9 + 7;
static void ADD(unsigned long long& x, const unsigned long long& y) {
    x += y;
    if (x >= mod)x -= mod;
}
template<unsigned long long rows, unsigned long long cols>
struct martix {
    unsigned long long a[rows + 1][cols + 1];
    void init() {
        memset(a, 0, sizeof(a));
    }
    inline void clear() { init(); }
    inline unsigned long long* operator[](const unsigned long long& p) {
        return a[p];
    }
    template<unsigned long long rows2, unsigned long long cols2>
    martix<rows, cols2> operator*(martix<rows2, cols2>& O) {
        martix<rows, cols2> m;
        m.clear();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols2; j++) {
                for (unsigned long long k = 1; k <= cols; k++) {
                    ADD(m[i][j], (a[i][k] * O[k][j]) % mod);
                }
            }
        }
        return m;
    }
    martix<rows, cols> operator^(long long pow_time) {
        martix<rows, cols>_copy = *this;
        martix<rows, cols> ret;
        ret.init();
        ret[1][1] = ret[2][2] = 1;
        for (; pow_time; (_copy = _copy * _copy)) {
            if (pow_time & 1)ret = ret * _copy;
            (pow_time >>= 1);
        }
        return ret;
    }
    martix<rows, cols> operator+(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] + O[i][j];
            }
        }
        return ret;
    }
    martix<rows, cols> operator-(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] - O[i][j];
            }
        }
        return ret;
    }
    bool operator>(martix<rows, cols> O) {//Í¬¼¶£¬É÷ÓÃ
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                if (a[i][j] > O[i][j])return true;
                if (a[i][j] < O[i][j])return false;
            }
        }
        return false;
    }
    martix<rows, cols> push_left(unsigned long long O) {
        martix<rows, cols> ret;
        ret.init();
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                ret[i][max(j - O, 1ULL)] = a[i][j];
            }
        }
        return ret;
    }
    martix<rows, cols> push_to_left() {
        int flag = 0;
        for (int j = 1; j <= cols; j++) {
            for (int i = 1; i <= rows; i++) {
                if (a[i][j]) {
                    return push_left(j);
                }
            }
        }
        martix<rows, cols> ret;
        ret.init();
        return ret;
    }
};
/*only add and no fix
#include <iostream>
#include <cstring>
using namespace std;
template<unsigned long long rows, unsigned long long cols>
struct martix {
    unsigned long long a[rows + 1][cols + 1];
    void init() {
        memset(a, 0, sizeof(a));
    }
    inline unsigned long long* operator[](const unsigned long long& p) {
        return a[p];
    }
    martix<rows, cols> operator+(martix<rows, cols> O) {
        martix<rows, cols> ret;
        ret.init();
        for (unsigned long long i = 1; i <= rows; i++) {
            for (unsigned long long j = 1; j <= cols; j++) {
                ret[i][j] = a[i][j] + O[i][j];
            }
        }
        return ret;
    }
};
*/