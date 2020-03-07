#include<stdio.h>
int ne=1,min,minCost,cost[10][10],n,visited[10];
int main() {
	int i,u,v,j;
	int a,b;
	printf("Enter of vertrices n\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("Cost [%d][%d] = ",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	printf("The edges of spanning tree are :\n");
	visited[1]=1;
	while(ne<n) {
		for(i=1,min=999;i<=n;i++) {
			for(j=1;j<=n;j++) {
				if(cost[i][j]<min) {
					if(visited[i]==0)
						continue;
					else {
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
	if(visited[v] == 0) {
		printf("%d edge(%d,%d)= %d\n",ne++,a,b,min);
		minCost +=min;
		visited[v] = 1;
	}
	cost[a][b] = cost[b][a] = 999;
	}
	printf("Minimum cost = %d\n",minCost);
}
