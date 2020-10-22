#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"



pHead* createList()
{
    pHead* ph = (pHead*)malloc(sizeof(pHead));
    ph->length = 0;
    ph->next = NULL;
    return ph;
}

int getLength(pHead* ph)
{
    if (ph!=NULL)
    {
        return ph->length;
    }
    else
    {
        printf("error");
        return -1;
    }
}


int addElm(pHead* ph, int val)
{
    Node* tpre=NULL;
    if (ph==NULL||val==NULL)
    {
        printf("error");
        return -1;
    }

    Node* tnode = (Node*)malloc(sizeof(Node));
    tnode->data = val;
    tpre = (Node*)ph;

    for (int  i = 0; i < ph->length; i++)
    {
        tpre = tpre->next;
    }
    tpre->next = tnode;
    tnode->next = NULL;
    ph->length++;
    return 1;

}

int insertElm(pHead* ph,int pos,int val)
{   
	Node* tpre=NULL;
	if (ph==NULL||pos<0||val==NULL||pos>ph->length)
	{
		printf("error");
		return -1;
	}

	Node* tnode = (Node*)malloc(sizeof(Node));
	tnode->data = val;
	tpre = (Node*)ph;
	for (int  i = 0; i < pos; i++)
	{
		tpre = tpre->next;
	}
	if (pos==ph->length)
	{
		addElm(ph,val);
	}

	tnode->next = tpre->next;
	tpre->next = tnode;
	ph->length++;
	return 1;

}

Node* find(pHead* ph, int val)
{
    if (ph==NULL)
    {
        printf("error");
        return NULL;
    }

    Node* pTmp = NULL;
    pTmp = (Node*)ph;
    while (pTmp->next!=NULL)
    {
        if (pTmp->data == val)
        {
            return pTmp;
        }
        pTmp = pTmp->next;
    }
    printf("have no %d in the linkedlist",val);
    return NULL;
}

int delElm(pHead* ph, int val)
{
    Node* ptemp= NULL;
    if(ph == NULL)
    {
        printf("linkedlist address error");
        return -1;
    }

    ptemp = find(ph,val);
    if (ptemp == NULL )
    {
        printf("have no the elm :%d",val);
        return -1;
    }
}