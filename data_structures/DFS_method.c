#include<stdio.h>
int i,j,v,n,cost[10][10],visited[10], order[12], count=1;
void dfs(int v) {
    int w;
    visited[v] = 1;
    order[count++] = v;
    for(w=1;w<=n;w++) {
        if(cost[v][w]==1 && visited[w]==0) {
            visited[w] = 1;
            printf("%d\n",w);
            dfs(w);
        }
    }
 }
 int main() {
     int flag = 0;
     printf("Enter number of Vertices : ");
     scanf("%d",&n);

     printf("Enter the Adjacency Matrix\n");
     for(i=1;i<=n;i++) {
         for(j=1;j<=n;j++) {
             printf("Enter value for Cost[%d][%d] : ",i,j);
             scanf("%d",&cost[i][j]);
         }
     }
     for(i=1;i<=n;i++)
        visited[i]=0;

    printf("Enter starting vertex : ");
    scanf("%d",&v);
    dfs(v);
    for(i=1;i<=n;i++) {
        if(visited[i]==0) {
            flag=1;
            printf("Disconnected Graph\n");
            break;
        }
    }
    if(flag==0) {
        printf("Connected Graph\n");
    }
 }
