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

	printf("�Է� : ");
	scanf_s("%c", &a, sizeof(a));
	scanf_s("%c", &b, sizeof(b));
	scanf_s("%c", &c, sizeof(c));
	scanf_s("%c", &d, sizeof(d));
	putchar(a); putchar(b); putchar(c); putchar(d);
	high=Packing(a,d);
	low=Packing(b,c);
	
	printf("ù°�� ��° ���� ��ŷ ���:\n");
	PackingPrint(high);

	printf("��°�� ��° ���� ��ŷ ���:\n");
	PackingPrint(low);

	printf("ù°�� ��° ���� ����ŷ ���:\n");

	for(k=1; k>=0; k--)
	{
	unpacking=UnPacking(high,k);
	UnPackingPrint(unpacking);
	}

	printf("\n");

	printf("��°�� ��° ���� ����ŷ ���:\n");

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
