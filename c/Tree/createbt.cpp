#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			/*数据元素*/
	struct node *lchild;	/*指向左孩子结点*/
	struct node *rchild;	/*指向右孩子结点*/
} BTNode;

void PreDisp(BTNode *b)//先序遍历
{
	if (b!=NULL)
	{	
		printf("%c",b->data);//先打印			
		PreDisp(b->lchild);//递归去左孩子				
		PreDisp(b->rchild);//递归去右孩子			
	}
}

void InDisp(BTNode *b)//中序遍历
{
	if (b!=NULL)
	{	

			InDisp(b->lchild);//递归	
			printf("%c",b->data);//从孩子退出时打印
			InDisp(b->rchild);//去右孩子				
	}
}

void BackDisp(BTNode *b)//后序遍历
{
	if (b!=NULL)
	{			
		BackDisp(b->lchild);//去左孩子				
		BackDisp(b->rchild);//去右孩子			
		printf("%c",b->data);//打印	
	}
}
BTNode* PreCreate()
{
	BTNode *b;
	ElemType data;
	b=(BTNode *)malloc(sizeof(BTNode));//创建内存空间
	scanf("%c",&data);//输入数据
	if (data == '#')//#作为空节点
	{
		b = NULL;
	}
	else
	{
		b->data = data;//设置数据域
		b->lchild = PreCreate();//递归进入左孩子
		b->rchild = PreCreate();//递归进入右孩子
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
