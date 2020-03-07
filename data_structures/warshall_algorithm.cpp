#include<stdio.h>
const int MAX = 100;
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert);
int main(void)
{
    int i, j, numVert;
    int graph[MAX][MAX];
    printf("Warshall's Transitive Closure\n");
    printf("Enter the number of vertices : ");
    scanf("%d",&numVert);
    printf("Enter the adjacency matrix :-\n");
    for (i=1; i<=numVert; i++)
        for (j=1; j<=numVert; j++) {
        	printf("Enter value for co-ordinate (%d,%d) : ",i,j);
            scanf("%d",&graph[i][j]);
        }
    WarshallTransitiveClosure(graph, numVert);
    printf("\nThe transitive closure for the given graph is :-\n");
    for (i=1; i<=numVert; i++) {
        for (j=1; j<=numVert; j++) {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert) {
    int i,j,k;
    for (k=1; k<=numVert; k++) {
        for (i=1; i<=numVert; i++) {
            for (j=1; j<=numVert; j++) {
                if (graph[i][j] || (graph[i][k] && graph[k][j]))
                    graph[i][j] = 1;
            }
        }
    }
}
