#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>

int main()
{
	pHead* a = NULL;
	a = createList();
	printf("%d",getLength(a));
	system("pause");
}