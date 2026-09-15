#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;


// INSERT AT END
void insertEnd(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

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


// DELETE BEGINNING
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
}


// DELETE END
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);
}


// DELETE AT POSITION
void deletePosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    struct Node *temp = head;
    int i = 1;

    while (i < position && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
}


// DISPLAY
void display()
{
    struct Node *temp = head;

    printf("NULL");

    while (temp != NULL)
    {
        printf(" <- %d ->", temp->data);
        temp = temp->next;
    }

    printf(" NULL\n");
}


int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Original List:\n");
    display();

    deleteBeginning();

    printf("\nAfter deleting beginning:\n");
    display();

    deleteEnd();

    printf("\nAfter deleting end:\n");
    display();

    deletePosition(2);

    printf("\nAfter deleting position 2:\n");
    display();

    return 0;
}