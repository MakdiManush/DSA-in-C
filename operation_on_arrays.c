#include<stdio.h>

// Traversal is done like this: 
void showArray(int* arr, int sizeArray){
    for(int i = 0; i < sizeArray; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion is done like this:
int indInsert(int* arr, int size, int element, int index, int capacity){
    if(size >= capacity){
        return -1;
    }
    for(int i = size-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

void indDelete(int* arr, int size, int index){
    for(int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
}

int main(){

    int arr[100] = {2, 5, 10, 15, 20, 25, 26};
    int size = 7, element = 8, index = 3;
    // Performing Traversal
    showArray(arr, size);

    // Performing Insertion
    int resultInsert = indInsert(arr, size, element, index, 100);
    if(resultInsert == -1){
        printf("Sorry, The insertion was not successful\n");
    }
    else{
        printf("Congratulations, the Insertion was successful\n");
        size += 1;
        showArray(arr, size);
    }

    // indInsert(arr, size, 50, 6, 100); // Trying it again
    // size += 1;
    // showArray(arr, size);

    // Performing Deletion
    indDelete(arr, size, index);
    size -= 1;
    showArray(arr, size);
    return 0;
}