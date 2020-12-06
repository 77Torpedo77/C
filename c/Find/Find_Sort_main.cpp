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
    Q->elem = (ElemType *)malloc(sizeof(ElemType) * (MAXSIZE + 1));//新建内存空间
    printf("Input keys(-1:End):");//打印提示信息
    scanf("%d", &x);//读入数据
    i = 0;
    while (x != -1 && i < MAXSIZE)//循环读入数据
    {
        Q->elem[i].key = x;
        i++;
        scanf("%d", &x);

    }
    Q->length = i;//设置表长
}

/* 输出顺序查找表 */
void list(stable *Q)
{
    int i;
    for (i = 0; i < Q->length; i++)//遍历输出表头
        printf("%5d", i);
    printf("\n");
    for (i = 0; i < Q->length; i++)
        printf("%5d", Q->elem[i].key);//遍历输出表头对应内容
    printf("\n");
}

int cutFind(stable *Q , keytype key)//二分查找
{
    int low=0 , hight = Q->length-1 , mid;
    while (low<=hight)//当低位下标小于等于高位下标时一直循环
    {
        mid = (low + hight)/2;//中点
        if (Q->elem[mid].key == key)//若刚好等于，返回
        {
            return mid;
        }
        else if (Q->elem[mid].key > key)//若中点值大于要查找的值，则调整高位下标
        {
            hight = mid-1;
        }
        else//反之调整低位下标
        {
            low = mid +1;
        }
    }
    return -1;
}

int seqFind(stable* Q , keytype key)//顺序查找
{
    int i = 0;
    for( i = 0; i < Q->length; i++)//按顺序遍历查找，当找到就返回即可
    {
        if (Q->elem[i].key == key)
        {
            return i;
        }
        
    }
    return -1;
}

void selectSort(stable* Q)//选择排序
{
    int i,j,min,temp;
    for ( i = 0; i < Q->length-1; i++)//从第一个遍历到倒数第二个
    {
        min = i;
        for ( j = i+1; j < Q->length; j++)//找最小
        {
            if (Q->elem[j].key < Q->elem[min].key)
            {
                min = j;
            }
        }
        temp = Q->elem[i].key;//交换最小与当前i指针指向的位置
        Q->elem[i].key = Q->elem[min].key;
        Q->elem[min].key = temp;
    }
    
}
void insertSort(stable* Q)//插入排序
{
	int i,j,temp;
	for (i = 1; i < Q->length; i++)//从第一个遍历到最后一个
	{
		temp = Q->elem[i].key;//把当前指向的拿出来
		for (j=i-1;j>=0 && Q->elem[j].key>temp;j--)//找他应该在的位置
		{
			 Q->elem[j+1].key = Q->elem[j].key;
		}
		 Q->elem[j+1].key = temp;//插进去
	}	
}

void bubbleSort(stable *Q)//冒泡排序
{
	int i, j, flag = 1;
	ElemType t;
	for (i = 0; flag && i < Q->length; i++)//从第一个遍历到最后一个，flag用于提前停止提高速度
		for (j = 0, flag = 0; j < Q->length - i-1; j++)//将大的值向前冒泡，若进行了冒泡则flag=1
			if (Q->elem[j].key > Q->elem[j + 1].key)
			{
				t = Q->elem[j];
				Q->elem[j] = Q->elem[j + 1];
				Q->elem[j + 1] = t;
				flag = 1;
			}
}
int main()
{   keytype a , b;
    stable Q,K;
    cretable(&Q);
    list(&Q);
	bubbleSort(&Q);
	printf("sorted list:\n");
	list(&Q);
	printf("plz input what key u want to find:");
	scanf("%d %d", &a,&b);
	printf("cutFind：the num1 position is:%d\n",cutFind(&Q,a));
	printf("seqFind：the num1 position is:%d\n",seqFind(&Q,a));
	printf("cutFind：the num2 position is:%d\n",cutFind(&Q,b));
	printf("seqFind：the num2 position is:%d\n",seqFind(&Q,b));

	cretable(&K);
	printf("bubble-sorted list:\n");
	bubbleSort(&K);
	list(&K);

	printf("select-sorted list:\n");
	selectSort(&K);
	list(&K);

	printf("insert-sorted list:\n");
	insertSort(&K);
    list(&K);

    system("pause");
}