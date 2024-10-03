#include<stdio.h>
#define e 10000
#define nodes1 40
int topology[nodes1][nodes1];
static int l,n,neighb,nodes;
static char neigh[nodes1];
struct
{
   char name;
     int delay;
   }dv[nodes1];
void main()
{
   int i,j,k[nodes1 *nodes1],add=0,src1;
   char src='a';

printf("----------------DISTANCE VECTOR ROUTING-----------------\n");
printf("");
printf("\n Enter no.of nodes:");
scanf("%d",&nodes);
fflush(stdin);
printf("Enter the node for which distance vector table is needed:");
scanf("%c",&src);
fflush(stdin);
printf("Enter the no.of neighbours to %c:",src);
scanf("%d",&neighb);
fflush(stdin);
printf("Enter the names of the neighbours(in alphabetical order):\n");
neigh[0]=src;
for(i=1;i<neighb+1;i++)
{
  scanf("%c",&neigh[i]);
  fflush(stdin);
}
printf("Enter the distance vectors of the source and the neighbouring nodes\n");
printf("starting with source,then with neighbouring nodes in alphabetical order:\n");
for(i=0;i<nodes*(neighb+1);i++)
{
  scanf("%d",&k[i]);
  }
  src1=src;
  l=nodes;n=1;
  for(i=0;i<nodes;i++)
  {
    if(i==src1-97)
    {
      for(j=0;j<nodes;j++)
      {
	if(k[j]<0)
	   topology[i][j]=e;
	else
	 topology[i][j]=k[j];
	}
	}
	else if(i==neigh[n]-97)
	{
	  for(j=0;j<nodes;j++)
	  {
	    if(k[l]<0)
	    topology[i][j]=e;
	    else
	    topology[i][j]=k[l];
	    l++;
	    }n++;
	    }
	    else
	    {
	      for(j=0;j<nodes;j++)
		topology[i][j]=e;
		}
		}
		i=src1-97;
		for(j=0;j<nodes;j++)
		{
		   dv[j].name=src1;
		   dv[j].delay=topology[i][j];
		}
		k[nodes *nodes]=e;
		n=1;
		for(i=0;i<nodes;i++)
		{
		  if((i==neigh[n]-97))
		  {
		    add=topology[src1-97][i];
		    for(j=0;j<nodes;j++)
		    {
		      k[j]=add+topology[i][j];
		      }
		      for(j=0;j<nodes;j++)
		      {
			if(k[j]<dv[j].delay)
			{
			   dv[j].name=i+97;
			     dv[j].delay=k[j];
			     }
			     }
			     if(i!=src1-97)
			     n++;
			     printf("\n %c's distance vector after receiving %c's vector:\n",src1,i+97);
			     for(j=0;j<nodes;j++)
			     printf("to %c:\t from:%c\t %d\n",j+97,dv[j].name,dv[j].delay);

			     }
			     }
			     }
