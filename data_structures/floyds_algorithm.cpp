#include<stdio.h>
int minimum(int a, int b);
int main() {
	int n,i,j,min,ar[10][10],k;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	printf("Enter cost matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("Enter Cost[%d][%d] : ",i,j);
			scanf("%d",&ar[i][j]);
		}
	}
	for(k=1;k<=n;k++) {
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++) {
				min = minimum(ar[i][j],ar[i][k]+ar[k][j]);
				ar[i][j]=min;
			}
		}
	}
	printf("Final Matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			printf("%d\t",ar[i][j]);
		}
		printf("\n");
	}
	
}
int minimum(int a,int b) {
	if(a<b)
		return a;
	else
		return b;
}
