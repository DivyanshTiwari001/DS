#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int vertex;
    struct ListNode* next;
};
struct Graph{
    int V;
    int E;
    struct ListNode **adj;
};
struct Graph* createGraph(){
    struct Graph* G=(struct Graph*)malloc(sizeof(struct Graph));
    printf("Number of vertices: ");
    scanf("%d",&G->V);
    printf("Number of edges: ");
    scanf("%d",&G->E);
    G->adj=(struct ListNode**)malloc(sizeof(struct ListNode*)*G->V);
    for(int i=0;i<G->V;i++){
        G->adj[i]=(struct ListNode*)malloc(sizeof(struct ListNode));
        G->adj[i]->vertex=i;
        G->adj[i]->next=G->adj[i];
    }
    for(int i=0;i<G->E;i++){
        int u,v;
        printf("Reading Edges: ");
        scanf("%d%d",&u,&v);
        struct ListNode* temp1=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp1->vertex=v;
        temp1->next=G->adj[u];
        struct ListNode* temp=G->adj[u];
        while(temp->next!=G->adj[u]){
            temp=temp->next;
        }
        temp->next=temp1;
        struct ListNode* temp2=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp2->vertex=u;
        temp2->next=G->adj[v];
        temp=G->adj[v];
        while(temp->next!=G->adj[v]){
            temp=temp->next;
        }
        temp->next=temp2;
    }
    return G;
}
void DFS(int* visited,struct Graph* G,int u){
    if(!visited[u]){
        printf("%d ",G->adj[u]->vertex);
    }
    visited[u]=1;
    struct ListNode* temp=G->adj[u]->next;
    do{
        if(!visited[temp->vertex]){
            DFS(visited,G,temp->vertex);
        }
        temp=temp->next;
    }while(temp!=G->adj[u]);
}
void DFSTraversal(struct Graph* G){
    int visited[G->V];
    for(int i=0;i<G->V;i++){
        visited[i]=0;
    }
    for(int i=0;i<G->V;i++){
        if(!visited[i]){
            DFS(visited,G,i);
        }
    }

}
typedef struct Node{
    int data;
    struct Node* next;
}ln;
typedef struct Queue{
    ln* front;
    ln* rear;  
}Queue;
Queue* createQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(!Q) return NULL;
    Q->front=Q->rear=NULL;
    return Q;
} 
int isQueueEmpty(Queue* Q){
    if(Q->front==NULL){
        return 1;
    }
    return 0;
}
void Enqueue(Queue* Q,int value){
        ln* newNode=(ln*)malloc(sizeof(ln));
        if(!newNode){
            printf("Memory Err");
            return;
        }
        newNode->data=value;
        newNode->next=NULL;
        if(Q->rear)Q->rear->next=newNode;
        Q->rear=newNode;
        if(Q->front==NULL){
            Q->front=Q->rear;
        }
}
int Dequeue(Queue* Q){
    if(isQueueEmpty(Q)){
        printf("Queue is Empty");
        return -1;
    }
    ln* temp=Q->front;
    int value = temp->data;
    Q->front=Q->front->next;
    free(temp);
    return value;
}
void Delete(Queue* Q){
    if(Q){
        ln* temp=NULL;
        while(Q->front!=NULL){
            temp=Q->front;
            Q->front=Q->front->next;
            free(temp);
        }
        free(Q);
    }
}
void BFS(struct Graph* G,int u,int* visited){
    Queue* Q = createQueue();
    Enqueue(Q,u);
    while(!isQueueEmpty(Q)){
        int v = Dequeue(Q);
        if(!visited[v]){
            printf("%d ",v);
            visited[v]=1;
            struct ListNode* temp=G->adj[v]->next;
            do{
                if(!visited[temp->vertex])
                    Enqueue(Q,temp->vertex);
                temp=temp->next;
            }while(temp!=G->adj[v]);
        }   
    }
    Delete(Q);
}
void BFSTraversal(struct Graph* G){
    int visited[G->V];
    for(int i=0;i<G->V;i++){
        visited[i]=0;
    }
    for(int i=0;i<G->V;i++){
        if(!visited[i]){
            BFS(G,i,visited);
        }
    }
}
int main(){
    struct Graph* G = createGraph();
    printf("BFS Traversal: ");
    BFSTraversal(G);
//     for(int i=0;i<G->V;i++){
//         struct ListNode* temp=G->adj[i];
//         do{
//             printf("%d ",temp->vertex);
//             temp=temp->next;
//         }while(temp!=G->adj[i]);
//         printf("\n");
// }
}
