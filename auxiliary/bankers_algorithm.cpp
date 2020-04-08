#include<stdio.h>
struct process{
	int max[10],alloc[10],need[10];
}p[6];
int avail[10],n,r,safe[10];
void getdata();
void banker();
main(){
	getdata();
	banker();
}
void getdata(){
	int i,j;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	printf("Enter the number of resources\n");
	scanf("%d",&r);
	printf("Enter the already allocated resources\n");
	for(i=0;i<n;i++){
		printf("Process p %d\n",i);
		for(j=0;j<r;j++)
		scanf("%d",&p[i].alloc[j]);
	}
	printf("Enter Maximum of each process\n");
	for(i=0;i<n;i++){
		printf("Process p %d\n",i);
		for(j=0;j<r;j++)
		scanf("%d",&p[i].max[j]);
	}
	printf("Enter the current available resources\n");
	for(i=0;i<r;i++)
	scanf("%d",&avail[i]);
	printf("Need Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<r;j++){
			p[i].need[j]=p[i].max[j]-p[i].alloc[j];
			printf("%d\t",p[i].need[j]);
		}
		printf("\n");
	}
}
void banker(){
	int flag,c=0,finish[10],i,j,f,s;
	for(i=0;i<n;i++)
	finish[i]=0;
	do{
		f=0;
		for(i=0;i<n;i++){
			for(j=0;j<r;j++){
				flag=0;
				if(p[i].need[j]>avail[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0 && finish[i]==0){
				f=1;
				printf("After process p %d Available Resources,",i);
				for(j=0;j<r;j++){
					p[i].need[j]=0;
					avail[j]=p[i].alloc[j]+avail[j];
					printf("%d\t",avail[j]);
				}
				printf("\n");
				safe[c++]=i;
				finish[i]=1;
			}
		}
		if(f==0)
		break;
	}while(f==1);
	s=1;
	for(i=0;i<n;i++)
	if(finish[i]==0){
		printf("Cannot Allocate Requested Resources for Process %d",i);
		s=0;
		break;
	}
	if(s!=0){
		printf("--Safe State--\n");
		printf("Safe Sequence\n");
		for(i=0;i<c;i++)
		printf("p %d \t",safe[i]);
		printf("/n");
	}
	else
	printf("--Unsafe State--\n");
}
