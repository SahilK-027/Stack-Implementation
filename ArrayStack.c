#include<stdio.h>
#include<stdlib.h>
typedef struct ArrayStack
{
    int capacity;
    int top;
    int *arrPtr;
}ArrayStack;

ArrayStack* createStack(int cap)
{
    ArrayStack *ptr;
    ptr=(ArrayStack*)malloc(sizeof(ArrayStack));
    ptr->capacity=cap;
    ptr->top=-1;
    ptr->arrPtr=(int *)malloc(sizeof(int)*cap);
    printf("\n✅Stack of size %d is successfully created ✅\n\n",ptr->capacity);
    return (ptr);
}

void push(ArrayStack *ptr,int data)
{
    if(ptr->top==(ptr->capacity-1))
    {
        printf("\n⚠️ Stack is full ""OVERFLOW"" ⚠️\n\n");
    }
    else
    {
        ptr->top++;
        ptr->arrPtr[ptr->top]=data;
        printf("\n✅ Data successfully pushed ✅\n\n");
    }
}

void pop(ArrayStack *ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW"" ⚠️\n\n");
    }
    else
    {
        ptr->arrPtr[ptr->top]=0;
        ptr->top=(ptr->top-1);
        printf("\n✅ Data successfully poped ✅\n\n");
    }
}

void peek(ArrayStack *ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        printf("Top element is %d\n\n",ptr->arrPtr[ptr->top]);
    }
}

int main()
{
    ArrayStack *NewStack;
    int flag=1;
    int capacity,ch,value;
    printf("Enter the capacity of stack\n");
    scanf("%d",&capacity);
    NewStack=createStack(capacity);
    while(flag==1)
    {
        printf("Enter your choice:");
        printf("\n1. Push new element\n2. Pop element\n3. Show top \n4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nYOU ARE GOING TO PUSH AN ELEMENT INTO STACK\n");
                printf("Enter Value: ");
                scanf("%d",&value);
                push(NewStack,value);
                break;
            case 2:
                printf("\nYOU ARE GOING TO POP AN ELEMENT FROM STACK\n");
                pop(NewStack);
                break;
            case 3:
                peek(NewStack);
                break;
            case 4:
                flag=0;
                break;
            default:
                printf("\n🚫Incorrect choice Re-Enter🚫\n\n");
        }
    }
    return 0;
}
