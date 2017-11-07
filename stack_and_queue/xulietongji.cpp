#include <stdio.h>

int n;
long long f[20];
void fill(int n)
{
	for(int i=0;i<n;i++)
		f[n]+=f[i]*f[n-i-1];
}
void init()
{
	f[0]=1;
	for(int i=1;i<=16;i++) fill(i);
}
int main()
{
	init();
	scanf("%d",&n);
	printf("%lld",f[n]);
	return 0;

}
