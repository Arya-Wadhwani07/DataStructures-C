#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int arr[100];
int k=0;
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
void inorder(struct node *root) //recursive function. self explanatory
{
    if(root==0)
    {return ;}
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void search(struct node *root, int a)
{
    if(root==0)
    {return ;}
    search(root->left,a);
    arr[k++]=root->data;
    search(root->right,a);
}
int main()
{
    int x,ch;
    struct node *root;
    root=0;
    int key;
    int a;
    printf("Enter the root node: ");
    scanf("%d",&x);
    root=create(root,x);
    printf("***BINARY SEARCH TREE IMPLEMENTATION***\n");
    printf("1.Create\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.Inorder Traversal\n");
    printf("5.Postorder Traversal\n");
    printf("6.Preorder Traversal\n");
    printf("7.Exit\n");
    while(1)
    {
        int flag=0;
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("Enter the data: ");
                scanf("%d",&x);
                create(root,x);
                break;
        case 2: 
                printf("Enter data to be deleted: ");
                scanf("%d",&key);
                root=deleteNode(root,key);
                break;
        case 3: 
                printf("Enter the data to be searched: ");
                scanf("%d",&a);
                search(root,a);
                int i;
                for(i=0;i<=k;i++)
                    {
                        if(arr[i]==a)
                            {
                                flag=1;
                            }
                    }
                    if(flag==0)
                    {
                        printf("NOT FOUND\n");
                        break;
                    }
                printf("FOUND\n");
                break;
        case 4: printf("In-order is: ");
                inorder(root);
                printf("\n");
                break;
        case 5: printf("Post-Order is: ");
                postorder(root);
                printf("\n");
                break;
        case 6: printf("Pre-Order is: ");
                preorder(root);
                printf("\n");
                break;
        case 7: exit(0);
                break;
        default: printf("Wrong Option");
                break;
        }
    }
}