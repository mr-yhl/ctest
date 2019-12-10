#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define N 80
/*
1A 2B 3C 4D
		A
	   / \
	  B   C
	/
   D
先根遍历：ABDC 
中根遍历：DBAC 
后根遍历：DBCA 
*/ 
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
	/*
	BiTree T;
	scanf(&ch);
    if(ch=='')  
		T->NULL;
	else{
      T=(BiTNode *)malloc(sizeof((BiTNode));
	  T->data->ch;//生 成根结点
      T->lch= creat_btree(); //构造左子树
	  T->rch=creat_btree();//构造右子树
	}
	return (T);
	*/ 
} 
//先跟遍历 
void pre_order(BiTree bt){
	if(bt){
		printf("%c ",bt->data);
		pre_order(bt->lch);
		pre_order(bt->rch);
	}
}
/*
//非递归写法 
void pre_order_no(BiTree bt){
	//栈 
	//p沿着根节点的左子树，右子树不空就进栈
	BiTree s[N],p;
	int top = 0;
	p=bt;
	while(p){
		printf("%c ",p->data);
		if(p->rch)
		s[top++]=p->rch;
		p=p->lch;
		if(!p)
			p=s[--top];
	}
	 
}*/
//中跟遍历 
void in_order(BiTree bt){
	if(bt){		
		in_order(bt->lch);
		printf("%c ",bt->data);
		in_order(bt->rch);
	}
}
//后跟遍历 
void po_order(BiTree bt){
	//int i=0; 
	if(bt){		
		po_order(bt->lch);		
		po_order(bt->rch);
		printf("%c ",bt->data);
		//统计叶子节点
		//if(bt->lch==NULL && bt->rch==NULL) 
		//i++;
	}
}
int main(){
	BiTree bt;
	//创建 
	bt=creat_btree();
	//二叉链表从内存中读取 
	printf("先根遍历次序为：\n");
	pre_order(bt); 
	printf("\n");
//	printf("(栈)先根遍历次序为：\n");
//	pre_order_no(bt); 
//	printf("\n");
	printf("中根遍历次序为：\n");
	in_order(bt); 
	printf("\n");
	printf("后根遍历次序为：\n");
	po_order(bt); 
	printf("\n");
	//用：叶子节点；高是多少 
	//建立一个二叉树，从一个字符串或从两个字符串建立 
	return 0;
} 
