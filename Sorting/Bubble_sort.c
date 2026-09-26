#include<stdio.h>
int main(){
    int arr[100], n, i, j, temp;
    
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
    // sorting algorithm (Bubble Sort)
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    // Display the sorted array
    printf("The sorted array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
