#include <stdio.h>

int main() {
    int arr[100], n, key, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d (Position %d)\n", i, i + 1);
            return 0;
        }
    }

    printf("Element not found.\n");

    return 0;
}
