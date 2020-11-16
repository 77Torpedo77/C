#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; 
typedef struct Node
{
	ElemType data;	   // ������ 
	struct Node *next; // ָ���� 
} LinkStack;

LinkStack *initstack()//��ʼ��������ͷ�ڵ�
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack));
	p->next = NULL;//��ʼ��ʱ��ָֹ������
	return p;
}

int push(LinkStack *S, ElemType data)//��ջ
{
	LinkStack *p;
	p = (LinkStack *)malloc(sizeof(LinkStack)); 
	if (p == NULL)
		return 0; //��ֹ�ռ��������
	p->data = data;//����ʱ�ڵ��data��ֵ
	p->next = S->next; // ���뵽ͷ���֮�� 
	S->next = p;//ͷ�ڵ�ָ���µ�ջ��
	return 1;
}

int pop(LinkStack *S, ElemType *data)//��ջ
{
	LinkStack *p;
	if (S->next == NULL)
		return 0; // ջ��ʱ����ɾ��
	p = S->next;
	*data = p->data; // ��ջʱҪ���ر�������Ԫ�ص�ֵ�����⴫��ָ��ﵽ����Ŀ��
	S->next = p->next;
	free(p);//�ͷű������Ľڵ�Ŀռ�
	return 1; // ��ջ�ɹ�,����1 
}

void printStack(LinkStack *S)//��ӡ����ջ
{
	LinkStack *p;
	p = S->next;
	while (p != NULL)//ջû��һֱ���´�ӡ
	{
		printf("%4d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int getTopElm(LinkStack *S, ElemType *data)//��ȡջ��Ԫ��
{
	if (S->next == NULL)
		return 0;		//�ж�ջ��
	*data = S->next->data; //ȡջ��
	return 1;
}

int isEmpty(LinkStack *S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S->next == NULL)
		return 1; // ջ��,����1,���򷵻�0 
	else
		return 0;
}

int getLength(LinkStack *S)//��ȡջ�ĳ���
{
	LinkStack *p;
	int i;
	p = S->next;
	i = 0;//������
	while (p != NULL)//ջû��һֱ��
	{
		i++;
		p = p->next;
	}
	return i;//���ؼ������
}
