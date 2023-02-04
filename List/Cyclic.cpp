#include<iostream>
using namespace std;
// Using Fast Pointer and Slow pointer
typedef struct ListNode{
    int data;
    struct ListNode* next;
}ln;
typedef struct HashListNode{
    int64_t data;
    struct HashListNode* next;
}hln;
bool checkCyclicHash(ln *head){
   hln *arr[10]={NULL};
   ln *p1=head;
   while(p1!=NULL){
    int64_t i =(int64_t)p1;
    hln* node=(hln*)malloc(sizeof(hln));
    node->data=i;
    node->next=NULL;
    if(arr[i%10]==NULL){
        arr[i%10]=node;
    }
    else{
        hln *temp=arr[i%10];
        while(temp->next!=NULL){
            if(temp->data==node->data){
                return true;
            }
            temp=temp->next;
        }
        if(temp->data==node->data){
            return true;
        }
        temp->next=node;   
    }
    p1=p1->next;
   }  
   return false;
}
bool checkCyclic(ln *head1){
    ln *p1=head1;
    ln *p2=head1;
    while(p1!=NULL && p2!=NULL){
        p1=p1->next;
        if(p2->next==NULL){
            return false;
        }
        p2=p2->next->next;
        if(p1==p2){
            return true;
        }
    }
    return false;
}
ln* firstNodeOfCycle(ln *head){
    ln *p1=head;
    ln *p2=head;
    while(true){
        p1=p1->next;
        p2=p2->next->next;
        if(p1==p2){
            break;
        }
    }
    p1=head;
    while(true){
        if(p1==p2){
            return p1;
        }
        p1=p1->next;
        p2=p2->next;
    }
}
void insertAtEnd(ln **head,int value){
    ln* node=(ln*)malloc(sizeof(ln));
    node->data=value;
    node->next=NULL;
    if(*head==NULL){
        *head=node;
    }
    else{
        ln* current=*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=node;
    }
}
void deleteLinkedList(ln **head){
    ln *temp,*iterator=*head;
    while(iterator){
        temp = iterator->next;
        free(iterator);
        iterator=temp;
    }
    *head=NULL;
}
void makeCyclic(ln **head,int pos,int value){
    ln* node=(ln*)malloc(sizeof(ln));
    node->data=value;
    int k=1;
    ln* temp=*head;
    while(k<pos){
        temp=temp->next;
        k++;
    }
    node->next=temp;;
    if(*head==NULL){
        *head=node;
    }
    else{
        ln* current=*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=node;
    }
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
    int value=0;
    for(int i=0;i<6;i++){
        cin>>value;
        insertAtEnd(&head,value);
    }
    cout<<"Printing the elements of the list"<<endl;
    linkedListTraversal(head);
    makeCyclic(&head,4,9);
    cout<<"check for cyclic"<<endl;
    cout<<checkCyclicHash(head);
    // ln* node=firstNodeOfCycle(head);
    // cout<<node<<endl<<node->data;
    return 0;
}