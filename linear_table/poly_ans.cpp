#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b)      ((a)>(b)?(a):(b))
#define M_LINE   110


typedef struct tagi
{
	int coeff;
	int power;
}Poly;

int numb;

Poly   array1[ M_LINE ];
Poly   array2[ M_LINE ];
Poly   array_result[ 100 ][ M_LINE*2 ];

/*====================================================================*/
void addPoly(Poly a[], int n1, int n2);
void Output(int n);
void Sort(Poly *, int);


void addPoly(Poly result[], int n1, int n2){
	int coeff;      // 系数
	int id1;
	int id2;
	int power;      // 幂数
	int num;        // 多项式和的非零项个数   
	
	array1[ n1 ].power = array2[ n2 ].power = -1;
	for (id1=id2=num=0; id1<n1 || id2<n2;  ){
		coeff = 0;
		power = MAX(array1[ id1 ].power, array2[ id2 ].power); 
		while ( array1[ id1 ].power == power && id1<n1 ){
			coeff += array1[ id1++ ].coeff;	
		}
		while ( array2[ id2 ].power == power && id2<n2 ){
			coeff += array2[ id2++ ].coeff;
		}
		if ( coeff != 0 ) {
			result[ num ].coeff = coeff;
			result[ num++ ].power = power;
		}
	}
	result[ num ].power = -1; 
}


void Output(int n){
	int i,j;
	for ( i=0; i<n; i++ ){
		for ( j=0; array_result[i][j].power>=0; j++ ){
			printf("[ %d %d ] ",array_result[i][j].coeff, array_result[i][j].power);
		}
		printf("\n");
	}
}


int Partition(Poly *ptr, int p, int q){
	int div = ptr[p].power;
	int x = p;
	int i;
	Poly tmp;
	for ( i=p+1; i<=q; i++ ){
		if ( ptr[i].power > div ){
			tmp = ptr[x+1];
			ptr[x+1] = ptr[i];
			ptr[i] = tmp;
			x++;
		}
	}
	tmp = ptr[p];
	ptr[p] = ptr[x];
	ptr[x] = tmp;

	return x;
}


void QuickSort(Poly *ptr, int p, int q){
	int res;
	if ( p >= q )	{ return; }

	res = Partition(ptr,p,q);
	QuickSort(ptr,p,res-1);
	QuickSort(ptr,res+1,q);
}


void Sort(Poly *a, int n){
	QuickSort(a,0,n-1);
}


int main(void){
	int i=0;
	int cnt1=0;
	int cnt2=0;
	char s[ M_LINE ];
	char *pch;

	numb = atoi( fgets(s,M_LINE,stdin) );    
	
	for( i=0; i<numb; i++ ){ 

	    fgets(s,M_LINE,stdin); 
		for( pch=strtok(s," "),cnt1=0; pch!=NULL; pch=strtok(NULL,"  \n"),cnt1++){
			if ( cnt1%2 == 0 ){
				array1[ cnt1/2 ].coeff = atoi(pch);
			}
			else{
				array1[ cnt1/2 ].power = atoi(pch);
			}
		}
		cnt1 = cnt1/2-1; 

		fgets(s,M_LINE,stdin); for( pch=strtok(s," "),cnt2=0; pch!=NULL; pch=strtok(NULL,"  \n"),cnt2++){ if ( cnt2%2 == 0 ){
				array2[ cnt2/2 ].coeff = atoi(pch);
			}
			else{
				array2[ cnt2/2 ].power = atoi(pch);
			}
		}
		cnt2 = cnt2/2-1; 

		Sort(array1,cnt1);   
		Sort(array2,cnt2);   
         
		addPoly(array_result[i],cnt1,cnt2);
	}

	Output(numb);
	
	return 0;
}
