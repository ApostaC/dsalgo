#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define MAXN1 1500000
using namespace std;
int MAXN;
void outRand(int size)
{
	printf("%d ",size);
	for(int i=0;i<size;i++)
	{
		int a=rand();srand(a);
		printf("%d ",a%MAXN);
	}
	printf("\n");
}
int main(int argc,char * argv[])
{
	if(argc!=3)
	{
		cerr<<"Usage : ./gen <maxNum1> <maxNum2>"<<endl;
		exit(-1);
	}
	int m=atoi(argv[1]),n=atoi(argv[2]);
	m%=MAXN1;
	n%=MAXN1;
	MAXN=(m+n)/4*3;
	srand(time(NULL));
	outRand(m);outRand(n);
}

