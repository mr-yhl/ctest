#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#define N 20 
typedef int ElemType;
typedef struct{
	//数据空间，共100个 
	ElemType data[N];
	//空间中存放多少数据 
	int top;//当前占顶 
}SqStack;   
/*
定义栈就是给别人使用的
1.初始化:你给我一个栈，我给你清空 
2.栈空  给我一个栈，我判断结果，判断栈是不是空。 
3.栈满 你给我一个栈，我判定结果 判断栈是不是满 
4.元素进  你要给栈，一个元素   我把元素放进栈里： 
5.元素出   你给一个栈 ，我取出空内元素 
主函数可以使用栈了！ 
*/
void init_stack(SqStack *s){
	s->top=0;//栈顶位置，指向栈顶元素上一个位置 
} 
//判空 
int empty_stack(SqStack *s) {
	if(s->top==0)
	return 1;
	return 0;
}
//判满 
int full_stack(SqStack *s) {
	if(s->top==4)
	return 1;
	return 0;
}
//进栈 
void push_stack(SqStack *s,ElemType e){
	if(full_stack(s)){
		printf("stack full.");
		exit(0);
	}
	s->data[s->top]=e;
	s->top++;
}
//出栈 
void pop_stack(SqStack *s,ElemType *e){
	if(empty_stack(s)){
		printf("stack empty.");
		exit(0);
	}
	s->top--;
	*e=s->data[s->top];

}
//获取栈顶元素
ElemType get_stack(SqStack s){
	return s.data[s.top-1];
} 
int main(){
	//123进，213出 
	SqStack s;
	int x,y;
	init_stack(&s);
	push_stack(&s,1);
	x=get_stack(s);
	printf("%d\n",x);
	push_stack(&s,2);
	x=get_stack(s);
	printf("%d\n",x);
	pop_stack(&s,&y);
	printf("%d\n",y);
	pop_stack(&s,&y);
	printf("%d\n",y);
		push_stack(&s,3);
	x=get_stack(s);
	printf("%d\n",x);
	system("pause");
	return 0;
}
