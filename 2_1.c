//linked list operations

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* createLinkedList(int size) {
    int i, data;
    struct Node *head, *curr;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    curr = head;

    for (i = 2; i <= size; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        curr->next = createNode(data);
        curr = curr->next;
    }

    return head;
}


void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node* insertAtBegi(struct node* head, int data) {
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
struct node* insertAfterKthNode(struct node* head, int data, int pos) {
    struct node *newNode, *curr;
    int i;

    newNode = createNode(data);
    curr = head;
    for (i = 1; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Error:Pos value is greater then nodes\n");
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return head;

struct Node *insertBeforeK(struct Node *head, int k) {
    int i = 1;
    struct Node *temp = head;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);

    if (k == 1) {
	newNode->next = head;
        head = newNode;
    } else {
        while (i < k - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("The list has less than %d Nodes.\n", k);
            free(newNode);
            return head;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node %d has been successfully inserted.\n", k);
    return head;
}

struct Node *insertBeforeValue(struct Node *head, int value) {
    struct Node *temp = head, *newNode;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value to be inserted: ");
    scanf("%d", &newNode->data);

    if (temp->data == value) {
        newNode->next = head;
        head = newNode;
        printf("Node has been successfully inserted.\n");
        return head;
    }

    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Value not found in the list.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node has been successfully inserted.\n");
    return head;
}

struct Node *deleteFirst(struct Node *head) {
    struct Node *temp;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("The first Node has been successfully deleted.\n");
    return head;
}

struct Node *deleteLast(struct Node *head) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    free(temp);
    printf("The last Node has been successfully deleted.\n");
    return head;
}

void deleteAfterKthNode(struct Node** headRef, int k) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *headRef;
    int count = 1;
    while (count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid k value or kth Node does not exist\n");
        return;
    }
    struct Node* NodeToDelete = temp->next;
    temp->next = NodeToDelete->next;
    free(NodeToDelete);
    printf("Node after kth Node deleted successfully\n");
}

void deleteBeforeKthNode(struct Node** headRef, int k) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    if (k == 1) {
        printf("Invalid k value or no Node before the first Node\n");
        return;
    }
    struct Node* temp = *headRef;
    int count = 1;
    while (count < k-1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid k value or no Node before the kth Node\n");
        return;
    }
    struct Node* NodeToDelete = temp->next->next;
    free(temp->next);
    temp->next = NodeToDelete;
    printf("Node before kth Node deleted successfully\n");
}

void deleteKthNode(struct Node** headRef, int k) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    if (k == 1) {
        struct Node* NodeToDelete = *headRef;
        *headRef = NodeToDelete->next;
        free(NodeToDelete);
        printf("First Node deleted successfully\n");
        return;
    }
    struct Node* temp = *headRef;
    int count = 1;
    while (count < k-1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
    printf("Invalid k value or kth Node does not exist\n");
        return;
    }
    struct Node* NodeToDelete = temp->next;
    temp->next = NodeToDelete->next;
    free(NodeToDelete);
    printf("Kth Node deleted successfully\n");
}

void deleteNodeWithValue(struct Node** headRef, int value) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *headRef;
    if (temp->data == value) {
        *headRef = temp->next;
        free(temp);
        printf("Node with value %d deleted successfully\n", value);
        return;
    }
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }
    struct Node* NodeToDelete = temp->next;
    temp->next = NodeToDelete->next;
    free(NodeToDelete);
    printf("Node with value %d deleted successfully\n", value);
}
void reverseList(struct Node** headRef) {
    struct Node* prevNode = NULL;
    struct Node* currentNode = *headRef;
    struct Node* nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *headRef = prevNode;
    printf("List reversed successfully\n");
}

void sortList(struct Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) {
        printf("List is empty or has only one Node\n");
        return;
    }
    struct Node* temp1 = *headRef;
    while (temp1 != NULL) {
        struct Node* temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {
                int temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    printf("List sorted successfully\n");
}

void searchElement(struct Node* head, int element) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == element) {
            printf("Element %d found at position %d\n", element, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", element);
}
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node *newNode, *curr;

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

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            insertAtEnd(mergedHead, temp1->data);
            temp1 = temp1->next;
        } else {
            insertAtEnd(mergedHead, temp2->data);
	    temp2 = temp2->next;
	}
}
	while (temp1 != NULL) {
	insertAtEnd(mergedHead, temp1->data);
	temp1 = temp1->next; 
	}
	while (temp2 != NULL) {
	insertAtEnd(mergedHead, temp2->data);
	temp2 = temp2->next;
	}
	return mergedHead;
}

void concatenateLists(struct Node *head1Ref, struct Node* head2) {
	if (head1Ref == NULL) {
	head1Ref = head2;
	printf("Second list appended to first list\n");
	return;
	}
	struct Node *temp = head1Ref;
	while (temp->next != NULL) {
	temp = temp->next;
	}
	temp->next = head2;
	printf("Second list appended to first list\n");
}

int areListsEqual(struct Node* head1, struct Node* head2) {
	while (head1 != NULL && head2 != NULL) {
	if (head1->data != head2->data) {
	return 0;
	}
	head1 = head1->next;
	head2 = head2->next;
	}
	if (head1 == NULL && head2 == NULL) {
	return 1;
	} else {
	return 0;
	}
}
int main() {
    struct Node* head = NULL;
    int choice, data, k, value, size;
    do {
        printf("\nMENU\n");
        printf("1. Create a linked list\n");
        printf("2. Print the contents of the linked list\n");
        printf("3. Insert at the beginning of the linked list\n");
        printf("4. Insert at the end of the linked list\n");
        printf("5. Insert a node after the kth node.\n");
        printf("6. Insert a node after the node (first from the start) containing agiven value..\n");
        printf("7. Insert a node before the kth node.\n");
        printf("8. Insert a node before the node (first from the start) containing agiven value..\n");
        printf("9. Delete the first node.\n");
        printf("10. Delete the last node.\n");
        printf("2. Delete a Node after the kth Node\n");
        printf("3. Delete a Node before the kth Node\n");
        printf("4. Delete the kth Node\n");
        printf("5. Delete the Node containing a specified value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the size you want to in the linked list ");
                scanf("%d", &size);
                head = createLinkedList(size);
                printf("Linked list created successfully.\n");
                break;
            case 2:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                deleteAfterKthNode(&head, k);
                break;
            case 3:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                deleteBeforeKthNode(&head, k);
                break;
            case 4:
                printf("Enter the value of k: ");
                scanf("%d", &k);
                deleteKthNode(&head, k);
                break;
            case 5:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                deleteNodeWithValue(&head, value);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                printf("Exiting...\n");
                break;
         
   default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}


