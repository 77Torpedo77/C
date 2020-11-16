#define N 20 // ���пռ�ĳ�ʼ������  
#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct
{
	ElemType *qlist;// ����ַ  
	int front, rear; //��ͷ�Ͷ�βָ�룬�����ֱ��
} lqueue;


void initQueue(lqueue *lq)//��ʼ��
{
	lq->qlist = (ElemType *)malloc(N * sizeof(ElemType)); // �����ڴ�  
	lq->front = lq->rear = 0;							 //ͷ��β��ʼ��Ϊ0 
}


int getFront(lqueue *lq, ElemType *data)//��ȡ��ͷԪ��ֵ
{
	if (lq->front == lq->rear)//�ж϶ӿ�
		return 0;
	*data = lq->qlist[lq->front]; // ȡ��ͷԪ��  
	return 1;
}

  
int intoQueue(lqueue *lq, ElemType data)//���
{
	if ((lq->rear + 1) % N == lq->front)//�ж϶���
		return 0;				   
	lq->qlist[lq->rear] = data;		   // �����  
	lq->rear = (lq->rear + 1) % N; // �޸Ķ�βָ��  
	return 1;
}

int outQueue(lqueue *lq, ElemType *data)//����
{
	if (lq->front == lq->rear)//�ж϶ӿ�
		return 0;					 
	*data = lq->qlist[lq->front]; // ȡ��ͷԪ��  
	lq->front = (lq->front + 1) % N; // �޸Ķ�ͷָ��  
	return 1;
}
  
int isempty(lqueue *lq)
{
	if (lq->front == lq->rear)
		return 1;
	else
		return 0;
}

void printQueue(lqueue *lq)//��ӡ����
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