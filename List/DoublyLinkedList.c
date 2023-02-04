// For Doubly
#include<stdio.h>
#include<stdlib.h>
typedef struct DoublyLinkedList{
    int data;
    struct DoublyLinkedList* prev;
    struct DoublyLinkedList* next;
}dll;
// Insertion
void insert(dll** head,int value,int pos){
    int k=1;
    dll* node=(dll*)malloc(sizeof(dll));
    node->data=value;
    node->prev=NULL;
    if(*head==NULL || pos==1){
        node->next=*head;
        *head=node;
        return;
    }
    dll* temp=*head;
    while(temp->next!=NULL && k<pos-1){
         k++;
         temp=temp->next;
    }
    node->next=temp->next;
    if(temp->next){
        temp->next->prev=node;
    }
    temp->next=node;
    node->prev=temp;
}
// Deletion
// based on position
int deleteNode(dll** head,int pos){
    int k=1;
    if(*head == NULL){
        return -1;
    }
    dll* temp=*head;
    if(pos==1){
        *head=(*head)->next;
        (*head)->prev=NULL;
    }
    else{
        while(temp->next!=NULL && k<pos){
            k++;
            temp=temp->next;
        }
        if(!temp){
            printf("No such Position exist\n");
            return -1;
        }
        temp->prev->next=temp->next;
        if(temp->next){
            temp->next->prev=temp->prev;
        }
    }
    int value=temp->data;
    free(temp);
    return value;
}
// based on address
int deleteByAddress(dll* adr){
    if(adr==NULL){
        return -1;
    }
    else{
        if(!(adr->next)){
            adr->prev->next=adr->next;
        }
        else{
            adr->prev->next=adr->next;
            adr->next->prev=adr->prev;
        }
    }
    int val=adr->data;
    free(adr);
    return val;
}
// based on Value
int deleteNodeWithGivenValue(dll** head,int value){
    dll* temp=*head;
    if(*head==NULL){
        return -1;
    }
    if(temp->data==value){
        *head=temp->next;
        (*head)->prev=NULL;
        free(temp);
    }
    else{
        while(temp!=NULL && temp->data!=value){
            temp=temp->next;
        }
        if(temp==NULL){
            return -1;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        free(temp);
    }
    return value;
}
// Traversal 
// From start to end;
void Traversal(dll* head){
    dll* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// From end to start
void reverseTraversal(dll* tail){
    while(tail!=NULL){
        printf("%d\n",tail->data);
        tail=tail->prev;
    }
}
// Reversal of Doubly Linked List
void reverse(dll **head, dll **tail){
    if(*head==NULL){
        return;
    }
    dll* current = *head;
    dll* temp=NULL;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    current=*head;
    *head=*tail;
    *tail=current;
}
// Helping Functions
dll* findTail(dll* head){
    dll* temp = head;
    if(head==NULL){
        return NULL;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}
int main(){
   dll* head = NULL;
    int value;
    for(int i=0;i<5;i++){
        printf("Enter Node to be inserted: ");
        scanf("%d",&value);
        insert(&head,value,i+1);
    }
    printf("Your list is: ");
    Traversal(head);
    printf("Enter the Node to be deleted(position): ");
    int pos;
    scanf("%d",&pos);
    printf("Deleted Node: %d\n",deleteNode(&head,pos));
    printf("List after deletion: ");
    Traversal(head);
    return 0;
}