#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int* ptr;
};

void createArray(struct myArray* a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(tSize*sizeof(int));
    // a->ptr = (int*)calloc(tSize, sizeof(int));
}

void setValue(struct myArray* a){
    for(int i = 0; i < a->used_size; i++){
        int n;
        printf("Enter value for element %d: \n", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

void show(struct myArray* a){
    for(int i = 0; i < a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
        // free(a->ptr);
    }
}

void get(struct myArray* a, int element){
    printf("The element at index %d is: %d", element, a->ptr[element-1]);
}

int main(){

    struct myArray marks;
    createArray(&marks, 50, 5);
    printf("Setting the values\n");
    setValue(&marks);

    printf("Printing out all the elemets\n");
    show(&marks);

    printf("Getting the desired element\n");
    get(&marks, 2);
    return 0;
}