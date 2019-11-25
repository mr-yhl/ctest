#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 20 
typedef int ElemType;
typedef struct{
	//数据空间，共100个 
	ElemType data[N];
	//空间中存放多少数据 
	int top;//当前占顶 
}SqStack; 
//初始化栈
void init_stack(SqStack *s){
	s->top=0;//栈顶位置，指向栈顶元素上一个位置 
} 
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
 char get_stack(SqStack s){
	return s.data[s.top-1];
} 

//进栈 
void push_stack(SqStack *s,char e){
	if(full_stack(s)){
		printf("stack full.");
		exit(0);
	}
	s->data[s->top]=e;
	s->top++;
}
//出栈 
void pop_stack(SqStack *s){
	if(empty_stack(s)){
		printf("stack empty.");
		exit(0);
	}
	s->top--;


}
int judge(char *ch){
	SqStack s;
	init_stack(&s);
	while(*ch){
		if(*ch=='(')
			push_stack(&s,*ch);
		else{
			if(*ch==')')
				if(get_stack(s)=='(')
					pop_stack(&s);
				else
					return 0;
		}
		ch++;
	}
	if(empty_stack(&s)) return 1;
	else return 0;	
}

int main(){
	int n=253;
	//转换为八进制
	//trans_10_to_8(n); 
	char *ch ="(()))";
	char *ch1 ="[(])";
	char *ch3 ="(())";
	int flag = 0;
	flag = judge(ch3);
	if(flag)
	printf("匹配的\n");
	else
	printf("不匹配的\n");
	
	//system("pause");
	return 0;
}