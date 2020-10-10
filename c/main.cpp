#include <stdio.h>
#include "LinkedList.h"

int main()
{
	pHead* a = NULL;
	a = createList();
	printf("%d",getLength(a));
}