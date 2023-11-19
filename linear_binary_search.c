#include<stdio.h>
#include<stdlib.h>
int linearSearch(int* arr, int element, int size){
    for(int i = 0; i < size; i++){
        if (arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int element , int size){
    int low = 0, mid, high=size-1;

    // Keep searching until low <= high, It will stop when low > high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    //Search Ends

    return -1;
}

int main(){
    int arr[100] = {5, 10 , 15, 20, 25, 30, 35, 40, 45, 50};
    int size = 10;
    int element = 40;
    
    // int size = sizeof(arr)/sizeof(int);

    // int result = linearSearch(arr, element, size);
    // if(result == -1){
    //     printf("The element %d is not present in the array", element);
    // }
    // else{
    //     printf("The element %d is present at the index: %d", element, result);
    // }

    int result = binarySearch(arr, element, size);
    printf("The element %d is present at the index: %d", element, result);

    return 0;
}