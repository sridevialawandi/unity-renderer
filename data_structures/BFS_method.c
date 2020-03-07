#include<stdio.h>
int cost[10][10],n,source,q[10],f,r,s[10];
void bfs() {   
    int i,j,u,v;
	for(i=1;i<=n;i++)
		s[i]=0;
	f=r=0;
	q[r]=source;
	s[source]=1;
	while(f<=r) {
		u=q[f++];
		for(v=1;v<=n;v++) {
			if(cost[u][v]==1 && s[v]==0) {
				s[v]=1;
				q[++r]=v;

			}
		}
	}
}
void main() {   
    int i,j;
	printf("\nEnter no of vertices : ");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++){
            printf("Enter value for Cost[%d][%d] : ",i,j);   
			scanf("%d",&cost[i][j]);
        }
    }	
    printf("\nEnter the source : ");
	scanf("%d",&source);
    bfs();
	for(i=1;i<=n;i++) {
		if(s[i]==0)
			printf("Vertex %d not reachable\n",i);
		else
			printf("Vertex %d reachable\n",i);
	}
	for(i=0;i<n;i++)
		printf("%d\t",q[i]);
}
