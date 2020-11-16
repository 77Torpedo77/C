#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; 
typedef struct Node
{
	ElemType data;	   // 数据域 
	struct Node *next; // 指针域 
} LinkStack;

LinkStack *initstack()//初始化，创建头节点
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack));
	p->next = NULL;//初始化时防止指针悬空
	return p;
}

int push(LinkStack *S, ElemType data)//入栈
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack)); 
	if (p == NULL)
		return 0; //防止空间申请出错
	p->data = data;//将临时节点的data赋值
	p->next = S->next; // 插入到头结点之后 
	S->next = p;//头节点指向新的栈顶
	return 1;
}

int pop(LinkStack *S, ElemType *data)//出栈
{
	LinkStack *p;
	if (S->next == NULL)
		return 0; // 栈空时不能删除
	p = S->next;
	*data = p->data; // 出栈时要返回被弹出的元素的值，在这传给指针达到返回目的
	S->next = p->next;
	free(p);//释放被弹出的节点的空间
	return 1; // 出栈成功,返回1 
}

void printStack(LinkStack *S)//打印整个栈
{
	LinkStack *p;
	p = S->next;
	while (p != NULL)//栈没空一直往下打印
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int getTopElm(LinkStack *S, ElemType *data)//读取栈顶元素
{
	if (S->next == NULL)
		return 0;		//判断栈空
	*data = S->next->data; //取栈顶
	return 1;
}

int isEmpty(LinkStack *S)//判断栈是否为空
{
	if (S->next == NULL)
		return 1; // 栈空,返回1,否则返回0 
	else
		return 0;
}

int getLength(LinkStack *S)//获取栈的长度
{
	LinkStack *p;
	int i;
	p = S->next;
	i = 0;//计数器
	while (p != NULL)//栈没空一直走
	{
		i++;
		p = p->next;
	}
	return i;//返回计数结果
}
