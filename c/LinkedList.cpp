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
    Node* temp;
    if (ph==NULL||pos<0||val==NULL||pos>ph->length)
    {
        printf("出现错误，请检查")；
        return -1;
    }

    Node* tnode = (Node*)malloc(sizeof(Node));
    tndoe->data = val;
    if (pos==0)
    {
        tnode->next = ph->next;
        ph->next = tnode;
    }
    else
    {
        for (int  i = 0; i < pos; i++)
        {
            
        }
        
    }
    
    
}