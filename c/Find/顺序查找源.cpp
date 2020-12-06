#include<stdlib.h>
#include<stdio.h>
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


/* ˳����ҵ�һ���㷨 */
int seqsearch1(stable *ST, keytype key)
{
	int i;
	for (i = ST->length; i>0; i--)                     /* Ҳ��д�� for(i=1;i<=ST.length;i++) */
		if (ST->elem[i].key == key) return i;
	return 0;
}

/* �Ľ���˳������㷨 */
int seqsearch2(stable *ST, keytype key)
{
	int i;
	ST->elem[0].key = key;                          /* ���ü����� */
	for (i = ST->length; ST->elem[i].key != key; i--);   /* ѭ����Ϊ�� */
	return i;
}


/* ������ҳɹ�ʱ��ƽ�����ҳ��� */
float ASLsucc(stable *Q)
{
	int i, s = 0;
	for (i = 1; i <= Q->length; i++)
		s += i;                                       /* ����Ƚϴ��� */
	return (float)s / Q->length;
}

/* �������ʧ��ʱ��ƽ�����ҳ��� */
int ASLfail(stable *Q)
{
	return Q->length + 1;
}

int main()
{
	stable Q;
	keytype key;
	cretable(&Q);                                /* �������ұ� */
	list(&Q);                                    /* ������ұ� */
	scanf("%d", &key);                            /* ������ҹؼ��� */
	printf("%d\n", seqsearch1(&Q, key));           /* �øĽ�ǰ�㷨���Ҳ�������ҽ�� */
	printf("%d\n", seqsearch2(&Q, key));           /* �øĽ�ǰ�㷨���Ҳ�������ҽ�� */
	printf("%f\n", ASLsucc(&Q));                  /* ������ҳɹ�ʱ��ƽ�����ҳ��� */
	printf("%d\n", ASLfail(&Q));                  /* �������ʧ��ʱ��ƽ�����ҳ��� */
}