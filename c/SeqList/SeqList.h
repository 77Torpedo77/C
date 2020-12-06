#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define MAXNUM 128 //限制表的最大长度，设置为超过20的是为了防止满表插入情况

typedef struct List
{
    int data[MAXNUM];//存放顺序表的数组
    int length;//顺序表的长度
} List;//将结构体重命名为List

void createList(List *l);
void printList(List *l);
int inserElm(List *l, int i, int data);
int deleteElm(List *l, int i);
void deleteNeg(List *l);
void invertList(List *list);

#endif
