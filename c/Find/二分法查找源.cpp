#include<stdio.h>
#include<stdlib.h>
typedef int keytype;           /* �ؼ������� */
typedef struct
{
	keytype key;                 /* �ؼ����� */
	/*datatype others;*/         /* ������������߿ɸ�����Ҫ���ж��� */
}ElemType;                     /* ���ұ�������Ԫ������ */
typedef struct
{
	ElemType *elem;              /* ˳������ַ */
	int length;                  /* ˳����� */
}stable;                       /* ���ұ����� */


/* ����˳����ұ� */
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

/* ���˳����ұ� */
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


/* ��˳����������������� */
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


/* ���ֲ����㷨 */
int binsearch(stable *ST, keytype key)
{
	int low = 1, high = ST->length, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;                       /* ȡ�м�Ԫ���±� */
		if (ST->elem[mid].key == key) return mid;  /* �ҵ� */
		if (key<ST->elem[mid].key) high = mid - 1;   /* ������� */
		else low = mid + 1;                         /* ���Ұ��� */
	}
	return 0;                                 /* û�ҵ� */
}


/* ������ҳɹ�ʱ��ƽ�����ҳ��� */
float ASLsucc(stable *Q)
{
	int k, i, low, high, mid, s = 0;       /* s�ǲ���ȫ����¼�ıȽϴ��� */
	for (i = 1; i <= Q->length; i++)
	{
		low = 1; high = Q->length;
		k = 0;                          /* k�ǲ���һ����¼�ıȽϴ��� */
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
	return (float)s / Q->length;      /* ƽ�����Ҳ鳤�� */
}


/* �������ʧ��ʱƽ�����ҳ��� */
float ASLfail(stable *Q)
{
	int k, i, low, high, mid, s = 0; keytype x;                 /* s�ǲ���ȫ����¼�ıȽϴ��� */
	Q->elem[0].key = Q->elem[1].key - 10;
	Q->elem[Q->length + 1].key = Q->elem[Q->length].key + 10;
	for (i = 1; i <= Q->length + 1; i++)                         /* ����ʧ����n+1����� */
	{
		x = (Q->elem[i - 1].key + Q->elem[i].key) / 2;            /* �õ������ڵļ�¼�ؼ��� */
		low = 1; high = Q->length;
		k = 0;                                              /* k�ǲ���һ����¼�ıȽϴ��� */
		while (low <= high)
		{
			mid = (low + high) / 2;
			k++;
			if (Q->elem[mid].key>x) high = mid - 1;
			else low = mid + 1;
		}
		s += k;
	}
	return (float)s / (Q->length + 1);                      /* ƽ�����Ҳ鳤�� */
}



int main()
{
	stable Q;
	keytype key;
	ElemType k;
	cretable(&Q);                              /* �������ұ� */
	list(&Q);                                  /* ������ұ� */

	sort(&Q);                                  /* ���ұ����� */
	list(&Q);                                  /* ��������Ĳ��ұ� */

	scanf("%d", &key);                          /* ������Ҽ�¼�ؼ��� */
	printf("%d\n", binsearch(&Q, key));          /* ���Ҳ�������ҽ�� */
	printf("%f\n", ASLsucc(&Q));                /* ������ҳɹ��ǵ�ƽ�����ҳ��� */
	printf("%f\n", ASLfail(&Q));                /* �������ʧ���ǵ�ƽ�����ҳ��� */
}