#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


// INSERT AT END
void insertEnd(int data)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}


// DELETE FROM BEGINNING
void deleteBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}


// DELETE FROM END
void deleteEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct Node *prev = NULL;
    struct Node *temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

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

    if (position == 1)
    {
        deleteBeginning();
        return;
    }

    struct Node *prev = NULL;
    struct Node *temp = head;

    int i = 1;

    while (i < position)
    {
        prev = temp;
        temp = temp->next;

        if (temp == head)
        {
            printf("Invalid position\n");
            return;
        }

        i++;
    }

    prev->next = temp->next;

    free(temp);
}


// DISPLAY
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(back to head)\n");
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
