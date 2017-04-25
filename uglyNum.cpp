#include <stdio.h>

bool isUgly(int num) {
    if(num == 1)
    return true;
    if (num%2 == 0)
        for( ; num%2 == 0 ; )
        {
            num = num/2;
        }
    if (num%3 == 0)
        for( ; num%3 == 0; )
        {
            num = num/3;
        }
    if (num%5 == 0)
        for( ; num%5 == 0; )
        {
            num = num/5;
        }    
    if(num == 1)return true;
    else 
    return false;
        
}
int main()
{
	int a;
	scanf("%d",&a);
	int b=isUgly(a);
	printf("the result:%d",b);
}
