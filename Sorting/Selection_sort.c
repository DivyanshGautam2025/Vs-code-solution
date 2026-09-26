#include<stdio.h>
int main(){
    int arr[100], n, i, j, min_idx, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // input array elements
    printf("Enter the elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Display the array before sorting
    printf("Array before sorting: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // sorting algorithm (Selection Sort)
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    // Display the sorted array
    printf("The sorted array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
