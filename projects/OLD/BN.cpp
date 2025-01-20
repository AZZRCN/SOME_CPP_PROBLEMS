#if 0
#include <iostream>
#define ll long long
const ll W = 100000000;

const ll s = 8;

const ll WS[8] = { 10000000,1000000,100000,10000,1000,100,10,1 };
using namespace std;
struct BigInt {
    bool flag;
    int size;
    ll values[4000];

    BigInt() {
        this->clear();
    }

    void clear() {
        memset(values, 0, sizeof values);
        this->size = 1;
        this->flag = true;
    }

    void operator =(int x) {
        this->clear();
        if (x == 0)
            return;
        ll cnt = 0;
        if (x < 0)
            x = -x, this->flag = false;
        while (x) {
            this->values[cnt] = x % W;
            x /= W;
            cnt++;
        }
        this->size = cnt;
    }

    void operator =(char* x) {
        this->clear();
        ll start = 0;
        ll len = strlen(x);
        if (len >= 1 && x[0] == '-')
            this->flag = false, start++;
        ll size = (len - start) % s ? (len - start) / s + 1 : (len - start) / s;
        this->size = size;
        ll cnt = 0;
        for (ll i = 0; i < this->size; i++) {
            for (ll j = s - 1; j >= 0; j--)
                this->values[cnt] = this->values[cnt] * 10 + (len - i * s - j - 1 >= start && x[len - i * s - j - 1] ? x[len - i * s - j - 1] - '0' : 0);
            cnt++;
        }
    }

    void operator =(BigInt x) {
        this->clear();
        this->size = x.size;
        this->flag = x.flag;
        for (int i = 0; i < this->size; i++)
            this->values[i] = x.values[i];
    }

    BigInt operator +(BigInt x) const {
        if (this->flag && x.flag) {
            BigInt y = *this;
            add(y, x);
            return y;
        }
        else if (this->flag) {
            x.flag = true;
            BigInt y = *this;
            subtract(y, x);
            return y;
        }
        else if (x.flag) {
            BigInt a = *this;
            a.flag = true;
            subtract(a, x);
            a.flag = false;
            return a;
        }
        else {
            BigInt a = *this;
            a.flag = true;
            x.flag = true;
            add(a, x);
            a.flag = false;
            return a;
        }
    }

    BigInt operator *(BigInt x) const {
        bool flag = this->flag == x.flag;
        BigInt y;
        y = *this;
        multiply(y, x);
        y.flag = flag;
        return y;
    }

    BigInt operator *(ll x) const {
        BigInt i;
        i = x;
        return this->operator *(i);
    }

    BigInt operator /(BigInt x) const {
        bool flag = this->flag == x.flag;
        BigInt y;
        y = *this;
        divide(y, x);
        y.flag = flag;
        return y;
    }

    BigInt operator /(ll x) const {
        BigInt i;
        i = x;
        return this->operator /(i);
    }

    void operator /=(BigInt x) {
        bool flag = this->flag == x.flag;
        divide(*this, x);
        this->flag = flag;
    }

    void operator /=(ll x) {
        BigInt i;
        i = x;
        this->operator /=(i);
    }

    BigInt operator %(BigInt x) {
        bool flag = this->flag == x.flag;
        BigInt y = *this;
        mod(y, x);
        y.flag = flag;
        return y;
    }

    BigInt operator %(ll x) {
        BigInt i;
        i = x;
        this->operator %(i);
    }

    void operator *=(BigInt x) {
        bool flag = this->flag == x.flag;
        multiply(*this, x);
        this->flag = flag;
    }

    void operator *=(ll x) {
        BigInt i;
        i = x;
        this->operator *=(i);
    }

    BigInt operator -(BigInt x) const {
        x.flag ^= 1;
        return this->operator +(x);
    }

    BigInt operator -() const {
        BigInt x = *this;
        x.flag ^= 1;
        return x;
    }

    BigInt operator +(ll x) const {
        BigInt i;
        i = x;
        return *this + i;
    }

    BigInt operator -(ll x) const {
        BigInt i;
        i = x;
        return *this - i;
    }

    void operator +=(BigInt x) {
        if (this->flag && x.flag)
            add(*this, x);
        else if (this->flag) {
            x.flag = true;
            subtract(*this, x);
        }
        else if (x.flag) {
            this->flag = true;
            subtract(*this, x);
            this->flag = false;
        }
        else {
            this->flag = true;
            x.flag = true;
            add(*this, x);
            this->flag = false;
        }
    }

    void operator +=(ll x) {
        BigInt i;
        i = x;
        return this->operator +=(i);
    }

    void operator -=(ll x) {
        BigInt i;
        i = x;
        return this->operator -=(i);
    }

