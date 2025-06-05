#include <bits/stdc++.h>
using namespace std;
int l=1,r=2;
size_t ca(void){
	return (l*(r-l+1))+((r-l+1)*(r-l))/2;
}
int main(){
	int m;
	cin >> m;
	while(1){
		if(l*2>=m){
			break;
		}
		if(ca()<m){
			r++;
			continue;
		}
		if(ca()>m){
			l++;
			continue;
		}
		if(ca()==m){
			printf("%d %d\n",l,r);
			l++;
			continue;
		}
	}
}