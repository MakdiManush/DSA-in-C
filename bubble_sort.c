#include<stdio.h>

int* bubbleSort(int* arr){
    for(int i = 0; i < 8; i++){
        if(arr[i] > arr[i+1]){
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    int i = 0;
    while(arr[0] != 0){
        bubbleSort(arr);
    }
    return arr;
}

int main(){
    int arr[8] = {5, 7, 4, 3, 0, 2, 6, 1};

    int* sortedArr = bubbleSort(arr);

    for(int i = 0; i < 8; i++){
        printf("%d ", sortedArr[i]);
    }

    return 0;
}