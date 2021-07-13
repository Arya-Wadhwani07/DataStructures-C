#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int arr[100];
int k=0;
struct node // Creating a node in a similar way as linked list
{
    int data;
    struct node *left; // to store location of left node
    struct node *right; // to store location of right node
};
struct node *create()
{
    int x; //data to be stored
    struct node *newnode; // the new node to be created
    newnode=(struct node *)malloc(sizeof(struct node)); //dynamic memory allocation
    printf("Enter the data (-1 for no child node): ");
    scanf("%d",&x);
    if(x==-1)
    {return 0;}
    newnode->data=x; //assigning the data to the new node
    printf("Left child of %d: ",x); //moving onto the left subtree 
    newnode->left=create(); //recursive function which will keep asking all left childs and then backtrack for right subtree
    printf("Right child of %d: ",x);
    newnode->right=create(); //recursive function for right sub tree
    return newnode; // returning the memory of newnode 
}
void preorder(struct node *root) //recursive function. self explanatory
{
    if(root==0)
    {return;}
    printf("%d ",root->data); 
    preorder(root->left); 
    preorder(root->right);
}
void postorder(struct node *root) //recursive function. self explanatory
{
    if(root==0)
    {return;}
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void inorder(struct node *root) //recursive function. self explanatory
{
    if(root==0)
    {return ;}
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    struct node *root; //creating the root node
    root=0;
    int a,b,c,key,levels,numChilds;
    printf("***BINARY TREE IMPLEMENTATION***\n");
    printf("1.Create\n");
    printf("2.Print the Depth First Search Traversals\n");
    int flag=1;
    while(flag==1)
    {
        int ch;
        printf("Enter your choice: ");
        scanf("%d",&ch);
       
        switch(ch)
        {
            case 1: root=create();
                    break;
            case 2: flag=0;
                 	break;
            default: printf("Invalid Input");
                    break;
        }
    }
	printf("Therefore, the Depth First Traversals of this Tree will be:\n");
	printf("In-order(Left,Root,Right) is: ");
	inorder(root);
	printf("\n");
    
	printf("Pre-Order(Root,Left,Right) is: ");
	preorder(root);
	printf("\n");
	
    printf("Post-order(Left,Right,Root) is: ");
    postorder(root); 
    printf("\n");
}