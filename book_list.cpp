#include<stdio.h>
#include<stdlib.h>
#include <string.h>    
#define N 100 
typedef struct{
	//表示图书编号 
	int id;
	//图书名称
	char name[50]; 
	//单价 
	float price;
}ElemType; 
//数据表从内存中申请下来--顺序表
typedef struct{
	//数据空间，共100个 
	ElemType data[N];
	//空间中存放多少数据 
	int len;
}Sqlist; 
void init_list(Sqlist *L){
	L->len = 0;
}
void input_list(Sqlist *L){
	printf("存入数据，输入999的时候结束。\n");
	char name[50];
	float price;
	scanf("%s%f",&name,&price);
	//printf("%d",strcmp(name,"999"));
	while(strcmp(name,"999")||price!=999){
		L->data[L->len].id=L->len+1;
		//字符串的赋值方式 
		strcpy(L->data[L->len].name,name);
		L->data[L->len].price=price;
		L->len++;		
		scanf("%s%f",&name,&price);
	}
	printf("输入结束！\n");
}
void output_list(Sqlist L){
	int i = 0;
	printf("序号\t图书名称\t单价\n");
	for (i = 0; i < L.len; i++) {
		printf("%d\t%s\t\t%f\n", L.data[i].id, L.data[i].name,L.data[i].price);
	}
} 
//对于表中的数据进行插入删除查找 -->基本操作
//1.在管理表中实现查找操作，分析程序基本功能
//1.1查找什么数据，主函数-->查找函数，查找的源：线性表，参数
//1.2返回什么，下表访问，链表，地址。找不到返回-1，位置返回0，地址返回空
//locate_list
int locate_list(Sqlist L,char *name){
	//依次比较每个元素
	int i;
	for(i=0;i<L.len;i++)
	if(strcmp(name,L.data[i].name)==0)
		{
			printf("%d\t%s\t\t%f\n", L.data[i].id, L.data[i].name,L.data[i].price);
		return i+1;
		} 
		 
	return 0;
}
//2.插入数据：数据来源，一个数据，一个表：插入位置，去向：表明状态：（隐含的） 
/*
2.1判定位置
2.2把n-1的数据元素放到n的下表处，n-2放到n-1处
2.3元素数+1 
*/ 
int insert_list(Sqlist *L,int k,ElemType e){
	int i;
	//健壮性判定。 
	if(k <1 || k> L->len + 1)    
       return 0;        
	else {	
		for(i=L->len;i>k-1;i--)
		//数据项传递 
		L->data[i]=L->data[i-1];
		L->data[k-1]=e;
		L->len++;
		return 1;
	}
	
} 
//3.删除 
int del_list (Sqlist *L,int k){
	int i,j=0;
	printf("%d\n",k);
	for(i=0;i<L->len;i++){
		printf("%d\n",L->data[i].id);
	if(L->data[i].id==k)
		{
		j=i;
		break;
		}
	}
	if (j>-1){
		for(;j<L->len;j++){
			L->data[j]=L->data[j+1];
		}
		L->len--;	
		return 1;
	}
	else
	return 0;		
} 
//目录输出 
void first_w(){
	system("color 0A");
	printf("==========================================\n");
	printf("+      欢迎使用图书管理系统v1.0.1        +\n");
	printf("+ 温馨提示：首先进行表格数据的创建输出   +\n");
	printf("+ 1：查找功能                            +\n");
	printf("+ 2：插入功能                            +\n");
	printf("+ 3：删除功能                            +\n");
	printf("+ 4：统计功能                            +\n");
	printf("+ 5：结束程序                            +\n");
	//printf("+ 6：清除屏幕                            +\n");
	printf("==========================================\n");
	
}
//查重 
int find_rp(Sqlist L,int n){
	int i;	
	for(i=0;i<L.len; i++)
		if(L.data[i].id==n)
		 return 1;
		 return 0;	
	
} 
//统计
int sta_list(Sqlist L,float s){
	int i,j;
	j=0;
	for(i=0;i<L.len; i++){
		if(L.data[i].price>s)
		 j++;
	}
	return j;
} 
int main(){
	//用线性表，存n条数据； 
	Sqlist L;	
	//按照书名查找
	char name[50];
	float price;	
	int pos;
	int fun;
	int id_in; 
	ElemType book;	
	//初始化 
	first_w(); 
	init_list(&L); 
	//存5条数据,指定条件结束 
	//system("color 05");
	input_list(&L);
	//把存入的数据输出
	output_list(L); 
	//查找功能
	printf("请按回车键继续...");
	getchar();getchar();
	while(1){
		system("cls");		
		first_w(); 
		output_list(L);
		printf("请选择需要的功能号：");
		scanf("%d",&fun);  
		if(fun==1){
			printf("请输入需要查找的书名："); 
			scanf("%s",&name); 
			pos=locate_list(L,name);
			if(pos)
				printf("找到了，是第%d个元素\n",pos);
			else
				printf("没有找到！！\n"); 
		}else if(fun == 2){
		
			printf("请输入插入位置：\n");
			scanf("%d",&id_in); 
		here1:
			printf("请输入需要插入的序号，书名，价格\n");
			scanf("%d %s %f",&book.id,&book.name,&book.price);
			if(find_rp(L,book.id)) {
				printf("序号重复，插入失败,请重新输入\n");
				goto here1;		
			}	
			pos = insert_list(&L,id_in,book);
			if(pos){
				printf("插入成功！！\n");
				output_list(L); 
			}else
				printf("失败！！\n");
				
		}else if(fun == 3){
			output_list(L); 
			printf("请输入删除的序号：\n");
			scanf("%d",&id_in); 
			pos=del_list(&L,id_in);
			if(pos){
				printf("删除成功！！\n");
				output_list(L); 
			}else
				printf("失败！！\n");
		} else if(fun == 4){
			printf("请输入最低价格，统计高于本价格的图书\n");
			scanf("%f",&price);
			pos=sta_list(L,price); 
			printf("高于%f元的图书共有%d本\n",price,pos);
		} 
		else if(fun ==5)
			break;
//		else if(fun == 6)
//		system("cls");//清除屏幕 
		else
			printf("输入错误。\n");
		printf("请按回车键继续...");
		getchar();getchar();
	} 
	
	system("pause");
	return 0;
}

