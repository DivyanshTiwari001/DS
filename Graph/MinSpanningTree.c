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
    scanf("%d",&G->V);
    printf("No. of Edges: ");
    scanf("%d",&G->E);
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
        int weight;
        printf("Enter the edge weight: ");
        scanf("%d",&weight);
        G->adj[u][v]=G->adj[v][u]=weight;
    }
    return G;
}
typedef struct element{
    int data;
    int priority;
}element;
typedef struct PriorityQueue{
    int front;
    int rear;
    int capacity;
    element* arr;
}PQ;
PQ* createPQ(){
    PQ* q=(PQ*)malloc(sizeof(PQ));
    if(!q){
        printf("Memory Err\n");
        return NULL;
    }
    q->capacity=MAX_CAPACITY;
    q->front=q->rear=-1;
    q->arr=(element*)malloc(sizeof(element)*q->capacity);
    if(!q->arr){
        printf("Memory Err\n");
        return NULL;
    }
    return q;
}
int IsPriorityQueueFull(PQ* Q){
    if((Q->rear+1)%Q->capacity==Q->front)return 1;
    return 0;
}
int IsPriorityQueueEmpty(PQ* Q){
    if(Q->front==-1)return 1;
    return 0;
}
void resize(PQ* Q){
    int size = Q->capacity;
    Q->capacity*=2;
    Q->arr=(element*)realloc(Q->arr,sizeof(element)*Q->capacity);
    if(Q->front>Q->rear){
        for(int i=0;i<Q->front;i++){
            Q->arr[i+size]=Q->arr[i];
        }
        Q->rear+=size;
    }
}
void PQEnqueue(PQ* Q,int data,int priority){
    if(IsPriorityQueueFull(Q)){
        resize(Q);
    }
    Q->rear=(Q->rear+1)%Q->capacity;
    Q->arr[Q->rear].data=data;
    Q->arr[Q->rear].priority=priority;
    if(Q->front==-1){
        Q->front=Q->rear;
    }
}
element *find(PQ* Q,int data){
    for(int i=Q->front;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].data==data){
            return &Q->arr[i];
        }
    }
    return NULL;
}
int peek(PQ* Q){
    if(IsPriorityQueueEmpty(Q)){
        printf("No Element in Queue");
        return -1;
    }
    int index=0,min=Q->arr[Q->front].priority;
    if(Q->front==Q->rear){
        index=0;
    }
    for(int i=(Q->front+1)%Q->capacity;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
        if(Q->arr[i].priority<min){
            min=Q->arr[i].priority;
            index=i;
        }
    }
    return index;
}
int DequeuePQ(PQ* Q){
    if(IsPriorityQueueEmpty(Q)){
        printf("No Element in Queue");
        return -1;
    }
    int index = peek(Q);
    int data = Q->arr[index].data;
    if(Q->front == Q->rear){
        Q->front = Q->rear =-1;
    }
    else{
        for(int i=index;i!=(Q->rear+1)%Q->capacity;i=(i+1)%Q->capacity){
            Q->arr[i]=Q->arr[(i+1)%Q->capacity];
        }
        Q->rear=(Q->rear-1)%Q->capacity;
    }
    return data;
}
void Prims(struct Graph* G,int* Distance,int* path){
    for(int i=0;i<G->V;i++){
        Distance[i]=INT_MAX;
        path[i]=-1;
    }
    Distance[0]=0;
    PQ* Q = createPQ();
    PQEnqueue(Q,0,0);
    while(!IsPriorityQueueEmpty(Q)){
        int v = DequeuePQ(Q);
        for(int i=0;i<G->V;i++){
           if(G->adj[v][i]<Distance[i]&&G->adj[v][i]!=0){
            Distance[i]=G->adj[v][i];
            if(find(Q,i)==NULL){
                PQEnqueue(Q,i,G->adj[v][i]);
            }
            else{
                find(Q,i)->priority=G->adj[v][i];
            }
            path[i]=v;
           }
        }
    }

}
typedef struct specialElement{
    int src,des,weight;
}spElement;
void sort(spElement* arr,int l){
    for(int i=0;i<l-1;i++){
        int flag=0;
        for(int j=0;j<l-i-1;j++){
            if(arr[j].weight>arr[j+1].weight){
                spElement temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(!flag){
            break;
        }
    }
}
void kruskalsAlgo(struct Graph* G,int *Distance , int* parent){
    spElement* edges=(spElement*)malloc(sizeof(spElement)*G->E);
    int k=0;
    for(int i=0;i<G->V;i++){
        for(int j=i+1;j<G->V;j++){
            if(G->adj[i][j]!=0){
                edges[k].src=i;
                edges[k].des=j;
                edges[k].weight=G->adj[i][j];
                k++;
            }
        }
    }
    sort(edges,G->E);
    int visited[G->V];
    for(int i=0;i<G->V;i++){
        parent[i]=-1;
        visited[i]=0;
    }
    Distance[0]=0;
    parent[0]=-1;
    visited[0]=1;
    for(int i=0;i<G->E;i++){
        if(!visited[edges[i].des]){
            parent[edges[i].des]=edges[i].src;
            Distance[edges[i].des]=edges[i].weight;
            visited[edges[i].des]=1;
        }
        else if(!visited[edges[i].src]){
            parent[edges[i].src]=edges[i].des;
            Distance[edges[i].src]=edges[i].weight;
            visited[edges[i].src]=1;
        }
    }
}
int main(){
    struct Graph* G=readGraph();
    int Distance[G->V];
    int path[G->V];
    // Prims(G,Distance,path);
    kruskalsAlgo(G,Distance,path);
    for(int i=0;i<G->V;i++){
        printf("%d ",path[i]);
    }
    printf("\n");
    for(int i=0;i<G->V;i++){
        printf("%d ",Distance[i]);
    }
    // PQ* Q = createPQ();
    // PQEnqueue(Q,0,0);
    // printf("%d",DequeuePQ(Q));
}