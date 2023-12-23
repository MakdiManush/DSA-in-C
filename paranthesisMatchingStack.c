#include<stdio.h>
#include<stdlib.h>

// Initializing stack
struct Stack{
    int size;
    int top;
    char* exp;
};

int isEmpty(struct Stack* st){
    if(st->top == -1){
        return 1;
    }
    return 0;
};

void push(struct Stack* st, char element){
    st->top++;
    st->exp[st->top] = element;
}

void pop(struct Stack* st){
    st->exp[st->top] = '\0'; // Set the top element to \0 to indicate it's not in use!!!!
    st->top--;
}

int parenthesisMatch(char* expIn){
    struct Stack* st = (struct Stack*)malloc(sizeof(struct Stack));
    st->size = 50;
    st->top = -1;
    st->exp = (char*)malloc(st->size*sizeof(char));

    // for(int i = 0; i < st->size; i++) -- This is another way but not good enough
    for(int i = 0; expIn[i] != '\0'; i++){
        if(expIn[i] == '('){
            push(st, expIn[i]);
        }
        else if(expIn[i] == ')'){
            if(isEmpty(st)){
                printf("Stack Underflow!\n");
                return 1;
            }
            pop(st);
        }
    }
    if(isEmpty(st)){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    char* expIn = "{[24]][3*2]-(8+1)}";
    if(parenthesisMatch(expIn) == 1){
        printf("The expression is Unbalanced\n");
    }
    else{
        printf("The expression is Balanced\n");
    }
    return 0;
}