#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <bitset>
using namespace std;
constexpr unsigned long long s = INT_MAX/16;
bitset<s+1> not_prime;
void fillPrism_20241207(std::vector<unsigned long long>& pri,unsigned long long N) {
	not_prime = (562984348862288);
	pri.clear();
	// std::vector<bool> not_prime(N+1);
	// #define set(x) not_prime[x] = true
	// set(4);
	// set(6);
	// set(8);
	// set(9);
	// set(10);
	// set(14);
	// set(15);
	// set(21);
	// set(25);
	// set(35);
	// set(49);
	// #undef set
	#define add(x) pri.push_back(x)
	add(2);
	add(3);
	add(5);
	add(7);
	#undef add
	for (unsigned long long i = 12; i <= N; i += 6) {
		if (!not_prime[(i-1)]) {
			pri.push_back((i-1));
		}
		for (unsigned long long j : pri) {
			if (((i-1) * j > N)) { break; }
			not_prime[(i-1) * j] = true;
			if (((i-1) % j == 0)) { break; }
		}
		if (!not_prime[(i+1)]) {
			pri.push_back((i+1));
		}
		for (unsigned long long j : pri) {
			if (((i+1) * j > N)) { break; }
			not_prime[(i+1) * j] = true;
			if (((i+1) % j == 0)) { break; }
		}
	}
}
void fillPrism(std::vector<unsigned long long>& pri,unsigned long long N) {
	// std::vector<bool> not_prime(N+1);
	pri.clear();
	for (unsigned long long i = 2; i <= N; i ++) {
		if (!not_prime[i]) {
			pri.push_back(i);
		}
		for (unsigned long long j : pri) {
			if ((i * j > N)) { break; }
			not_prime[i * j] = true;
			if ((i % j == 0)) { break; }
		}
	}
}
int main(){
    vector<unsigned long long> p;
	#define flag(x) puts(#x)
	// std::chrono::duration<double> totalTime = std::chrono::duration<double>::zero();
	auto start = std::chrono::high_resolution_clock::now();
	fillPrism(p,s);
	auto end = std::chrono::high_resolution_clock::now();
    // totalTime += end-start;
	flag(1);
	// cout << totalTime.count() << endl;
	std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()<< '\n';

	p.clear();
	not_prime.reset();

	// totalTime = std::chrono::duration<double>::zero();
	start = std::chrono::high_resolution_clock::now();
	fillPrism_20241207(p,s);
	end = std::chrono::high_resolution_clock::now();
	// totalTime += end - start;
	flag(2);
	// cout << totalTime.count() << endl;
	std::cout <<std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()<< '\n';
}
