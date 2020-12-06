#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			/*����Ԫ��*/
	struct node *lchild;	/*ָ�����ӽ��*/
	struct node *rchild;	/*ָ���Һ��ӽ��*/
} BTNode;

void PreDisp(BTNode *b)//�������
{
	if (b!=NULL)
	{	
		printf("%c",b->data);//�ȴ�ӡ			
		PreDisp(b->lchild);//�ݹ�ȥ����				
		PreDisp(b->rchild);//�ݹ�ȥ�Һ���			
	}
}

void InDisp(BTNode *b)//�������
{
	if (b!=NULL)
	{	

			InDisp(b->lchild);//�ݹ�	
			printf("%c",b->data);//�Ӻ����˳�ʱ��ӡ
			InDisp(b->rchild);//ȥ�Һ���				
	}
}

void BackDisp(BTNode *b)//�������
{
	if (b!=NULL)
	{			
		BackDisp(b->lchild);//ȥ����				
		BackDisp(b->rchild);//ȥ�Һ���			
		printf("%c",b->data);//��ӡ	
	}
}
BTNode* PreCreate()
{
	BTNode *b;
	ElemType data;
	b=(BTNode *)malloc(sizeof(BTNode));//�����ڴ�ռ�
	scanf("%c",&data);//��������
	if (data == '#')//#��Ϊ�սڵ�
	{
		b = NULL;
	}
	else
	{
		b->data = data;//����������
		b->lchild = PreCreate();//�ݹ��������
		b->rchild = PreCreate();//�ݹ�����Һ���
	}
	return b;
	
}
int main()
{
	BTNode* b;
	printf("plz input pre tree data:");
	b=PreCreate(); 
	printf("pre:");PreDisp(b);printf("\n");
	printf("In:");InDisp(b);printf("\n");
	printf("Back:");BackDisp(b);printf("\n");
	system("pause");
	return 0;
}
