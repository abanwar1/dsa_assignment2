#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node; 

void show(node* last){
   printf("The number of people of the circle is: ");
    node* ptr=last->next;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=last->next);
    printf("\n");
}

node* execute(node *last,node *ptr,int k){
    int t=k;
    show(last);
    node* temp;
    if(last==NULL || last->next==last){
        return last;
    }
    k--;
    while(--k){
        ptr=ptr->next;
    }
    if(ptr->next==last){
        last=ptr;
    }
    temp=ptr->next;
    printf("%d is freed\n",temp->data);
    ptr->next=temp->next;
    free(temp);
    return execute(last,ptr->next,t);
}

node* insertLast(node* last,int info){
    node* temp = (node *)malloc(sizeof(node));
    temp->data=info;
    if(last!=NULL){
        temp->next = last->next;
        last->next =temp;
        last = last->next;
    }else{
        temp->next=temp;
        last=temp;
    }
    return last;
}

node* createCircle(node* last,int number){
    int i=1;
    while(number--){
        last = insertLast(last,i++);
    }
    return last;
}

void reverseList( node **head) 
{
     node *prev, *cur, *next, *last;

    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       
}


int main(){
    node *last = NULL;
    printf("Enter the  number of people :");
    int number;
    scanf("%d",&number);
    last = createCircle(last,number);
    printf("Enter the specified number of people :");
    int k;
    scanf("%d",&k);
    int choice ;
    printf("Press 1 for clockwise and 0 for anti-clockwise : ");
    scanf("%d",&choice);
    if(choice)
    last = execute(last,last->next,k);
    else 
       last = execute(last,last->next,number-k);
    printf("The last person to freed is :");
    printf("%d\n",last->data);
    return 0;
}

