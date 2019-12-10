//采用顺序结构存储，来存储节点
//ElemType，权值，左右子树下标，父节点下表
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct{
	int weight;
	int lch,rch,parent;
}ElemType;

typedef struct{
	ElemType *huf;
}HuFman;

HuFman creatHuf(int a[],int n){
	HuFman ht;
	int s,t;
	ht.huf=(ElemType *)malloc(sizeof(ElemType)*(2*n-1));
	for(i=0;i<n;i++){
		ht.huf[i].weight=a[i];
		ht.huf[i].lch=ht.huf[i].rch=-1;
	}
	for(i=n;i<2*n-1;i++){
		min(ht.huf,1,i,&s,&t);
		ht.huf[i].weight=ht.huf[s].weight+ht.huf[t].weight;
		ht.huf[i].lch=s;
		ht.huf[i].rch=t;
		ht.huf[s].parent=i;
		ht.huf[t].parent=i;
	}
}

int main(){
	int a[4]={7,5,2,4};
	int n=4;
	HuFman ht;
	ht=creatHuf();
} 