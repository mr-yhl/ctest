#include<stdio.h>
#define N 50
typedef struct{
	int key;
	char name[20];
}KeyType;

typedef struct{//抽出的关键字组织到一起去 
	KeyType r[N]; 
	int len;
}SSTable;
//顺序查找，带有监视哨 


//二分查找 =》表中元素必须有序 
int nin_locate(SSTable r){
	int low =1,high=r.len;
	while(low<high){
		mid=(low+high)/2;
		if(key>r->r[mid].key)
			low=mid+1;
		else if(key<r->r[mid].key)
			high=mid-1;
		else return 0;
		
	}
}

int main(){
	SSTable r={{0,56,98,34,65,43,22,65,89,78,65},10};
	SSTable r={}; 
}