#include <stdio.h>
#include "SeqList.h"

void createList(List *list)//创建表
{
    int i, data;
    list->length = 0;//创建表时设置表长为0
    for (i = 0; i < 20; i++)//录入20个元素
    {
        scanf(" %d", &data);
        if (data == -1)//碰到-1时就结束录入
        {
            break;
        }
        list->data[i] = data;
        list->length++;//表长每次+1
    }
}

void printList(List *list)//打印表
{
    int i;
    printf("\n 这有%d个记录\n", list->length);
    if (list->length <= 0)
    {
        printf("表是空的!\n");
    }
    for (i = 0; i < list->length; i++)
    {
        printf("%d\n", list->data[i]);
    }
}

int inserElm(List *list, int i, int data)
{
    int j;
    if (list->length >= MAXNUM)
    {
        printf("满了，插不进了");
        return (0);
    }
    if (i < 0 || i > list->length)
    {
        printf("\n%d 这个位置不合法", i);
        return (0);
    }
    for (j = list->length; j >= i; j--)
    {
        list->data[j + 1] = list->data[j];
    }
    list->data[i] = data;
    list->length++;
    return (1);
}

int deleteElm(List *list, int i)
{
    int j;
    if (i < 0 || i > list->length - 1)
    {
        printf("该元素不存在");
        return (0);
    }
    for (j = i + 1; j < list->length; j++)
    {
        list->data[j - 1] = list->data[j];
    }
    list->length--;
    return (1);
}

void deleteNeg(List *list)
{
    int i, j, k;
    for (j = 0; j < list->length; j++)
    {
        if (list->data[j] < 0)
        {
            i = 1;
            while (list->data[j + i] < 0 && (j + i) < list->length)
            {
                i++;
            }
            for (k = j; k < list->length; k++)
            {
                list->data[k] = list->data[k + i];
            }
            list->length -= i;
        }
    }
    return;
}

void invertList(List *list)
{
    int i = 0, j = 0, len = list->length / 2;
    for (i = 0; i < len; i++)
    {
        j = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = j;
    }
}
