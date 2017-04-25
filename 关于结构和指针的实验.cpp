#include<stdio.h>
#include<malloc.h>

	typedef struct BiTree
	{
		int k;
		struct BiTree *a;
	}*aaaa;

bool De(BiTree *q)
{
	printf("q:%d\n",q->k);
}	
int main()
{

	struct BiTree *b=(BiTree*)malloc(1+sizeof(BiTree));
	b->k=8;

	BiTree* c=(BiTree*)malloc(2*sizeof(BiTree));
	c = b->a;
	b->a->k = 9;
	printf("c->k:%d, b->k:%d",c->k,b->k);
	
}
