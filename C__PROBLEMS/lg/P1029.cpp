#include <bits/stdc++.h>
using namespace std;
#ifndef __forceinline
#define __forceinline
#define __fastcall
#endif
int cnt = 0;
int main(){
	int x,y;
	cin >> x >> y;
	if(x>y){
		swap(x,y);
	}
	for(int i = 2; i <= y; i++){
		while(x%i==0&&y%i==0){
			x/=i;
			y/=i;
		}
		if(x%i==0&&y%i!=0) {
			cout << 0;
			return 0;
		}
		if(y%i==0){
			cnt++;
			while(y%i==0){
				y/=i;
			}	
		}
	}
	if(x>1){
		cout << 0;
		return 0;
	}
	cout << (1<<cnt);
	return 0;
}