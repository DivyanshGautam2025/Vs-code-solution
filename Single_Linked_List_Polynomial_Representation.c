#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;

    int n, i;

    // Input number of terms
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    // Create polynomial
    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("\nEnter coefficient for term %d: ", i + 1);
        scanf("%d", &newNode->coefficient);

        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &newNode->exponent);

        newNode->next = NULL;

        // If list is empty
        if (head == NULL) {
            head = newNode;
        } 
        else {
            temp = head;

            // Move to the last node
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display polynomial
    printf("\nPolynomial: ");

    temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");

    return 0;
}