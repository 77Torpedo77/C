#include<stdio.h>
#include"Stack.cpp"
int main()
{
    LinkStack *S;
    ElemType data;
    int i;

    S = initstack(); // 初始化栈

    printf("plz input data(end for 0):");
    scanf(" %d", &data);
    while (data != 0)//读到0就停止
    {
        push(S, data); // 插入 
        scanf(" %d", &data);
    }
    printf("this is the stack:");
    printStack(S);//打印
    printf("\n");


    printf("pop 1\n");
    i = pop(S, &data);//弹栈
    if (i)
    {
        printf("this is the data1 :%4d\n", data);
        printf("this is the stack:");
        printStack(S);//打印
    }
    else
    {
        printf("stack is empty,can not pop!");
    }

    printf("pop 2\n");
    i = pop(S, &data);//弹栈
    if (i)
    {
        printf("this is the data2 :%4d\n", data);
        printf("this is the stack:");
        printStack(S);//打印
    }
    else
    {
        printf("stack is empty,can not pop!");
    }
    system("pause");
}