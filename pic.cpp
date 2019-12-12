#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//邻接矩阵，图部分内容
/*
1--------2
|      / |
|    3   |
| /   \  |
4-------5
*/ 
#define N 50
typedef int ADjvex;
typedef struct node{
	ADjvex adjvex;
	struct node *next;	
}ADjNode,*ADjLink; 
typedef char VerType;
typedef struct{
	VerType data;
	ADjLink firstarc;
}Ver[N];
typedef struct{
	Ver vexs;
	int kind;
	int vernum,arcnum;
}ALGraph;
int main(){
	ALGraph g1,*g2;
	g2=&g1;
	//访问g1的下表为1的顶点的数据和链表的头指针 
}