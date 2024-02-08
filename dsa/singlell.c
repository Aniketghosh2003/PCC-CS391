
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *next;

} l;

l *head = NULL;
void create(l *);
void display(l *);
void insert_beg(l *);
void insert_end(l *);
void insert_after(l *);
void insert_before(l *);
void delete_anypose(l *);
void sort(l *);
void search(l *);
void swap(l *);
void reverse(l *);

int main()
{

    int opition = 0;

    while (opition != 13)
    {
        printf("\n ****** Main Menu ****** ");
        printf("\n 1.create the sigle List ");
        printf("\n 2.Display the single List ");
        printf("\n 3.Insert a element at the beginning ");
        printf("\n 4.Insert a element at the end ");
        printf("\n 5.Insert a element at the before ");
        printf("\n 6.Insert a element at the after ");
        printf("\n 7.Delete a element at the beginning ");
        printf("\n 8.sort the whole list");
        printf("\n 9.search a element in the list");
        printf("\n 10.Enter the element for swaping");
        printf("\n 11.reverse the whole list ");
        printf("\n 12.Exit ");

        printf("\n Please Enter the right choose ");
        scanf("%d", &opition);

        switch (opition)
        {
        case 1:
            head = (l *)malloc(sizeof(l));
            create(head);
            break;

        case 2:
            display(head);
            break;

            case 3:
                insert_beg(head);
                break;

            case 4:
                insert_end(head);
                break;

            case 5:
                insert_before(head);
                break;

            case 6:
                insert_after(head);
                break;

        case 7:
            delete_anypose(head);
            break;

        case 8:
            sort(head);
            break;

            // case 9:
            //      search(head);
            //      break;

            // case 10:
            //      swap(head);
            //      break;

            // case 11:
            //     reverse(head);
            //     break;

            // case 12:
            //     exit(0);
            //     break;

        default:
            break;
        }
    }

    return 0;
}

void create(l *ptr)
{
    char ch = 'y';
    printf("\n Enter the value in the Linked list :-");
    scanf("%d", &ptr->data);
    ptr->next = NULL;

    printf("\n Do you want to continue ?");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        ptr->next = (l *)malloc(sizeof(l));
        ptr = ptr->next;
        return create(ptr);
    }
}

void display(l *ptr)
{
    if (head == NULL)
    {
        printf("\n List is empty :-");
    }
    while (ptr != NULL)
    {
        printf("\n");
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n");
}

void delete_anypose(l *ptr)
{
    int ele;
    printf("\n Enter the element that want to delete :-");
    scanf("%d", &ele);

    if (head->data == ele)
    {
        l *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        l *curr = head;
        l *prev = NULL;

        while (curr->data != ele)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}

void sort(l *ptr)
{
    l *p1 = head;
    l *p2 = NULL;
    int temp;

    while (p1 != NULL)
    {
        p2 = p1->next;
        while (p2 != NULL)
        {
            if (p1->data > p2->data)
            {
                temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

void insert_beg(l *ptr)
{
    l *new_node;
    new_node = (l *)malloc(sizeof(l));
    printf("\n Enter the value for the new node :-");
    scanf("%d", &new_node->data);

    new_node->next = ptr;
    head = new_node;
}

void insert_end(l *ptr)
{

    l *new_node;
    new_node = (l *)malloc(sizeof(l));
    printf("\n Enter the value for the new node :-");
    scanf("%d", &new_node->data);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = new_node;
    new_node->next = NULL;
}

void insert_before(l *ptr)
{
    l *new_node;
    new_node = (l *)malloc(sizeof(l));
    printf("\n Enter the value for the new node :-");
    scanf("%d", &new_node->data);

    int num;
    printf("\n Enter the number before you want to insert:-");
    scanf("%d", &num);

    while (ptr->next->data != num)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}

void insert_after(l *ptr)
{
    l *new_node;
    new_node = (l *)malloc(sizeof(l));
    printf("\n Enter the value for the new node :-");
    scanf("%d", &new_node->data);

    int num;
    printf("\n Enter the number after you want to insert:-");
    scanf("%d", &num);

    while (ptr->data != num)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}

