#include <cstdlib>
#include <cstring>
#include <cstdio>

char buf[20][10];

char number[32][10] = {
	"negative", "zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve", 
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
	"eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", 
	"sixty", "seventy", "eighty", "ninety", "hundred", 
	"thousand", "million"}; 

int value[32] = {
	-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
	20,30,40,50,60,70,80,90,100,1000,1000000};

int str2val(char *str)
{
	for (int i = 1 ; i < 29 ; ++ i)
		if (!strcmp(str, number[i]))
			return value[i];
	return -1;
}

int translate(int a, int b)
{
	if (a > b) return 0;
	if (a == b) return str2val(buf[a]);
	else {
		int million = 0,thousand = 0,hundred = 0;
		int sum = 0;
		for (int i = a ; i <= b ; ++ i) {
			if (!strcmp(buf[i], "million")) million = i;
			if (!strcmp(buf[i], "thousand")) thousand = i;
			if (!strcmp(buf[i], "hundred")) hundred = i;
			sum += str2val(buf[i]);
		}
		if (million) return translate(a, million-1)*1000000+translate(million+1, b);	
		if (thousand) return translate(a, thousand-1)*1000+translate(thousand+1, b);
		if (hundred) return translate(a, hundred-1)*100+translate(hundred+1, b);
		return sum;
	}
}

int main()
{
	int cnt = 0;
	while (scanf("%s",buf[cnt ++]) != EOF) {
		while (getchar() != '\n')
			scanf("%s",buf[cnt++]);

		if (!strcmp(buf[0], "negative"))
			printf("-%d\n",translate(1, cnt-1));
		else printf("%d\n",translate(0, cnt-1));
		cnt = 0;
	}
	return 0;
}

