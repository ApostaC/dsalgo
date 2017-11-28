#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		cerr<<"Usage : ./gen <size>"<<endl;
		exit(-1);
	}
	int n=atoi(argv[1]);
	cout<<n<<endl;

	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		int a=rand();srand(a);
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}
