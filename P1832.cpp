#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
using namespace std;
#define int long long
constexpr int prime_max_limit = 1000000000;
bitset<prime_max_limit+1> not_prime;
//update 2
// void fillPrism_20241207(std::vector<unsigned long long>& pri,unsigned long long N) {
// 	not_prime = (562984348862288);//把这个放到定义里y去
// 	pri.clear();
// 	// std::vector<bool> not_prime(N+1);
// 	// #define set(x) not_prime[x] = true
// 	// set(4);
// 	// set(6);
// 	// set(8);
// 	// set(9);
// 	// set(10);
// 	// set(14);
// 	// set(15);
// 	// set(21);
// 	// set(25);
// 	// set(35);
// 	// set(49);
// 	// #undef set
// 	#define add(x) pri.push_back(x)
// 	add(2);
// 	add(3);
// 	add(5);
// 	add(7);
// 	#undef add
// 	for (unsigned long long i = 12; i <= N; i += 6) {
// 		if (!not_prime[(i-1)]) {
// 			pri.push_back((i-1));
// 		}
// 		for (unsigned long long j : pri) {
// 			if (((i-1) * j > N)) { break; }
// 			not_prime[(i-1) * j] = true;
// 			if (((i-1) % j == 0)) { break; }
// 		}
// 		if (!not_prime[(i+1)]) {
// 			pri.push_back((i+1));
// 		}
// 		for (unsigned long long j : pri) {
// 			if (((i+1) * j > N)) { break; }
// 			not_prime[(i+1) * j] = true;
// 			if (((i+1) % j == 0)) { break; }
// 		}
// 	}
// }
//update 1
// void fillPrism_update(std::vector<int>& pri,int limit) {
// 	// bitset<prime_max_limit+1> not_prime(848);//把这个放到not_prime定义里去
// 	pri.push_back(2);
// 	pri.push_back(3);
// 	for (unsigned int i = 6; i-1 <= limit; i += 6) {
// 		const int t = i-1,t2 = i+1,div1=limit/(i-1),div2=limit/(i+1);
// 		if (!not_prime[t]) {
// 			pri.push_back(t);
// 		}
// 		for (unsigned int j : pri) {
// 			if (j>div1) { break; }
// 			not_prime[t * j] = true;
// 			if ((t % j == 0)) { break; }
// 		}
// 		if (t2 > limit) { return; }
// 		if (!not_prime[t2]) {
// 			pri.push_back(t2);
// 		}
// 		for (unsigned int j : pri) {
// 			if (j>div2) { break; }
// 			not_prime[t2 * j] = true;
// 			if ((t2 % j == 0)) { break; }
// 		}
// 	}
// }
//OI Wiki
// void pre(std::vector<int>& pri,int n) {
//   	for (int i = 2; i <= n; ++i) {
//     	if (!not_prime[i]) {
//       		pri.push_back(i);
//     	}
//     	for (int pri_j : pri) {
//       		if (i * pri_j > n) break;
//       		not_prime[i * pri_j] = true;
//       		if (i % pri_j == 0) {
//         		break;
//       		}
//     	}
//   	}
// }
//手写prime
// void fillPrism(std::vector<unsigned long long>& pri,unsigned long long N) {
// 	// std::vector<bool> not_prime(N+1);
// 	pri.clear();
// 	for (unsigned long long i = 2; i <= N; i ++) {
// 		if (!not_prime[i]) {
// 			pri.push_back(i);
// 		}
// 		for (unsigned long long j : pri) {
// 			if ((i * j > N)) { break; }
// 			not_prime[i * j] = true;
// 			if ((i % j == 0)) { break; }
// 		}
// 	}
// }
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