#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct {
    node *front;
    node * rear;
    int size;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->front = queue->rear = (node*)malloc(sizeof(node));
    queue->front->next = NULL;
    queue->size = maxSize;
    queue->front->data = 0;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    if(queue->front->data == queue->size) return;
    node *s = (node*)malloc(sizeof(node));
    s->data = element;
    s->next =NULL;
    queue->rear->next = s;
    queue->rear = s;
    queue->front->data++;
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if(queue->front->next==NULL)return;
    queue->front->next->next=NULL;
    queue->front->next = queue->front->next->next;
}

/* Get the front element */
int queuePeek(Queue *queue) {
    return queue->front->next->data;
}

/* Return whether the queue is empty */
bool queueEmpty(Queue *queue) {
    if(queue->front==queue->rear)return 1;
    else return 0;
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
    if(queue->rear!=queue->front)
    {
    queue->front->next = queue->front->next->next;
    free(queue->front->next);
    }else return ;
    queueDestroy(queue);
}
int main()
{
	int a=6;
	Queue *b = (Queue*)malloc(sizeof(Queue));
	queueCreate(b,a);
	queuePush(b,1);
	queuePush(b,1);
	printf("%d",queueEmpty(b));
}
