//队列：为啥要排队？先来的，一定要先为我服务
//设定一个队列：在多大空间内排队，对头在哪？对尾在哪？
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 10  
typedef int ElemType;
typedef struct{	 
	//ElemType data[N];
	int front,rear;//队头队尾 
	//队头指向第一个元素，队尾指向最后一个元素的后面 
}SqQueue; 
//初始化
void init_queue(SqQueue *q){
	q->front=q->rear=0;
} 
void empty_queue(SqQueue q){
	if(q.front==q.rear)
	return 1;
	else
	return 0;
} 
void full_queue(SqQueue q){
	if((q.rear+1)%N == q.front)
	return 1;	
	return 0;
} 
int main(){
	
} 