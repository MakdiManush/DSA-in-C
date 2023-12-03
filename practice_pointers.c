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

// // Swapping two arrays using pointers----------------------------------
// #include<stdio.h>
// #include<stdlib.h>

// void print_array(int* ptr){
//     for(int i = 0; i < 5; i++){
//         printf("%d ", *ptr);
//         ptr++;
//     }
// }

// int main(){
//     int arr1[5] = {1, 2, 3, 4, 5};
//     int arr2[5] = {10, 20, 30 , 40, 50};
//     int* ptr1 = arr1;
//     int* ptr2 = arr2;

//     int* arr3 = (int*)calloc(5, (sizeof(int)));
//     int* ptr3 = arr3;

//     for(int i = 0; i<5; i++){
//         *ptr3 = *ptr1;
//         *ptr1 = *ptr2;
//         *ptr2 = *ptr3;
//         ptr1++;
//         ptr2++;
//         ptr3++;
//     }

//     print_array(arr1);
//     printf("\n");
//     print_array(arr2);

//     free(arr3);
//     return 0;
// }

// // Reversing an array using pointers----------------------------------
// #include<stdio.h>

// void reverse_array(int* ptr, int size){
//     for(int i = 0; i<size/2; i++){
//         int c = 0;
//         c = *(ptr+i);
//         *(ptr+i) = *(ptr+size-i-1);
//         *(ptr+size-i-1) = c;
//     }
// }

// int main(){
//     int arr[11] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
//     int* ptr = arr;

//     reverse_array(ptr, 11);

//     for(int i = 0; i < 11; i++){
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// //Searching an element in an array----------------------------------
// #include<stdio.h>

// int search_element(int* ptr, int element){
//     for(int i = 0; i < 11; i++){
//         if(*ptr == element){
//             return i;
//         }
//         ptr++;
//     }
//     return -1;
// }

// int main(){
//     int arr[11] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
//     int* ptr = arr;
//     int result = search_element(arr, 110);
//     if(result == -1){
//         printf("Element not found");
//     }
//     else{
//         printf("Element is present at index %d", result);
//     }

//     return 0;
// }

// // Access two dimensional arrays using pointers----------------------------------
// #include<stdio.h>

// void create_array(int arr[3][3]){
//     int* ptr = &arr[0][0];
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             printf("Enter element for row %d, column %d: \n", i, j);
//             scanf("%d", &arr[i][j]);
//         }
//     }
// }

// void print_array(int arr[3][3]){
//     int* ptr = &arr[0][0];
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main(){
//     int arr[3][3];
//     create_array(arr);
//     print_array(arr);

//     return 0;
// }

// Add two two-dimensional arrays using pointers----------------------------------
#include<stdio.h>

void create_array(int arr[3][3]){
    int* ptr = &arr[0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Enter element for row %d, column %d: \n", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void sum_array(int arr[3][3], int arr2[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int arr[3][3];
    int arr2[3][3];
    printf("Input for Array 1:\n");
    create_array(arr);
    printf("\n");

    printf("Input for Array 2:\n");
    create_array(arr2);
    printf("\n");
    
    printf("Sum of both the Arrays:\n");
    sum_array(arr, arr2);

    return 0;
}