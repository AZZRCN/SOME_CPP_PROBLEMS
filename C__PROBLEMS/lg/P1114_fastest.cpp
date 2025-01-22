//https://www.luogu.com.cn/record/178236495
//免责声明：仅从洛谷复制，本人已通过，只能作为学习使用
//请勿直接CV
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __uint128_t

void out(lll x)
{
	if(x>9) out(x/10);
	putchar(x%10+48);
}

int read()
{
	int f=1,x=0;
	char ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}

int n,c0,c1,x,s,ans;
int l[200005],r[200005];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		c0+=(x==0);
		c1+=(x==1);
		s=c0-c1+n;
		if(!l[s]&&s!=n) l[s]=i; else r[s]=i;
	}
	ans=0;
	for(int i=0;i<=2*n;i++)
	{
		ans=max(ans,r[i]-l[i]);
	}
	cout<<ans;
	return 0;
}