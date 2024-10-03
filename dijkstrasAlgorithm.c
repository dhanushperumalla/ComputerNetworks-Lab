#include<stdio.h>
#include<stdlib.h>
int main()
{
	int graph[15][15],s[15],pathestimate[15],mark[15];
	int num_of_vertices,source,target,i,j,u,predecessor[15];
	int count=0;
	int minimum(int a[],int m[],int k);
	void printpath(int,int,int[]);
	printf("Enter the no.of vertices:");
	scanf("%d",&num_of_vertices);
	if(num_of_vertices<=0)
	{
		printf("\nThis is meaningless\n");
		exit(1);
	}
	printf("ENTER ADJACENT MATRIX\n");
	for(i=1;i<=num_of_vertices;i++)
	{
			for(j=1;j<=num_of_vertices;j++)
			scanf("%d",&graph[i][j]);
	}
	printf("Enter the source vertex:");
	scanf("%d",&source);
	printf("Enter the target vertex:");
	scanf("%d",&target);
	for(j=1;j<=num_of_vertices;j++)
	{
		mark[j]=0;
		pathestimate[j]=999;
		predecessor[j]=0;
	}
	pathestimate[source]=0;
	while(count<num_of_vertices)
	{
		u=minimum(pathestimate,mark,num_of_vertices);
		s[++count]=u;
		mark[u]=1;
		for(i=1;i<=num_of_vertices;i++)
		{
			if(graph[u][i]>0)
			{
				if(mark[i]!=1)
				{
					if(pathestimate[i]>pathestimate[u]+graph[u][i])
					{
						pathestimate[i]=pathestimate[u]+graph[u][i];
						predecessor[i]=u;
					}
				}
			}
		}
	}
	printf("The shortest path from %d to %d is:\n",source,target);
	printpath(source,target,predecessor);
	if(pathestimate[i]!=999)
		printf("->(%d)\n",pathestimate[target]);
}

int minimum(int a[],int m[],int k)
{
	int mi=999;
	int i,t;
	for(i=1;i<=k;i++)
	{
		if(m[i]!=1)
		{
			if(mi>=a[i])
			{
				mi=a[i];
				t=i;
			}
		}
	}
	return t;
}

void printpath(int x,int i,int p[])
{
		if(i==x)
	{
		printf("%d",x);
	}
	else if(p[i]==0)
		printf("No path from %d to %d",x,i);
	else
	{
		printpath(x,p[i],p);
		printf("...%d",i);
	}
}
