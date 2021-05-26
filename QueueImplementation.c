#include<stdio.h>
#include<stdlib.h>
#define N 100
int queue[N];
int front,rear=-1;
void enqueue(int x)
{
    if(rear==(N-1))
        {printf("OVERFLOW\n");return;}
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
int dequeue()
{
    if(front==-1 || front>rear)
        printf("UNDERFLOW\n");
    else
    {
        return queue[front++];
    }
}
void display()
{
    int i;
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
}
int main()
{
    int ch;
    printf("***MENU DRIVEN PROGRAM***");
    printf("\n1.Insertion");
    printf("\n2.Deletion");
    printf("\n3.Display");
    printf("\n4.Exit\n");
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the data to be inserted: ");  
                    int x;
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2: printf("The deleted number is %d",dequeue());
                    break;
            case 3: display();  
                    break;
            case 4: exit(0);        
                    break;
            default: printf("Wrong Input");
        }
    }
}