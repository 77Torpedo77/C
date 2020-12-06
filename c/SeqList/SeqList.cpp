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
    if (list->length <= 0)//判断表长是否为0
    {
        printf("表是空的!\n");
    }
    for (i = 0; i < list->length; i++)//在表的长度内打印所有的元素
    {
        printf("%d\n", list->data[i]);
    }
}

int inserElm(List *list, int i, int data)//加入元素到指定位置
{
    int j;
    if (list->length >= MAXNUM)//判断表是否已满
    {
        printf("满了，插不进了");
        return (0);
    }
    if (i < 0 || i > list->length)//判断位置是否合法，负数或超出当前表长为不合法
    {
        printf("\n%d 这个位置不合法", i);
        return (0);
    }
    for (j = list->length; j >= i; j--)//将该位置之后的所有元素后移一位
    {
        list->data[j + 1] = list->data[j];
    }
    list->data[i] = data;//将该位置的值设置为插入值
    list->length++;//增加表长
    return (1);
}

int deleteElm(List *list, int i)//删除元素
{
    int j;
    if (i < 0 || i > list->length - 1)//判断删除位置是否合法
    {
        printf("该元素不存在");
        return (0);
    }
    for (j = i + 1; j < list->length; j++)//将该位置之后的元素全部向前移动
    {
        list->data[j - 1] = list->data[j];
    }
    list->length--;//表长-1
    return (1);
}

void deleteNeg(List *list)//删除负数
{
    int i, j, k;
    for (j = 0; j < list->length; j++)//遍历一次表
    {
        if (list->data[j] < 0)//如果为负数
        {
            i = 1;
            while (list->data[j + i] < 0 && (j + i) < list->length)//记录连着的负数个数
            {
                i++;
            }
            for (k = j; k < list->length; k++)//将所有负数移动到表的后端
            {
                list->data[k] = list->data[k + i];
            }
            list->length -= i;//表长减少负数个个数
        }
    }
    return;
}

void invertList(List *list)//翻转顺序表
{
    int i = 0, j = 0, len = list->length / 2;
    for (i = 0; i < len; i++)//将首尾对应元素对换位置
    {
        j = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = j;
    }
}
