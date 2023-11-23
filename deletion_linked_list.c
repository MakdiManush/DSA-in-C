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
struct Node* deleteBegg(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// ---------------Case 2
struct Node* deleteBetween(struct Node* head, int index){
    struct Node* ptr = head;
    int i = 0;
    while(i != index-1){
        ptr = ptr->next;
        i++;
    }
    struct Node* q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

// ---------------Case 3
struct Node* deleteLast(struct Node* head){
    struct Node* ptr = head;
    struct Node* q = head->next;
    while(q->next != NULL){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

// ---------------Case 4
struct Node* deleteCertain(struct Node* head, struct Node* target){
    struct Node* ptr = head;
    struct Node* p = target;
    struct Node* q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

// Different Method for Case 4
struct Node* deleteCertain2(struct Node* head, struct Node* target){
    struct Node* ptr = head;
    struct Node* q = head->next;
    while(q != target){
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);    
    return head;
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

    printf("Linked List before Operation:\n");
    linkedListTraversal(head);

    // Deletion at the Beginning
    // head = deleteBegg(head);
    // printf("Linked List after Operation:\n");
    // linkedListTraversal(head);

    // Deletion in Between
    // head = deleteBetween(head, 2);
    // printf("Linked List after Operation:\n");
    // linkedListTraversal(head);

    // Deletion at the Last
    // head = deleteLast(head);
    // printf("Linked List after Operation:\n");
    // linkedListTraversal(head);

    // Deletion at a given Node
    // head = deleteCertain(head, second);
    // printf("Linked List after Operation:\n");
    // linkedListTraversal(head);

    // Different Method for the upper one
    head = deleteCertain2(head, third);
    printf("Linked List after Operation:\n");
    linkedListTraversal(head);
    return 0;
}