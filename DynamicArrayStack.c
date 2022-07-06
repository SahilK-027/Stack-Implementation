#include<stdio.h>
#include<stdlib.h>
typedef struct  DArrayStack
{
    int capacity;
    int top;
    int *arrPtr;
}DArrayStack;

DArrayStack* createStack(int cap)
{
    DArrayStack *ptr;
    ptr=(DArrayStack*)malloc(sizeof(DArrayStack));
    ptr->capacity=cap;
    ptr->top=-1;
    ptr->arrPtr=(int *)malloc(sizeof(int)*cap);
    printf("\n✅Stack of size %d is successfully created ✅\n\n",ptr->capacity);
    return (ptr);
}
DArrayStack* doubleArray(DArrayStack*ptr,int cap)
{
    int newCap=2*cap;
    int *temp;
    temp=(int*)malloc(sizeof(int)*newCap);
    for(int i=0;i<(ptr->top)+1;i++)
    {
        temp[i]=ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr=temp;
    ptr->capacity=newCap;
    return ptr;
}

DArrayStack* shrinkAray(DArrayStack*ptr,int cap)
{
    int newCap=cap/2;
    int *temp;
    temp=(int*)malloc(sizeof(int)*newCap);
    for(int i=0;i<(ptr->top)+1;i++)
    {
        temp[i]=ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr=temp;
    ptr->capacity=newCap;
    return ptr;
}

void push(DArrayStack* ptr,int data)
{
    if(ptr->top==(ptr->capacity)-1)
    {
        ptr=doubleArray(ptr, ptr->capacity);
        ptr->top++;
        ptr->arrPtr[ptr->top]=data;
        printf("\n✅ Data successfully pushed ✅\n\n");
    }
    else
    {
        ptr->top++;
        ptr->arrPtr[ptr->top]=data;
        printf("\n✅ Data successfully pushed ✅\n\n");
    }
}
void pop(DArrayStack*ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW"" ⚠️\n\n");
    }
    else
    {
        ptr->arrPtr[ptr->top]=0;
        ptr->top=(ptr->top-1);
        if((ptr->capacity)%2==0)
        {
            if(ptr->top<=(ptr->capacity/2)-1)
            {
                ptr=shrinkAray(ptr,ptr->capacity);
            }
        }
        printf("\n✅ Data successfully poped ✅\n\n");
    }
}
void peek(DArrayStack*ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        if((ptr->top)+1==1)
        {
            printf("Top element is %d which is %dst element in your stack\n",ptr->arrPtr[ptr->top],(ptr->top)+1);
        }
        else if((ptr->top)+1==2)
        {
            printf("Top element is %d which is %dnd element in your stack\n",ptr->arrPtr[ptr->top],(ptr->top)+1);
        }
        else if((ptr->top)+1==3)
        {
            printf("Top element is %d which is %drd element in your stack\n",ptr->arrPtr[ptr->top],(ptr->top)+1);
        }
        else
        {
            printf("Top element is %d which is %dth element in your stack\n",ptr->arrPtr[ptr->top],(ptr->top)+1);
        }
    }
}

void showCapacity(DArrayStack *ptr)
{
    printf("Capacity of your stack is %d\n\n",ptr->capacity);
}

int main()
{
    DArrayStack *NewStack;
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
                showCapacity(NewStack);
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
