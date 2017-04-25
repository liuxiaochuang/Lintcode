#include<stdio.h>
//bool isHappy(int n);
static int kk =0;

int getsum(int x)
{	 int sum=0; 
	while(x)
	{ 	sum+=(x%10)*(x%10); 
		x=x/10;
	} 
	return sum; 
} 

bool isHappy(int n) 
{ if(n<=0)return false;

	while(n!=1)
		{
			n=getsum(n);
			if(n==4)return false;
		}//When the algorithm ends in a cycle of repeating numbers, this cycle always includes the number 4, so it is not even necessary to store previous numbers in the sequence:
		
	return true;
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("result%d",isHappy(a));
}
