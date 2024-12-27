//这个代码里面有很多+1，-1这些操作，这个和差分方式与画的坐标方向有关系
//属于个人思维习惯，代码参考一下，然后最好自己用自己的方式写一遍 
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
struct mat{
	int x1,y1,x2,y2;
}a[N];
int num[4*N],cnt;
int b[4*N][4*N];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y2,&a[i].x2,&a[i].y1);//这里y1和y2交换了含义，这是为了让x1<x2,y1<y2，更方便 
		num[++cnt]=a[i].x1;
		num[++cnt]=a[i].y1;
		num[++cnt]=a[i].x2;
		num[++cnt]=a[i].y2;
	}
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	for(int i=1;i<=n;++i){
		int x1=lower_bound(num+1,num+cnt+1,a[i].x1)-num;
		int x2=lower_bound(num+1,num+cnt+1,a[i].x2)-num;
		int y1=lower_bound(num+1,num+cnt+1,a[i].y1)-num;
		int y2=lower_bound(num+1,num+cnt+1,a[i].y2)-num;
		--x2;//整点与格点的转化，题目给的是坐标系上的整点，但我们希望能直接计算在格子上（类似地毯那个题） 
		--y2;
		b[x2+1][y2+1]+=1;//二维差分 
		b[x2+1][y1]-=1;
		b[x1][y1]+=1;
		b[x1][y2+1]-=1;
	}
	for(int i=1;i<=cnt;++i){//还原一次 
		for(int j=1;j<=cnt;++j){
			b[i][j]+=b[i][j-1];
		}
	}
	for(int i=1;i<=cnt;++i){//再还原一次 
		for(int j=1;j<=cnt;++j){
			b[i][j]+=b[i-1][j];
		}
	}
	long long ans=0;
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){//如果被覆盖了，就把这个矩形的面积加入到答案里面。 
			if(b[i][j]>0) ans+=((ll)num[i+1]-num[i])*((ll)num[j+1]-num[j]);
		}
	}
	cout<<ans;
	return 0;
}
