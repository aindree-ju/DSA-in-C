#include <stdio.h>
#include <stdlib.h> // For malloc

// Structure to represent the singly linked list
struct Node {
	int data;
	struct Node* next;   // Pointer to the next node
};

// Insert a new node at the start of a linked list
void insertAtBeginning(struct Node** head, int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = *head;
	*head = temp;
}

/* Time complexity = O(1)
   Space complexity = O(1) */

// Insert a new node at the end of a linked list
void insertAtEnd(struct Node** head, int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;

	if (*head == NULL) {
		*head = temp;
		return;
	}

	struct Node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = temp;
}

/* Time complexity = O(N)
   Space complexity = O(1) */

// Insert a new node at a specific position in a linked list
void insertAtPosition(struct Node** head, int x, int position) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;

	// Insert at the beginning if position is 0
	if (position == 0) {
		temp->next = *head;
		*head = temp;
		return;
	}

	struct Node* current = *head;
	for (int i = 0; current != NULL && i < position - 1; i++) {
		current = current->next;
	}

	// If the position is invalid (out of bounds)
	if (current == NULL) {
		printf("Position out of bounds.\n");
		free(temp); // Free allocated memory
		return;
	}

	// Insert at the specified position
	temp->next = current->next;
	current->next = temp;
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

	// Insert at the beginning
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);

	printf("Linked List after inserting at the beginning:\n");
	display(head);

	// Insert at the end
	insertAtEnd(&head, 40);
	insertAtEnd(&head, 50);

	printf("Linked List after inserting at the end:\n");
	display(head);

	// Insert at specific positions
	insertAtPosition(&head, 25, 2); // Insert 25 at position 2
	insertAtPosition(&head, 5, 0);  // Insert 5 at position 0
	insertAtPosition(&head, 60, 10); // Insert 60 at an out-of-bounds position

	printf("Linked List after inserting at specific positions:\n");
	display(head);

	return 0;
}
