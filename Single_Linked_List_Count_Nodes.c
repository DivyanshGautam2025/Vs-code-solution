#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int n, i, value, count = 0;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Count nodes
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("\nTotal number of nodes = %d\n", count);

    return 0;
}