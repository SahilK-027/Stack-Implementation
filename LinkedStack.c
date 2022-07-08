#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;
typedef struct LinkedStack
{
    int top;
    int capacity;
    Node *start;
}LinkedStack;

LinkedStack* createStack(int cap)
{
    LinkedStack *ptr;
    ptr=(LinkedStack*)malloc(sizeof(LinkedStack));
    ptr->top=-1;
    ptr->capacity=cap;
    ptr->start=NULL;
    return ptr;
}
void push(LinkedStack*ptr,int item)
{
    Node *n1;
    n1=(Node*)malloc(sizeof(Node));
    n1->data=item;
    n1->next=NULL;
    if(ptr->top==(ptr->capacity-1))
    {
        printf("\n⚠️ Stack is full ""OVERFLOW"" ⚠️\n\n");
    }
    else
    {
        if(ptr->start==NULL)
        {
            ptr->start=n1;
            ptr->top++;
            printf("\n✅ Data successfully pushed ✅\n\n");
        }
        else
        {
            Node *temp;
            temp=ptr->start;
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n1;
            ptr->top++;
            printf("\n✅ Data successfully pushed ✅\n\n");
        }
    }
}
void pop(LinkedStack*ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        int count=0;
        Node *temp1, *temp2;
        temp1=ptr->start;
        temp2=NULL;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
            count++;
        }
        if(count)
        {
            temp2->next=NULL;
            free(temp1);
        }
        else
        {
            ptr->start=NULL;
            free(temp1);
        }
        printf("\n✅ Top element succesfully poped✅\n\n");
        ptr->top=(ptr->top-1);
    }
}
void peek(LinkedStack*ptr)
{
    if(ptr->top==-1)
    {
        printf("\n⚠️ Stack is empty ""UNDERFLOW""⚠️ \n\n");
    }
    else
    {
        Node *temp;
        temp=ptr->start;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        printf("Top element of the stack is %d \n",temp->data);
    }
}
int main()
{
    LinkedStack * NewStack;
    int cap,flag=1,ch,value;
    printf("Enter the capacity of stack\n");
    scanf("%d",&cap);
    NewStack=createStack(cap);
    while(flag==1)
    {
        printf("\nEnter your choice:");
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