    void operator -=(BigInt x) {
        x.flag ^= 1;
        this->operator +=(x);
    }

    BigInt operator ++() {
        this->operator +=(1);
        return *this;
    }

    BigInt operator --() {
        this->operator +=(-1);
        return *this;
    }

    char* charValue() const {
        ll maxcnt = 0;
        ll start = 0;
        if (!this->flag)
            start++;
        char* t = new char[this->size * s + 1 + start];
        if (!this->flag)
            t[0] = '-';
        for (ll i = 0; i < this->size; i++) {
            for (ll j = s - 1; j >= 0; j--) {
                t[i * s + s - 1 - j + start] = (this->values[i] / WS[j]) % 10 + '0';
                if (t[i * s + s - 1 - j + start] != '0')
                    maxcnt = i * s + s - 1 - j + start;
            }
        }
        t[maxcnt + 1] = 0;
        reverse(t + start, t + maxcnt + 1);
        return t;
    }

    operator char* () const {
        return charValue();
    }

    bool operator==(BigInt x) const {
        if (this->size != x.size)
            return false;
        if (this->size == 1 && this->values[0] == x.values[0] && this->values[0] == 0)
            return true;
        if (this->flag != x.flag)
            return false;
        for (ll i = 0; i < this->size; i++)
            if (this->values[i] != x.values[i])
                return false;
        return true;
    }

    bool operator==(int x) const {
        BigInt y;
        y = x;
        return *this == y;
    }

    bool operator !=(BigInt x) const {
        if (*this == x)
            return false;
        return true;
    }

    bool operator <(BigInt x) const {
        if (this->size > x.size)
            return false;
        else if (this->size < x.size)
            return true;
        if ((ll)this->flag > (ll)x.flag)
            return false;
        for (ll i = this->size - 1; i >= 0; i--) {
            if (this->values[i] < x.values[i]) {
                if (this->flag)
                    return true;
                else return false;
            }
            else if (this->values[i] > x.values[i]) {
                if (this->flag)
                    return false;
                else return true;
            }
        }
        return false;
    }

    bool operator >(BigInt x) const {
        if (*this < x)
            return false;
        if (*this == x)
            return false;
        return true;
    }

    bool operator <=(BigInt x) const {
        if (*this > x)
            return false;
        return true;
    }

    bool operator >=(BigInt x) const {
        if (*this < x)
            return false;
        return true;
    }

    bool operator !() const {
        if (this->size != 1)
            return true;
        if (this->values[0] != 0)
            return true;
        return false;
    }

    void println() {
        print(*this);
        printf("\n");
    }

    static void add(BigInt& a, BigInt b) {
        ll cnt = max(a.size, b.size) + 1;
        for (ll i = 0; i < cnt; i++) {
            ll t = a.values[i] + b.values[i];
            if (t >= W)
                a.values[i] = t - W, a.values[i + 1]++;
            else
                a.values[i] = t;
        }
        if (a.values[cnt - 1])
            a.size = cnt;
        else
            a.size = cnt - 1;
    }

    static void subtract(BigInt& a, BigInt b) {
        if (a == b) {
            a = 0;
            return;
        }
        if (a < b)
            swap(a, b), a.flag = false;
        ll maxcnt = 0;
        ll cnt = max(a.size, b.size);
        bool flag = false;
        for (ll i = 0; i < cnt; i++) {
            ll t = a.values[i] - b.values[i];
            if (flag)
                t--, flag = false;
            if (t < 0)
                flag = true, a.values[i] = t + W;
            else
                a.values[i] = t;
            if (a.values[i])
                maxcnt = i;
        }
        a.size = maxcnt + 1;
    }

    static void multiply(BigInt& a, BigInt b) {
        if (a == 1) {
            a = b;
            return;
        }
        if (a == 0 || b == 0) {
            a = 0;
            return;
        }
        if (b == 1) {
            return;
        }
        ll size = a.size + b.size;
        ll* ts = new ll[size];
        for (ll i = 0; i < size; i++)
            ts[i] = 0;
        for (ll i = 0; i < a.size; i++)
            for (ll j = 0; j < b.size; j++) {
                ll t = a.values[i] * b.values[j];
                if (t >= W)
                    ts[i + j] += t % W, ts[i + j + 1] += t / W;
                else
                    ts[i + j] += t;
            }
        for (ll i = 0; i < size; i++) {
            if (ts[i] >= W)
                ts[i + 1] += ts[i] / W, ts[i] %= W;
            a.values[i] = ts[i];
        }
        if (ts[size - 1])
            a.size = size;
        else a.size = size - 1;
    }

