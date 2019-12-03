#include<stdio.h>
#include<stdlib.h>
#include <string.h>    
#define N 30
//数据表从内存中申请下来--顺序表
//三元组表数据元素比顺序表多 
typedef struct{	
	int i;
    int j;
    int e;
}ElemType; 
typedef struct{
	ElemType data[N];
	int m,n,t;//m行；n列；t表示非零元个数 
}TSMatrix;
void input(TSMatrix *s){	
	int m,n,t;
	int i=0;
	printf("存入行列非零元个数。\n");
	scanf("%d%d%d",&m,&n,&t);
	s->m=m;
	s->n=n;
	s->t=t;	
	printf("请输入%d个非零元\n",s->t);
	for(i=0;i<s->t;i++){
		scanf("%d%d%d",&m,&n,&t);
		s->data[i].i=m;
		s->data[i].j=n;
		s->data[i].e=t;
	}
}
void output(TSMatrix *s){
	printf("_________________________________\n");
	printf("\ti\tj\te\n");
	printf("_________________________________\n");	
	for(int i=0;i<s->t;i++){		
		printf("\t%d\t%d\t%d\n",s->data[i].i,s->data[i].j,s->data[i].e);
	}
} 
//转置 A-->B 
void Travers(TSMatrix *B,TSMatrix *A){
	//扫描A的所有元素找到1列，放到B的1行；
	int i,j;
	int k=0;//设定k表示B中存储元素的下标；
	//共有A->n列，扫描n次；在A中和每个元素的列对比； 
	B->m=A->n;
	B->n=A->m;
	B->t=A->t;
	 for(j=1;j<A->n;j++){ 
	 	for(i=0;i<A->t;i++){ 		 	 	
			if(A->data[i].j==j)
			{   //printf("%d\n",A->data[i].j);
				B->data[k].i=A->data[i].j;
				B->data[k].j=A->data[i].i;	
				B->data[k].e=A->data[i].e;
				//printf("\t%d\t%d\t%d\n",B->data[i].i,B->data[i].j,B->data[i].e);		
				k++;
			}
		}
	} 
} 
int main(){
	TSMatrix A,B;
	input(&A);
	output(&A);	
	Travers(&B,&A);
	output(&B);	
	return 0;
} 