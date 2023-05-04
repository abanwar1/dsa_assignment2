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

void printList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *insertBeforeK(struct node *head, int k) {
    int i = 1;
    struct node *temp = head, *newNode;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
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
            printf("The list has less than %d nodes.\n", k);
            free(newNode);
            return head;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node %d has been successfully inserted.\n", k);
    return head;
}

struct node *insertBeforeValue(struct node *head, int value) {
    struct node *temp = head, *newNode;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    newNode = (struct node *)malloc(sizeof(struct node));
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

struct node *deleteFirst(struct node *head) {
    struct node *temp;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("The first node has been successfully deleted.\n");
    return head;
}

struct node *deleteLast(struct node *head) {
    struct node *temp = head, *prev = NULL;

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
    printf("The last node has been successfully deleted.\n");
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
        printf("Invalid k value or kth node does not exist\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after kth node deleted successfully\n");
}

void deleteBeforeKthNode(struct Node** headRef, int k) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    if (k == 1) {
        printf("Invalid k value or no node before the first node\n");
        return;
    }
    struct Node* temp = *headRef;
    int count = 1;
    while (count < k-1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid k value or no node before the kth node\n");
        return;
    }
    struct Node* nodeToDelete = temp->next->next;
    free(temp->next);
    temp->next = nodeToDelete;
    printf("Node before kth node deleted successfully\n");
}

void deleteKthNode(struct Node** headRef, int k) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    if (k == 1) {
        struct Node* nodeToDelete = *headRef;
        *headRef = nodeToDelete->next;
        free(nodeToDelete);
        printf("First node deleted successfully\n");
        return;
    }
    struct Node* temp = *headRef;
    int count = 1;
    while (count < k-1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
    printf("Invalid k value or kth node does not exist\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Kth node deleted successfully\n");
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
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
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
        printf("List is empty or has only one node\n");
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

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node* mergedHead = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            insertEnd(&mergedHead, temp1->data);
            temp1 = temp1->next;
        } else {
            insertEnd(&mergedHead, temp2->data);
	    temp2 = temp2->next;
	}
}
	while (temp1 != NULL) {
	insertEnd(&mergedHead, temp1->data);
	temp1 = temp1->next; 
	}
	while (temp2 != NULL) {
	insertEnd(&mergedHead, temp2->data);
	temp2 = temp2->next;
	}
	return mergedHead;
}


void concatenateLists(struct Node** head1Ref, struct Node* head2) {
	if (*head1Ref == NULL) {
	head1Ref = head2;
	printf("Second list appended to first list\n");
	return;
}
	struct Node temp = *head1Ref;
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
    int choice, data, k, value;
    do {
        printf("\nMENU\n");
        printf("1. Create a linked list\n");
        printf("2. Delete a node after the kth node\n");
        printf("3. Delete a node before the kth node\n");
        printf("4. Delete the kth node\n");
        printf("5. Delete the node containing a specified value\n");
        printf("6. Print the linked list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data for the linked list (-1 to stop): ");
                scanf("%d", &data);
                while (data != -1) {
                    insertEnd(&head, data);
                    scanf("%d", &data);
                }
                printf("Linked list created successfully\n");
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


