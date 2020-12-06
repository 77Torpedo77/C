#include<stdio.h>
#include<stdlib.h>
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


/* 对顺序表用起泡排序法排序 */
void sort(stable *Q)
{
	int i, j, flag = 1; ElemType t;
	for (i = 1; flag&&i<Q->length; i++)
		for (j = 1, flag = 0; j <= Q->length - i; j++)
			if (Q->elem[j].key>Q->elem[j + 1].key)
			{
				t = Q->elem[j];
				Q->elem[j] = Q->elem[j + 1];
				Q->elem[j + 1] = t;
				flag = 1;
			}
}


/* 二分查找算法 */
int binsearch(stable *ST, keytype key)
{
	int low = 1, high = ST->length, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;                       /* 取中间元素下标 */
		if (ST->elem[mid].key == key) return mid;  /* 找到 */
		if (key<ST->elem[mid].key) high = mid - 1;   /* 在左半区 */
		else low = mid + 1;                         /* 在右半区 */
	}
	return 0;                                 /* 没找到 */
}


/* 计算查找成功时的平均查找长度 */
float ASLsucc(stable *Q)
{
	int k, i, low, high, mid, s = 0;       /* s是查找全部记录的比较次数 */
	for (i = 1; i <= Q->length; i++)
	{
		low = 1; high = Q->length;
		k = 0;                          /* k是查找一个记录的比较次数 */
		while (low <= high)
		{
			mid = (low + high) / 2;
			k++;
			if (mid == i) break;
			if (Q->elem[mid].key>Q->elem[i].key) high = mid - 1;
			else low = mid + 1;
		}
		s += k;
	}
	return (float)s / Q->length;      /* 平均查找查长度 */
}


/* 计算查找失败时平均查找长度 */
float ASLfail(stable *Q)
{
	int k, i, low, high, mid, s = 0; keytype x;                 /* s是查找全部记录的比较次数 */
	Q->elem[0].key = Q->elem[1].key - 10;
	Q->elem[Q->length + 1].key = Q->elem[Q->length].key + 10;
	for (i = 1; i <= Q->length + 1; i++)                         /* 查找失败有n+1种情况 */
	{
		x = (Q->elem[i - 1].key + Q->elem[i].key) / 2;            /* 得到不存在的记录关键字 */
		low = 1; high = Q->length;
		k = 0;                                              /* k是查找一个记录的比较次数 */
		while (low <= high)
		{
			mid = (low + high) / 2;
			k++;
			if (Q->elem[mid].key>x) high = mid - 1;
			else low = mid + 1;
		}
		s += k;
	}
	return (float)s / (Q->length + 1);                      /* 平均查找查长度 */
}



int main()
{
	stable Q;
	keytype key;
	ElemType k;
	cretable(&Q);                              /* 建立查找表 */
	list(&Q);                                  /* 输出查找表 */

	sort(&Q);                                  /* 查找表排序 */
	list(&Q);                                  /* 输出排序后的查找表 */

	scanf("%d", &key);                          /* 输入查找记录关键字 */
	printf("%d\n", binsearch(&Q, key));          /* 查找并输出查找结果 */
	printf("%f\n", ASLsucc(&Q));                /* 输出查找成功是的平均查找长度 */
	printf("%f\n", ASLfail(&Q));                /* 输出查找失败是的平均查找长度 */
}