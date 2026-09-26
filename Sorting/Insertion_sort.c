#include<stdio.h>
int main(){
    int arr[100], n, i, j, key, pos, flag;
    
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
    // sorting algorithm (Insertion Sort)
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    // Display the sorted array
    printf("The sorted array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
