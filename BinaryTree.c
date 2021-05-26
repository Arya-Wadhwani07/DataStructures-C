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
void search(struct node *root, int a)
{
    if(root==0)
    {return ;}
    search(root->left,a);
    arr[k++]=root->data;
    search(root->right,a);
}
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
 
int height(struct node *root)
{
  if(!root) return 0;
   
  int leftHt = height(root->left);
  int rightHt = height(root->right);
   
  return max(leftHt, rightHt) + 1;
}

struct node *deepestNode(struct node *root, int levels)
{
    if(!root) return NULL;
     
    if(levels == 1)
        return root;
     
    else if(levels > 1)
    {
        deepestNode(root->left, levels - 1);
        deepestNode(root->right, levels - 1);
    }

    // return NULL;
}

int numOfChild(struct node* root, int key){

    if(root==NULL){
        return 0;
    }

    if(root->data==key){

        int c=0;

        if(root->left){
            c++;
        }

        if(root->right){
            c++;
        }

        return c;
    }

    int num1 = numOfChild(root->left,key);
    int num2 = numOfChild(root->right,key);  

    return num1+num2;
}

void deletion(struct node *root, int key, struct node *temp, int numOfChilds){ //*&temp
    
    if(root==NULL){
        return;
    }


    if(numOfChilds==2){
        
        if(root->left==temp){
            root->left=NULL;
        }

        if(root->right==temp){
            root->right=NULL;
        }

        if(root->data==key){
            printf("Deleted Element is %d\n",root->data);
            root->data=temp->data;
            free(temp);
        }

    }
    else if(numOfChilds==1){

        if(root->left && (root->left->data == key)){

            struct node *temp2 = root->left;

            if(root->left->left){
                root->left=root->left->left;
            }

            if(root->left->right){
                root->left=root->left->right;
            }
            printf("Deleted Element is %d\n",temp2->data);
            free(temp2);
        }
        else if(root->right && root->right->data == key){

            struct node *temp2 = root->right;

            if(root->right->left){
                root->right=root->right->left;
            }

            if(root->right->right){
                root->right=root->right->right;
            }
            printf("Deleted Element is %d\n",temp2->data);
            free(temp2);
        }

    }
    else if(numOfChilds==0){

        if(root->left && root->left->data==key){
            printf("Deleted Element is %d\n",root->left->data);
            root->left=NULL;
            free(root->left);
        }

        if(root->right && root->right->data==key){
            printf("Deleted Element is %d\n",root->right->data);
            root->right=NULL;
            free(root->right);
        }

    }
    deletion(root->left,key,temp,numOfChilds);
    deletion(root->right,key,temp,numOfChilds);
}
int main()
{
    struct node *root; //creating the root node
    root=0;
    int a,b,c,key,levels,numChilds;
    printf("***BINARY TREE IMPLEMENTATION***\n");
    printf("1.Create\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.Inorder Traversal\n");
    printf("5.Postorder Traversal\n");
    printf("6.Preorder Traversal\n");
    printf("7.Exit\n");
    while(1)
    {
        int ch;
        printf("Enter your choice: ");
        scanf("%d",&ch);
        int flag=0;
        switch(ch)
        {
            case 1: root=create();
                    break;
            case 2: printf("Enter the data that needs to be deleted: ");
                    scanf("%d",&key);
                    levels=height(root);
                    struct node *temp = deepestNode(root, levels);
                    numChilds = numOfChild(root,key);
                    deletion(root,key,temp,numChilds);
                    //printf("Deletion");
                    break;
            case 3: printf("Enter the data to be searched: ");
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
            case 6: printf("Pre-order is: ");
                    preorder(root); 
                    printf("\n");
                    break;
            case 7: exit(0);
                    break;
            default: printf("Invalid Input");
                    break;
            

        }
    }
}