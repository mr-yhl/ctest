//数据库，Excel===》索引表，主关键字和次关键字
//线性顺序表：===》查找表 
#include<stdio.h>
#define N 50
typedef struct{
	int key;
}Key;
typedef struct{
	Key data[N];
	int len;
}SSTable;//静态顺序查找表
//int locate(SSTable r,int n){
//	r->data[0].key=
//}

int main(){
	SSTable r={{0,56,98,34,65,43,22,65,89,78,65},10};
	int i,k;
	//k=locate(r,43);
	
	for(i=1;i<=r.len;i++){
		printf("%d   ",r.data[i].key);
	}
} 