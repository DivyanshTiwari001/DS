// #include<iostream>
// using namespace std;
#include<stdio.h>
#include<stdlib.h>
typedef struct CircularLinkedListNode{
    int data;
    struct CircularLinkedListNode* next;
}cll;
// void insertNodeAtEnd(cll **head,int value){
//     cll* node=(cll*)malloc(sizeof(cll));
//     node->data=value;
//     node->next=node;
//     if(*head==NULL){
//         *head=node;
//         return;
//     }
//     node->next=*head;
//     cll* current=*head;
//     do{
//         current=current->next;
//     }while(current->next!=*head);
//     current->next=node;
// }
void insert(cll** head,int val,int pos){
    int k=1;
    cll* node = (cll*)malloc(sizeof(cll));
    node->data=val;
    node->next=node;
    if(*head==NULL || pos==1){
        if(*head!=NULL){
            node->next=*head;
            cll* temp=*head;
            do{
                temp=temp->next;
            }while(temp->next!=*head);
            temp->next=node;
        }
        *head=node;
        return;
    }
    else{
        cll* temp=*head;
        while(temp->next!=*head && k<pos-1){
            k++;
            temp=temp->next;
        }
        node->next=temp->next;
        temp->next=node;
    }
}
void Traversal(cll*head){
    cll* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int deleteNode(cll** head,int pos){
    if(*head==NULL){
        printf("The List is Empty\n");
        return -1;
    }
    cll* rn = *head;
    int k=1;
    if(pos==1){
        if(*head==(*head)->next)*head=NULL;
        else{
            *head=(*head)->next;
            cll* temp = *head;
            while(temp->next!=rn){
                temp=temp->next;
            } 
            temp->next=*head;
        }
    }
    else{
        cll* pn=NULL;
        while(rn->next!=*head && k<pos){
            k++;
            pn=rn;
            rn=rn->next;
        }
        if(k!=pos){
            printf("No node at that position\n");
            return -1;
        }
        pn->next=rn->next;
    }
    int val=rn->data;
    free(rn);
    return val;
}
// void insertNodeAtStart(cll **head,int value){
//     cll* node=(cll*)malloc(sizeof(cll));
//     node->data=value;
//     node->next=node;
//     if(*head==NULL){
//         *head=node;
//         return;
//     }
//     node->next=*head;
//     cll* current=*head;
//     do{
//         current=current->next;
//     }while(current->next!=*head);
//     current->next=node;
//     *head=node;
// }
// int countNode(cll *head){
//     cll* current=head;
//     int count=0;
//     do{
//         count++;
//         current=current->next;
//     }while(current!=head);
//     return count;
// }
// void printNode(cll *head){
//     cll* current=head;
//     do{
//         cout<<current->data<<endl;
//         current=current->next;
//     }while(current!=head);
// }
// void deleteLastNode(cll *head){
//     cll* tail=head;
//     cll*ptail;
//     if(tail==NULL){
//         cout<<"List is empty"<<endl;
//         return;
//     }
//     do{
//         ptail=tail;
//         tail=tail->next;
//     }while(tail->next!=head);
//     ptail->next=head;
//     free(tail);
// }
// void deleteFirstNode(cll **head){
//     cll *temp=*head;
//     cll *tail=*head;
//     if(*head==NULL){
//         cout<<"Already Null"<<endl;
//         return;
//     }
//     do{
//         tail=tail->next;
//     }while(tail->next!=temp);
//     tail->next=temp->next;
//     *head=temp->next;
//     free(temp);
// }
int main(){
    cll* head = NULL;
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
    if(head!=NULL){
        printf("List after deletion: ");
        Traversal(head);
    }
    else{
        printf("No element in the list");
    }
    return 0;
}