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
LinkList create_list(){//建立一个带有头结点的单链表
        LinkList p,q;
        LinkList L;
        L=(LinkList)malloc(sizeof(LNode));
        q=L;
        int x;//自己定义n个数据的结束标志，输入0结束

        char name[30];
        char phone[20];
        scanf("%d%s%s",&x,&name,&phone);
        while(x){
                 p=(LinkList)malloc(sizeof(LNode));
                 p->data.id=x;
                 strcpy(p->data.name,name);
                 strcpy(p->data.phone,phone);
                 q->next=p;
                 q=p;
                 scanf("%d%s%s",&x,&name,&phone);
        }
        q->next=NULL;//链表最后一个节点清空
        return L;
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
//查找
LinkList locate_list(LinkList L,int e){
        LinkList p;
        p=L->next;
        while(p){
                if(p->data.id==e)
                return p;
                p=p->next;
        }
        return NULL;
}
//统计节点个数 
int count_list(LinkList L){
        LinkList p;
        int x;
        p=L->next;
        while(p){
                x++;
                p=p->next;
        }
        return x;
}
//查找节点
LinkList  find_list(LinkList L,int x){
	LinkList p;
        int i=0;
        p=L->next;
        while(p){
                i++;
                if(i==x)
                	return p;
                p=p->next;
                
        }
        return NULL;
}
//c查找某个节点的前驱
LinkList find_pre_list(LinkList L,int x) {
		LinkList p,pre;
        int i=0;
        p=L->next;
        pre=L;
        while(p){        	
                i++;
                if(i==x)
                	return pre;
                	pre=p;
                p=p->next;
                
        }
        return NULL;
}
void pandu(LinkList p){
	if(p){
	printf("序号\t姓名\t电话\n");
    printf("%d\t%s\t%s\n",p->data.id,p->data.name,p->data.phone);
	}else
	printf("没有找到！\n");
	
}
int main(){
        //分配一个存储空间
        LinkList L,p;
        int sum;
        L=create_list();
        print_list(L);
        p=locate_list(L,2);//找序号为2的节点
        if(p!=NULL)
        	printf("找到了\n");
        else
            printf("没找到\n");
        sum=count_list(L);
        printf("共有%d个节点\n",sum);
        //查找第2个节点
        p=find_list(L,2);
        pandu(p);
        //查找第二个结点的前驱
		p=find_pre_list(L,2);
		pandu(p);
        system("pause");
        return 0;
}

