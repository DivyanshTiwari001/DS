#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Graph{
    int V,E;
    int **adj;
}Graph;

Graph* createGraph(){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    if(!G)return NULL;
    printf("Enter the number of vertices: ");
    scanf("%d",&G->V);
    printf("Enter the number of edges: ");
    scanf("%d",&G->E);
    G->adj=(int **)malloc(sizeof(int)*G->V);
    for(int i=0;i<G->V;i++){
        G->adj[i]=(int *)malloc(sizeof(int)*G->V);
    }
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            G->adj[i][j]=0;
        }
    }
    for(int i=0;i<G->E;i++){
        int u,v,w;
        printf("Reading Edges: ");
        scanf("%d%d",&u,&v);
        printf("Enter the weight: ");
        scanf("%d",&w);
        G->adj[u][v]=w;
    }
    return G;
}
int findMin(int distance[],int Visited[],int n){
    int min=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(Visited[i])continue;
        else if(distance[i]<min){
            min=distance[i];
            index=i;
        }
    }
    if(index ==-1){
       for(int i=0;i<n;i++){if(distance[i]==INT_MAX && !Visited[i])return i;}
}
    return index;
}
int allVisited(int Visited[],int n){
    for(int i=0;i<n;i++){
        if(Visited[i]==0)return 0;
    }
    return 1;
}
void dijkstra(Graph* G,int distance[]){
    int Visited[G->V];
    for(int i=0;i<G->V;i++){
        distance[i]=INT_MAX;
        Visited[i]=0;
    }
    distance[0]=0;
    while(!allVisited(Visited,G->V)){
    int i = findMin(distance,Visited,G->V);
    Visited[i]=1;
    for(int j=0;j<G->V;j++){
        if(G->adj[i][j]!=0 && distance[i]+G->adj[i][j]<distance[j]){
            distance[j]=distance[i]+G->adj[i][j];
        }
    }
    }
}
void printSolution(int dist[],int V)
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}
int main()
{
	Graph* G = createGraph();
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            printf("%d ",G->adj[i][j]);
        }
        printf("\n");
    }
	int distance[G->V];
    dijkstra(G, distance);
    for(int i=0;i<G->V;i++){
        printf("%d ",distance[i]);
    }
    printSolution(distance,G->V);

	return 0;
}
