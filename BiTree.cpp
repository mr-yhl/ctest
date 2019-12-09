#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 80
//二叉链表
typedef char ElemType;//存储内容 

typedef struct node{
	ElemType data;//存数据 
	struct node *lch,*rch;//存储结构 
}BiNode,*BiTree;  //二叉树类型 
//建立二叉树
BiTree creat_btree(){
	ElemType ch;
	int i,k;
	BiTree s[N],p,bt;
	scanf("%d%c",&i,&ch);
	while(i!=0&&ch!='0'){
		p=(BiTree)malloc(sizeof(BiNode));
		p->data=ch;
		p->lch=p->rch=NULL;
		s[i]=p;
		if(i==1)//是第一个节点连接上其他节点 
		bt=p;
		else{//不是头结点，链接到父节点
			k=i/2;
			if(i%2==0)
			s[k]->lch=p;//父节点的左子树 
			else
			s[k]->rch=p;//父节点的右子树 
			}
			scanf("%d%c",&i,&ch);
		}
	return bt;
} 


int main(){
	BiTree bt;
	bt=creat_btree();
	return 0;
} 
