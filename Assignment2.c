//Ian Gachugu
//SCT222-0136/2023

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node to the end of the doubly linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two doubly linked lists
struct Node* addDoublyLinkedLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* p1 = list1;
    struct Node* p2 = list2;
    int carry = 0;

    // Traverse both lists from the end
    while (p1 != NULL || p2 != NULL || carry) {
        int sum = carry;
        if (p1 != NULL) {
            sum += p1->data;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->data;
            p2 = p2->next;
        }
        carry = sum / 10; // Calculate carry for the next iteration
        appendNode(&result, sum % 10); // Store the single digit result
    }

    return result; // Return the resulting linked list
}

// Function to free the doubly linked list
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
    // Create first doubly linked list: 4 -> 5 -> 6 (represents 654)
    struct Node* list1 = NULL;
    appendNode(&list1, 4);
    appendNode(&list1, 5);
    appendNode(&list1, 6);

    // Create second doubly linked list: 7 -> 8 -> 9 (represents 987)
    struct Node* list2 = NULL;
    appendNode(&list2, 7);
    appendNode(&list2, 8);
    appendNode(&list2, 9);

    // Print the original lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Add the two lists
    struct Node* sumList = addDoublyLinkedLists(list1, list2);

    // Print the sum
    printf("Sum stored in a doubly linked list: ");
    printList(sumList);

    // Free the allocated memory
    freeList(list1);
    freeList(list2);
    freeList(sumList);

    return 0;
}