//赏花
 #include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define N 255
//C语言定长度字符串 
/*
typedef struct{
	char ch[N];
	int len;
}SString;*/
//堆分配字符串 
typedef struct
{
	char *ch;
	int len;
}HString;
//字符串存储时。0单元不用，从1开始存字符，输入时也从1开始 
/*
typedef struct node
{
	char ch[20];
	struct node *next;
}LString;*/
void Assign(HString *s,char *str){
	/*
	1. 判定str是不是空字符串；如果是，给s的ch成员NULL； 
	2. 计算str的长度n，为s的ch成员分配n+1个字符空间； 
	3. 把str字符一一写到s的ch空间中；	 
	*/
	int i,n;
	if(!s->len) {
	free(s->ch);//如果字符空间被占用，清空 
	s->len=0; 
	} 
	n=strlen(str);
	if(!n){
	s->ch=(char *)malloc(sizeof(char));
	s->len=0;
	s->ch[0]='\0';
	return ;
	}
	s->ch=(char *)malloc(sizeof(char)*(n+1));
	for(i=0;str[i]!='\0';i++) 
		s->ch[i]=str[i];
	s->ch[i]='\0';
	s->len=i;	
}
/*
int get_len(HString s){
	return s.len;
}*/ 
void print_1(HString s){
	printf("字符串为\t%s\n",s.ch);
	printf("长度为%d\n",s.len);
}
int index_s(HString s,HString t,int pos){
	int m,n,i,j;
	i=pos;
	j=pos;
	m=s.len;
	n=t.len;
	while(i<m&&j<n){
		if(s.ch[i] == t.ch[j]){
			//i,j同步后移
			i++;
			j++; 
		}
		else{
			//i回退到本次比较开头的下一个位置；j为1；
			i=i-j+2;
			j=1; 
		}
	}
	if(i<m)
	return i-j+1;
	else
	return -1; 
}
int main(){
//char str[]={"赏花归去马如飞酒力微醒时已暮"};
char str[]={"12345632"};
char str1[]={"4"};
HString s,t;
int k;
Assign(&s,str);
Assign(&t,str1);
print_1(s);	
k=index_s(s,t,0);
printf("位置为%d",k);
return 0;
}  