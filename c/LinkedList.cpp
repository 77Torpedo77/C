#include <stdio.h>
#include <stdlib.h>

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
        printf("参数有误");
        return -1;
    }
}

int insertElm(pHead* ph,int pos,int val)
{   
    Node* tpre=NULL;
    if (ph==NULL||pos<0||val==NULL||pos>ph->length)
    {
        printf("出现错误，请检查")；
        return -1;
    }

    Node* tnode = (Node*)malloc(sizeof(Node));
    tndoe->data = val;
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

int addElm(pHead* ph, int val)
{
    Node* tpre=NULL;
    if (ph==NULL||val==NULL)
    {
        printf("出现错误，请检查")；
        return -1;
    }

    Node* tnode = (Node*)malloc(sizeof(Node));
    tndoe->data = val;
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

Node* find(pHead* ph, int val)
{
    if (ph==NULL)
    {
        printf("参数有误");
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
    printf("没有值为%d的元素",val);
    return NULL;
}