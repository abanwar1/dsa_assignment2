#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* createLinkedList(int size) {
    int i, data;
    struct node *head, *curr;

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


void printLinkedList(struct node* head) {
    struct node* curr = head;
    printf("Linked list: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
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

/*void insertBeforeValue(struct Node** headRef, int value, int data) {
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
}*/
/*struct node* insertAfterKthNode(struct node* head, int data, int pos) {
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
}*/ 

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


void deleteFirst(struct Node** headR) {
    if (*headR == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *headR;
    *headR = (*headR)->next;
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
    int choice, size, data, pos, value;
    struct node* head = NULL;

    while (1) {
        printf("\n*****Operations*****\n");
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
        printf("11. Delete a node after the kth node,\n");
        printf("12. Delete a node befor the kth node,\n");
        printf("13. Delete the k node.\n");
        printf("14. Delete a node before the node (first from the start) containing agiven value..\n");
        printf("15. Reverse the list.\n");
        printf("16. Sort the list.\n");
        printf("17. Search the given element.\n");
        printf("18. Mearge the list.\n");
        printf("19. Concatenate two list.\n");
        printf("20. Find two list is equal.\n");
        printf("0. Exit\n");
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
                if (head == NULL) {
                    printf("Linked list is empty.\n");
                } else {
                    printLinkedList(head);
                }
                break;

            case 3:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                head = insertAtBegi(head, data);
                printf("Node inserted at the beginning of the linked list.\n");
                break;
            case 4:
            	printf("Enter data for the new node: ");
                scanf("%d", &data);
         
       		head = insertAtEnd(head, data);
                printf("Node inserted at the end of the linked list.\n");
                break;
            case 5:
            	printf("Enter data for the new node:\n");
            	scanf("%d", &data);
            	printf("Enter the position\n");
            	scanf("%d",&pos);
            	head=insertAfterKthNode(head,data,pos);
            	printf("Node inserted after kth position");
            	break;	           	       
            	
            case 6:
            	printf("Enter data for the new node:\n");
            	scanf("%d", &data);
            	printf("Enter the Value\n");
            	scanf("%d",&value);
            	head=insertAfterKthNode(head,value,data);
            	printf("Node inserted after given value position");	           	       
            	break;
            case 7:
            		
            case 9:
            	deleteFirst(*head);*/	
            case 0:
                printf("Exit.\n");
                exit(0);

            default:
                printf("Invalid! Try Corrent Choiece.\n");
        }
    }

    return 0;
}

