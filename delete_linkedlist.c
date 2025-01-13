#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Structure to represent the singly linked list
struct Node {
    int data;
    struct Node* next;   // Pointer to the next node
};

// Delete a node from the beginning of a linked list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

/* Time complexity = O(1)  
   Space complexity = O(1) */

// Delete a node from the end of a linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // If there's only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Node deleted from the end.\n");
}

/* Time complexity = O(N)  
   Space complexity = O(1) */

// Delete a node from a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is at position 0
    if (position == 0) {
        *head = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    // Traverse to the node just before the position
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds. No node deleted.\n");
        return;
    }

    // Delete the node at the specified position
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node deleted from position %d.\n", position);
}

/* Time complexity = O(N)  
   Space complexity = O(1) */

// Display Function
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main Function
int main() {
    struct Node* head = NULL; // Initialize the linked list as empty

    // Adding some nodes manually for testing
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 10;
    n1->next = NULL;
    head = n1;

    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    n2->data = 20;
    n2->next = NULL;
    n1->next = n2;

    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n3->data = 30;
    n3->next = NULL;
    n2->next = n3;

    printf("Initial Linked List:\n");
    display(head);

    // Delete nodes
    deleteFromBeginning(&head);
    printf("Linked List after deleting from the beginning:\n");
    display(head);

    deleteFromEnd(&head);
    printf("Linked List after deleting from the end:\n");
    display(head);

    deleteAtPosition(&head, 0);
    printf("Linked List after deleting from position 0:\n");
    display(head);

    deleteAtPosition(&head, 5); // Out of bounds
    printf("Attempting to delete from an empty list:\n");
    deleteFromBeginning(&head);

    return 0;
}
