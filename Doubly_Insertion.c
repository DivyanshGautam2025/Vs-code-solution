#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


// INSERT AT BEGINNING
void insertBeginning(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}


// INSERT AT END
void insertEnd(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


// INSERT AT POSITION
void insertPosition(int data, int position)
{
    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        insertBeginning(data);
        return;
    }

    if (head == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (i < position - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}


// DISPLAY
void display()
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ⇄ ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Original List:\n");
    display();

    insertBeginning(5);

    printf("\nAfter inserting 5 at beginning:\n");
    display();

    insertEnd(40);

    printf("\nAfter inserting 40 at end:\n");
    display();

    insertPosition(25, 4);

    printf("\nAfter inserting 25 at position 4:\n");
    display();

    return 0;
}