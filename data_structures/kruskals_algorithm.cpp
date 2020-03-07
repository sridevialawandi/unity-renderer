#include<stdio.h>
int min,minCost,cost[10][10], parent[10],ne=1,n;

main() {
	int i,j;
	int a,b,u,v;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter cost of Matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("Cost[%d][%d] = ",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0) {
				cost[i][j]=999;
			}
		}
	}
	while(ne<n) {
		for(i=1,min=999;i<=n;i++) {
			for(j=1;j<=n;j++) {
				if(cost[i][j]<min) {
					min = cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
					
		if(parent[u]==0||parent[v]==0) {
			printf("Edge %d(%d,%d) Cost : %d\n",ne++,a,b,min);
			minCost+=min;
			parent[v] = u;
		}
		cost[a][b] = cost[b][a]=999;
	}
	printf("Minimum Cost = %d\n",minCost);
}
