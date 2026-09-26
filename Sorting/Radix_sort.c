#include<stdio.h>
int main(){
    int arr[100], n, i, j, max, exp;
    
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
    
    // Find the maximum number to know the number of digits
    max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    
    // Radix Sort
    for(exp = 1; max/exp > 0; exp *= 10){
        int output[n];
        int count[10] = {0};
        
        for(i = 0; i < n; i++){
            count[(arr[i]/exp)%10]++;
        }
        
        for(i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        
        for(i = n - 1; i >= 0; i--){
            output[count[(arr[i]/exp)%10] - 1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        
        for(i = 0; i < n; i++){
            arr[i] = output[i];
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
