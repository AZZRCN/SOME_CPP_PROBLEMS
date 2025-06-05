//神
#include <iostream>
#include <vector>
#include <bitset>
#include <chrono>
using namespace std;
constexpr unsigned long long prime_max_limit = 1000000000;
bitset<prime_max_limit+1> not_prime;
// //update 2
// void fillPrism_20241207(std::vector<unsigned long long>& pri,unsigned long long N) {
// 	// not_prime = (562984348862288);//把这个放到定义里y去
// 	pri.clear();
// 	// std::vector<bool> not_prime(N+1);
// 	#define set(x) not_prime[x] = true
// 	set(4);
// 	set(6);
// 	set(8);
// 	set(9);
// 	set(10);
// 	set(14);
// 	set(15);
// 	set(21);
// 	set(25);
// 	set(35);
// 	set(49);
// 	#undef set
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
// //update 1
// // void fillPrism_update(std::vector<unsigned long long>& pri,unsigned long long limit) {
// // 	// bitset<prime_max_limit+1> not_prime(848);//把这个放到not_prime定义里去
// // 	pri.push_back(2);
// // 	pri.push_back(3);
// // 	for (unsigned long long i = 6; i-1 <= limit; i += 6) {
// // 		const unsigned long long t = i-1,t2 = i+1,div1=limit/(i-1),div2=limit/(i+1);
// // 		if (!not_prime[t]) {
// // 			pri.push_back(t);
// // 		}
// // 		for (unsigned long long j : pri) {
// // 			if (j>div1) { break; }
// // 			not_prime[t * j] = true;
// // 			if ((t % j == 0)) { break; }
// // 		}
// // 		if (t2 > limit) { return; }
// // 		if (!not_prime[t2]) {
// // 			pri.push_back(t2);
// // 		}
// // 		for (unsigned long long j : pri) {
// // 			if (j>div2) { break; }
// // 			not_prime[t2 * j] = true;
// // 			if ((t2 % j == 0)) { break; }
// // 		}
// // 	}
// // }
// //OI Wiki
// // void pre(std::vector<unsigned long long>& pri,unsigned long long n) {
// //   	for (unsigned long long i = 2; i <= n; ++i) {
// //     	if (!not_prime[i]) {
// //       		pri.push_back(i);
// //     	}
// //     	for (unsigned long long pri_j : pri) {
// //       		if (i * pri_j > n) break;
// //       		not_prime[i * pri_j] = true;
// //       		if (i % pri_j == 0) {
// //         		break;
// //       		}
// //     	}
// //   	}
// // }
// //手写prime
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
// 	// __debugbreak();
// }
void fillPrism_20250116(std::vector<unsigned long long>& pri,unsigned long long N) {
	pri.clear();
	// std::vector<bool> not_prime(N+1);
	#define set(x) not_prime[x] = true
	#define add(x) pri.push_back(x)
	add(2); add(3); add(5); add(7); add(11);
	add(13); add(17); add(19); add(23); add(29);

	set(4); set(6); set(8); set(9); set(10);
	set(12); set(14); set(15); set(16); set(18);
	set(20); set(21); set(22); set(24); set(25);
	set(26); set(27); set(28); set(30); set(32);
	set(33); set(34); set(35); set(36); set(38);
	set(39); set(40); set(42); set(44); set(45);
	set(46); set(48); set(49); set(50); set(51);
	set(52); set(54); set(55); set(56); set(57);
	set(58); set(60); set(63); set(65); set(69);
	set(75); set(77); set(81); set(85); set(87);
	set(91); set(95); set(115); set(119); set(121);
	set(125); set(133); set(143); set(145); set(161);
	set(169); set(187); set(203); set(209); set(221);
	set(247); set(253); set(289); set(299); set(319);
	set(323); set(361); set(377); set(391); set(437);
	set(493); set(529); set(551); set(667); set(841);
	#undef set
	#undef add
	#define do(x,y) const unsigned long long t##y = x+y;\
	if(!not_prime[t##y]){pri.push_back(t##y);}\
	for (unsigned long long j : pri) {\
		if((t##y*j>N)){break;}not_prime[t##y*j]=true;if((t##y%j==0)){break;}\
	}\

	for (unsigned long long i = 30; i <= N; i += 30) {
		do(i,1);
		do(i,7);
		do(i,11);
		do(i,13);
		do(i,17);
		do(i,19);
		do(i,23);
		do(i,29);
	}
}
signed main(){
    vector<unsigned long long> primes;
	std::chrono::duration<double> totalTime = std::chrono::duration<double>::zero();
	auto start = std::chrono::high_resolution_clock::now();
	fillPrism_20250116(primes,(unsigned long long) INT_MAX/16);
	auto end = std::chrono::high_resolution_clock::now();
	totalTime+=end-start;
    cout << totalTime.count() << endl;
	freopen("D:\\std","w",stdout);
    cout << totalTime.count() << endl;
	unsigned long long cnt = 0;
	for(unsigned long long i : primes){
		if(cnt == 10){
			cout << endl;
			cnt=0;
		}
		cout << i << "\t";
		cnt++;
	}
}
//10.0073