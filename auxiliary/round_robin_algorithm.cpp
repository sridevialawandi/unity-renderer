#include<stdio.h>
#include<stdlib.h>
typedef struct rr{
	int pid,bt,tat,wt,bt_bal;
}RR;
int main(){
	RR p[10];
	int i,j,n,tq;
	int sum_bt=0,sum_wt=0,sum_tat=0,tq_used=0;
	printf("Enter the number of process\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time of processes%d:\t",i+1);
		p[i].pid=i+1;
		scanf("%d",&p[i].bt);
		p[i].bt_bal=p[i].bt;
	}
	printf("Enter the time quantum number\n");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	sum_bt+=p[i].bt;
	printf("Sum of Burst time=%d\n",sum_bt);
	do {
		for(i=0;i<n;i++)
		if(p[i].bt_bal>0 &&p[i].bt_bal<=tq)	{
			tq_used+=p[i].bt_bal;
			p[i].tat=tq_used;
			p[i].wt=p[i].tat-p[i].bt;
			p[i].bt_bal=0;
		}
		else if(p[i].bt_bal>0){
			tq_used+=tq;
			p[i].bt_bal-=tq;
		}
		else if(p[i].bt_bal<0)
		{
			printf("Error:Burst time is negative\n");
			exit(1);
		}
	}
	while(tq_used!=sum_bt);
	for(i=0;i<n;i++)
	sum_wt+=p[i].wt;
	for(i=0;i<n;i++)
	sum_tat+=p[i].tat;
	printf("Total waiting time=%d\n",sum_wt);
	printf("Average waiting time=%2f\n",(float)sum_wt/n);
	printf("Total turn around time=%d\n",sum_tat);
	printf("Average turn around time=%2f\n",(float)sum_tat/n);	
}
