#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void doublyLinkedListTraversal(struct Node* ptr){
    // Traversing Forwards
    while(ptr->next != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("Element: %d\n", ptr->data);
    printf("\n");
    
    // Traversing Backwards
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");

}

int main(){
    struct Node* N1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* N4 = (struct Node*)malloc(sizeof(struct Node));

    N1->data = 23;
    N1->prev = NULL;
    N1->next = N2;
    
    N2->data = 34;
    N2->prev = N1;
    N2->next = N3;

    N3->data = 56;
    N3->prev = N2;
    N3->next = N4;

    N4->data = 52;
    N4->prev = N3;
    N4->next = NULL;

    // Doubly Linked List Traversal
    doublyLinkedListTraversal(N1);

    return 0;
}