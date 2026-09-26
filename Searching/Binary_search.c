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
    // Searching algorithm (Binary Search)
    printf("Enter the element to search: ");
    scanf("%d", &key);
    flag = 0;
    i = 0;
    j = n - 1;
    while(i <= j){
        pos = (i + j) / 2;
        if(arr[pos] == key){
            flag = 1;
            break;
        }
        else if(arr[pos] < key){
            i = pos + 1;
        }
        else{
            j = pos - 1;
        }
    }
    if(flag == 1){
        printf("Element found at position %d\n", pos + 1);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
                arr[j+1] = key;
            }
        }
    }
    
    return 0;
}
