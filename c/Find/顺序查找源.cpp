#include<stdlib.h>
#include<stdio.h>
typedef int keytype;           /* 关键字类型 */
typedef struct
{
	keytype key;                 /* 关键字域 */
	/*datatype others;*/         /* 其他数据项，读者可根据需要自行定义 */
}ElemType;                     /* 查找表中数据元素类型 */
typedef struct
{
	ElemType *elem;              /* 顺序表基地址 */
	int length;                  /* 顺序表长度 */
}stable;                       /* 查找表类型 */


/* 建立顺序查找表 */
#define MAXSIZE 20
void cretable(stable *Q)
{
	int i; keytype x;
	Q->elem = (ElemType *)malloc(sizeof(ElemType)*(MAXSIZE + 1));
	printf("Input keys(-1:End):");
	scanf("%d", &x);
	i = 0;
	while (x != -1 && i<MAXSIZE)
	{
		i++;
		Q->elem[i].key = x;
		scanf("%d", &x);
	}
	Q->length = i;
}

/* 输出顺序查找表 */
void list(stable *Q)
{
	int i;
	for (i = 1; i <= Q->length; i++)
		printf("%5d", i);
	printf("\n");
	for (i = 1; i <= Q->length; i++)
		printf("%5d", Q->elem[i].key);
	printf("\n");
}


/* 顺序查找的一般算法 */
int seqsearch1(stable *ST, keytype key)
{
	int i;
	for (i = ST->length; i>0; i--)                     /* 也可写成 for(i=1;i<=ST.length;i++) */
		if (ST->elem[i].key == key) return i;
	return 0;
}

/* 改进的顺序查找算法 */
int seqsearch2(stable *ST, keytype key)
{
	int i;
	ST->elem[0].key = key;                          /* 设置监视哨 */
	for (i = ST->length; ST->elem[i].key != key; i--);   /* 循环体为空 */
	return i;
}


/* 计算查找成功时的平均查找长度 */
float ASLsucc(stable *Q)
{
	int i, s = 0;
	for (i = 1; i <= Q->length; i++)
		s += i;                                       /* 计算比较次数 */
	return (float)s / Q->length;
}

/* 计算查找失败时的平均查找长度 */
int ASLfail(stable *Q)
{
	return Q->length + 1;
}

int main()
{
	stable Q;
	keytype key;
	cretable(&Q);                                /* 建立查找表 */
	list(&Q);                                    /* 输出查找表 */
	scanf("%d", &key);                            /* 输入查找关键字 */
	printf("%d\n", seqsearch1(&Q, key));           /* 用改进前算法查找并输出查找结果 */
	printf("%d\n", seqsearch2(&Q, key));           /* 用改进前算法查找并输出查找结果 */
	printf("%f\n", ASLsucc(&Q));                  /* 输出查找成功时的平均查找长度 */
	printf("%d\n", ASLfail(&Q));                  /* 输出查找失败时的平均查找长度 */
}