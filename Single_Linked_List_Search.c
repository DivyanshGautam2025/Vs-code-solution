#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int n, i, value, searchValue;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Creating the linked list
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

    // Display of linked list before searching
    printf("\nLinked list: ");
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    // Searching an element
    printf("\nEnter the value to search: ");
    scanf("%d", &searchValue);

    temp = head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == searchValue) {
            printf("Value %d found in the linked list.\n", searchValue);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("Value %d not found in the linked list.\n", searchValue);
    }

    return 0;
}