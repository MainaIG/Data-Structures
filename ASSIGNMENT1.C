#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    // Create a dummy node to simplify the merge process
    struct Node dummy;
    struct Node* tail = &test;
    test.next = NULL;

    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining elements
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return test.next; // Return the merged list, skipping the dummy node
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    struct Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    struct Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Print the original lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Merge the two lists
    struct Node* mergedList = merge(list1, list2);

    // Print the merged list
    printf("Merged List: ");
    printList(mergedList);

    // Free the allocated memory
    freeList(mergedList);
    // Note: list1 and list2 are already merged, so we don't free them separately

    return 0;
}