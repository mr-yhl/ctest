//队列：为啥要排队？先来的，一定要先为我服务
//设定一个队列：在多大空间内排队，对头在哪？对尾在哪？
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 10  
typedef int ElemType;
typedef struct{	 
	ElemType data[N];
	int front,rear;//队头队尾 
	//队头指向第一个元素，队尾指向最后一个元素的后面 
}SqQueue; 
int empty_queue(SqQueue *q){
	//printf("%p\n",q);
	if(q->front==q->rear)
	return 1;	
	return 0;
} 
int full_queue(SqQueue *q){
	//printf("%p\n",q);
	if((q->rear+1)%N == q->front)
	return 1;	
	return 0;
} 
//进入队列 
void Enqueue(SqQueue *q,ElemType e){
	if(!full_queue(q))
	{
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%N;	
	}
} 
void init_queue(SqQueue *q){
	q->front=q->rear=0;
} 
//出队列
void Dequeue(SqQueue *q,ElemType *y){	
	if(!empty_queue(q)){			
		*y=q->data[q->front];
		q->front=(q->front+1)%N;
	}
}
//统计元素数 
int count_queue(SqQueue q){
	return (N+q.rear-q.front)%N;
}
int main(){
	SqQueue q;
	int n;
	ElemType x=134,y;
	init_queue(&q);
	//进入队列 
	Enqueue(&q,x); 
	Enqueue(&q,135);
	n=count_queue(q);
	printf("元素个数%d\n",n);
	Dequeue(&q,&y);	
	printf("出队列元素%d\n",y);
	Dequeue(&q,&y);	
	printf("出队列元素%d\n",y);
	
	
	/*if(q.rear>q.front)
		n=q.rear-q.front;
	else
		n=N+(q.rear-q.front);
	*/
	
	return 0;
} 