#include <stdio.h>
#include <stdlib.h>
typedef int keytype; /* 关键字类型 */
typedef struct
{
    keytype key;         /* 关键字域 */
} ElemType;              /* 查找表中数据元素类型 */
typedef struct
{
    ElemType *elem; /* 顺序表基地址 */
    int length;     /* 顺序表长度 */
} stable;           /* 查找表类型 */

/* 建立顺序查找表 */
#define MAXSIZE 20
void cretable(stable *Q)
{
    int i;
    keytype x;
    Q->elem = (ElemType *)malloc(sizeof(ElemType) * (MAXSIZE + 1));
    printf("Input keys(-1:End):");
    scanf("%d", &x);
    i = 0;
    while (x != -1 && i < MAXSIZE)
    {
        Q->elem[i].key = x;
        i++;
        scanf("%d", &x);

    }
    Q->length = i;
}

/* 输出顺序查找表 */
void list(stable *Q)
{
    int i;
    for (i = 0; i < Q->length; i++)
        printf("%5d", i);
    printf("\n");
    for (i = 0; i < Q->length; i++)
        printf("%5d", Q->elem[i].key);
    printf("\n");
}

/* 对顺序表用起泡排序法排序 */
void sort(stable *Q)
{
    int i, j, flag = 1;
    ElemType t;
    for (i = 0; flag && i < Q->length; i++)
        for (j = 0, flag = 0; j < Q->length - i-1; j++)
            if (Q->elem[j].key > Q->elem[j + 1].key)
            {
                t = Q->elem[j];
                Q->elem[j] = Q->elem[j + 1];
                Q->elem[j + 1] = t;
                flag = 1;
            }
}

int cutFind(stable *Q , keytype key)
{
    int low=0 , hight = Q->length-1 , mid;
    while (low<=hight)
    {
        mid = (low + hight)/2;
        if (Q->elem[mid].key == key)
        {
            return mid;
        }
        else if (Q->elem[mid].key > key)
        {
            hight = mid-1;
        }
        else
        {
            low = mid +1;
        }
    }
    return -1;
}

int seqFind(stable* Q , keytype key)
{
    int i = 0;
    for( i = 0; i < Q->length; i++)
    {
        if (Q->elem[i].key == key)
        {
            return i;
        }
        
    }
    return -1;
}

void selectSort(stable* Q)
{
    int i,j,min,temp;
    for ( i = 0; i < Q->length-1; i++)
    {
        min = i;
        for ( j = i+1; j < Q->length; j++)
        {
            if (Q->elem[j].key < Q->elem[min].key)
            {
                min = j;
            }
        }
        temp = Q->elem[i].key;
        Q->elem[i].key = Q->elem[min].key;
        Q->elem[min].key = temp;
    }
    
}
int main()
{   keytype a , b;
    stable Q;
    cretable(&Q);
    list(&Q);
    selectSort(&Q);
    list(&Q);
    //scanf("%d %d", &a,&b);
    //printf("cutFind：the num1 position is:%d\n",cutFind(&Q,a));
    //printf("seqFind：the num1 position is:%d\n",seqFind(&Q,a));
    //printf("cutFind：the num2 position is:%d\n",cutFind(&Q,b));
    //printf("seqFind：the num2 position is:%d\n",seqFind(&Q,b));

    system("pause");
}