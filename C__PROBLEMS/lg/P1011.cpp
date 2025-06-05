#include <bits/stdc++.h>
using namespace std;
#if (!defined __forceinline) || (defined CP)
#define open
#else
#define open freopen("..\\in","r",stdin);
#endif
unsigned long long fib(long long n) {
    if (n <= 1) return n;
    
    unsigned long long prev = 0, curr = 1;
    for(unsigned long long i = 2; i <= n; ++i) {
        unsigned long long next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
int main(){
    open;
    int m,n,s,x;
    cin >> m >> n >> s >> x;
    
	if(n == 2){
		cout << m;
		return 0;
	}
    int a;
    s -= (fib(n-3)+1)*m;
    a = s/(fib(n-2)-1);
    // cout << a;
    cout << (fib(x-1)-1)*a+(fib(x-2)+1)*m;
}
/**
 * fib()
*/