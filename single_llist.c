#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head=NULL,*ptr;

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

void insert_begin(int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        temp->next=head;
        head=temp;
    }
}
void insert_end(int value){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL) {
        head=temp;
    }
    else {
        ptr=head;
        while(ptr->next!=NULL) {
            ptr->next=temp;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
}
void insert_specified_element(int value, int ele) {
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    if(head==NULL) {
        head=temp;
    }
    else {
        ptr=head;
        while(ptr->data!=ele) {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
}

void delete_begin() {
    if(head==NULL) {
        printf("List is Empty,Deletion Not Possible");
    }
    else {
        ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
    }
}
void delete_end() {
    if(head==NULL) {
        printf("Deletion Not Possible\n");
    }
    else {
        struct node *p;
        ptr=head;
        while(ptr->next!=NULL) {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=NULL;
        free(ptr);
    }
}
void delete_middle(int ele) {
    if(head==NULL) {
        printf("List is empty,Deletion Not Possible");
    }
    else {
        struct node *p;
        ptr=head;
        while(ptr->data!=ele) {
            p=ptr;
            ptr=ptr->next;
        }
        p->next=ptr->next;
        free(ptr);
    }
}
void display() {
    if(head==NULL) {
        printf("List is Empty\n");
    }
    else {
        ptr=head;
        while(ptr!=NULL) {
            printf("-> %d",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void main() {
    int choiceh, ele, value,size;
    printf("MENU\n");
    printf("1.Insert in the Begining\n");
    printf("2.Insert in the End\n");
    printf("3.Insert After Specified Element\n");
    printf("4.Delete From Begining\n");
    printf("5.Delete From End\n");
    printf("6.Delete After Specified Element\n");
    printf("7.Create LinkList\n");
    printf("7.Exit\n");

    while(1) {
        printf("Enter Your Choice\n");
        scanf("%d",&choiceh);
        switch(choiceh) {
            case 1: {
                printf("Enter the value\n");
                scanf("%d",&value);
                insert_begin(value);
                display();
                break;
            }
            case 2: {
                printf("Enter the value\n");
                scanf("%d",&value);
                insert_end(value);
                display();
                break;           
            }
            case 3: {
                printf("Enter the value\n");
                scanf("%d",&value);
                printf("Enter the Position\n");
                scanf("%d",&ele);
                insert_specified_element(value,ele);
                display();
                break;
            }
            case 4: {
                delete_end();
                display();
                break;
            }
            case 5: {
                delete_end();
                display();
                break;
            }
            case 6: {
                printf("Enter the Position\n");
                scanf("%d",&ele);
                delete_middle(ele);
                display();
                break;
            }
            case 7:
                printf("Enter size of link list:\n");
                scanf("%d",&size);
                createLinkedList(size);
                display();
            case 8:
            	exit(0);
            default:printf("invalied choice!");    

        }
    }
}

