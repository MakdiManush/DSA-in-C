#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverseLinkedList(struct Node* ptr){
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* reverseLinkedList(struct Node* head, int noOfNodes){
    struct Node* ptr = head;
    struct Node* last = head->next;
    struct Node* secondLast = head;
    while (secondLast->next != NULL) {
        last = last->next;
        secondLast = head->next;
    }

    int temp;
    // for(int i = 0; i < noOfNodes/2; i++){
        temp = ptr->data;
        ptr->data = last->data;
        last->data = temp;
        ptr = ptr->next;
        temp = ptr->data;
        ptr->data = secondLast->data;
        secondLast->data = temp;

    // }
    return head;

}

int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = tail;

    tail->data = 1;
    tail->next = NULL;

    // Linked List Traversal
    printf("Linked List Traversal\n");
    traverseLinkedList(head);
    printf("\n");

    // Linked List Backwards Traversal
    printf("Linked List Backwards Traversal\n");
    head = reverseLinkedList(head, 5);
    traverseLinkedList(head);
    

    return 0;
}