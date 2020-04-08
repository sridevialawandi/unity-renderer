#include<stdio.h>
int main()
{
	int p[10],pt[10],b[10],t[10],w[10];
	int n,i,j,temp,temp1,temp2;
	float avgw,avgt;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time and priority for process %d\n",i);
		scanf("%d%d",&b[i],&pt[i]);
		p[i]=i;
	}
	for(i=0;i<n;i++)
	{
		printf("i=%d\n",i);
		for(j=i;j<n;j++)
		{
			printf("i=%d,j=%d\n",i,j);
			if(pt[i]>pt[j])
			{
				temp=b[i];
				temp1=p[i];
				temp2=pt[i];
				b[i]=b[j];
				p[i]=p[j];
				pt[i]=pt[j];
				b[j]=temp;
				p[j]=temp1;
				pt[j]=temp2;
			}
		}
	}
	w[0]=0;
	for(i=1;i<n;i++)
	{
		w[i]=w[i-1]+b[i-1];
	}
	for(i=0;i<n;i++)
	{
		t[i]=w[i]+b[i];
	}
	for(i=0;i<n;i++)
	{
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
