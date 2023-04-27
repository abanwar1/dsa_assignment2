
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list of given size
struct node* createLinkedList(int size) {
    int i, data;
    struct node *head, *curr;

    // Create the first node
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    curr = head;

    // Create the rest of the nodes
    for (i = 2; i <= size; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        curr->next = createNode(data);
        curr = curr->next;
    }

    return head;
}

// Function to print the contents of the linked list
void printLinkedList(struct node* head) {
    struct node* curr = head;
    printf("Linked list: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}
struct node* insertAtEnd(struct node* head, int data) {
    struct node *newNode, *curr;

    newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    return head;
}
struct node* insertAfterKthNode(struct node* head, int data, int k) {
    struct node *newNode, *curr;
    int i;

    newNode = createNode(data);
    curr = head;
    for (i = 1; i < k && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: k is greater than the number of nodes in the list.\n");
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}
struct node* insertAfterKthNode(struct node* head, int data, int k) {
    struct node *newNode, *curr;
    int i;

    newNode = createNode(data);
    curr = head;
    for (i = 1; i < k && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error: k is greater than the number of nodes in the list.\n");
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}
void insertAfterValue(struct Node** headRef, int value, int data) {
    struct Node* current = *headRef;
    while (current != NULL && current->data != value) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the list.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

void insertBeforeKth(struct Node** headRef, int k, int data) {
    struct Node* current = *headRef;
    int i = 1;
    while (current != NULL && i < k - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}

void insertBeforeValue(struct Node** headRef, int value, int data) {
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found in the list.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = current;
    if (prev == NULL) {
        *headRef = newNode;
    } else {
        prev->next = newNode;
    }
}

void deleteFirst(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
}

void deleteLast(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*headRef)->next == NULL) {
        free(*headRef);
        *headRef = NULL;
        return;
    }
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}


int main() {
    int choice, size, data;
    struct node* head = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a linked list\n");
        printf("2. Print the contents of the linked list\n");
        printf("3. Insert a node at the beginning of the linked list\n");
        printf("4. Insert a node at the end of the linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the linked list: ");
                scanf("%d", &size);
                head = createLinkedList(size);
                printf("Linked list created successfully.\n");
                break;

            case 2:
                if (head == NULL) {
                    printf("Linked list is empty.\n");
                } else {
                    printLinkedList(head);
                }
                break;

            case 3:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("Node inserted at the beginning of the linked list.\n");
                break;
            case 4:
            	printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Node inserted at the end of the linked list.\n");
                break;    

            case 5:
                printf("Exit.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
