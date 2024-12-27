#include <stdio.h>
#include <string.h>
#define fast __forceinline __fastcall const
template<typename _Ty>
_Ty __forceinline static constexpr max(_Ty a,_Ty b){
	return ((a>b)?(a):(b));
}
template<int size>
class bs{
	public:
	// using s = size;
	unsigned char dat[(size/8)+((size&0b111)?(1):(0))];
	fast bool operator[](unsigned int x){
		return (((dat[x/8])>>(x&0b111))&1);
	}
	fast void set(unsigned int x){
		(dat[x/8])|= (1<<(x&0b111));
	}
	fast void reset(unsigned int x){
		(dat[x/8])&= ((0b11111111)^(1<<(x&0b111)));
	}
	fast void set(void){
		memset(dat,0b11111111,(size/8)+((size&0b111)?(1):(0)));
	}

};
bs<100> b;
int main(){
	b.set();
	b.set(10);
	b.reset(10);
	printf("%d",b[9]);
}
/*
__forceinline bool _catch(const vector<int>& a,const vector<int>& b){
    if(a.size() != b.size()) return false;
    for(vector<int>::const_iterator _ = a.begin(),__ = b.begin();
        _ != a.end() && __ != b.begin();
        _++,__++){
        if(*_ != *__)return false;
    }
    return true;
}
*/