// // Add two numbers using pointers----------------------------------
// #include<stdio.h>

// int sum(int* a, int* b){
//     return *a + *b;
// }

// int main(){
//     int a, b;
//     int* ptr_a = &a;
//     int* ptr_b = &b;
//     printf("Enter Number 1: ");
//     scanf("%d", &a);
//     printf("Enter Number 2: ");
//     scanf("%d", &b);

//     // Performing SUM on both the numbers
//     int sum_result = sum(ptr_a, ptr_b);
//     printf("Sum of %d and %d is: %d\n", a, b, sum_result);



//     return 0;
// }

// Swapping two numbers using pointers----------------------------------
// #include<stdio.h>

// void swap(int* a, int* b){
//     // int c;
//     // c = *a;
//     // *a = *b;
//     // *b = c;

//     // The other way
//     *a = *a-*b;
//     *b = *a+*b;
//     *a = *b-*a;
// }

// int main(){
//     int a, b;
//     int* ptr_a = &a;
//     int* ptr_b = &b;
//     printf("Enter Number 1: ");
//     scanf("%d", &a);
//     printf("Enter Number 2: ");
//     scanf("%d", &b);

//     // Performing SUM on both the numbers
//     printf("Value of a and b before swap: %d, %d\n", a, b);
//     swap(ptr_a, ptr_b);
//     printf("Value of a and b after swap: %d, %d", a, b);



//     return 0;
// }

// // Print array using pointers----------------------------------
// #include<stdio.h>

// void arr_input(int* ptr){
//     for(int i = 0; i < 5; i++){
//         printf("Enter the value for index %d: \n", i);
//         scanf("%d", ptr);
//         ptr++;
//     }
// }

// void arr_print(int* ptr){
//     for(int i = 0; i < 5; i++){
//         printf("Value for index %d: %d\n", i, *ptr);
//         ptr++;
//     }
// }

// int main(){
//     int arr[5];
//     int* ptr = arr;
//     arr_input(ptr);
//     arr_print(ptr);
//     return 0;
// }

// // Copy one array to another array using pointers----------------------------------
// #include<stdio.h>
// #include<stdlib.h>
// int* copy_array(int* ptr){
//     int* arr2 = (int*)malloc(5*sizeof(int));
//     int* ptr2 = arr2;
//     for(int i = 0; i < 5; i++){
//         *ptr2 = *ptr;
//         ptr2++;
//         ptr++;
//     }
//     return arr2;
// }

// int main(){
//     int arr[5] = {1, 2, 3, 4, 5};
//     int* ptr = arr;
//     int* ptr2 = copy_array(arr);
//     for(int i = 0; i < 5; i++){
//         printf("Value for index %d: %d\n", i, *ptr2);
//         ptr2++;
//     }
//     free(ptr2);

//     return 0;
// }

// Swapping two arrays using pointers----------------------------------
#include<stdio.h>
#include<stdlib.h>

void print_array(int* ptr){
    for(int i = 0; i < 5; i++){
        printf("%d ", *ptr);
        ptr++;
    }
}

int main(){
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {10, 20, 30 , 40, 50};
    int* ptr1 = arr1;
    int* ptr2 = arr2;

    int* arr3 = (int*)malloc(5*sizeof(int));
    int* ptr3 = arr3;

    for(int i = 0; i<5; i++){
        *ptr3 = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = *ptr3;
        ptr1++;
        ptr2++;
        ptr3++;
    }

    print_array(arr1);
    printf("\n");
    print_array(arr2);

    free(arr3);
    return 0;
}