#include<stdio.h>

// Traversal is done like this: 
void showArray(int* arr, int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        printf("%d\n", arr[i]);
    }
}

// Insertion is odne like this:
void indInsert(int* arr, int size, int element, int index, int capacity){

}

int main(){

    int arr[100] = {2, 5, 10, 15, 20, 25, 26};
    int size = 7, element = 8, index = 3;
    // Performing Traversal
    showArray(arr, 7);

    // Performing Insertion
    indInsert(arr, size, element, index, 100);
    return 0;
}