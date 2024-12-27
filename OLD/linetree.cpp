/*
* [1,5]
* |	   \____
* [1,3]     [4,5]
* |   \     |   \
* [1,2][2,3][4,4][4,5]
* |   \
* [1,1][2,2]
* * * * * * * * * * * * * * * * * *
* 这是基础操作，只进行一次！
* build(int l,int r,int p)
* eg:
* build(1,5,1)
* 即从1,5开始递归,当前节点编号为p
* 当前节点编号不只是叶子，也可以是区间
* 我们必须要把l,r,p看成一个整体
* build(l,r,p)
* if(l == r)
*   d[p]=a[l or r]
*   return;
* build(l,mid,ls(p))
* build(mid+1,r,rs(p))
* d[p] = sum(d[ls(p)],d[rs(p)])
* * * * * * * * * * * * * * * * * *
* make_b_mark(p,l,r)
* p是本节点编号,l是本节点左区间,r是本节点右区间
* (自己写的)
* m = (l+r)/2;
* d[ls(p)] += b[p] * (m-l+1);更新ls值
* d[rs(p)] += b[p] * (r-m);  更新rs值
* b[ls(p)] += b[p];更新ls懒惰标记
* b[rs(p)] += b[p];更新rs懒惰标记
* b[p] = 0;release(释放p懒惰标记)
* * * * * * * * * * * * * * * * * *
* update(l,r,c,s,t,p)(你也可以当做change)
* 牛魔的懒惰标记！
* =====* * * * * * * * * * * * * *
* =====* 所谓懒惰标记
* =====* 就是打标记，修改本节点
* =====* 但不立即修改该节点的子儿子的数值
* =====* 不管了！！！
* =====* 我的理解是
* =====* 当查询这个节点时
* =====* 如果有懒惰标记
* =====* 下放标记(不修改，直接传)
* =====* 修改孩子的值
* =====* 清空本节点标记
* =====* 返回值
* =====* 注:由于从上到下查询，可以保证一定会遍历懒惰标记
* =====* 越来越像完全递归了(bushi
* =====* * * * * * * * * * * * * *
* l,r是修改区间
* c是变化量
* s,t是当前节点负责区间
* p是节点编号
*
* 记住：查询过程中一定要写懒惰标记的处理
*
* 如果当前节点完全在lr中
* 打标记后,修改本节点,退出
* 否则就往下找
* update(l,r,c,s,t,p)
* if(l <= s && t <= r)
*   d[p]+=(t-s+1)*c
*   b[p] += c
*   return;
* m = (s+t)/2;
* make_b_mark(p,s,t);
* if(l<=m)update(l,r,c,s,m,ls(p));
* if(r>m) update(l,r,c,m+1,t,rs(p));
* dp[p] = dp[ls(p)]+dp[rs(p)];
* * * * * * * * * * * * * * * * * *
* sum(l,r,s,t,p)
* l,r为查询区间
* s,t为当前节点区间
* p为当前节点编号
* eg:sum(1,3,1,5,1)//我也不知道怎么想到的逻辑，翻得OIWIKI
* //反正是过了
* 你可以想成中央下放挖空区域
* 各X长下放本管辖区要求
* 发动群众挖空
* 如果本负责区域正好需要全部挖空,返回d[p]
* 否则处理懒惰标记,再往下细分,并"回收"值
* if(l<=s&&t<=r)return d[p];
* int m = (s+t)/2;
* make_b_mark(p,s,t);
* int ret = 0;
* if(l<=m) ret += sum(l,r,s,m,ls(p));
* if(m<r)  ret += sum(l,r,m+1,t,rs(p));
* return ret;
*/
template<int MAXN>
class lineTree {
public:
    long long a[MAXN + 1];
    long long d[MAXN + 1];//真值
    long long b[MAXN + 1];//懒惰标记
    inline long long ls(long long n) {
        return (n << 1);
    }
    inline long long rs(long long n) {
        return ((n << 1) | 1);
    }
    void build(long long l, long long r, long long p) {//左区间，右区间，当前节点编号
        if (l == r) {
            d[p] = a[l];
            return;
        }
        long long mid = (l + r) >> 1;
        build(l, mid, ls(p));
        build(mid + 1, r, rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    void make_b_mark(long long p, long long l, long long r) {
        long long m = (l + r) / 2;
        d[ls(p)] += b[p] * (m - l + 1);
        d[rs(p)] += b[p] * (r - m);
        b[ls(p)] += b[p];
        b[rs(p)] += b[p];
        b[p] = 0;
    }
    void update(long long l, long long r, long long c, long long s, long long t, long long p) {
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * c;
            b[p] += c;
            return;
        }
        long long m = (s + t) >> 1;
        make_b_mark(p, s, t);
        if (l <= m) update(l, r, c, s, m, ls(p));
        if (r > m) update(l, r, c, m + 1, t, rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    long long sum(long long l, long long r, long long s, long long t, long long p) {
        if (l <= s && t <= r)return d[p];
        long long m = (s + t) >> 1;
        make_b_mark(p, s, t);
        long long ret = 0;
        if (l <= m) ret += sum(l, r, s, m, ls(p));
        if (m < r)  ret += sum(l, r, m + 1, t, rs(p));
        return ret;
    }
    void operator()(long long n) {//上界
        build(1, n, 1);
    }
    lineTree() { ; };
};
//按照惯例，迫害一下锣鼓(喧天)
//关于P3373,这里是我的思路
//定义懒惰标记k,b,如果你不知道意义的话,看这个式子:y=kx+b
// 传递/添加k标记:
//  k[now]*=k;
//  b[now]*=k;
//  d[now]*=k;
// 传递/添加b标记
//  b[now]+=b;
//  d[now]+=(len*b)(这个不用写了，正常的包含)
// 传递时先传递k再传递b
//P3372
/*
#include <bits/stdc++.h>
using namespace std;
constexpr long long MAXN = 400000;
class lineTree{
    public:
    long long a[MAXN+1],d[MAXN+1],b[MAXN+1],mid,ret;
    inline long long ls(long long n){return  (n<<1)   ;}
    inline long long rs(long long n){return ((n<<1)|1);}
    void build(long long l,long long r,long long p){
        mid = (l+r)>>1;
        if(l==r){d[p]=a[l];return;}
        build(l,  mid,ls(p));
        build(mid+1,r,rs(p));
        d[p]=d[ls(p)]+d[rs(p)];
    }
    void make_b_mark(long long p,long long l,long long r){
        mid = (l + r)/2;
        d[ls(p)] += b[p] * (mid-l+1);
        d[rs(p)] += b[p] * (r-mid);
        b[ls(p)] += b[p];
        b[rs(p)] += b[p];
        b[p] = 0;
    }
    void update(long long l,long long r,long long c,long long s,long long t,long long p){
        if(l <= s && t <= r){d[p] += (t - s + 1) * c;b[p] += c;return;}
        mid = (s + t) >> 1;
        make_b_mark(p,s,t);
        if(l <= mid) update(l,r,c,s,  mid,ls(p));
        if(r > mid)  update(l,r,c,mid+1,t,rs(p));
        d[p] = d[ls(p)] + d[rs(p)];
    }
    long long sum(long long l,long long r,long long s,long long t,long long p){
        if(l <= s && t<=r)return d[p];
        mid = ((s + t) >> 1),ret=0;
        make_b_mark(p,s,t);
        if(l <= mid) ret += sum(l,r,s,mid,ls(p));
        if(mid < r)  ret += sum(l,r,mid+1,t,rs(p));
        return ret;
    }
    void operator()(long long n){build(1,n,1);}
    lineTree(){;};
};
lineTree t;
int main(){
    long long n,m,opt,a,b,c,i;
    cin >> n >> m;
    for(i = 1; i <= n; i++){cin >> t.a[i];}
    t(n);
    for(i = 1; i <=m ;i++){
        cin >> opt;
        if(opt == 1){cin >> a >> b >> c;t.update(a,b,c,1,n,1);}
        else{cin >> a >> b;cout << t.sum(a,b,1,n,1) << endl;}
    }
}
*/