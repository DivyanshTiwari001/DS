#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int data;
    struct ListNode* next;
}ln;

void Traversal(ln* head){
    ln* current = head;
    while(current!=NULL){
        // cout<<current->data<<endl;
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
// ln* insertAtStarting(ln *head,int value){
//     ln *current=head;
//     ln *node=(ln*)malloc(sizeof(ln));
//     node->data=value;
//     node->next=current;
//     return node;
// }
// void insertAtEnd(ln **head,int value){
//     ln* node=(ln*)malloc(sizeof(ln));
//     node->data=value;
//     node->next=NULL;
//     if(*head==NULL){
//         *head=node;
//     }
//     else{
//         ln* current=*head;
//         while(current->next!=NULL){
//             current=current->next;
//         }
//         current->next=node;
//     }
// }
void insert(ln **head,int value,int position){
    int k=1;
    ln *node=(ln*)malloc(sizeof(ln));
    node->data=value;
    if(*head==NULL || position==1){
        node->next=*head;
        *head=node;
        return;
    }
    ln *p,*q;
    p=*head;
    while(p!=NULL && k<position){
        k++;
        q=p;
        p=p->next;
    }
    q->next=node;
    node->next=p;
}
// int deleteFirstNode(ln **head){
//         ln* temp = *head;
//         if(*head==NULL){
//             // cout<<"The List is Empty"<<endl;
//             printf("The List is Empty\n");
//             return -1;
//         }
//         *head=(*head)->next;
//         int val=temp->data;
//         free(temp);
//         return val;
// }
// int deleteLastNode(ln **head){
//     if(*head==NULL){
//             cout<<"The List is Empty"<<endl;
//             return -1;
//         }
//     ln* tail = *head;
//     ln* priorTail=NULL;
//     while(tail->next!=NULL){
//         priorTail=tail;
//         tail=tail->next;
//     }
//     priorTail->next=NULL;
//     int val = tail->data;
//     free(tail);
//     return val;
// }
int deleteNode(ln **head,int position){
    if(*head==NULL){
        // cout<<"The List is Empty"<<endl;
        printf("The List is Empty\n");
        return -1;
    }
    int k=1;
    ln* rn= *head;
    ln* pn=NULL;
    if(position == 1){
        *head=(*head)->next;
    }
    else{
        while(rn!=NULL && k<position){
        k++;
        pn=rn;
        rn=rn->next;
    }
    if(rn == NULL){
        // cout<<"Element is not there"<<endl;
        printf("Element is not there\n");
        return -1;
    }else pn->next=rn->next;
    }
    int val=rn->data;
    free(rn);
    return val;
}
// void deleteLinkedList(ln **head){
//     ln *temp,*iterator=*head;
//     while(iterator){
//         temp = iterator->next;
//         free(iterator);
//         iterator=temp;
//     }
//     *head=NULL;
// }
int main(){
    ln* head = NULL;
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