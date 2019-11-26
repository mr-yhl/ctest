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
int main(){
	SqQueue q;
	ElemType x=134,y;
	q.front=q.rear=0;
	//进入队列 
	if((q.rear+1)%N!=q.front)
	{
	q.data[q.rear]=x;
	q.rear=(q.rear+1)%N;	
	}

	//出队列
	if((q.front)%N!=q.rear){			
		y=q.data[q.front];
		q.front=(q.front+1)%N;
	}
	printf("出队列元素%d\n",y);
	return 0;
} 