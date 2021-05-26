#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int stack[100];
int top=-1;
void push(int x)
{
    if(top==99)
        printf("OVERFLOW\n");
    else if(top==-1)
    {stack[++top]=x;}
    else
    {
        top++;
        stack[top]=x;
    }
}
int delete()
{
    if(top==-1)
        printf("EMPTY\n");
    else
        return stack[top--];
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
}
int main()
{
    printf("1.Insertion\n");
    printf("2.Deletion\n");
    printf("3.Display\n");
    printf("4.Exit\n");
    int ch,n;
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number to be added: ");
                    scanf("%d",&n);
                    push(n);
                    break;
            case 2: printf("The deleted number is %d \n",delete());
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Input\n");
        }
    }
}