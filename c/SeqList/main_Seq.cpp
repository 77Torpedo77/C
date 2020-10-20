#include<stdio.h>
#include"SeqList.h"
#include<stdlib.h>

int main()
{
    List list;
    int i,data;
    createList(&list);
    printList(&list);

    printf("\n请输入插入位置以及值：\n");
    scanf("%d %d",&i,&data);
    inserElm(&list,i,data);
    printf("\n插入之后的表如下\n");
    printList(&list);

    printf("\n请输入要删除的位置\n");
    scanf("%d",&i);
    deleteElm(&list,i);
    printf("\n删除之后的表如下\n");
    printList(&list);

    deleteNeg(&list);
    printf("\n删除负数之后的表如下\n");
    printList(&list);

    invertList(&list);
    printf("\n颠倒之后的表如下\n");
    printList(&list);
    system("pause");       
}