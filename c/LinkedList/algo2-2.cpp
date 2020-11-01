#include <stdio.h>
#include <malloc.h>
typedef int ElemType;//Ϊ��ʹ��������
typedef struct LNode //���嵥����������
{
	ElemType data;
	struct LNode *next;
} LinkList;

void initList(LinkList *&L) //��ʼ�����Ա�
{
	L = (LinkList *)malloc(sizeof(LinkList)); //����ͷ���
	L->next = NULL;//��ָֹ������
}
void delList(LinkList *&L) //�������Ա�
{
	LinkList *p = L, *next = p->next;//������ʱָ�룬�����ͷ��ڴ�
	while (next != NULL)//ֻҪû�������һֱ������
	{
		free(p);//�ͷŵ�ǰ�ڵ�
		p = next;
		next = p->next;//������
	}
	free(p);//���һ��ѭ��ʱ�ͷŵ�p
}
bool isEmpty(LinkList *L) //�����Ա��Ƿ�Ϊ�ձ�
{
	return (L->next == NULL);//�жϣ����ͷ�ڵ����һ��Ϊ�գ��򷵻�0����֮����1
}
int getLength(LinkList *L) //�����Ա�ĳ���
{
	LinkList *p = L;//������ʱָ��
	int i = 0;
	while (p->next != NULL)//����һ����Ϊ��ʱ��һֱ������
	{
		i++;
		p = p->next;
	}
	return (i);//���ؼ�����i��ֵ
}
void printList(LinkList *L) //������Ա�
{
	LinkList *p = L->next;//ͷ�ڵ�����Ϣ
	while (p != NULL)//û����β��һֱ��ӡ
	{
		printf("%d ", p->data);//��ӡdata
		p = p->next;//������
	}
	printf("\n");//��ӡ���У�Ϊ������
}
bool isElmExist(LinkList *L, int i, ElemType &e) //�����Ա���ĳ��λ�õ�Ԫ���Ƿ����
{
	int j = 0;
	LinkList *p = L;		   //pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i && p != NULL) //�ҵ�i���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //�����ڵ�i�����ݽڵ�,����0
		return false;
	else //���ڵ�i�����ݽڵ�,����1
	{
		e = p->data;
		return true;
	}
}
int getElmPos(LinkList *L, ElemType e) //��Ԫ��ֵ�������λ��
{
	int i = 1;
	LinkList *p = L->next;			  //pָ��ʼ�ڵ�,i��Ϊ1(����ʼ�ڵ�����Ϊ1)
	while (p != NULL && p->data != e) //����dataֵΪe�Ľڵ�,�����Ϊi
	{
		p = p->next;
		i++;
	}
	if (p == NULL) //������Ԫ��ֵΪe�Ľڵ�,����0
		return (0);
	else //����Ԫ��ֵΪe�Ľڵ�,�������߼����i
		return (i);
}
bool inserElm(LinkList *&L, int i, ElemType e) //��������Ԫ�ص�ĳһλ��
{
	int j = 0;
	LinkList *p = L, *s;		   //pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i - 1 && p != NULL) //���ҵ�i-1���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //δ�ҵ���i-1���ڵ�,����false
		return false;
	else //�ҵ���i-1���ڵ�*p,�����½ڵ㲢����1
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = e;	   //�����½ڵ�*s,��data����Ϊe
		s->next = p->next; //��*s���뵽*p֮��
		p->next = s;
		return true;
	}
}
bool delElm(LinkList *&L, int i, ElemType &e) //ɾ��ĳһ��λ�õ�Ԫ��
{
	int j = 0;
	LinkList *p = L, *q;		   //pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i - 1 && p != NULL) //���ҵ�i-1���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //δ�ҵ���i-1���ڵ�,����false
		return false;
	else //�ҵ���i-1���ڵ�*p
	{
		q = p->next;   //qָ���i���ڵ�
		if (q == NULL) //�������ڵ�i���ڵ�,����false
			return false;
		e = q->data;
		p->next = q->next; //�ӵ�������ɾ��*q�ڵ�
		free(q);		   //�ͷ�*q�ڵ�
		return true;	   //����true��ʾ�ɹ�ɾ����i���ڵ�
	}
}

void creatList(LinkList *&L)
{
	int i;
	int data;//�����������
	for (i = 1; i < 20; i++)
	{
		scanf(" %d", &data);
		if (data == -1) //����-1ʱ�ͽ���¼��
		{
			break;
		}
		inserElm(*&L, i, data);//���ò��뺯���������Ԫ�ز�������
	}
}