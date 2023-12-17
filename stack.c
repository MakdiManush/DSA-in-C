#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack* ptr, int element){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow");
        return -1;
    }
    else{
        int x = ptr->arr[ptr->top];
        ptr->arr[ptr->top] = 0;
        ptr->top--;
        return x;
    }
}

int peek(struct stack* ptr, int index){
    if(ptr->top-index+1 < 0){
        printf("Nothing to peek at, EMPTY!\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top - index + 1];
    }
}

void traverseStack(struct stack* ptr){
    for(int i = 0; i <= ptr->top; i++){
        printf("Element: %d\n", ptr->arr[i]);
    }
}

int main(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    //Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }

    push(s, 7);
    push(s, 8);
    push(s, 10);
    push(s, 15);
    traverseStack(s);
    printf("\n");

    int poppedElement = pop(s);
    printf("Popped element: %d\n", poppedElement);
    traverseStack(s);
    printf("\n");

    push(s, 20);
    traverseStack(s);
    printf("\n");

    printf("The Element at given index is: %d\n", peek(s, 3));
    // Free the allocated memory once the program has executed completely
    free(s->arr);
    free(s);
    return 0;
}