#include<stdio.h>
#define N 20

void trans_10_to_8(int n){
	int s[N];//假设进栈的元素为整形
	int top;
	top=0;
	//s[top++]=e;//进栈序列 
	//e=s[--top];//出栈序列 
	//栈干什么，需要记忆一种特殊的顺序
	//ex'  N，求N的八进制数据 
	
	while(n)
	{
		s[top++]=n%8;
		n=n/8;
	 } 
	 //把栈里面的数据读出来 
	 while(top)
	 {//取出栈顶元素
	 printf(" %d   \n",s[--top]); 	 	
	 }
}
int main(){
	int n=253;
	//转换为八进制
	trans_10_to_8(n); 
	
	//system("pause");
	return 0;
}