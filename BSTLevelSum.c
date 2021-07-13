#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int sum=0;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int item)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=0;
    return temp;
}
struct node *create(struct node *root,int x)
{
    if(root==0)
    {
        return newnode(x);
    }
   
    if(x<root->data)
    {
        root->left=create(root->left,x);
    }
    else if(x>root->data)
    {
        root->right=create(root->right,x);
    }
    return root;
}
void inorder(struct node *root) 
{
    if(root==0)
    {return ;}
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int getLevelUtil(struct node *node,
                 int data, int level)
{
    if (node == NULL)
        return 0;
    if (node->data == data)
        return level;
    int downlevel = getLevelUtil(node->left,
                                 data, level+1);
    if (downlevel != 0)
        return downlevel;
    downlevel = getLevelUtil(node->right,
                             data, level+1);
    return downlevel;
}
int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
}
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        sum=sum+root->data;
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

int main()
{
    struct node *root;
    root=0;
    int i,n,x,k;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements for BST Creation: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Creating BST\n");
    root=create(root,arr[0]);
    for(i=1;i<n;i++)
    {
        create(root,arr[i]);
    }
    printf("INORDER of Binary Search Tree\n");
    inorder(root);
    printf("\n");
    printf("Enter the element for finding level sum: ");
    scanf("%d",&k);
    int level;
    level=getLevel(root,k);
    printCurrentLevel(root,level);
    printf("Sum is %d",sum);
}