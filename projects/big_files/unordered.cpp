#include <iostream>
#include <unordered_set>
#define Hash2(type,chiletypeX,chiletypeY,chileX,childY,name) \
struct name{\
size_t operator()(const type& a)const{\
return std::hash<chiletypeX>()(a chileX) ^ std::hash<chiletypeY>()(a childY);\
}}
#define Equal2(type,childX,childY,name) \
struct name{\
bool operator()(const type& a,const type& b)const{\
return a childX == b childX && a childY == b childY;}}
#define hashF(type,childtypeX,childtypeY,childX,childY,Hname,Ename)\
struct Hname{size_t operator()(const type& a)const{return std::hash<childtypeX>()(a childX)^std::hash<childtypeX>()(a childY);}};\
struct Ename{bool operator()(const type& a,const type& b)const{return a childX == b childX && a childY == b childY;}};

#define hashFF(type,childtypeX,childtypeY,childX,childY,Hname,Ename,Sname)\
struct Hname{size_t operator()(const type& a)const{return std::hash<childtypeX>()(a childX)^std::hash<childtypeX>()(a childY);}};\
struct Ename{bool operator()(const type& a,const type& b)const{return a childX == b childX && a childY == b childY;}};\
std::unordered_set<type,Hname,Ename> Sname;
//#define defFirP(type,name) \
type* first = &name
#define defP(PNAME,type,name,_Val)\
type name = _Val;\
type* PNAME = &name;
#define defuP(PNAME,type,name)\
type name;\
type* PNAME = &name;
#define defu(type,name)\
type name;
#define def(type,name,_Val)\
type name = _Val;
/*template<typename T1, typename T2, typename T3>
T1 rHash2(T2 x,T3 y) {
	struct T1 {
		size_t operator()(const T2& x,const T3& y) {
			return hash<T2>()(x) ^ hash<T3>()y;
		}
	};
	return T1;
}*/
/*template<typename T1, typename T2, typename T3>
T1 rEqual2(T2 x, T3 y) {
	struct T1 {
		size_t operator()(const T2& x, const T3& y) {
			return hash<T2>()(x) == hash<T3>y;
		}
	};
	return T1;
}*/

#define DC2RULE "DC2T((STD)P)N(V) -> type ((fist ans second) or p_name) elem_name elem_value"
#define DC2TPNV(SN,T,P,N,V,T1,P1,N1,V1)\
class SN{public:defP(P,T,N,V);defP(P1,T1,N1,V1);SN(T a,T1 b){N = a;N1=b;}}
#define DC2TPN(SN,T,P,N,T1,P1,N1)\
class SN{public:defuP(P,T,N);defuP(P1,T1,N1);SN(T a,T1 b){N = a;N1=b;}}
#define DC2TSTDPN(SN,T,N,T1,N1)\
class SN{public:defuP(first,T,N);defuP(second,T1,N1);SN(T a,T1 b){N = a;N1=b;}}
#define DC2TSTDPNV(SN,T,N,V,T1,N1,V1)\
class SN{public:defP(first,T,N,V);defP(second,T1,N1,V1);SN(T a,T1 b){N = a;N1=b;}}
#define DC2TN(SN,T,N,T1,N1)\
class SN { public:defu(T,N); defu(T1,N1); SN(T a, T1 b) { N = a; N1 = b; } }
#define DC2TNV(SN,T,N,V,T1,N1,V1)\
class SN { public:def(T,N,V); def(T1,N1,V1); SN(T a, T1 b) { N = a; N1 = b; } }