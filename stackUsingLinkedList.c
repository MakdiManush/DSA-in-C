#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int isEmpty(struct Node* top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

int isFull(struct Node* top){
    // Stack will be full when we create a pointer and it is NULL
    // Which means that the memory in the heap is exhausted;
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
        return 1;
    }
    return 0;
}

struct Node* push(struct Node* top, int element){
    if(isFull(top)){
        printf("Stack Overflow!\n");
        return 0;
    }
    struct Node* newTop = (struct Node*)malloc(sizeof(struct Node));
    newTop->data = element;
    newTop->next = top;
    return newTop;
}

struct Node* pop(struct Node* top){
    if(isEmpty(top)){
        printf("Stack Underflow!\n");   
        return 0;
    } 
    // printf("Popped: %d\n", top->data);
    // printf("\n");
    // struct Node* newTop = top->next;
    // return newTop;

    // Alternate and a better way
    // Because we are freeing the first node;
    struct Node* ptr = top;
    printf("Popped: %d\n", ptr->data);
    printf("\n");
    top = top->next;
    free(ptr);
    return top;
}

void traverseStack(struct Node* top){
    struct Node* ptr = top;
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void peek(struct Node* top, int index){
    struct Node* ptr = top;
    if(isEmpty(ptr)){
        printf("Stack is Empty\n");
    }
    /* We could just keep one condition of checking the index only, 
    but let's say a person puts 50 and we only have 5 elements then 
    the loop would just run unnecessarily for 45 times, so we are going 
    to exit it as soon as the pointer hits NULL; */
    for(int i = 0;(i < index-1 && ptr != NULL); i++){
        ptr = ptr->next;
    }
    if(ptr == NULL){
        printf("Wrong Index\n");
    }
    else{
        printf("The element at given index is: %d\n", ptr->data);
    }
    printf("\n");
}

int stackTop(struct Node* top){
    return top->data;
}

int stackBottom(struct Node* top){
    while(top->next != NULL){
        top = top->next;
    }
    return top->data;
}

int main(){
    // Initializing the Stack using Linked List
    struct Node* top = NULL;
    if(isEmpty(top)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is Not Empty\n");
    }
    top = push(top, 7);
    top = push(top, 22);
    top = push(top, 4);
    top = push(top, 3);

    // Implementing Empty and Full functions
    // if(isEmpty(top)){
    //     printf("Stack is Empty\n");
    // }
    // else{
    //     printf("Stack is Not Empty\n");
    // }

    // if(isFull(top)){
    //     printf("Stack is Full\n");
    // }
    // else{
    //     printf("Stack is Not Full\n");
    // }

    // Implementing Push and Pop functions
    printf("Before operation: \n");
    traverseStack(top);
    top = push(top, 15);
    top = push(top, 20);
    top = push(top, 6);

    printf("After operation: \n");
    traverseStack(top);

    printf("After popping: \n");
    top = pop(top);
    traverseStack(top);

    // Implementing Peek function
    peek(top, 3);
    peek(top, 5);
    peek(top, 7);

    // Implementing Stack Top and Stack Bottom
    printf("Value at Stack Top is: %d\n", stackTop(top));

    printf("Value at Stack Bottom is: %d\n", stackBottom(top));

    return 0;
}