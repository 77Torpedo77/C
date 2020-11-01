#include <stdio.h>
//#include "LinkedList.h"
#include "algo2-2.cpp"
#include <stdlib.h>

int main()
{
	LinkList *list;
	int data,pos;
	initList(*&list);

	printf("plz input 5 int(end of -1):");
	creatList(*&list);
	printf("\nthis is the list:");
	printList(*&list);

	printf("\nplz input the insert val and pos:");
	scanf("%d %d",&data,&pos);
	inserElm(*&list, pos, data);
	printf("\nthis is the list after insert:");
	printList(*&list);

	printf("\nplz input the del val and pos:");
	scanf("%d %d",&data,&pos);
	delElm(*&list, pos, data);
	printf("\nthis is the list after del:");
	printList(*&list);

	printf("\nplease input a num,if exist,del;if no exist,inset:");	
	scanf("%d",&data);
	pos = getElmPos(*&list,data);
	if (pos)
	{
		delElm(*&list, pos, data);
		printf("\nthis is the list:");
		printList(*&list);
	}
	else
	{
		pos = getLength(*&list);
		inserElm(*&list, pos+1, data);
		printf("\nthis is the list:");
		printList(*&list);
	}
	
	
	system("pause");
}