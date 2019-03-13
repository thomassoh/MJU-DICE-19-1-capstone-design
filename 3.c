#include<stdio.h>
#include<limits.h>

short int Packing(char c1,char c2);
void PackingPrint(short int a);
char UnPacking(short int a, int k);
void UnPackingPrint(short int unpack);

int main()
{
	char a,b,c,d,unpacking;
	short int high,low;
	int k;

	printf("입력 : ");
	scanf_s("%c", &a, sizeof(a));
	scanf_s("%c", &b, sizeof(b));
	scanf_s("%c", &c, sizeof(c));
	scanf_s("%c", &d, sizeof(d));
	putchar(a); putchar(b); putchar(c); putchar(d);
	high=Packing(a,d);
	low=Packing(b,c);
	
	printf("첫째와 네째 문자 패킹 결과:\n");
	PackingPrint(high);

	printf("둘째와 셋째 문자 패킹 결과:\n");
	PackingPrint(low);

	printf("첫째와 네째 문자 언패킹 결과:\n");

	for(k=1; k>=0; k--)
	{
	unpacking=UnPacking(high,k);
	UnPackingPrint(unpacking);
	}

	printf("\n");

	printf("둘째와 셋째 문자 언패킹 결과:\n");

	for(k=1; k>=0; k--)
	{
	unpacking=UnPacking(low,k);
	UnPackingPrint(unpacking);
	}

	printf("\n");


	return 0;
}

short int Packing(char c1,char c2)
{
	short int p;
	p=c1;
	p = (p<<CHAR_BIT)|c2;
	return p;
}

void PackingPrint(short int a)
{
	int i;
	int n=sizeof(short int)* CHAR_BIT;
	int mask = 1<<(n-1);

	for(i=1; i<=n; i++)
	{
		putchar(((a&mask)==0)?'0':'1');
		a<<=1;
		if(i % CHAR_BIT == 0 && i < n)
			putchar(' ');
	}
	putchar('\n');
}

void UnPackingPrint(short int unpack)
{
	printf("%c  ",unpack);
}

char UnPacking(short int a,int k)
{
	int  n = k * CHAR_BIT;  
	unsigned  mask = 255;    
	mask <<= n;
   return ((a & mask) >> n);

}
