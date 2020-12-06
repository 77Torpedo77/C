#include<stdio.h>
#include<stdlib.h>
#include"LoopQueue.cpp"
int main()
{
	lqueue lq;
	ElemType data;
	int i;

	initQueue(&lq); // 创建一个空循环队列  

	printf("plz input elm(end for -1)"); // 输入数据,-1作为结束标志  
	scanf(" %d", &data);
	while (data != -1)
	{
		intoQueue(&lq, data); // 入队  
		scanf(" %d", &data);
	}

	printf("this is the queue before aa:");
	printQueue(&lq); // 输出循环队列  
	printf("\n");

	aa(&lq);
	printf("this is the queue after aa:");
	printQueue(&lq); // 输出循环队列  
	system("pause");
}