// Creation and Traversal of Linked Lists
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// ---------------Case 1
struct Node* insertBegg(struct Node* head, int data){
    struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
    newHead->data = data;
    newHead->next = head;
    return newHead;
}

// ---------------Case 2
struct Node* insertBetween(struct Node* head, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while(i != index-1){
        p = ptr->next;
        i++;
    }
    ptr->data = 86;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// ---------------Case 3
struct Node* insertEnd(struct Node* head){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = 52;
    ptr->next = NULL;
    return head;
}

// ---------------Case 4
struct Node* insertAfterNode(struct Node* afterNode){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = 17;
    ptr->next = afterNode->next;
    afterNode->next = ptr;
}


int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocated in Heap
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
    fourth->next = NULL;

    linkedListTraversal(head);

    // Insert in the beginning    // Case 1
    // head = insertBegg(head, 2);  
    // linkedListTraversal(head);

    // Insert in between          // Case 2
    // head = insertBetween(head, 1);  //         CONFUSION
    // linkedListTraversal(head);
    
    // Insert at the End          // Case 3
    head = insertEnd(head);
    linkedListTraversal(head);             //         CONFUSION

    // Insert After a Node        // Case 4
    insertAfterNode(third);
    linkedListTraversal(head);
    return 0;
}