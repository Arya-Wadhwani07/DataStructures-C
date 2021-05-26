#include<stdio.h>
#include<stdlib.h>
#define N 5
int dequeue[N];
int front=-1;
int rear=-1;
void enqueuefront(int x)
{
    if((front==0 && rear==N-1) || (front==rear+1))
        printf("QUEUE IS FULL\n");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        dequeue[front]=x;
    }
    else if(front==0)
    {
        front=N-1;
        dequeue[front]=x;
    }
    else
    {
        front--;
        dequeue[front]=x;
    }
}
void enqueuerear(int x)
{
    if((front==0 && rear==N-1) || (front==rear+1))
        printf("QUEUE IS FULL\n");
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        dequeue[rear]=x;
    }
    else if(rear==N-1)
    {
        rear=0;
        dequeue[rear]=x;
    }
    else
    {
        rear++;
        dequeue[rear]=x;
    }
}
void dequeuefront()
{
    if((front==-1 && rear==-1))
        printf("QUEUE IS EMPTY\n");
    else if(front==rear)
    {
        printf("The deleted element is %d\n",dequeue[front]);
        front=-1;
        rear=-1;
    }
    else if(front==N-1)
    {
        printf("The deleted element is %d\n",dequeue[front]);
        front=0;
    }
    else
    {
        printf("The deleted element is %d\n",dequeue[front]);
        front++;
    }
}
void dequeuerear()
{
    if((front==-1)&&(rear==-1))
        printf("QUEUE IS EMPTY\n");
    else if(front==rear)
    {
        printf("The deleted element is %d\n",dequeue[rear]);
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        printf("The deleted element is %d\n",dequeue[rear]);
        rear=N-1;
    }
    else
    {
        printf("The deleted element is %d\n",dequeue[rear]);
        rear--;
    }
}
void display()
{
    int i=front;
    while(i!=rear)
    {
        printf("%d ",dequeue[i]);
        i=(i+1)%N;
    }
    printf("%d ",dequeue[rear]);
}
int main()
{
    int x;
    printf("***DOUBLE ENDED QUEUE IMPLEMENTATION***\n");
    printf("1.Insertion At Front\n");
    printf("2.Insertion At End\n");
    printf("3.Deletion At Front\n");
    printf("4.Deletion At End\n");
    printf("5.Display\n");
    printf("\n6.Exit\n");
    while(1)
    {
        int ch;
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the data that needs to be inserted: "); 
                scanf("%d",&x);
                enqueuefront(x);
                break;
        case 2: printf("Enter the data that needs to be inserted: ");
                scanf("%d",&x);
                enqueuerear(x);
                break;
        case 3: dequeuefront();
                break;
        case 4: dequeuerear();
                break;
        case 5: display();
                break;
        case 6: exit(0);
                break;
        default: printf("INVALID INPUT");
                break;
        }
    }

}