#include<stdio.h>
#include<stdlib.h>

// Paranthesis Matching using Stack;
struct Stack{
    int size;
    int top;
    char* exp;
};

void push(struct Stack* sp, char element){
    sp->top++;
    sp->exp[sp->top] = element;
}

void pop(struct Stack* sp){
    sp->exp[sp->top] = '\0'; // Setting top element to '\0' Indicates that it is no longer in use;
    sp->top--;
}

int isEmpty(struct Stack* sp){
    if(sp->top == -1){
        return 1;
    }
    return 0;
}


int parenthesisMatching(char* expIn){
    // Initializing Stack
    struct Stack* sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 50;
    sp->top = -1;
    sp->exp = (char*)malloc(sp->size*(sizeof(char)));

    // Let's Get Into the real thing; We'll need pop(), push(), and isEmpty() functions;
    for(int i = 0; expIn[i] != '\0'; i++){
        if(expIn[i] == '('){
            push(sp, expIn[i]);
        }
        else if(expIn[i] == ')'){
            if(isEmpty(sp)){
                printf("Stack Underflow!\n");
                return 1;
            }
            pop(sp);
        }
    }

    // Here we are checking if we have any extra paranthesis;
    if(isEmpty(sp)){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    char* expIn = "(2/9)+(3*7)-45";
    if(parenthesisMatching(expIn) == 1){
        printf("The Expression is Unbalanced!\n");
    }
    else{
        printf("The Expression is Balanced!\n");
    }

    return 0;
}