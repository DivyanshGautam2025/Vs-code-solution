#include<stdio.h>
int main() {
    int arr1[100][100], arr2[100][100],diff[100][100];
    int i, j, n;

     /*Two matrix can be subtracted only ,
    if they have the same dimensions.*/
    //Input size of arrays
    printf("Enter the size of the matrices (n x n): ");
    scanf("%d",&n);

    //Input first array
    printf("Enter elements of first array:\n");
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            scanf("%d",&arr1[i][j]);
        }
    }

    //Input second array
    printf("Enter elements of second array:\n");
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            scanf("%d",&arr2[i][j]);
        }
    }

    // Subtract corresponding elements of both arrays
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            diff[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    // Display the difference array
    printf("Difference of the two arrays:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    return 0;   
}
