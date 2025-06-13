/**
 * First of all:
 * 第一点：
 * All the Functions are directly copied,but I can sure that it is able to run.
 * 所有函数都是直接复制的，但我确定它们能直接使用
 * If can't,then check the includes is or not full.
 * 如果不能，看看库有没有导入全
 * Second:
 * 第二点：
 * This is a file with ... A LOT things
 * 这是一个有一坨东西的oi.cpp
 * The prupose is give tools and examples
 * 意在提供工具和例子
 * And be used widely
 * 然后被广泛使用
 * 
 * 你最好不要把这些文件，因为定义了许多不必要的东西
 * 这个文件旨在给大家提供思路（主要）
 * 如果你直接复制的函数有问题（一些变量没有定义）
 * 你有自信的话可以直接手写，因为一般都是默认的空的变量
 * 比如: vector<int> v;
 * 
 * 如果你有意向（意见等）
 * 包括但不限于：提交一些你想要的函数，让我重新构建一下namespace，或者你来提供现成的namespace列表
 * 请在Issue里提交?
 * 
 * How to Find me:
 * Bilibili 夕阳下的中学生
 * Github   AZZRCN
 * 各平台是AZZR,AZZRCN或者BD_AZZR_CN,都有可能失我
 * 我技术不高，所以没啥技术含量
 * 当成宣传了，希望有人看
 * 
 * 天下大同
*/
#include <random>
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <assert.h>
using namespace std;
#define is_in_oi_namespace
namespace oi{
//a:1->2->3->end
//b:9->7->-1->end
//cat_list(a,next(a.begin()),b)
//a:1->9->7->-1->2->3->end
#define cat_list(_Dist_to_Add_,_Dist_Insert_Position_,_Src_List) _Dist_to_Add_.splice(_Dist_Insert_Position_,_Src_List)
//str = "AKFW0"
//sub(str,1,3)
//"KFW"
// #define sub(_Dist_,_Start_Position_,_Sub_Length_) _Dist_.substr(_Start_Position_,_Sub_Length_)
#define sub(_Dist_,...) _Dist_.substr(__VA_ARGS__)
// char c[] = "ABC";
// put(c,c+3,stdout);
// out:ABC
#define put(_Dist_,_End_,_Stream_) fwrite(_Dist_,sizeof(char),_End_-_Dist_+1,stdout);
/**
 * An example of class and p(cur)
 * class example_class_p{public:
 *     int b,a;string str;int d;
 *     template<typename t>
 *     t* get(long long offest = 0){
 *         return (t*)((unsigned char*)this+offest);
 *     }
 * };
 * int main(){
 *     example_class_p a({20,10,"abcd",999});
 *     cout << *(a.get<int>(8+sizeof(string)));
 * }
*/
#define itera_for(type,dist_name,it_name)\
for(type::iterator it_name = dist_name.begin();it_name != dist_name.end(); it_name++)
#define use(x) const x&
#define error(_Cond) assert(!(_Cond));
#define fast __forceinline __fastcall
#define lam(name,catch_args,args,return_type,do_what) auto name = catch_args args->return_type do_what;//{return return_what;};
#define force_con(type,x) *(type*)&x
// #ifndef fast_io
//     inline void out(const int& n){
//         printf("%d ",n);
//     }
// #endif
#define test_process(times,func,...) \
for(unsigned long long i = 1,last = 0; i <= times; i++){\
    if(i*100/times>last)printf("\r%d%%",(last=i*100/times));\
    func(__VA_ARGS__);\
}
#define test_process_std(times,std_func,func,...) \
for(unsigned long long i = 1,last = 0; i <= times; i++){\
    if(i*100/times>last){printf("%d%%\n",(last=i*100/times));}\
    if(std_func(__VA_ARGS__)!=func(__VA_ARGS__)){printf("unequal_at:%d\n",i);}\
}
#define test(times,func,...) \
for(int i = 1; i <= times; i++){\
    func(__VA_ARGS__);\
}
    inline const int dec_len(int n){
        int ans = (n==0);
        while(n){
            n/=10;
            ans++;
        }
        return ans;
    }
    namespace data{
        // template<typename _Count>
        // vector<pair<_Count,size_t>> count_unorder(vector<_Count> v){
        //     unordered_map<_Count,size_t> c;
        //     vector<pair<_Count,size_t>> ret;
        //     for(_Count&i:v){
        //         if(c.find(i)!=c.end()){c.find(i)->second++;}
        //         else{c.insert(make_pair(i,1));}
        //     }
        //     for(pair<_Count,size_t> i:c){ret.push_back(i);}
        //     return ret;
        // }
        template<typename _Ty>
        unordered_set<_Ty> most(vector<_Ty> &vec){
            unordered_map<_Ty, size_t> mp;
            unordered_set<_Ty> _;
            size_t __ = 0;
            for (_Ty i : vec){
                if (mp.find(i) == mp.end()){mp.insert(make_pair(i, 1));}
            else{mp[i]++;}}
            for (pair<_Ty, size_t> i : mp){
                if (i.second > __){
                    _.clear();_.insert(i.first);
                __ = i.second;continue;}
                if (i.second == __){_.insert(i.first);continue;}
            } return _;
        }
        template<typename _Ty>
        vector<_Ty> most(vector<_Ty>& vec){
            unordered_map<_Ty,size_t> mp;
            for(_Ty i : mp){
                if(mp.find(i) == mp.end()){
                    mp.insert(make_pair(i,1));
                }
                else{
                    mp[i]++;
                }
            }
            vector<_Ty> _;
            size_t __ = 0;
            for(pair<_Ty,size_t> i:mp){
                if(i.second>__){
                    _.clear();
                    _.push_back(i.first);
                    __ = i.second;
                    continue;
                }
                if(i.second == __){
                    _.push_back(i.first);
                    continue;
                }
            }
            return _;
        }
        vector<pair<size_t,size_t>> elements_in_vector_position(vector<int>& Dist,vector<int>& src){
            //locate
            vector<pair<int,int>> v;
            for(int i = 0; i < Dist.size(); i++){
                v.push_back({Dist[i],i});
            }
            sort(v.begin(),v.end());
            sort(src.begin(),src.end());
            //now we have the nums and the positions
            int v_cur = 0;
            int src_cur = 0;
            int last = 0;
            int be,en;
            vector<pair<size_t,size_t>> ret;
            #define safe (v_cur<v.size()&&src_cur<src.size())
            for(;v_cur<v.size()&&src_cur<src.size();){
                while(safe && v[v_cur].first != src[src_cur]){
                    while(safe&&v[v_cur].first>src[src_cur]){
                        src_cur++;
                        ret.push_back({0,0});
                    }
                    while(safe&&v[v_cur].first<src[src_cur]){
                        v_cur++;
                    }
                }
                if(!safe){
                    break;
                }
                last = v[v_cur].first;
                be = v[v_cur].second;
                for(;v_cur<v.size()&&v[v_cur].first==last;v_cur++);
                en = v[v_cur-1].second;
                ret.push_back({be,en});
                v_cur++;
                src_cur++;
            }
            #undef safe
            for(;src_cur<src.size();src_cur++){
                ret.push_back({0,0});
            }
            return ret;
        }
        template<typename _Count>
        inline vector<pair<_Count,size_t>> count_unorder(vector<_Count> v,vector<pair<_Count,size_t>>&ret){
            unordered_map<_Count,size_t> c;
            for(_Count&i:v){
                if(c.find(i)!=c.end()){c.find(i)->second++;}
                else{c.insert(make_pair(i,1));}
            }
            for(pair<_Count,size_t> i:c){ret.push_back(i);}
            return ret;
        }
        void fill_rand(list<int>& Dist,int Size_){
            srand(time(0)|19491001);
            Dist.clear();
            while(Size_--){
                Dist.push_back(rand());
            }
        }
        namespace sort_{
            list<int> tmp[10];
            inline void shuffle(const int& Mod_ten,list<int>& data){
                while(!data.empty()){
                    tmp[(data.front()/Mod_ten)%10].push_back(data.front());
                    data.pop_front();
                }
            }
            inline void collect(list<int>& data){
                for(int i = 0; i < 10; i++){
                    cat_list(data,data.end(),tmp[i]);
                }
            }
            void auto_lsd(list<int>& l){
                int maxn = 0;
                for(int i : l){
                    maxn = max(maxn,dec_len(i));
                }
                int mod = 1;
                for(int i = 1; i <= maxn; i++){
                    mod *= 10;
                    shuffle(mod,l);
                    collect(l);
                }
            }
            //重要:times指的是最后times+1位保持有序
            //例如lsd(...,1):
            //1,3,73,889,951->
            //1,3,951,73,889
            //而不是
            //1,951,3,73,889
            void lsd(list<int>& l,int times){
                int mod = 1;
                for(int i = 1; i <= times; i++){
                    mod*=10;
                    shuffle(mod,l);
                    collect(l);
                }
            }
            vector<int> findMostElement(vector<int>& n){
                unordered_map<int,int> um;
                for(int i:n){
                    if(um.find(i) == um.end()){um.insert(make_pair(i,1));}
                    else{um[i]++;}
                }
                vector<int> ret;
                int max = -1;
                for(pair<int,int> i : um){
                    if(i.second<max){continue;}
                    if(i.second>max){
                        ret.clear();
                        max = i.second;
                    }
                    ret.push_back(i.first);
                }
                return ret;
            }
        }
    }
    namespace tools{
        template<typename _Ty>
        class counterV1/*计数器*/{
            public:
            unordered_map<_Ty,size_t> um;
            __forceinline __fastcall void operator+(const _Ty x){add(x);}
            __forceinline __fastcall void operator-(const _Ty x){del(x);}
            __forceinline void clear() const {um.clear();}
            __forceinline bool empty() const {return um.empty();}
            void merge(const counterV1<_Ty>&c){for(pair<_Ty,size_t>&i:c.um){add(i.first,i.second);}}
            bool contains(const _Ty x){return um.find(x) != um.end();}
            __forceinline __fastcall const void add(const _Ty x)             {typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){it->second++;}else{um.insert(make_pair<const _Ty&,size_t>(x,1));}}
            __forceinline __fastcall const void add(const _Ty x,size_t times){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){it->second += times;}else{um.insert(make_pair<const _Ty&,size_t>(x,times));}}
            __forceinline __fastcall const void del(const _Ty x)             {typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){if(it->second > 0){it->second--;}else{um.erase(it);}}}
            __forceinline __fastcall const void del(const _Ty x,size_t times){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);if(it != um.end()){if(it->second > times){it->second -= times;}else{um.erase(it);}}}
            //count a element
            __forceinline size_t count(const _Ty&x){typename unordered_map<_Ty,size_t>::iterator it = um.find(x);return ((it != um.end()) ? (it->second) : (0));}
            //count the elements
            __forceinline __fastcall size_t size() const {return um.size();}
            //the number of all elements
            __forceinline size_t total() const {size_t ret = 0;for(const pair<_Ty,size_t>&i:um){ret += i.second;}return ret;}
            _Ty most()/*最多元素(随机顺序,只返回一个)*/{_Ty maxn;size_t max_;for(pair<_Ty,size_t> i:um){if(i.second>max_){max_ = i.second;maxn = i.first;}}return maxn;}
            vector<_Ty> most_repeat()/*最多元素(随机顺序,返回多个)*/{vector<_Ty> maxn;size_t max_;for(pair<_Ty,size_t>&i:um)
            {if(i.second>max_){maxn.clear();maxn.push_back(i.first);max_ = i.second;continue;}if(i.second == max_){maxn.push_back(i.first);}}return maxn;}
            vector<_Ty> all_key()/*所有元素,乱序*/{vector<_Ty> v;for(pair<const _Ty,size_t>&i:um){v.push_back(i.first);}return v;}
            void print(){for(pair<_Ty,size_t> i:um){cout << i.first << " " << i.second << endl;}}
            friend std::ostream& operator<<(std::ostream& os, const counter& c) {for(const auto& pair : c.um) {os << pair.first << " " << pair.second << std::endl;}return os;}
        };
    }
    namespace bin{
        template<int sus_size=64>
        string bin_to_string(unsigned long long x){
            static_assert(sus_size>0,"你还给人留活路吗？");
            if(x==0){return"0";}
            bitset<sus_size> bs;int last = 0;string ret;
            while(x&&last<sus_size){bs[last++]=(x&1);x>>=1;}
            last--;
            while(last>=0){ret.push_back(bs[last--]|'0');}
            return ret;
        }
        template<typename T>
        bool mem_equal(T a,T b){
            char* _a = (char*)&a;
            char* _b = (char*)&b;
            int loop = sizeof(T);
            while(loop--){
                if(*(_a++)!=*(_b++))return false;
            }
            return true;
        }
        template<typename T,typename T2>
        bool mem_equal_sizebyfirst(T a,T2 b){
            char* _a = (char*)&a;
            char* _b = (char*)&b;
            int loop = sizeof(T);
            while(loop--){
                if(*(_a++)!=*(_b++))return false;
            }
            return true;
        }
        // bool memequal(void* A,void* B,size_t size){
        //     unsigned char *_A = (unsigned char*)A,*_B = (unsigned char*)B;
        //     while(size--){
        //         if(*(_A++)!=*(_B++)){
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        // template<typename t = void>
        // void memout(t* A,size_t size){
        //     unsigned char *_A = (unsigned char*)A;
        //     size_t it = 0;
        //     while(it != size){
        //         printf("%02hx ",*(_A++));
        //         it++;
        //         if(it%8==0){
        //             putchar(' ');
        //         }
        //     }
        //     putchar('\n');
        // }
        // template<typename t>
        // void memout(t& A){
        //     unsigned char *_A = (unsigned char*)&A;
        //     size_t it = 0;
        //     while(it != sizeof(t)){
        //         printf("%02hx ",*(_A++));
        //         it++;
        //         if(it%8==0){
        //             putchar(' ');
        //         }
        //     }
        //     putchar('\n');
        // }
        // template<typename t>
        // void memout_rev(t& A){
        //     const unsigned char *_A = (unsigned char*)&A;
        //     signed int it = sizeof(t)-1;
        //     while(it>=0){
        //         printf("%02hx ",*(_A+it));
        //         it--;
        //         if(it%8==7){
        //             putchar(' ');
        //         }
        //     }
        //     putchar('\n');
        // }
        //check whether the _catch_ each one bit is also one is _Host_
        inline bool bites_belong(use(int) _Host_,use(int) _catch_){
            return ((_Host_&_catch_)==_catch_);
        }
        //从右侧数第一个0的位置
        //
        int pop_(uint64_t n){
            int ans = 0;
            if(n&0xFFFFFFFF00000000){ans+=32;n>>=32;}
            if(n&0x00000000FFFF0000){ans+=16;n>>=16;}
            if(n&0x000000000000FF00){ans+=8;n>>=8;}
            if(n&0x00000000000000F0){ans+=4;n>>=4;}
            if(n&0x000000000000000C){ans+=2;n>>=2;}
            if(n&0x0000000000000002){ans+=1;n>>=1;}
            if(n&0x0000000000000001){ans+=1;n>>=1;}
            return ans;
        }
        inline int count_one(int x){
            int ans = 0;
            while(x){
                x &= (x-1);
                ans++;
            }
            return ans;
        }
        int max_multi2_signed(int x){
            while(!(x>>(sizeof(int)*8-2))){
                x<<=1;
            }
            return x;
        }
        class bit_iterator{
            public:void* p;char of;/*1-7*/
            bit_iterator(void* cur=nullptr,int offest=0){p=cur;of=offest;}
            void flip(){*(char*)p=((*(unsigned char*)(p))^(1<<of));}
            void chk(){p += (of/8);of%=8;}
            void operator+=(const int& n){p += (n+of)/8;of = (n+of)%8;}
        };
        // void fputbin(const auto& obj,FILE* _stream,char byte_end='\0'){
        //     char* buf = (char*)malloc(9);
        //     buf[8] = byte_end;
        //     unsigned char* r = (unsigned char*)&obj + sizeof(obj)-1;
        //     unsigned char c;
        //     char* _buf;
        //     // #define fill(_Dist,dynamic_position,_val) _Dist[dynamic_position] = _val
        //     for(int i = 0; i < sizeof(obj); i++){
        //         _buf = buf+7;
        //         c = *r;
        //         for(int j = 0 ; j < 8; j++){
        //             *(_buf--)=('0'+((c>>j)&1));
        //         }
        //         r--;
        //         fwrite(buf,sizeof(char),9,stdout);
        //     }
        // }
        // void fputbin(const auto& obj,FILE* _stream,char byte_end='\0'){
        //     char* buf = (char*)malloc(9);char* _buf;buf[8] = byte_end;
        //     unsigned char* r = (unsigned char*)&obj + sizeof(obj)-1;
        //     unsigned char c;
        //     for(int i = 0; i < sizeof(obj); i++){
        //         _buf = buf+7;c = *(r--);
        //         for(int j = 0 ; j < 8; j++){*(_buf--)=('0'+((c>>j)&1));}
        //         fwrite(buf,sizeof(char),9,stdout);
        //     }
        // }
        // void fputbin(const auto& obj,FILE* _stream,char byte_end='\0'){
        //     char* buf = (char*)malloc(9);buf[8] = byte_end;
        //     unsigned char* r = (unsigned char*)&obj + sizeof(obj)-1;
        //     unsigned char c;
        //     for(int i = 0; i < sizeof(obj); i++){
        //         c = *(r--);
        //         buf[7]=('0'|((c>>0)&1));
        //         buf[6]=('0'|((c>>1)&1));
        //         buf[5]=('0'|((c>>2)&1));
        //         buf[4]=('0'|((c>>3)&1));
        //         buf[3]=('0'|((c>>4)&1));
        //         buf[2]=('0'|((c>>5)&1));
        //         buf[1]=('0'|((c>>6)&1));
        //         buf[0]=('0'|((c>>7)&1));
        //         fwrite(buf,sizeof(char),9,stdout);
        //     }
        // }
        inline static void f1(char* buf,const unsigned char&c){
            buf[7]=('0'|((c>>0)&1));
            buf[6]=('0'|((c>>1)&1));
            buf[5]=('0'|((c>>2)&1));
            buf[4]=('0'|((c>>3)&1));
        }
        inline static void f2(char*buf,const unsigned char&c){
            buf[3]=('0'|((c>>4)&1));
            buf[2]=('0'|((c>>5)&1));
            buf[1]=('0'|((c>>6)&1));
            buf[0]=('0'|((c>>7)&1));
        }
        void fputbin(const auto& obj,FILE* _stream,char byte_end='\0'){
            char* buf = (char*)malloc(9);buf[8] = byte_end;
            unsigned char* r = (unsigned char*)&obj + sizeof(obj)-1;
            unsigned char c;
            for(int i = 0; i < sizeof(obj); i++,r--){
                thread(f1,buf,*r).join();
                thread(f2,buf,*r).join();
                fwrite(buf,sizeof(char),9,stdout);
            }
        }
    }
    namespace kmp{
        vector<int> prefix_function(string s) {
            int n = (int)s.length();
            vector<int> pi(n);
            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) j = pi[j - 1];
                if (s[i] == s[j]) j++;
                pi[i] = j;
            }
            return pi;
        }
        vector<int> find_occurrences(string text, string pattern) {
            string cur = pattern + '#' + text;
            int sz1 = text.size(), sz2 = pattern.size();
            vector<int> v;
            vector<int> lps = prefix_function(cur);
            for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
                if (lps[i] == sz2) v.push_back(i - 2 * sz2);
            }
            return v;
        }
        vector<int> kmp_single(const string& _Dist, const string& _Pattern) {
            const int D = _Dist.length();
            const int P = _Pattern.length();
            
            vector<int> pv(P, 0); // 前缀数组
            vector<int> ans; // 匹配结果的存储

            // 计算前缀数组
            for (int i = 1; i < P; i++) {
                int j = pv[i - 1];
                while (j > 0 && _Pattern[i] != _Pattern[j]) {
                    j = pv[j - 1];
                }
                pv[i] = (j + (_Pattern[i] == _Pattern[j]));
            }

            // KMP 匹配过程
            int j = 0; // 模式的当前匹配位置
            for (int i = 0; i < D; i++) { // 从 0 开始遍历 _Dist
                while (j > 0 && _Dist[i] != _Pattern[j]) {
                    j = pv[j - 1];
                }
                if (_Dist[i] == _Pattern[j]) {
                    j++;
                }
                if (j == P) {
                    ans.push_back(i - P + 1); // 匹配成功，存储匹配位置（从0索引）
                    j = pv[j - 1]; // 继续查找下一个可能的匹配
                }
            }
            return ans;
        }
        vector<int>kmp_20241116(const string&_Dist,const string&_Pattern){
            const int D=_Dist.length(),P=_Pattern.length();int j,i;vector<int>pv(P,0),ans;
            for(i=1,j=pv[0];i<P;++i,j=pv[i-1]){
                while(j&&_Pattern[i]!=_Pattern[j]&&(j=pv[j-1],1));
                pv[i]=(j+(_Pattern[i]==_Pattern[j]));
            }for(i=j=0;i<D;i++){
                while(j&&_Dist[i]!=_Pattern[j]&&(j=pv[j-1],1));
                j+=(_Dist[i]==_Pattern[j]);if(j==P){ans.push_back(i-P+1);j=pv[j-1];}
            }return ans;
        }
    }
    namespace math{
        namespace roma{
            //罗马数字
            string intToRoman(int num) {int values[] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };string reps[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
                string res;for (int i = 0; i < 13; i++) {while (num >= values[i]) {num -= values[i];res += reps[i];}}return res;}
            inline const char* convertor(int num)/*查找数值对应的罗马字符*/{
                switch (num) {
                case 0: fail:return ""; /*0为特殊情况，需注意*/
                case 1:return"I";case 2:return"II";case 3:return"III";case 4:return"IV";case 5:return"V";case 6:return"VI";case 7:return"VII";case 8:return"VIII";case 9:return"IX";
                case 10:return"X";case 20:return"XX";case 30:return"XXX";case 40:return"XL";case 50:return"L";case 60:return"LX";case 70:return"LXX";case 80:return"LXXX";case 90:return"XC";
                case 100:return"C";case 200:return"CC";case 300:return"CCC";case 400:return"CD";case 500:return"D";case 600:return"DC";case 700:return"DCC";case 800:return"DCCC";case 900:return"CM";
                case 1000:return"M";case 2000:return"MM";case 3000:return"MMM";
                default: goto fail;
                }
            }
            string intToRoman2(int num) {return (string)convertor(num / 1000 * 1000) /*千位*/ + convertor(num / 100 % 10 * 100) /*百位*/ + convertor(num / 10 % 10 * 10) /*十位*/ + convertor(num % 10); /*个位*/}
            int romatoint(char c){/*DEBUG*/if(c=='T')return 0;if(c=='I')return 1;if(c=='V')return 5;if(c=='X')return 10;if(c=='L')return 50;if(c=='C')return 100;if(c=='D')return 500;if(c=='M')return 1000;}
            int romanToInt(string s) {
                s.push_back('T');
                int last = 0;
                int ret = 0;
                int now = 0;
                for(char c:s){
                    last = now;
                    now = romatoint(c);
                    if(last<now){ret-=last;}
                    else{ret += last;}
                }
                return ret;
            }
        }
        #define int long long
        //注释：此三者预期工作环境为long long
        //bitset的大小需要自己更改，下方变量是方便测试用的
        constexpr int prime_max_limit = 1000000000;
        bitset<prime_max_limit+1> not_prime(0);
            // not_prime = 848;
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
            // not_prime = (562984348862288);
        void fillPrism_20241207(std::vector<int>& pri,unsigned long long N) {
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
            (((((0)))));
            {{{{}}}};
            for (int i = 12; i <= N; i += 6) {
                if (!not_prime[(i-1)]) {
                    pri.push_back((i-1));
                }
                for (int j : pri) {
                    if (((i-1) * j > N)) { break; }
                    not_prime[(i-1) * j] = true;
                    if (((i-1) % j == 0)) { break; }
                }
                if (!not_prime[(i+1)]) {
                    pri.push_back((i+1));
                }
                for (int j : pri) {
                    if (((i+1) * j > N)) { break; }
                    not_prime[(i+1) * j] = true;
                    if (((i+1) % j == 0)) { break; }
                }
            }
        }
        void fillPrism(std::vector<int>& pri,int n) {
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
        #undef int
        static __forceinline bool is_prime20241209(const unsigned long long x) {
            if (x <= 1) return false;  // 0 and 1 are not prime numbers
            if (x == 2 || x == 3) return true;  // 2 and 3 are prime numbers
            if (x % 2 == 0 || x % 3 == 0) return false;  // multiples of 2 and 3 are not prime

            // Check for factors from 5 to sqrt(x)
            for (unsigned long long i = 5; i * i <= x; i += 6) {
                if (x % i == 0 || x % (i + 2) == 0) return false;
            }
            return true;
        }
        long double insert(vector<pair<long double,long double>> v,long double _x){
            long double ret = 0;
            long double t = 0;
            //[x,y]
            for(int i = 0; i < v.size(); i++){
                t = v[i].second;
                for(int j = 0; j < v.size(); j++){
                    if(j == i) {continue;}
                    t = t * (_x-v[j].first) / (v[i].first-v[j].first);
                }
                ret += t;
            }
            return ret;
        }
        int kgcd(int x,int y){
            if(!x)return y;
            if(!y)return x;
            if(!((x&1)|(y&1))){
                return kgcd(x>>1,y>>1)<<1;
            } else if(!(x&1)){
                return kgcd(x>>1,y);
            } else if(!(y&1)){
                return kgcd(x,y>>1);
            } else {
                return kgcd(abs(x-y),min(x,y));
            }
        }
    }
    namespace data_struct{
        fast void set(const void* _Dist,const void* _Val,size_t size){
            unsigned char* Dist = (unsigned char*)_Dist, * Val = (unsigned char*)_Val;
            while(size--){
                *(Dist++) = *(Val++);
            }
        }
        fast void set(unsigned char* Dist,unsigned char* Val,size_t size){
            while(size--){
                *(Dist++) = *(Val++);
            }
        }
        fast void set(void* _Dist,void* _Val,size_t repeat,size_t each_size){
            unsigned char* Dist = (unsigned char*)_Dist, * Val = (unsigned char*)_Val;
            while(repeat--){
                set(Dist,Val,each_size);
                Dist += each_size;
            }
        }
        namespase arr{
            template<typename _Ty,int size>
            class arr{
                public:
                _Ty data[size];
                fast _Ty& operator[](const size_t x){
                    return *(data+x-1);
                }
                fast void set_memset(_Ty _val){
                    _Ty temp = _val;
                    ::set(data,&temp,size,sizeof(_Ty));
                }
                fast void set(_Ty _val){
                    _Ty const* be = begin();
                    _Ty const * en = end();
                    for(_Ty* i = be; i != en; i++){
                        // i->operator=(_val);
                        *(i) = _val;
                    }
                }
                constexpr fast _Ty* begin(){
                    return data+0;
                }
                constexpr fast _Ty* end(){
                    return data+size;
                }
                fast void print(){
                    for(_Ty*i = begin();i!=end();i++){
                        cout << *i << " ";
                    }
                    cout << endl;
                }
                template<typename t>
                fast void sort(t cmp){
                    ::sort(begin(),end(),cmp);
                }
            };
        }        
    }
}
/**
 * @package:个人自制
*/
/**
 * @name:传入路径和算子，来反转一个文件的内容
*/
bool rev_file_with_key(const char* path,unsigned long long key) {
    FILE* f = fopen64(path, "rb+");
    if (!f) {
        perror("File opening failed");
        return false;
    }
    unsigned char keys[8];
    // sizeof(unsigned long long);
    for(int i = 0; i < 8; i++){
        keys[i] = (key&0xFF);
        key >>= 8;
    }
    fseeko64(f, 0, SEEK_END);
    unsigned long long len = ftello64(f);
    fseeko64(f, 0, SEEK_SET);
    for (unsigned long long i = 0; i < len; i++) {
        fseeko64(f, i, SEEK_SET);  // 每次读取前定位到正确的位置
        unsigned char c;
        fread(&c, sizeof(unsigned char), 1, f);
        c = (~c)^(keys[i%8]);  // 对字符进行位取反
        fseeko64(f, i, SEEK_SET);  // 写之前再次定位到正确的位置
        fwrite(&c, sizeof(unsigned char), 1, f);
    }
    fclose(f);
    return true;
}
/**
 * @name:平方根
*/
int mySqrt(uint32_t x) {
    uint64_t l=0,r=0xFFFF,mid;
    while(r>=l){
        mid = (l+r)/2;//找出中间
        if(mid*mid==x){//返回条件
            return mid;
        }
        if(mid*mid<x){//左侧没有的判定条件
            l = mid + 1;
        }
        else{//右侧没有的判定条件
            r = mid-1;
        }
    }
    return (l+r)/2;
}
/**
 * @name:阶乘，logn
*/
double myPow(double x, int n) {
    if(x == (double)(1))return 1;
    if(n<0){
        x = 1/x;
    }
    double ans = 1;
    while(n){
        if((n&1)) ans *= x;
        n/=2;
        x*=x;
    }
    return ans;
}
/**
 * @name:获取控制台支付消息
 * @need:windows.h
*/
void get_windows_console_key_msgs(){
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    if (hInput == INVALID_HANDLE_VALUE) {
        // cerr << "获取标准输入句柄失败！" << endl;
        return 1;
    }
    INPUT_RECORD ibufs[128];
    // cout << "请输入字符（Ctrl+C 退出）：" << endl;
    while (true) {
        DWORD eventsRead;
        // 检查输入缓冲区中是否有事件
        if (PeekConsoleInput(hInput, ibufs, 128, &eventsRead) && eventsRead > 0) {
            DWORD count;
            // 读取输入事件
            ReadConsoleInput(hInput, ibufs, eventsRead, &count);
            for (DWORD i = 0; i < count; i++) {
                if (ibufs[i].EventType == KEY_EVENT && ibufs[i].Event.KeyEvent.bKeyDown) {
                    // 输出按下的字符
                    /*此时ibufs[i].Event.KeyEvent.uChar.AsciiChar就是按键消息*/
                    /*可进行修改*/
                    putchar(' ');
                    putchar(ibufs[i].Event.KeyEvent.uChar.AsciiChar);
                    // 在控制台输出换行符，以便后续输入清晰可见
                    fflush(stdout); // 确保字符立即显示
                }
            }
        }
        // 加入延时，避免占用CPU资源
        Sleep(10);
    }
}
/**
 * @name:获取控制台都说了点啥(控制台显示内容)
*/
void get_windows_console_what_outputed(){
    HANDLE hConOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwConSize;
    COORD upperLeft = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConOut, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    CHAR_INFO* chiBuffer = new CHAR_INFO[dwConSize];
    if (!ReadConsoleOutput(hConOut, chiBuffer, csbi.dwSize, upperLeft, &csbi.srWindow)) {
        std::cerr << "Failed to read console output." << std::endl;
        return 1;
    }
    std::ofstream ofs("console_output.txt");
    if (!ofs.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
        delete[] chiBuffer;
        return 1;
    }
    for (DWORD i = 0; i < dwConSize; ++i) {
        ofs << chiBuffer[i].Char.AsciiChar;
    }
    ofs.close();
    delete[] chiBuffer;
    std::cout << "Console output captured and written to 'console_output.txt'." << std::endl;
}