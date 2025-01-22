#define _CRT_SECURE_NO_WARNINGS
#include <type_traits>
#include <stdio.h>
#include <process.h>
#include <numeric>
using namespace std;
#ifdef HEAD
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdbool>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#endif
#ifdef DEFINE
#define re register int
#define ce constexpr
#define il inline
#define gm int mid((l+r)/2)
#define Size(x) ((int)x.size())
#define mem(x,y) memset(x,y,sizeof(x))
#define cls system("cls")
#define pau system("pause")
#define stop system("pause")
#define exi exit(0)
#define co continue
#define Lgo(x,y) x<<=y
#define Rgo(x,y) x>>=y;
#define even(X) (!(X&1))
#define odd(X) (X&1)
#define out_file(path) freopen(path,"r",stdin)
#define in_file(path) freopen(path,"w",stdout)
#define elif else if
#define unless(...) while(!(__VA_ARGS))
#define r(...) return __VA_ARGS__
#endif
#ifdef TYPE
template<typename L, typename R> constexpr bool same() { return is_same<L, R>::value; }
template<typename L, typename R>using p = pair<L, R>;
template<typename L, typename R>p<L, R> il mp(L l, R r) { return make_pair(l, r); };
typedef long long LL; typedef unsigned int ui; typedef unsigned long long ull;
#endif
//int read1() { int x = 0, f = 1; char ch = gc(); while (ch < 48 || ch>57) { if (ch == '-') { f = -1; }ch = gc(); }while (ch >= 48 && ch <= 57) { x = x * 10 + ch - 48, ch = gc(); }return x * f; }
#ifdef IN
#define il inline
static void il read_u(unsigned long long& n) { n = 0; unsigned char ch = getchar(); while ((ch ^ '0') > 9) { ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); } }
static void il read_s(long long& n) { n = 0; unsigned char ch = getchar(), w = 0; while ((ch ^ '0') > 9) { if (!(ch ^ '-')) { w = 1; } ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }if (w) { n = -n; } }
static long long il read_s() { long long n = 0; unsigned char ch = getchar(), w = 0; while ((ch ^ '0') > 9) { if (!(ch ^ '-')) w = 1; ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }if (w) { return -n; }return n; }
static unsigned long long il read_u() { unsigned long long n = 0; unsigned char ch = getchar(); while ((ch ^ '0') > 9) { ch = getchar(); }while ((ch ^ '0') < 0xA) { n = n * 0xA + ch - 0x30; ch = getchar(); }return n; }
template<class T>void read(T& n) { if (is_unsigned<T>::value) { n = read_u(); } else { n = read_s(); } }
template<class T, class ...Args>il void read(T& x, Args &...args) { read(x); read(args...); }
#define read_(name,T) T name;read(name)
#ifdef IN_OLD
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void in_o(T& x) { x = 0; char c = getchar(); bool f = 0; while (!isdigit(c)) { f |= (c == '-'), c = getchar(); }while (isdigit(c)) { x = x * 10 + (c ^ '0'), c = getchar(); }f ? x = -x : 0; }
template<class T, class ...Args>il static void in_o(T& x, Args &...args) { in_o(x); in_o(args...); }
#endif
#endif
#ifdef GCD
unsigned long long gcd(unsigned long long L, unsigned long long R) {
    unsigned long long lgo = 0;
    while (L ^ R) {
        if (!((L | R) & 1)) { L >>= 1; R >>= 1; lgo++; continue; }
        if (!(L & 1)) { L >>= 1; continue; }
        if (!(R & 1)) { R >>= 1; continue; }
        if (L < R) { R -= L; }
        else { L -= R; }
    }
    return max(L, R) << lgo;
}
#endif
#ifdef OUT
template<class T, class = typename enable_if<is_integral<T>::value>::type>il void out(T x, const char c = '\n') { static short st[40]; short m = 0; if (x < 0) { putchar('-'), x = -x; }do { st[++m] = x % 10, x /= 10; } while (x); while (m) { putchar(st[m--] | '0'); }putchar(c); }
template<class T, class ...Args>il static void out(const T& x, const Args &...args) { out(x, ' '); out(args...); }
template<class T>il void static prt(T a, int n) { --n; for (int i = 0; i < n; ++i) out(a[i], ' '); out(a[n], '\n'); }
#endif
#ifdef MEM
template<class T>il void static clr(T a[], int n) { memset(a, 0, sizeof(T) * n); }
template<class T>il void static clr(T* a, T* b) { memset(a, 0, sizeof(T) * (b - a)); }
#endif
#ifdef CMP
template<class T>il bool static ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T>il bool static ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
#endif
#ifdef GC
char* p1, * p2, buf[1 << 20];
#define gc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)//only for judge!
#endif
#ifdef CALC
const int md = 1e9 + 7;
il int static add(const int a, const int b) { return a + b >= md ? a + b - md : a + b; }
il int static sub(const int a, const int b) { return a - b < 0 ? a - b + md : a - b; }
il int static mul(const int a, const int b) { return (LL)a * b % md; }
il void static inc(int& a, const int b) { (a += b) >= md ? a -= md : 0; }
il void static dec(int& a, const int b) { (a -= b) < 0 ? a += md : 0; }
il int static qpow(int a, int b) { int r = 1; for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a); return r; }
il int static qpow(int a, int b, const int p) { int r = 1; for (; b; b >>= 1, a = (LL)a * a % p) if (b & 1) r = (LL)r * a % p; return r; }
il int static mdinv(const int a) { return qpow(a, md - 2); }
template<class ...Args>il int static add(const int a, const int b, const Args &...args) { return add(add(a, b), args...); }
template<class ...Args>il int static mul(const int a, const int b, const Args &...args) { return mul(mul(a, b), args...); }
#endif
#ifdef NEW_GETCHAR
#define getchar() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?EOF:*S++)
#endif
#ifdef DANDIAO
template <int x>class dandiao {
public:
    list<int> minn, maxn;
    int n, k, a[x + 1];
    void inline init() { for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); } }
    void inline init_to_k() { for (int i = 1; i <= k; i++) { minn_push(i); maxn_push(i); } }
    void inline init_args() { scanf("%d %d", &n, &k); }
    void inline minn_push(int pos) { if (!minn.empty() && minn.front() == pos - k) { minn.pop_front(); }while (!minn.empty() && a[pos] < a[minn.back()]) { minn.pop_back(); }minn.push_back(pos); }
    void inline maxn_push(int pos) { if (!maxn.empty() && maxn.front() == pos - k) { maxn.pop_front(); }while (!maxn.empty() && a[pos] > a[maxn.back()]) { maxn.pop_back(); }maxn.push_back(pos); }
    void builtin() { scanf("%d %d", &n, &k); for (int i = 1; i <= k; i++) { scanf("%d", &a[i]); minn_push(i); maxn_push(i); }      for (int i = k + 1; i <= n; i++) { scanf("%d", &a[i]); } }
    void builtin(void (*act)()) { scanf("%d %d", &n, &k); for (int i = 1; i <= k; i++) { scanf("%d", &a[i]); minn_push(i); maxn_push(i); }act(); for (int i = k + 1; i <= n; i++) { scanf("%d", &a[i]); minn_push(i); maxn_push(i); act(); } }
};
#endif
#ifdef DREAD
inline double dread()
{
    double X = 0, Y = 1.0; int w = 0; char ch = 0;
    while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
    while (isdigit(ch)) X = X * 10 + (ch ^ 48), ch = getchar();
    ch = getchar();//读入小数点
    while (isdigit(ch)) X += (Y /= 10) * (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
#endif
#ifdef IOF
namespace iof {
    const int Buffer_MAXSIZE = 0xfffff;
    const char endl = '\n';
    class ifast {
    public:
        ifast& operator>>(char& ch);
        ifast& operator>>(char* s);
        ifast& operator>>(std::string& string);
        ifast& operator>>(bool& x) { return read_unsigned_integer(x); }
        ifast& operator>>(int& x) { return read_signed_integer(x); }
        ifast& operator>>(long long& x) { return read_signed_integer(x); }
        ifast& operator>>(unsigned int& x) { return read_unsigned_integer(x); }
        ifast& operator>>(unsigned long long& x) { return read_unsigned_integer(x); }
        void getline(std::string& string);
        void getline(char* s);
        auto hasMoreToken() { return front <= back; }
    private:
        template<typename T>ifast& read_signed_integer(T& x);
        template<typename T>ifast& read_unsigned_integer(T& x);
        char getchar();
        char buffer[Buffer_MAXSIZE]{};
        char* front = buffer;
        char* back = buffer;
        char next_char{};
    } fin;

    class ofast {
    public:
        ofast& operator<<(const char& c);
        ofast& operator<<(const char* c);
        ofast& operator<<(const std::string& s);
        ofast& operator<<(const bool& x) { return print_integer(x); }
        ofast& operator<<(const int& x) { return print_integer(x); }
        ofast& operator<<(const long long& x) { return print_integer(x); }
        ofast& operator<<(const unsigned int& x) { return print_integer(x); }
        ofast& operator<<(const unsigned long long& x) { return print_integer(x); }
        void flush();
        ~ofast() { flush(); }
    private:
        void putchar(const char& c) { *top++ = c; }
        char buffer[Buffer_MAXSIZE]{};
        char* top = buffer;
        template<typename T>
        ofast& print_positive_integer(const T& x);
        template<typename T>
        ofast& print_integer(const T& x);
    } fout;

    char ifast::getchar() { if (front == back) { back = buffer + fread(buffer, 1, Buffer_MAXSIZE, stdin); front = buffer; }return *(front++); }
    void ifast::getline(std::string& string) { string.clear(); for (*this >> next_char; hasMoreToken() && next_char != '\n'; next_char = getchar()) { string.push_back(next_char); } }
    void ifast::getline(char* s) { for (char* p = s; hasMoreToken() && next_char != '\n'; next_char = getchar(), p++) { *p = next_char; } }
    ifast& ifast::operator>>(char& ch) { do { ch = getchar(); } while (hasMoreToken() && (ch == ' ' || ch == '\n')); return *this; }
    ifast& ifast::operator>>(char* s) { *this >> next_char; for (char* p = s; hasMoreToken() && next_char != ' ' && next_char != '\n'; next_char = getchar(), p++) { *p = next_char; }return *this; }
    ifast& ifast::operator>>(std::string& string) { *this >> next_char; string.clear(); for (; hasMoreToken() && next_char != ' ' && next_char != '\n'; next_char = getchar()) { string.push_back(next_char); }return *this; }
    template<typename T>ifast& ifast::read_unsigned_integer(T& x) { *this >> next_char; x = 0; do { x = (x << 1) + (x << 3) + next_char - '0'; next_char = getchar(); } while (hasMoreToken() && next_char != ' ' && next_char != '\n'); return *this; }
    template<typename T>ifast& ifast::read_signed_integer(T& x) {
        *this >> next_char; auto isNegative = next_char == '-'; if (isNegative) { next_char = getchar(); }x = 0;
        do { x = (x << 1) + (x << 3) + next_char - '0'; next_char = getchar(); } while (hasMoreToken() && next_char != ' ' && next_char != '\n'); if (isNegative) { x = -x; }return *this;
    }
    ofast& ofast::operator<<(const char& c) { putchar(c); return *this; }
    ofast& ofast::operator<<(const char* c) { for (auto* p = c; *p != '\0'; p++) { putchar(*p); }return *this; }
    ofast& ofast::operator<<(const std::string& s) { for (const auto& i : s) { putchar(i); }return *this; }
    void ofast::flush() { fwrite(buffer, 1, top - buffer, stdout); top = buffer; }
    template<typename T>ofast& ofast::print_integer(const T& x) { if (x > 0) { return print_positive_integer(x); }elif(x == 0) { putchar('0'); return *this; } else { putchar('-'); return print_positive_integer(-x); } }
    template<typename T>ofast& ofast::print_positive_integer(const T& x) { if (x > 9) { print_positive_integer(x / 10); }putchar(x % 10 + '0'); return *this; }
}
#endif
#ifdef BN
namespace BN {
#define LL long long
    const int base = 1e8;
    const int N = 1e4 + 10;
    int aux[80080];
    class Int {
    public:
        int s[N], l;
        inline void CL() { l = 0; memset(s, 0, sizeof(s)); };
        inline void pr() { printf("%d", s[l]); for (re i = l - 1; i; i--) { printf("%08d", s[i]); } };
        inline void re_l() {re i, x = 0, k = 1, L = 0, fl, o; char c = getchar(); for (; c < '0' || c>'9'; c = getchar()); for (; c >= '0' && c <= '9'; c = getchar()) {if (!(L - 1) && !aux[L])L--; aux[++L] = c - '0';}; CL(); l = L / 8 + ((o = L % 8) > 0); for (i = 1; i <= o; i++) { x = x * 10 + aux[i]; }; if (o) { s[l] = x; fl = !o ? l + 1 : l; }for (i = o + 1, x = 0; i<= L; i++, k++) {x = x * 10 + aux[i]; if (!(k ^ 8)) { s[--fl] = x, x = k = 0; };}; if (!l) { l = 1; };};
        inline LL toint() { LL x = 0; for (re i = l; i; i--) { x = x * base + s[i]; }; return x; };


        inline Int operator=(re b) { CL(); do { s[++l] = b % base, b /= base; } while (b > 0); return *this; };
        inline Int operator=(LL b) { CL(); do { s[++l] = b % base, b /= base; } while (b > 0); return *this; };


        inline Int operator+(const re& b) { Int c = *this; LL x = b; for (re i = 1; i <= l && x; i++) { x = x + c.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
        inline Int operator+(const LL& b) { Int c = *this; LL x = b; for (re i = 1; i <= l && x; i++) { x = x + c.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
        inline Int operator-(const re& b) { Int c; return *this - (c = b); };
        inline Int operator-(const LL& b) { Int c; return *this - (c = b); }
        inline Int operator*(const re& b) { Int c; LL x = 0; c.CL(); for (re i = 1; i <= l; i++) { x = x + 1LL * s[i] * b, c.s[i] = x % base, x /= base; }; for (c.l = l; x; x /= base) { c.s[++c.l] = x % base; }; return c; };
        inline Int operator*(const LL& b) { Int c; if (b > 2e9) { c = b; return *this * c; }LL x = 0; c.CL(); for (re i = 1; i <= l; i++) { x = x + b * s[i], c.s[i] = x % base, x /= base; }for (c.l = l; x; x /= base) { c.s[++c.l] = x % base; }return c; };
        inline Int operator/(const re& b) { Int c; LL x = 0; c.CL(); for (re i = l; i; i--) { c.s[i] = (x * base + s[i]) / b, x = (x * base + s[i]) % b; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
        inline Int operator/(const LL& b) { Int c; LL x = 0; c.CL(); for (re i = l; i; i--) { c.s[i] = (x * base + s[i]) / b, x = (x * base + s[i]) % b; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
        inline Int operator%(const re& b) { Int c; LL x = 0; c.CL(); for (re i = l; i; i--) { x = (x * base + s[i]) % b; }return c = x; };
        inline Int operator%(const LL& b) { Int c; LL x = 0; c.CL(); for (re i = l; i; i--) { x = (x * base + s[i]) % b; }return c = x; };
        inline Int operator+(Int& b) { if (b.l < 3) { return *this + b.toint(); }; Int c; LL x = 0; re k = l < b.l ? b.l : l; c.CL(), c.l = k; for (re i = 1; i <= k; i++) { x = x + s[i] + b.s[i], c.s[i] = x % base, x /= base; }; if (x) { c.s[++c.l] = x; }; return c; };
        inline Int operator-(const Int& b) { Int c, d = *this; LL x = 0; c.CL(); for (re i = 1; i <= l; i++) { if ((x = d.s[i]) < b.s[i]) { d.s[i + 1]--, x += base; }c.s[i] = x - b.s[i]; }c.l = l; for (; !c.s[c.l] && c.l > 1; c.l--); return c; }
        inline Int operator*(Int& b) { if (b.l < 2) { return *this * b.toint(); }Int c; LL x; re i, j, k; c.CL(); for (i = 1; i <= l; i++) { x = 0; for (j = 1; j <= b.l; j++) { x = x + 1LL * s[i] * b.s[j] + c.s[k = i + j - 1], c.s[k] = x % base, x /= base; }; if (x) { c.s[i + b.l] = x; }; }for (c.l = l + b.l; !c.s[c.l] && c.l > 1; c.l--); return c; };
        inline Int operator/(Int& b) { if (b.l < 2) { return *this / b.toint(); }; Int c, d; re i, j, le, r, mid, k; c.CL(); d.CL(); for (i = l; i; i--) { for (j = ++d.l; j > 1; j--) { d.s[j] = d.s[j - 1]; }; d.s[1] = s[i]; if (d < b) { continue; }; le = k = 0; r = base - 1; while (le <= r) { mid = (le + r) >> 1; if (b * mid <= d) { le = mid + 1, k = mid; } else { r = mid - 1; } }; c.s[i] = k, d = d - b * k; }; for (c.l = l; !c.s[c.l] && c.l > 1; c.l--); return c; };
        inline Int operator%(Int& b) { if (b.l < 2) { return *this % b.toint(); }Int c; re i, j, le, r, mid, k; c.CL(); for (i = l; i; i--) { for (j = ++c.l; j > 1; j--) { c.s[j] = c.s[j - 1]; }c.s[1] = s[i]; if (c < b) { continue; }le = k = 0, r = base - 1; while (le <= r) { mid = (le + r) >> 1; if (b * mid <= c) { le = mid + 1, k = mid; } else { r = mid - 1; } }c = c - b * k; }for (; !c.s[c.l] && c.l > 1; c.l--); return c; }


        inline Int operator+=(re& b) { return *this = *this + b; };
        inline Int operator-=(re& b) { return *this = *this - b; };
        inline Int operator*=(re& b) { return *this = *this * b; };
        inline Int operator/=(re& b) { return *this = *this / b; };
        inline Int operator%=(re& b) { return *this = *this % b; };
        inline Int operator+=(LL& b) { return *this = *this + b; };
        inline Int operator-=(LL& b) { return *this = *this - b; };
        inline Int operator*=(LL& b) { return *this = *this * b; };
        inline Int operator/=(LL& b) { return *this = *this / b; };
        inline Int operator%=(LL& b) { return *this = *this % b; };
        inline Int operator+=(Int& b) { return *this = *this + b; };
        inline Int operator-=(Int& b) { return *this = *this - b; };
        inline Int operator*=(Int& b) { return *this = *this * b; };
        inline Int operator/=(Int& b) { return *this = *this / b; };
        inline Int operator%=(Int& b) { return *this = *this % b; };


        inline bool operator<=(const Int& b)const { if (l ^ b.l) { return l < b.l; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] < b.s[i]; } }; return 1; };
        inline bool operator>=(const Int& b)const { if (l ^ b.l) { return l > b.l; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] > b.s[i]; } }; return 1; };
        inline bool operator< (const Int& b)const { if (l ^ b.l) { return l < b.l; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] < b.s[i]; } }; return 0; };
        inline bool operator> (const Int& b)const { if (l ^ b.l) { return l > b.l; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return s[i] > b.s[i]; } }; return 0; };
        inline bool operator==(const Int& b)const { if (l ^ b.l) { return 0; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return 0; } }; return 1; };
        inline bool operator!=(const Int& b)const { if (l ^ b.l) { return 1; }; for (re i = l; i; i--) { if (s[i] ^ b.s[i]) { return 1; } }; return 0; };
        inline bool operator< (LL b)const { Int c; return *this < (c = b); };
        inline bool operator> (LL b)const { Int c; return *this > (c = b); };
        inline bool operator<=(LL b)const { Int c; return *this <= (c = b); };
        inline bool operator>=(LL b)const { Int c; return *this >= (c = b); };
        inline bool operator==(LL b)const { Int c; return *this == (c = b); };
        inline bool operator!=(LL b)const { Int c; return *this != (c = b); };
        inline bool operator< (re b)const { Int c; return *this < (c = b); };
        inline bool operator> (re b)const { Int c; return *this > (c = b); };
        inline bool operator<=(re b)const { Int c; return *this <= (c = b); };
        inline bool operator>=(re b)const { Int c; return *this >= (c = b); };
        inline bool operator==(re b)const { Int c; return *this == (c = b); };
        inline bool operator!=(re b)const { Int c; return *this != (c = b); };
    };
}
#endif
static constexpr const unsigned long long MAXN = static_cast<unsigned long long>((unsigned long long int)((const unsigned long long)(static_cast<unsigned long long>((1145141919810ull << 63Ull) + 1145141919810uLL))) / (static_cast<unsigned long long>(10000000))) % (static_cast<unsigned long long>(10000000));