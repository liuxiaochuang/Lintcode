#include<stdio.h>
//bool isHappy(int n);
static int kk =0;
bool isHappy(int n) {
	
	if(n==4)return false;
//	kk++;
    int num1[100]={
    	0
    },i,j,k=1;
    for(i=0 ; n/k!= 0 ;i++)
    {
        
        num1[i] = n/k%10;
        k*=10;
     //    printf("%d\n",num1[i]);
    }
   n=0;
    for(j=0;j<i;j++)
zzzzz
        n+=num1[j]*num1[j];
  
    }
   //  printf("%d\n",n);
    if (n ==1)return true;
    else
     return isHappy(n);
    
}
int main()
{
	int a;
	scanf("%d",&a);
	printf("result%d",isHappy(a));
}