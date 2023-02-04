#include<iostream>
using namespace std;
// insertion at any position after the given address;
typedef struct LinkedListNode{
    int data;
    struct LinkedListNode *next;
}ln;
void insertAfterGivenAddress(ln* ptr,int value){
    ln *newNode=(ln*)malloc(sizeof(ln));
    newNode->data=value;
    newNode->next=ptr->next;
    ptr->next=newNode;
}
void insertAtAnyPosition(ln **head,int value,int position){
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
void reverseLinkedList(ln **head){
    ln *current=*head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    int arr[count];
    current=*head;
    int i=0;
    while(current!=NULL){
        arr[i]=current->data;
        i++;
        current=current->next;
    }
    current=*head;
    while(current!=NULL){
        current->data=arr[--i];
        current=current->next;
    }
}
void reverseLinkedList2(ln **head){
    ln *pn,*cn,*nextNode;
    pn=NULL;
    cn=*head;
    nextNode=(*head)->next;
    while(nextNode!=NULL){
        cn->next=pn;
        pn=cn;
        cn=nextNode;
        nextNode=nextNode->next;
    }
    cn->next=pn;
    *head=cn;
}
ln* reverseLinkedListThroughRecursion(ln *head,ln *pn,ln *cn,ln *nextNode){
        if(nextNode==NULL){
            cn->next=pn;
            return cn;
        }
        if(cn==NULL){
            cn=head;
        }
        cn->next=pn;
        pn=cn;
        cn=nextNode;
        nextNode=nextNode->next;
        return reverseLinkedListThroughRecursion(head,pn,cn,nextNode);
}
void linkedListTraversal(ln* head){
    ln* current = head;
    while(current!=NULL){
        cout<<current->data<<endl;
        current=current->next;
    }
}
int main(){
    ln *head=NULL;
    // ln n1;
    // n1.data=14;
    // n1.next=NULL;
    // head=&n1;
    // insertAfterGivenAddress(head,45);
    // cout<<head->data<<endl<<head->next->data<<endl;
    for(int i=0;i<7;i++){
        int value;
        cin>>value;
        insertAtAnyPosition(&head,value,i+1);
    }
    linkedListTraversal(head);
    cout<<"Reversing the List"<<endl;
    // reverseLinkedList2(&head);
    head=reverseLinkedListThroughRecursion(head,NULL,NULL,head->next);
    linkedListTraversal(head);
    return 0;
}