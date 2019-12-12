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
void creatALG(ALGraph *g){
	/*
	把有向图存储到g指向的存储空间中；
	g是什么图（0 有向图，1无向图）
	顶点，边
	1访问g的数组，输入顶点，同时边的指针为空
	2输入g->adjvex边数
		2.1输入起始点下标和终止点下标
		头插法往起始点指针插入终止点节点 
	*/
	printf("请输入你想存储的图的类型：\n");
	scanf("%d",&g->kind);
	printf("请输入图的顶点：\n");
	scanf("%d",&g->vernum);
	
	for(i=1;i<=g->adjvex;i++){
		scanf("%d%d",&s,&d);
		p=(ADjLink)malloc(sizeof(ADjNode));
		p->adjvex=d;
		p->next=g->vexs[s].firstarc;
		g->vexs[s].firstarc=p;
	}
	 
	
}
int main(){
	ALGraph g1,*g2;
	ADjLink p;
	VerType ve1; 
	g2=&g1;
	//访问g1的下表为1的顶点的数据和链表的头指针 
	creatALG(&g1);
	/*
	//ve1 = find_data_fir(g2);
	ve1=g1.vexs[1].data;
	//ve1=g2->vexs[1].data;
	p=g1.vexs[1].firstarc;
	//p=g2->vexs[1].firstarc;
	p->adjvex;
	*/
	
}