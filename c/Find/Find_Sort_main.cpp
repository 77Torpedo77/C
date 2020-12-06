#include <stdio.h>
#include <stdlib.h>
typedef int keytype; /* �ؼ������� */
typedef struct
{
    keytype key;         /* �ؼ����� */
} ElemType;              /* ���ұ�������Ԫ������ */
typedef struct
{
    ElemType *elem; /* ˳������ַ */
    int length;     /* ˳����� */
} stable;           /* ���ұ����� */

/* ����˳����ұ� */
#define MAXSIZE 20
void cretable(stable *Q)
{
    int i;
    keytype x;
    Q->elem = (ElemType *)malloc(sizeof(ElemType) * (MAXSIZE + 1));//�½��ڴ�ռ�
    printf("Input keys(-1:End):");//��ӡ��ʾ��Ϣ
    scanf("%d", &x);//��������
    i = 0;
    while (x != -1 && i < MAXSIZE)//ѭ����������
    {
        Q->elem[i].key = x;
        i++;
        scanf("%d", &x);

    }
    Q->length = i;//���ñ�
}

/* ���˳����ұ� */
void list(stable *Q)
{
    int i;
    for (i = 0; i < Q->length; i++)//���������ͷ
        printf("%5d", i);
    printf("\n");
    for (i = 0; i < Q->length; i++)
        printf("%5d", Q->elem[i].key);//���������ͷ��Ӧ����
    printf("\n");
}

int cutFind(stable *Q , keytype key)//���ֲ���
{
    int low=0 , hight = Q->length-1 , mid;
    while (low<=hight)//����λ�±�С�ڵ��ڸ�λ�±�ʱһֱѭ��
    {
        mid = (low + hight)/2;//�е�
        if (Q->elem[mid].key == key)//���պõ��ڣ�����
        {
            return mid;
        }
        else if (Q->elem[mid].key > key)//���е�ֵ����Ҫ���ҵ�ֵ���������λ�±�
        {
            hight = mid-1;
        }
        else//��֮������λ�±�
        {
            low = mid +1;
        }
    }
    return -1;
}

int seqFind(stable* Q , keytype key)//˳�����
{
    int i = 0;
    for( i = 0; i < Q->length; i++)//��˳��������ң����ҵ��ͷ��ؼ���
    {
        if (Q->elem[i].key == key)
        {
            return i;
        }
        
    }
    return -1;
}

void selectSort(stable* Q)//ѡ������
{
    int i,j,min,temp;
    for ( i = 0; i < Q->length-1; i++)//�ӵ�һ�������������ڶ���
    {
        min = i;
        for ( j = i+1; j < Q->length; j++)//����С
        {
            if (Q->elem[j].key < Q->elem[min].key)
            {
                min = j;
            }
        }
        temp = Q->elem[i].key;//������С�뵱ǰiָ��ָ���λ��
        Q->elem[i].key = Q->elem[min].key;
        Q->elem[min].key = temp;
    }
    
}
void insertSort(stable* Q)//��������
{
	int i,j,temp;
	for (i = 1; i < Q->length; i++)//�ӵ�һ�����������һ��
	{
		temp = Q->elem[i].key;//�ѵ�ǰָ����ó���
		for (j=i-1;j>=0 && Q->elem[j].key>temp;j--)//����Ӧ���ڵ�λ��
		{
			 Q->elem[j+1].key = Q->elem[j].key;
		}
		 Q->elem[j+1].key = temp;//���ȥ
	}	
}

void bubbleSort(stable *Q)//ð������
{
	int i, j, flag = 1;
	ElemType t;
	for (i = 0; flag && i < Q->length; i++)//�ӵ�һ�����������һ����flag������ǰֹͣ����ٶ�
		for (j = 0, flag = 0; j < Q->length - i-1; j++)//�����ֵ��ǰð�ݣ���������ð����flag=1
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
	printf("cutFind��the num1 position is:%d\n",cutFind(&Q,a));
	printf("seqFind��the num1 position is:%d\n",seqFind(&Q,a));
	printf("cutFind��the num2 position is:%d\n",cutFind(&Q,b));
	printf("seqFind��the num2 position is:%d\n",seqFind(&Q,b));

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