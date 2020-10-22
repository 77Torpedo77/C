#include <stdio.h>
//#include "LinkedList.h"
#include "algo2-2.cpp"
#include <stdlib.h>

int main()
{
	LinkList *list;
	int data,pos;
	InitList(*&list);

	printf("plz input 5 int:");
	CreatList(*&list);
	printf("\nthis is the list:");
	DispList(*&list);
/*
	printf("\nplz input the insert val and pos:");
	scanf("%d %d",&data,&pos);
	ListInsert(*&list, pos, data);
	printf("\nthis is the list after insert:");
	DispList(*&list);

	printf("\nplz input the del val and pos:");
	scanf("%d %d",&data,&pos);
	ListDelete(*&list, pos, data);
	printf("\nthis is the list after del:");
	DispList(*&list);
*/
	scanf("%d",&data);
	pos = LocateElem(*&list,data);
	if (pos)
	{
		ListDelete(*&list, pos, data);
		DispList(*&list);
	}
	else
	{
		pos = ListLength(*&list);
		ListInsert(*&list, pos+1, data);
		DispList(*&list);
	}
	
	
	system("pause");
}