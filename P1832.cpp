#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
using namespace std;
#define int long long
constexpr int prime_max_limit = 1000000000;
bitset<prime_max_limit+1> not_prime(848);
void fillPrism_update(std::vector<int>& pri,int limit) {
	pri.push_back(2);
	pri.push_back(3);
	for (unsigned int i = 6; i-1 <= limit; i += 6) {
		const int t = i-1,t2 = i+1,div1=limit/(i-1),div2=limit/(i+1);
		if (!not_prime[t]) {
			pri.push_back(t);
		}
		for (unsigned int j : pri) {
			if (j>div1) { break; }
			not_prime[t * j] = true;
			if ((t % j == 0)) { break; }
		}
		if (t2 > limit) { return; }
		if (!not_prime[t2]) {
			pri.push_back(t2);
		}
		for (unsigned int j : pri) {
			if (j>div2) { break; }
			not_prime[t2 * j] = true;
			if ((t2 % j == 0)) { break; }
		}
	}
}
void pre(std::vector<int>& pri,int n) {
  	for (int i = 2; i <= n; ++i) {
    	if (!not_prime[i]) {
      		pri.push_back(i);
    	}
    	for (int pri_j : pri) {
      		if (i * pri_j > n) break;
      		not_prime[i * pri_j] = true;
      		if (i % pri_j == 0) {
        		break;
      		}
    	}
  	}
}
signed main(){
	freopen("D:\\std","w",stdout);
    vector<int> primes;
	std::chrono::duration<double> totalTime = std::chrono::duration<double>::zero();
	auto start = std::chrono::high_resolution_clock::now();
	pre(primes,(int)INT_MAX/16);
	auto end = std::chrono::high_resolution_clock::now();
	totalTime+=end-start;
    cout << totalTime.count() << endl;
	int cnt = 0;
	for(int i : primes){
		if(cnt == 10){
			cout << endl;
			cnt=0;
		}
		cout << i << "\t";
		cnt++;
	}
}