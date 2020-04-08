#include<stdio.h>
int main()
{
	int p[10],b[10],t[10],w[10];
	int n,i,j,temp,temp1;
	float avgw,avgt;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time for process %d\n",i);
		scanf("%d",&b[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(b[i]>b[j]){
				temp=b[i];
				temp1=p[i];
				b[i]=b[j];
				p[i]=p[j];
				b[j]=temp;
				p[j]=temp1;
			}
		}
	}
	w[0]=0;
	for(i=1;i<n;i++){
		w[i]=w[i-1]+b[i-1];
	}
	for(i=0;i<n;i++){
		t[i]=w[i]+b[i];
	}
	for(i=0;i<n;i++){
		avgw+=w[i];
		avgt+=t[i];
	}
	printf("Total Waiting Time=%f\n",avgw);
	avgw/=n;
	printf("Average Waiting Time=%f\n",avgw);
	printf("Total Turn Around Time=%f\n",avgt);
	avgt/=n;
	printf("Average Turn Around Time=%f\n",avgt);
}
