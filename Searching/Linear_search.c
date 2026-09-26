#include<stdio.h>
int main(){
    int arr[100], n, i, key, flag;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // input array elements
    printf("Enter the elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Display the array
    printf("Array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Searching algorithm (Linear Search)
    printf("Enter the element to search: ");
    scanf("%d", &key);
    flag = 0;
    for(i = 0; i < n; i++){
        if(arr[i] == key){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("Element found at position %d\n", i + 1);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
