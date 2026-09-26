#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end
struct Node* insert(struct Node *head, int coefficient, int exponent) {
    struct Node *newNode, *temp;

    newNode = createNode(coefficient, exponent);

    if (head == NULL) {
        head = newNode;
    } 
    else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

// Function to display polynomial
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);

        if (temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {

        if (p1->exponent == p2->exponent) {
            result = insert(result,
                            p1->coefficient + p2->coefficient,
                            p1->exponent);

            p1 = p1->next;
            p2 = p2->next;
        }

        else if (p1->exponent > p2->exponent) {
            result = insert(result,
                            p1->coefficient,
                            p1->exponent);

            p1 = p1->next;
        }

        else {
            result = insert(result,
                            p2->coefficient,
                            p2->exponent);

            p2 = p2->next;
        }
    }

    // Add remaining terms of polynomial 1
    while (p1 != NULL) {
        result = insert(result,
                        p1->coefficient,
                        p1->exponent);

        p1 = p1->next;
    }

    // Add remaining terms of polynomial 2
    while (p2 != NULL) {
        result = insert(result,
                        p2->coefficient,
                        p2->exponent);

        p2 = p2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *result = NULL;

    int n1, n2;
    int i, coefficient, exponent;

    // First polynomial
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);

    for (i = 0; i < n1; i++) {
        printf("\nEnter coefficient: ");
        scanf("%d", &coefficient);

        printf("Enter exponent: ");
        scanf("%d", &exponent);

        poly1 = insert(poly1, coefficient, exponent);
    }

    // Second polynomial
    printf("\nEnter number of terms in second polynomial: ");
    scanf("%d", &n2);

    for (i = 0; i < n2; i++) {
        printf("\nEnter coefficient: ");
        scanf("%d", &coefficient);

        printf("Enter exponent: ");
        scanf("%d", &exponent);

        poly2 = insert(poly2, coefficient, exponent);
    }

    // Display polynomials
    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    // Add polynomials
    result = addPolynomials(poly1, poly2);

    // Display result
    printf("Sum of Polynomials: ");
    display(result);

    return 0;
}
