#include "color.hpp"
#include <bitset>
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
#define C_pause system("pause")
#define C_end return 0
#define not_(ABC) ABC = not ABC
#define elif else if
#define r(...) return __VA_ARGS__
#define ull unsigned long long
#undef min
#undef max
#define min(a,b) (a>b?b:a)
#define max(a,b) (a<b?b:a)
typedef signed int SI;
typedef unsigned int UI;
typedef signed long SL;
typedef unsigned long UL;
typedef signed short SS;
typedef unsigned short US;
typedef signed long long SLL;
typedef unsigned long long ULL;
typedef signed char SC;
typedef unsigned char UC;
HANDLE STDOUTHANDLE = GetStdHandle(STD_OUTPUT_HANDLE);
class SCREENINFO {
public:
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	SCREENINFO() {
		GetConsoleScreenBufferInfo(STDOUTHANDLE, &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left +1;//已经实践证实
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	}
	void update() {
		GetConsoleScreenBufferInfo(STDOUTHANDLE, &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left;// +1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top;// +1;
	}
};
static void operator>>(std::string & L, char& R) {
	if (not L.empty()) {
		R = L.back();
		L.pop_back();
	}
	else {
		R = -1;
	}
};
static void operator<<(std::string& L, char R) {
	L.push_back(R);
};
struct NAME {
	std::string name;
	NAME(std::string str) {name = str;}
	NAME(){}
};
NAME to_name(std::string str) {
	return NAME(str);
};
void fillPrism(std::vector<int>& pri,int N) {
	std::vector<bool> not_prime;
	not_prime.clear();
	not_prime.resize(static_cast<std::vector<bool, std::allocator<bool>>::size_type>(N) + 1, 0);
	pri.push_back(2);
	not_prime[4] = true;
	for (int i = 3; i <= N; i += 2) {
		if (!not_prime[i]) {
			pri.push_back(i);
		}
		for (int j : pri) {
			if ((i * j > N)) { break; }
			not_prime[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(i) * j] = true;
			if ((i % j == 0)) { break; }
		}
	}
}
void fillPrism_update(std::vector<int>& pri,int limit) {
	std::vector<bool> not_prime;
	not_prime.resize(static_cast<std::vector<bool, std::allocator<bool>>::size_type>(limit) + 1, 0);
	not_prime[4] = true;
	not_prime[6] = true;
	not_prime[8] = true;
	not_prime[9] = true;
	pri.push_back(2);
	pri.push_back(3);
	//注意,这种筛法筛不出5
	//所以i改成了i-1
	for (int i = 6; i-1/**/ <= limit; i += 6) {
		if (!not_prime[i - 1]) {
			pri.push_back(i - 1);
		}
		for (int j : pri) {
			if (((i - 1) * j > limit)) { break; }
			not_prime[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(i - 1) * j] = true;
			if (((i - 1) % j == 0)) { break; }
		}
		if (!not_prime[i + 1]) {
			pri.push_back(i + 1);
		}
		if (i + 1 > limit) { break; }
		for (int j : pri) {
			if (((i + 1) * j > limit)) { break; }
			not_prime[static_cast<std::vector<bool, std::allocator<bool>>::size_type>(i + 1) * j] = true;
			if (((i + 1) % j == 0)) { break; }
		}
	}
}
long long kgcd(long long a, long long b)
{
	if (a == 0) return b;
	if (b == 0) return a;
	if (!(a & 1) && !(b & 1))
		return kgcd(a >> 1, b >> 1) << 1;
	else if (!(b & 1))
		return kgcd(a, b >> 1);
	else if (!(a & 1))
		return kgcd(a >> 1, b);
	else
		return kgcd(abs(a - b), min(a, b));
}
bool isPrime(ull n) {
	if (n < 2 || (!(n & 1))) r(false);
	int sqrtnum = (int)floor(sqrt(n)) + 1;
	for (ull i = 3; i < sqrtnum; i += 2) {
		if (n % i == 0) {
			r(false);
		}
	}
	r(true);
}
//reverse output_mode
	bool output_choose = false;
	static void RevOUTM() { not_(output_choose); }
	int global_output = 0;
//0 for global,1 for each
class Text {
public:
	std::vector<std::string> data = { "" };
	std::string data_name;
	int output = 0;
	void operator<<(const std::string& str) {
		if (data.empty()) { new_line(); }
		if (not data.back().empty()) {
			new_line();
		}
		for (size_t i = 0; i < str.length(); i++) {
			if (str[i] == '\n') {
				new_line();
			}
			else {
				data.back().push_back(str[i]);
			}
		}
	};
	const std::string &operator[](const int a) {
		return data[a];
	};
	void operator=(const Text& L) {
		data = L.data;
	};
	void operator=(const std::string& str) {
		clear();
		operator<<(str);
	}
	void print() {
		if (not data_name.empty()) {
			printf("★%s_", data_name.c_str());
		}
		global_output++;
		output++;
		printf("OUTPUT★[%d]:\n",output_choose?output:global_output);
		
		for (size_t i = 0; i < data.size(); i++) {
			std::cout << data[i] << std::endl;
		}
		printf("===☆END☆===");
	};
	void clear() {
		data.clear();
		new_line();
	};
	void new_line() {
		data.push_back("");
	};
	void pop_back() {
		if (not data.empty()) {
			data.pop_back();
		}
	}
	//for output last_line
	void operator>>(std::string& R) {
		if (not data.empty()) {
			R = data.back();
			pop_back();
		}
		else
		{
			R = "";
		}
	};
	void set_name(std::string name) {
		data_name = name;
	};
	Text(NAME str) {
		data_name = str.name;
	};
	Text(std::string dat) {
		operator<<(dat);
		data_name = "NULL";
	}
	Text(NAME nam, std::string dat) {
		data_name = nam.name;
		operator<<(dat);
	}
	Text(void) {
		data_name = "NULL";
	}
};
class STN {
public:
	std::string intpart;
	std::string doublepart;
	std::string bufpart;
	bool zf = true;//true = postive | negtive
	int bufprecision = 100;
	int doubleprecision = 5;
	int intprecision = 100;
	void operator=(int n) {
		init();
		if (n < 0) {
			zf = false;
			n = -n;
		}
		for (int cur = 0; n && cur < intprecision; cur++) {
			intpart[cur] = n % 10+'0';
			n /= 10;
		}
		reverse(intpart.begin(), intpart.end());
	};
	void operator=(double n) {
		init();
		if (n < 0) {
			zf = false;
			n = -n;
		}
		int intp = floor(n);
		for (int cur = 0; intp && cur < intprecision; cur++) {
			intpart[cur] = intp % 10 + '0';
			intp /= 10;
		}
		reverse(intpart.begin(), intpart.end());
		n = n - intp;
		for (int cur = 0; n && cur < doubleprecision; cur++) {
			n *= 10;
			doublepart[cur] = (int)floor(n) % 10 + '0';
			n = n - floor(n);
		}
	}
	void operator=(std::string str) {
		init();
		if (str[0] == '-') {
			zf = false;
		}
		int j = 0,begin = zf?0:1,cur = intprecision-1,end =str.length()-1;
		for(;j < str.length() && str[j] != '.';j++){}
		for (int i = j - 1; i >= begin && cur >= 0; i--) {
			intpart[cur] = str[i];
			cur--;
		}
		if(j < end)
		{
			cur = 0;
			for (int i = j + 1; i <= end && doubleprecision > cur; i++) {
				doublepart[cur] = str[i];
				cur++;
			}
		}
	}
	bool operator>(const STN& R) {
		const STN L = *this;
		if (L.zf ^ R.zf) { return L.zf > R.zf; }
		if (L.intprecision > R.intprecision) {
			for (int i = L.intprecision - 1; i >= R.intprecision; i--) {
				if (L.intpart[i]^'0') { return true; }
			}
		}
		elif (L.intprecision > R.intprecision) {
			for (int i = R.intprecision - 1; i >= L.intprecision; i--) {
				if (R.intpart[i]^'0') { return false; }
			}
		}
		for (int i = min(L.intprecision, R.intprecision) - 1; i >= 0; i--) {
			if (L.intpart[i] ^ R.intpart[i]) { return L.intpart[i] > R.intpart[i]; }
		}
		return false;
	}
	void print() {
		//const int l = intpart.length();
		//for (int i = 0; i < l; i++) {
		//	putchar(intpart[i]);
		//}
		if (not zf)putchar('-');
		printf("%s.%s", intpart.c_str(),doublepart.c_str());
	};
	void print_fix() {
		int i,j;
		for (i = 0; i < intprecision; i++) {
			if (intpart[i] != '0') { break; }
		}
		i = min(i, intprecision - 1);
		for (j = doubleprecision - 1; j >= 0; j--) {
			if (doublepart[j] != '0') { break; }
		}
		printf("%s.", intpart.c_str() + i);
		for (i = 0; i <= j; i++) {
			putchar(doublepart[i]);
		}
	}
	void setprecis(const int &intlong, const int &doublelong) {
		doubleprecision = doublelong;
		intprecision = intlong;
	}
	void init() {
		intpart.clear();
		doublepart.clear();
		for (int i = 0; i < intprecision; i++) {
			intpart.push_back('0');
		}
		for (int i = 0; i < doubleprecision; i++) {
			doublepart.push_back('0');
		}
		zf = true;
	}
	void operator*(const int &num) {
		if (num < 0) {
			not_(zf);
		}
		const int n = abs(num);
		int t = 0,carry = 0;
		for (int i = doubleprecision - 1; i >= 0; i--) {
			t = (doublepart[i] - '0') * n+carry;
			doublepart[i] = t % 10+'0';
			carry = (t / 10);
		}
		for (int i = intprecision-1; i >=0; i--) {
			t = (intpart[i] - '0') * n + carry;
			intpart[i] = t % 10 + '0';
			carry = (t / 10);
		}
	}
	void operator+(const STN& O) {
		int t, carry = 0;
		for (int i = min(doubleprecision,O.doubleprecision) - 1; i >= 0; i--) {
			t = (doublepart[i] - '0' + O.doublepart[i] - '0');
			carry = (t + carry) / 10;
			doublepart[i] = t % 10 + '0';
		}
		for (int i = min(intprecision, O.intprecision) - 1; i >= 0; i--) {
			t = (intpart[i] - '0' + O.intpart[i] - '0');
			carry = (t + carry) / 10;
			intpart[i] = t % 10 + '0';
		}
	}
	void operator>>(int n) {
		if (n == 0)return;
		if (n > 0) {
			if (n <= doubleprecision) {
				for (int i = doubleprecision - 1; i >= n; i--) {
					doublepart[i] = doublepart[i - n];
				}//最后一位到进入int
				for (int i = n-1; i >= 0; i--) {
					doublepart[i] = intpart[intprecision-n+i];
				}//double <--> int
				for (int i = intprecision - 1; i >= n; i--) {
					intpart[i] = intpart[i - n];
				}//int最后一位到n
				for (int i = n - 1; i >= 0; i--) {
					intpart[i] = '0';
				}
			}
			elif(n > doubleprecision) {

			}
		}
	}
	void operator*(const STN& O) {
		STN T(0);
		
	}
	inline STN(int n) {
		operator=(n);
	};
	inline STN(double n) {
		operator=(n);
	};
	
};
bool operator<(STN& L, STN& R) {
	return R > L;
}
class bits {
public:
	size_t precision;
	std::vector<bool> Bits;
	void setpre(size_t si) {
		precision = si;
		Bits.resize(si, 0);
	}
	void operator++() {
		for (size_t i = precision - 1; i >= 0; i--) {
			if (Bits[i] == 0) {
				Bits[i] = 1;
				break;
			}
			else {
				Bits[i] = 0;
			}
		}
	}
};
//POW
/*
static inline unsigned long long qpow(unsigned long long base,unsigned long long pow_time){
	unsigned long long ret = 1;
	while(pow_time){
		if(pow_time&1)	ret *= base;
		pow_time>>=1;
		base*=base;
	}
	return ret;
}
static inline unsigned long long qpow(unsigned long long base,unsigned long long pow_time,unsigned long long mod){
	unsigned long long ret = 1;
	while(pow_time){
		if(pow_time&1)	ret =(ret*base)%mod;
		pow_time>>=1;
		base=(base*base)%mod;
	}
	return ret;
}
static inline unsigned long long qpow(unsigned long long base,unsigned long long pow_time,unsigned long long mod){
	unsigned long long ret = 1;
	for(;pow_time;base=(base*base)%mod,pow_time>>=1){
		if(pow_time&1)	ret =(ret*base)%mod;
	}
	return ret;
}
*/
//LENGTH
/*
unsigned long long length(unsigned long long x){
	return log10l(x)+1;
}
unsigned long long length_base2(unsigned long long n){
	return (unsigned long long)(log10l(2)*n+1);
}
*/
//#define s signed
//#define u unsigned
//#define c char
//#define i int
//#define l long
//#define uc u c
//#define ui u i
//#define ul u l
//#define sc s c
//#define si s i
//#define sl s l
//#define ll l l
//#define ull u ll
//#define sll s ll
/*luogu
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
*/
/*
class LIS{//uses dp
	public:
	int max_len=0;
	vector<int> nums;//数字
	vector<int> li;//最长数值
	void insert(int O){
		int i = nums.size();
		nums.push_back(O);
		li.push_back(1);
		for(int j = 0; j < i; j++){
			if(nums[j] < nums[i]){
				li[i] = max(li[i],li[j]+1);
			}
		}
		max_len = max(max_len,li[i]);
	}
};
*/
//gcd
/*
*/