    static void divide(BigInt& a, BigInt b) {
        if (a < b) {
            a = 0;
            return;
        }
        if (a == b) {
            a = 1;
            return;
        }
        if (b == 0) {
            a = 0;
            return;
        }
        if (b == 1)
            return;
        if (b == 2) {
            divide2(a);
            return;
        }
        BigInt left, right;
        left = pow10_(max(0, a.size - b.size - 1)), right = pow10_(a.size - b.size + 1);
        while (left <= right) {
            BigInt mid;
            mid = left + right;
            divide2(mid);
            BigInt o = mid * b;
            BigInt o2 = o + b;
            if (o <= a && o2 > a) {
                a = mid;
                return;
            }
            else if (o2 <= a)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    static void divide2(BigInt& a) {
        for (ll i = 0; i < a.size; i++) {
            ll t = a.values[i];
            if (t % 2 == 0 || i == 0)
                a.values[i] /= 2;
            else
                a.values[i] /= 2, a.values[i - 1] += W / 2;
        }
        if (!a.values[a.size - 1])
            a.size--;
    }

    static BigInt pow10_(int x) {
        BigInt y;
        if (x == 0) {
            y = 1;
            return y;
        }
        y.size = x;
        y.values[x - 1] = WS[0];
        return y;
    }

    static BigInt pow10(ll x) {
        ll size = (x + 1) % s == 0 ? (x + 1) / s : (x + 1) / s + 1;
        BigInt y;
        y.size = size;
        if ((x + 1) % s) {
            y.values[(x + 1) / s] = WS[s - (x + 1) % s];
        }
        else
            y.values[(x + 1) / s - 1] = WS[0];
        return y;
    }

    static void mod(BigInt& a, BigInt b) {
        BigInt x = a;
        divide(x, b);
        a -= b * x;
    }

    static void print(BigInt x) {
        if (!x.flag)
            cout << "-";
        cout << x.values[x.size - 1];
        for (ll i = x.size - 2; i >= 0; i--)
            print(x.values[i], s);
    }

    static void print(char* x) {
        cout << x;
    }

    static void print(ll x, ll d) {
        for (ll i = 0; i < d; i++)
            cout << (x / WS[i]) % 10;
    }

    static void swap(BigInt& a, BigInt& b) {
        BigInt x = a;
        a = b;
        b = x;
    }
};
#ifndef INT128_H
#define INT128_H

#ifdef CONFIG_INT128

typedef __int128_t Int128;

static inline Int128 int128_make64(uint64_t a)
{
    return a;
}

static inline Int128 int128_make128(uint64_t lo, uint64_t hi)
{
    return (__uint128_t)hi << 64 | lo;
}

static inline uint64_t int128_get64(Int128 a)
{
    uint64_t r = a;
    assert(r == a);
    return r;
}

static inline uint64_t int128_getlo(Int128 a)
{
    return a;
}

static inline int64_t int128_gethi(Int128 a)
{
    return a >> 64;
}

static inline Int128 int128_zero(void)
{
    return 0;
}

static inline Int128 int128_one(void)
{
    return 1;
}

static inline Int128 int128_2_64(void)
{
    return (Int128)1 << 64;
}

static inline Int128 int128_exts64(int64_t a)
{
    return a;
}

static inline Int128 int128_and(Int128 a, Int128 b)
{
    return a & b;
}

static inline Int128 int128_rshift(Int128 a, int n)
{
    return a >> n;
}

static inline Int128 int128_add(Int128 a, Int128 b)
{
    return a + b;
}

static inline Int128 int128_neg(Int128 a)
{
    return -a;
}

static inline Int128 int128_sub(Int128 a, Int128 b)
{
    return a - b;
}

static inline bool int128_nonneg(Int128 a)
{
    return a >= 0;
}

static inline bool int128_eq(Int128 a, Int128 b)
{
    return a == b;
}

static inline bool int128_ne(Int128 a, Int128 b)
{
    return a != b;
}

static inline bool int128_ge(Int128 a, Int128 b)
{
    return a >= b;
}

static inline bool int128_lt(Int128 a, Int128 b)
{
    return a < b;
}

static inline bool int128_le(Int128 a, Int128 b)
{
    return a <= b;
}

static inline bool int128_gt(Int128 a, Int128 b)
{
    return a > b;
}

static inline bool int128_nz(Int128 a)
{
    return a != 0;
}

static inline Int128 int128_min(Int128 a, Int128 b)
{
    return a < b ? a : b;
}

static inline Int128 int128_max(Int128 a, Int128 b)
{
    return a > b ? a : b;
}

static inline void int128_addto(Int128* a, Int128 b)
{
    *a += b;
}

static inline void int128_subfrom(Int128* a, Int128 b)
{
    *a -= b;
}

#else /* !CONFIG_INT128 */

typedef struct Int128 Int128;

struct Int128 {
    uint64_t lo;
    int64_t hi;
};

static inline Int128 int128_make64(uint64_t a)
{
    return (Int128) { a, 0 };
}

static inline Int128 int128_make128(uint64_t lo, uint64_t hi)
{
    return (Int128) { lo, hi };
}

static inline uint64_t int128_get64(Int128 a)
{
    assert(!a.hi);
    return a.lo;
}

static inline uint64_t int128_getlo(Int128 a)
{
    return a.lo;
}

static inline int64_t int128_gethi(Int128 a)
{
    return a.hi;
}

static inline Int128 int128_zero(void)
{
    return int128_make64(0);
}

static inline Int128 int128_one(void)
{
    return int128_make64(1);
}

static inline Int128 int128_2_64(void)
{
    return (Int128) { 0, 1 };
}

static inline Int128 int128_exts64(int64_t a)
{
    return (Int128) { .lo = a, .hi = (a < 0) ? -1 : 0 };
}

static inline Int128 int128_and(Int128 a, Int128 b)
{
    return (Int128) { a.lo& b.lo, a.hi& b.hi };
}

static inline Int128 int128_rshift(Int128 a, int n)
{
    int64_t h;
    if (!n) {
        return a;
    }
    h = a.hi >> (n & 63);
    if (n >= 64) {
        return int128_make128(h, h >> 63);
    }
    else {
        return int128_make128((a.lo >> n) | ((uint64_t)a.hi << (64 - n)), h);
    }
}

static inline Int128 int128_add(Int128 a, Int128 b)
{
    uint64_t lo = a.lo + b.lo;

    /* a.lo <= a.lo + b.lo < a.lo + k (k is the base, 2^64).  Hence,
     * a.lo + b.lo >= k implies 0 <= lo = a.lo + b.lo - k < a.lo.
     * Similarly, a.lo + b.lo < k implies a.lo <= lo = a.lo + b.lo < k.
     *
     * So the carry is lo < a.lo.
     */
    return int128_make128(lo, (uint64_t)a.hi + b.hi + (lo < a.lo));
}

static inline Int128 int128_neg(Int128 a)
{
    uint64_t lo = -a.lo;
    return int128_make128(lo, ~(uint64_t)a.hi + !lo);
}

static inline Int128 int128_sub(Int128 a, Int128 b)
{
    return int128_make128(a.lo - b.lo, (uint64_t)a.hi - b.hi - (a.lo < b.lo));
}

static inline bool int128_nonneg(Int128 a)
{
    return a.hi >= 0;
}

static inline bool int128_eq(Int128 a, Int128 b)
{
    return a.lo == b.lo && a.hi == b.hi;
}

static inline bool int128_ne(Int128 a, Int128 b)
{
    return !int128_eq(a, b);
}

static inline bool int128_ge(Int128 a, Int128 b)
{
    return a.hi > b.hi || (a.hi == b.hi && a.lo >= b.lo);
}

static inline bool int128_lt(Int128 a, Int128 b)
{
    return !int128_ge(a, b);
}

static inline bool int128_le(Int128 a, Int128 b)
{
    return int128_ge(b, a);
}

static inline bool int128_gt(Int128 a, Int128 b)
{
    return !int128_le(a, b);
}

static inline bool int128_nz(Int128 a)
{
    return a.lo || a.hi;
}

static inline Int128 int128_min(Int128 a, Int128 b)
{
    return int128_le(a, b) ? a : b;
}

static inline Int128 int128_max(Int128 a, Int128 b)
{
    return int128_ge(a, b) ? a : b;
}

static inline void int128_addto(Int128* a, Int128 b)
{
    *a = int128_add(*a, b);
}

static inline void int128_subfrom(Int128* a, Int128 b)
{
    *a = int128_sub(*a, b);
}

#endif /* CONFIG_INT128 */
#endif /* INT128_H */
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
        inline void re_l() {
            re i, x = 0, k = 1, L = 0, fl, o; char c = getchar(); for (; c < '0' || c>'9'; c = getchar()); for (; c >= '0' && c <= '9'; c = getchar()) {
                if (!(L - 1) && !aux[L])
                    L--; aux[++L] = c - '0';
            }; CL(); l = L / 8 + ((o = L % 8) > 0); for (i = 1; i <= o; i++) { x = x * 10 + aux[i]; }; if (o) { s[l] = x; fl = !o ? l + 1 : l; }for (i = o + 1, x = 0; i
                <= L; i++, k++) {
                x = x * 10 + aux[i]; if (!(k ^ 8)) { s[--fl] = x, x = k = 0; };
            }; if (!l) { l = 1; };
        };
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