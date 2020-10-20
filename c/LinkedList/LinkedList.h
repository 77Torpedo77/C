
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct Header
{
	int length;
	struct Node* next;
}pHead;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

pHead* createList();
int getLength(pHead* ph);
int addElm(pHead* ph, int val);
int insertElm(pHead* ph,int pos,int val);
Node* find(pHead* ph, int val);

#endif 