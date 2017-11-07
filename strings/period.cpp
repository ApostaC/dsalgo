#include <string.h>
#include <stdio.h>
#define N 1000010

int next[N];
char s[N];
void getNext(int l)
{
	int j=0,k=-1;
	next[0]=-1;
	while(j<l)
	{
		if(k==-1 || s[j]==s[k])
			next[++j]=(++k);
		else k=next[k];
	}
}
int len;
int main()
{
	int cnt=1;
	while(scanf("%d",&len) && len)
	{
		memset(s,0,sizeof(s));
		memset(next,0,sizeof(next));
		scanf("%s",s);
		getNext(len);
		printf("Test case #%d\n", cnt++);
		for(int i=1;i<=len;i++)
		{
			int size=i-next[i];
			if(i % size == 0 && size!=i)
			{
				printf("%d %d\n",i,i/size);
			}
		}
		printf("\n");
	}
	return 0;
}
