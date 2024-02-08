#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} cl;
cl *head;

void create(cl *);
void display(cl *);
void insertion_beg(cl *);
void insertion_end(cl *);
void insertion_specified(cl *);
void deletaion_beg(cl *);
cl *deletation_end(cl *);
void deletation_specified(cl *);

int main(int argc, char const *argv[])
{
    head = (cl *)malloc(sizeof(cl));
    create(head);
    display(head);
    insertion_beg(head);
    display(head);
    insertion_end(head);
    display(head);
    insertion_specified(head);
    display(head);
    deletaion_beg(head);
    display(head);
    head = deletation_end(head);
    display(head);
    deletation_specified(head);
    display(head);
    return 0;
}

void create(cl *ptr)
{
    char ch = 'y';
    printf("\n Enter the element :-");
    scanf("%d", &ptr->data);
    ptr->next = head;
    printf(" \n Do you want to continue :-");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (cl *)malloc(sizeof(cl));
        ptr = ptr->next;
        return create(ptr);
    }
}

void display(cl *ptr)
{
    if (ptr == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        printf("\n");
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;

        } while (ptr != head);
        printf("\n");
    }
}

void insertion_beg(cl *ptr)
{
    cl *new = (cl *)malloc(sizeof(cl));
    printf("Please enter the element for insertion at beginning :-");
    scanf("%d", &new->data);

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = new;
    new->next = head;
    head = new;
}

void insertion_end(cl *ptr)
{
    cl *new = (cl *)malloc(sizeof(cl));
    printf("Please enter the element for insertion at end :-");
    scanf("%d", &new->data);
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = new;
    new->next = head;
}

void insertion_specified(cl *ptr)
{

    cl *new = (cl *)malloc(sizeof(cl));
    printf("Please enter the element for insertion at specified place :-");
    scanf("%d", &new->data);
    int ele;
    printf("\n Please enter the element after you want to insert :- ");
    scanf("%d", &ele);
    while (ptr->data != ele)
    {
        ptr = ptr->next;
    }
    new->next = ptr->next;
    ptr->next = new;
}

void deletaion_beg(cl *ptr)
{
    cl *temp;
    temp = ptr;

    if (ptr == NULL)
    {
        printf("Nothing to delete.");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr->next;
        free(ptr);
        ptr = temp->next;
    }
}
cl *deletation_end(cl *ptr)
{
    cl *prev;
    cl *curr;
    curr = ptr;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
    return ptr;
}

void deletation_specified(cl *ptr)
{
    cl *curr, *prev;
    curr = ptr;
    int val;
    printf("\n Enter the value after which the node has to deleted ");
    scanf("%d", &val);
    while (curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
}