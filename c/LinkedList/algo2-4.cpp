//�ļ���:algo2-4.cpp
#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode		//���嵥�����������
{
	ElemType data;
    struct LNode *next;
} LinkList;
void initList(LinkList *&L)	//��ʼ�����Ա�
{
	L=(LinkList *)malloc(sizeof(LinkList));	//����ͷ���
	L->next=L;
}
void delList(LinkList *&L)	//�������Ա�
{
	LinkList *p=L,*q=p->next;
	while (q!=L)
	{
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
}
bool isEmpty(LinkList *L)	//�пձ�
{
	return(L->next==L);
}
int getLength(LinkList *L)	//�����
{
	LinkList *p=L;
	int i=0;
	while (p->next!=L)
	{
		i++;
		p=p->next;
	}
	return(i);
}
void printList(LinkList *L)	//������Ա�
{
	LinkList *p=L->next;
	while (p!=L)
	{
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
bool isElmExist(LinkList *L,int i,ElemType &e)	//��ָ��λ�õ�Ԫ��
{
	int j=0;
	LinkList *p;
	if (L->next!=L)		//��������Ϊ�ձ�ʱ
	{
		if (i==1)
		{
			e=L->next->data;
			return true;
		}
		else			//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-1 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)
				return false;
			else
			{
				e=p->data;
				return true;
			}
		}
	}
	else				//�ձ�����false
		return false;
}
int getElmPos(LinkList *L,ElemType e)	//����Ԫ��λ��
{
	LinkList *p=L->next;
	int n=1;
	while (p!=L && p->data!=e)
	{
		p=p->next;
		n++;
	}
	if (p==L)
		return(0);
	else
		return(n);
}
bool inserElm(LinkList *&L,int i,ElemType e)	//����Ԫ��
{
	int j=0;
	LinkList *p=L,*s;
	if (p->next==L || i==1)		//ԭ������Ϊ�ձ���i==1ʱ
	{
		s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
		s->data=e;								
		s->next=p->next;		//��*s���뵽*p֮��
		p->next=s;
		return true;
	}
	else
	{
		p=L->next;
		while (j<i-2 && p!=L)
		{
			j++;
			p=p->next;
		}
		if (p==L)				//δ�ҵ���i-1�����
			return false;
		else					//�ҵ���i-1�����*p
		{
			s=(LinkList *)malloc(sizeof(LinkList));	//�����½��*s
			s->data=e;								
			s->next=p->next;						//��*s���뵽*p֮��
			p->next=s;
			return true;
		}
	}
}
bool delElm(LinkList *&L,int i,ElemType &e)	//ɾ��Ԫ��
{
	int j=0;
	LinkList *p=L,*q;
	if (p->next!=L)					//ԭ��������Ϊ�ձ�ʱ
	{
		if (i==1)					//i==1ʱ
		{
			q=L->next;				//ɾ����1�����
			e=q->data;
			L->next=q->next;
			free(q);
			return true;
		}
		else						//i��Ϊ1ʱ
		{
			p=L->next;
			while (j<i-2 && p!=L)
			{
				j++;
				p=p->next;
			}
			if (p==L)				//δ�ҵ���i-1�����
				return false;
			else					//�ҵ���i-1�����*p
			{
				q=p->next;			//qָ��Ҫɾ���Ľ��
				e=q->data;
				p->next=q->next;	//�ӵ�������ɾ��*q���
				free(q);			//�ͷ�*q���
				return true;
			}
		}
	}
	else							//�ձ�����false
		return false;
}


