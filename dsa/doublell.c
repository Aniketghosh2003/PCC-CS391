#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} dl;

dl *head;

void display(dl *);
void create(dl *);
void insertion_beg(dl *);
void insertion_end(dl *);
void insertion_before(dl *);
void insertion_after(dl *);
void deletation_beg(dl *);
void deletation_end(dl *);
void deletation_before(dl *);
void deletation_after(dl *);

int main()
{

    int opition = 0;

    while (opition != 12)
    {
        printf("\n ****** Main Menu ****** ");
        printf("\n 1.create the Double List ");
        printf("\n 2.Display the Double List ");
        printf("\n 3.Insert a element at the beginning ");
        printf("\n 4.Insert a element at the end ");
        printf("\n 5.Insert a element at the before ");
        printf("\n 6.Insert a element at the after ");
        printf("\n 7.Delete a element at the beginning ");
        printf("\n 8.Delete a element at the end ");
        printf("\n 9.Delete a element at the before ");
        printf("\n 10.Delete a element at the after ");
        printf("\n 11.Exit ");

        printf("\n Please Enter the right choose ");
        scanf("%d", &opition);

        switch (opition)
        {
        case 1:
            head = (dl *)malloc(sizeof(dl));
            head->prev = NULL;
            create(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            insertion_beg(head);
            break;

        case 4:
            insertion_end(head);
            break;

        case 5:
            insertion_before(head);
            break;

        case 6:
            insertion_after(head);
            break;

        case 7:
            deletation_beg(head);
            break;

        case 8:
            deletation_end(head);
            break;

        case 9:
            deletation_before(head);
            break;

        case 10:
            deletation_after(head);
            break;

        case 11:
            exit(0);
            break;

        default:
            break;
        }
    }

    return 0;
}

void create(dl *ptr)
{
    printf("\n Enter the element :-");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    printf("\n Do you want to continue ?");
    char ch;
    scanf(" %c", &ch);
    fflush(stdin);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (dl *)malloc(sizeof(dl));
        ptr->next->prev = ptr;
        ptr = ptr->next;
        return (create(ptr));
    }
}

void display(dl *ptr)
{
    if (ptr == NULL)
    {
        printf("\n List is empty");
    }
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n");
}

void insertion_beg(dl *ptr)
{
    dl *new = (dl *)malloc(sizeof(dl));
    printf("\n please enter the value of the element :-");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = ptr;
    ptr->prev = new;
    head = new;
}

void insertion_end(dl *ptr)
{
    dl *new = (dl *)malloc(sizeof(dl));
    printf("\n please enter the value of the element :-");
    scanf("%d", &new->data);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new->prev = ptr;
    new->next = NULL;
    ptr->next = new;
}

void insertion_before(dl *ptr)
{
    dl *new = (dl *)malloc(sizeof(dl));
    printf("\n please enter the value of the element :-");
    scanf("%d", &new->data);

    int ele;
    printf("\n Enter the element before you want to insert ");
    scanf("%d", &ele);

    while (ptr->data != ele)
    {
        ptr = ptr->next;
    }
    dl *ptr1 = ptr->prev;
    new->prev = ptr1;
    new->next = ptr;
    ptr->prev = new;
    ptr1->next = new;
}

void insertion_after(dl *ptr)
{

    dl *new = (dl *)malloc(sizeof(dl));
    printf("\n please enter the value of the element :-");
    scanf("%d", &new->data);

    int ele;
    printf("\n Enter the element after you want to insert ");
    scanf("%d", &ele);

    while (ptr->data != ele)
    {
        ptr = ptr->next;
    }
    dl *ptr1 = ptr->next;
    new->prev = ptr;
    new->next = ptr1;
    ptr1->prev = new;
    ptr->next = new;
}

void deletation_beg(dl *ptr)
{
    ptr->next->prev = NULL;
    head = ptr->next;
    free(ptr);
}

void deletation_end(dl *ptr)
{

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free(ptr);
}

void deletation_before(dl *ptr)
{

    int ele;
    printf("\n Enter the element before you want to delete :-");
    scanf("%d", &ele);

    while (ptr->data != ele)
    {
        ptr = ptr->next;
    }
    dl *ptr1 = ptr->prev;
    ptr1->prev->next = ptr;
    ptr->prev = ptr1->prev;
    free(ptr1);
}

void deletation_after(dl *ptr)
{
    
    int ele;
    printf("\n Enter the element after you want to delete :-");
    scanf("%d", &ele);

    while (ptr->data != ele)
    {
        ptr = ptr->next;
    }
    dl* ptr1 = ptr->next;
    ptr1->next->prev = ptr;
    ptr->next = ptr1->next;
    free(ptr1);
}