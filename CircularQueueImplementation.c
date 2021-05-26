#include<stdio.h>
#include<stdlib.h>
#define N 5
int front=-1;
int rear=-1;
int queue[N];
void enqueue(int x)
{
    if((front==-1) &&  (rear==-1))
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%N==front)
        printf("OVERFLOW\n");
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}
void dequeue()
{
    if((front==-1) && (rear==-1))
        printf("UNDERFLOW\n");
    else if(front==rear)
    {
        printf("Delteted Element is %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Deleted Element is %d\n",queue[front]);
        front=(front+1)%N;
    }
}
void display()
{
    int i=front;
    if(front==-1 && rear==-1)
        printf("EMPTY\n");
    else 
    {
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
    }
    printf("%d",queue[i]);
    
}
int main()
{
    printf("***CIRCULAR QUEUE***\n");
    printf("1.Insertions\n");
    printf("2.Deletion\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    int ch;
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the data that needs to be inserted: ");
                    int c;
                    scanf("%d",&c);
                    enqueue(c);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invaild Input");
                    break;
        }
    }
}