#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// simple linked list program - insertion  and deletion

int element;
struct node
{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL, *temp1 = NULL, *temp2 = NULL, *new_node = NULL;
void allocate()
{
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = element;
    new_node->next = NULL;
}
void insert_beg()
{
    printf("\nENTER THE ELEMENT ");
    scanf("%d", &element);
    allocate();
    if (head == NULL && tail == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}
void insert_mid()
{
    int ele;
    printf("\nENTER THE ELEMENT ");
    scanf("%d", &element);
    printf("\nSELECT A VALID ELEMENT AFTER WHICH TO BE INSERTED ");
    scanf("%d", &ele);

    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
        getch();
        return;
    }

    allocate();

    for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
    {
        if (temp1->data == ele)
        {
            if (temp1 == tail)
                tail = new_node;

            new_node->next = temp1->next;
            temp1->next = new_node;
            return;
        }
    }

    printf("\nELEMENT IS NOT FOUND IN THE LIST\n");
    getch();
}
void insert_end()
{
    printf("\nENTER THE ELEMENT ");
    scanf("%d", &element);

    allocate();

    if (head == NULL && tail == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    tail->next = new_node;
    tail = new_node;
}
void delete_beg()
{
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
        getch();
        return;
    }

    temp1 = head;
    if (head == tail)
    {
        printf("\nELEMENT DELETED is %d \n", head->data);
        head = NULL;
        tail = NULL;
    }
    else
    {
        printf("\nELEMENT DELETED is %d \n", head->data);
        head = head->next;
    }
    free(temp1);
    getch();
}
void delete_mid()
{
    printf("\nENTER THE ELEMENT ");
    scanf("%d", &element);
    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
        getch();
        return;
    }
    temp2 = NULL;
    temp1 = head;
    while (temp1 != NULL && temp1->data != element)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL)
    {
        printf("\nELEMENT IS NOT FOUND\n");
        getch();
        return;
    }
    if (temp1 == head)
    {
        printf("\nELEMENT DELETED is %d \n", element);
        if (head == tail)
            tail = NULL;
        head = head->next;
        free(head);
    }
    else
    {
        printf("\nELEMENT DELETED is %d \n", element);
        if (temp1 == tail)
            tail = temp2;

        temp2->next = temp1->next;
        free(temp1);
    }
    getch();
}
void delete_end()
{

    if (head == NULL)
    {
        printf("\nLIST IS EMPTY\n");
        getch();
        return;
    }
    if (head == tail)
    {
        printf("\nELEMENT DELETED is %d \n", head->data);
        free(tail);
        head = NULL;
        tail = NULL;
    }
    else
    {
        printf("\nELEMENT DELETED is %d \n", tail->data);
        temp1 = head;
        temp2 = NULL;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        free(temp1);
        temp2->next = NULL;
        tail = temp2;
    }
    getch();
}
void display()
{
    printf("\nCONTENTS OF THE LIST\n");

    if (head == NULL)
        printf("\nNO ELEMENTS TO DISPLAY. \n");

    else
        for (temp1 = head; temp1 != NULL; temp1 = temp1->next)
            printf("%d ", temp1->data);

    printf("\n\n");
}
int main()
{
    int value1, value2;
    do
    {
        system("cls"); //clrscr
        display();
        printf("\nSELECT THE OPERATION YOU WANNA PERFORM\n");
        printf("\n1-INSERTION\n");
        printf("\n2-DELETION\n");
        printf("\n3-EXIT\n");
        printf("\nENTER THE VALUE ");
        scanf("%d", &value1);
        printf("\n\n");
        switch (value1)
        {
        case 1:
            printf("\n1-INSERTION AT THE BEGENNING\n");
            printf("\n2-INSERTION AT THE MIDDLE\n");
            printf("\n3-INSERTION AT THE END\n");
            printf("\nENTER THE VALUE ");
            scanf("%d", &value2);
            printf("\n");
            switch (value2)
            {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_mid();
                break;
            case 3:
                insert_end();
                break;
            default:
                printf("\nINVALID INPUT\n");
                break;
            }
            break;
        case 2:
            printf("\n1-DELETION AT THE BEGENNING\n");
            printf("\n2-DELETION AT THE MIDDLE\n");
            printf("\n3-DELETION AT THE END\n");
            printf("\nENTER THE VALUE ");
            scanf("%d", &value2);
            printf("\n");
            switch (value2)
            {
            case 1:
                delete_beg();
                break;
            case 2:
                delete_mid();
                break;
            case 3:
                delete_end();
                break;
            default:
                printf("\nINVALID INPUT\n");
                break;
            }
            break;
        case 3:
            printf("\nPRESS ANY KEY AGAIN TO EXIT ");
            getch();
            break;
        default:
            printf("\nINVALID INPUT\n");
            getch();
            break;
        }

    } while (value1 != 3);
    return 0;
}