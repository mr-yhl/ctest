#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 30
int visited[N]={0}; 
void DFS(ALGraph *g,int v){
	/*
	g中v元素的visited数字为1；
	输出v元素
	找v的第一个邻接点
	如果不为空并且没用访问，DFS（g，h） 
	*/
	p=g->vers[v].firstarc;
	while(p){
		k=p->adjvex;
		if(visited[x]==0)
		DFS(g,k);
		p=p->nextarc;
	}
	
	
}
void DFSTravse(ALGraph *g){
	for(i=0;i<=g->vernum;i++)
		visited[i]=0;
	for(i=1;i<=g->vernum;i++)
		if(visited[i]==0)
		DFS(g,i);
} 
int main(){
	ALGraph G;
	G=CreatALG();//图的邻接链表中没用0单元 
	DFS(&G,1);//输出图的联通分量 
}