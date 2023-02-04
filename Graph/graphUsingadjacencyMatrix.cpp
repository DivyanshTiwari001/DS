// Graph using adjacency matrix
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_CAPACITY 1
struct Graph{
    int V;//Vertices
    int E;//Edges
    int **adj;//adjacency matrix
};

struct Graph* readGraph(){
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    if(!G){
        printf("Memory Error!");
        return NULL;
    }
    printf("No. of Vertices: ");
    scanf("%d",&(G->V));
    printf("No. of Edges: ");
    scanf("%d",&(G->E));
    G->adj=(int **)malloc(G->V*sizeof(int*));
    for(int i=0;i<G->V;i++){
        G->adj[i]=(int *)malloc(G->V*sizeof(int));
        if(G->adj[i]==NULL)return NULL;
    }
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            G->adj[i][j]=0;
        }
    }
    for(int i=0;i<G->E;i++){
        int u,v;
        printf("Reading the edges: ");
        scanf("%d%d",&u,&v);
        // unweighted undirected Graph;
        G->adj[u][v]=G->adj[v][u]=1;
    }
    return G;
}
void DFS(int* visited,struct Graph* G,int u){
    if(!visited[u]){
        printf("%d ",u);
    }
    visited[u]=1;
    for(int v=0;v<G->V;v++){
        if(!visited[v] && G->adj[u][v]){
            DFS(visited,G,v);
        }
    }
}
void DFSTraversal(struct Graph* G){
    int visited[G->V];
    for(int i=0;i<G->V;i++){
        visited[i]=0;
    }
    for(int i=0;i<G->V;i++){
        if(!visited[i])
            DFS(visited,G,i);
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
void BFS(struct Graph* G,int u,int* visited){
    Queue* Q=createQueue();
    Enqueue(Q,u);
    while(!isQueueEmpty(Q)){
        int v=Dequeue(Q);
        if(!visited[v]){
            printf("%d ",v);
            visited[v]=1;
            for(int i=0;i<G->V;i++){
                if(G->adj[v][i] && !visited[i]){
                    Enqueue(Q,i);
                }
            }  
        }
    }
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
void FreeGraph(struct Graph* G){
    for(int i=0;i<G->V;i++){
        free(G->adj[i]);
    }
    free(G->adj);
    free(G);
}
int main(){
struct Graph* G = readGraph();
    // for(int i=0;i<G->V;i++){
    //     for(int j=0;j<G->V;j++){
    //         printf("%d ",G->adj[i][j]);
    //     }
    //     printf("\n");
    // }
    DFSTraversal(G);

    FreeGraph(G);
}