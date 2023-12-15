#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Circular Linked list Traversal
void cirLinkedListTraversal(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

// Case 1--------------------------------
// Insertion at the beginning
struct Node* insertBegg(struct Node* head, int data){
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    newHead->data = data;
    newHead->next = head;
    do{
        p = p->next;
    }while(p->next != head);
    p->next = newHead;
    return newHead;
}

// Case 2------------------------------------
// Insertion at the end
struct Node* insertEnd(struct Node* head){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    do{
        p = p->next;
    }while(p->next != head);
    ptr->data = 25;
    ptr->next = head;
    p->next = ptr;
    return head;
}

// Case 3-------------------------------------
// Insertion at an index
struct Node* insertAtIndex(struct Node* head, int index, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    struct Node* q = head->next;

    int i = 0;
    while(i != index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    ptr->data = data;
    ptr->next = q;
    p->next = ptr;
    return head;
}

// Case 4-----------------------------------
// Insertion after a specific node

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 14;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = head;

    // Traversal
    printf("Circular Linked List before Operation:\n");
    cirLinkedListTraversal(head);

    // Insertion at the beginning of the linked list;
    // printf("Circular Linked List after Operation:\n");
    // head = insertBegg(head, 25);
    // head = insertBegg(head, 30);
    // head = insertBegg(head, 35);
    // cirLinkedListTraversal(head);

    // Insertion at the end of the linked list;
    // printf("Circular Linked List after Operation:\n");
    // head = insertEnd(head);
    // cirLinkedListTraversal(head);

    // Insertion at a given index;
    printf("Circular Linked List after Operation:\n");
    head = insertAtIndex(head, 2, 17);
    cirLinkedListTraversal(head);

    // Insertion at a given node;

    return 0;
}



// ------------------- Practice Insertion at a node and Deletion for all the cases in circular linked list

