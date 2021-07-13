// CPP program to sort a doubly linked list using
// bubble sort
#include<stdlib.h> 
#include<stdio.h>
// structure of a node
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
 
/* Function to insert a node at the beginning of a linked list */
void insertAtTheBegin(struct node **start_ref, int data)
{
    struct node *ptr1;
    ptr1=(struct node*)malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    if (*start_ref != NULL)
       (*start_ref)->prev = ptr1;
    *start_ref = ptr1;
}
  
/* Function to print nodes in a given linked list */
void printList(struct node *start)
{
    struct node *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
  
/* Bubble sort the given linked list */
void bubbleSort(struct node *start)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
    int temp;
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr1->next->data;
                ptr1->next->data=temp;
                // swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
 
int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;
  
    /* start with empty linked list */
    struct node *start = NULL;
  
   /
    for (i = 0; i< 6; i++)
        insertAtTheBegin(&start, arr[i]);
  
    printf("\n Linked list before sorting ");
    printList(start);

    bubbleSort(start);
  
    printf("\n Linked list after sorting ");
    printList(start);
    
    return 0;
}