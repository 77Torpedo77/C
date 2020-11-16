#define N 20 // 队列空间的初始分配量  
#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct
{
	ElemType *qlist;// 基地址  
	int front, rear; //队头和队尾指针，即数字标记
} lqueue;


void initQueue(lqueue *lq)//初始化
{
	lq->qlist = (ElemType *)malloc(N * sizeof(ElemType)); // 分配内存  
	lq->front = lq->rear = 0;							 //头和尾初始化为0 
}


int getFront(lqueue *lq, ElemType *data)//读取队头元素值
{
	if (lq->front == lq->rear)//判断队空
		return 0;
	*data = lq->qlist[lq->front]; // 取队头元素  
	return 1;
}

  
int intoQueue(lqueue *lq, ElemType data)//入队
{
	if ((lq->rear + 1) % N == lq->front)//判断队满
		return 0;				   
	lq->qlist[lq->rear] = data;		   // 入队列  
	lq->rear = (lq->rear + 1) % N; // 修改队尾指针  
	return 1;
}

int outQueue(lqueue *lq, ElemType *data)//出队
{
	if (lq->front == lq->rear)//判断队空
		return 0;					 
	*data = lq->qlist[lq->front]; // 取队头元素  
	lq->front = (lq->front + 1) % N; // 修改队头指针  
	return 1;
}
  
int isempty(lqueue *lq)
{
	if (lq->front == lq->rear)
		return 1;
	else
		return 0;
}

void printQueue(lqueue *lq)//打印队列
{
	int i;
	i = lq->front;
	while (i != lq->rear)
	{
		printf("%4d ", lq->qlist[i]);
		i = (i + 1) % N;
	}
	printf("\n");
}