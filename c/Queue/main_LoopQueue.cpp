#include<stdio.h>
#include<stdlib.h>
#include"LoopQueue.cpp"
int main()
{
	lqueue lq;
	ElemType data;
	int i;

	initQueue(&lq); // 创建一个空循环队列  

	printf("plz input elm(end for 0)"); // 输入数据,0作为结束标志  
	scanf(" %d", &data);
	while (data != -1)
	{
		intoQueue(&lq, data); // 入队  
		scanf(" %d", &data);
	}

	printf("the data from head to tail are:");
	printQueue(&lq); // 输出循环队列  
	printf("\n");

	printf("out queue a enement");
	i = outQueue(&lq, &data);
	if (i)
		printf("%4d\n", data);

	printf("the data from head to tail are:");
	printQueue(&lq); // 输出循环队列  
	printf("\n");
}