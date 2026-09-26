#include <stdio.h>

int main() {
    int arr[100], n, choice;
    int i, j, key, pos, flag;
    

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n==== MENU ====\n");
        printf("1. Traversal(display) elements\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Array: ");
            for(i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 2:
            if(n == 100) {
                printf("Array is full!\n");
                break;
            }

            printf("Enter element to insert: ");
            scanf("%d", &key);

            printf("Enter position (0 to %d): ", n);
            scanf("%d", &pos);

            if(pos < 0 || pos > n) {
                printf("Invalid position!\n");
            } else {
                for(i = n; i > pos; i--)
                    arr[i] = arr[i - 1];

                arr[pos] = key;
                n++;

                printf("Element inserted successfully.\n");
            }
            break;

        case 3:
            printf("Enter element to delete: ");
            scanf("%d", &key);

            flag = 0;
            for(i = 0; i < n; i++) {
                if(arr[i] == key) {
                    flag = 1;
                    break;
                }
            }

            if(flag == 1) {
                for(j = i; j < n - 1; j++)
                    arr[j] = arr[j + 1];

                n--;
                printf("Element deleted successfully.\n");
            } else {
                printf("Element not found.\n");
            }
            break;
        case 4:
            printf("Program ended\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}
