/*
调试、数据 、数据的存储 ——链式存储
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
        int id;
        char name[30];
        char phone[20];
        //char addr[50];
}ELenType;
typedef struct node{
        ELenType data;
        struct node *next;//指向下一个元素的地址
}*LinkList,LNode;
LinkList create_head_list(){//建立一个带有头结点的单链表
        LinkList h;
        LinkList p;
        h=(LinkList)malloc(sizeof(LNode));		
        h->next=NULL;
        int x;//自己定义n个数据的结束标志，输入0结束
        char name[30];
        char phone[20];
        scanf("%d%s%s",&x,&name,&phone);
        while(x){
                 p=(LinkList)malloc(sizeof(LNode));
                 p->data.id=x;
                 strcpy(p->data.name,name);
                 strcpy(p->data.phone,phone);
                 p->next=h->next;
                 h->next=p;                 
                 scanf("%d%s%s",&x,&name,&phone);
        }       
        return h;
}

void print_list(LinkList L){
        LinkList p;
        p=L->next;
        printf("序号\t姓名\t电话\n");
        while(p){
                printf("%d\t%s\t%s\n",p->data.id,p->data.name,p->data.phone);
                p=p->next;
        }
}
LinkList reverse_list(LinkList L){
LinkList p=L;
LinkList q=p->next;
p=NULL;
LinkList r;
while(q){
  r=q->next;
  q->next=p;
  p=q;
  q=r;
} 
return p;
}
int main(){
		LinkList L,r;	
        L=create_head_list();        
        print_list(L);		
        r=reverse_list(L);
        print_list(r);
        system("pause");
        return 0;
}

