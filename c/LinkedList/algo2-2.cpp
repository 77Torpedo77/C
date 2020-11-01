#include <stdio.h>
#include <malloc.h>
typedef int ElemType;//为了使程序美观
typedef struct LNode //定义单链表结点类型
{
	ElemType data;
	struct LNode *next;
} LinkList;

void initList(LinkList *&L) //初始化线性表
{
	L = (LinkList *)malloc(sizeof(LinkList)); //创建头结点
	L->next = NULL;//防止指针悬空
}
void delList(LinkList *&L) //销毁线性表
{
	LinkList *p = L, *next = p->next;//创建临时指针，方便释放内存
	while (next != NULL)//只要没销毁完就一直往下走
	{
		free(p);//释放当前节点
		p = next;
		next = p->next;//往下走
	}
	free(p);//最后一步循环时释放掉p
}
bool isEmpty(LinkList *L) //判线性表是否为空表
{
	return (L->next == NULL);//判断，如果头节点的下一个为空，则返回0，反之返回1
}
int getLength(LinkList *L) //求线性表的长度
{
	LinkList *p = L;//创建临时指针
	int i = 0;
	while (p->next != NULL)//当下一个不为空时就一直往下走
	{
		i++;
		p = p->next;
	}
	return (i);//返回计数器i的值
}
void printList(LinkList *L) //输出线性表
{
	LinkList *p = L->next;//头节点无信息
	while (p != NULL)//没到表尾就一直打印
	{
		printf("%d ", p->data);//打印data
		p = p->next;//往下走
	}
	printf("\n");//打印换行，为了美观
}
bool isElmExist(LinkList *L, int i, ElemType &e) //求线性表中某个位置的元素是否存在
{
	int j = 0;
	LinkList *p = L;		   //p指向头节点,j置为0(即头节点的序号为0)
	while (j < i && p != NULL) //找第i个节点
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //不存在第i个数据节点,返回0
		return false;
	else //存在第i个数据节点,返回1
	{
		e = p->data;
		return true;
	}
}
int getElmPos(LinkList *L, ElemType e) //按元素值查找其的位置
{
	int i = 1;
	LinkList *p = L->next;			  //p指向开始节点,i置为1(即开始节点的序号为1)
	while (p != NULL && p->data != e) //查找data值为e的节点,其序号为i
	{
		p = p->next;
		i++;
	}
	if (p == NULL) //不存在元素值为e的节点,返回0
		return (0);
	else //存在元素值为e的节点,返回其逻辑序号i
		return (i);
}
bool inserElm(LinkList *&L, int i, ElemType e) //插入数据元素到某一位置
{
	int j = 0;
	LinkList *p = L, *s;		   //p指向头节点,j置为0(即头节点的序号为0)
	while (j < i - 1 && p != NULL) //查找第i-1个节点
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //未找到第i-1个节点,返回false
		return false;
	else //找到第i-1个节点*p,插入新节点并返回1
	{
		s = (LinkList *)malloc(sizeof(LinkList));
		s->data = e;	   //创建新节点*s,其data域置为e
		s->next = p->next; //将*s插入到*p之后
		p->next = s;
		return true;
	}
}
bool delElm(LinkList *&L, int i, ElemType &e) //删除某一个位置的元素
{
	int j = 0;
	LinkList *p = L, *q;		   //p指向头节点,j置为0(即头节点的序号为0)
	while (j < i - 1 && p != NULL) //查找第i-1个节点
	{
		j++;
		p = p->next;
	}
	if (p == NULL) //未找到第i-1个节点,返回false
		return false;
	else //找到第i-1个节点*p
	{
		q = p->next;   //q指向第i个节点
		if (q == NULL) //若不存在第i个节点,返回false
			return false;
		e = q->data;
		p->next = q->next; //从单链表中删除*q节点
		free(q);		   //释放*q节点
		return true;	   //返回true表示成功删除第i个节点
	}
}

void creatList(LinkList *&L)
{
	int i;
	int data;//待输入的数据
	for (i = 1; i < 20; i++)
	{
		scanf(" %d", &data);
		if (data == -1) //碰到-1时就结束录入
		{
			break;
		}
		inserElm(*&L, i, data);//调用插入函数将输入的元素插入链表
	}
}