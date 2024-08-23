#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
void main()
{
int j,nf,N;
int tr=0;
clrscr();
srand(time(NULL));

printf("Enter the number of frames : ");
scanf("%d",&nf);
printf("Enter the Window Size : ");
scanf("%d",&N);
int i=1;
while(i<=nf)
{
int x=0;
for(j=i;j<i+N && j<=nf;j++)
{
printf("Sent Frame %d \n", j);
tr++;
}
for(j=i;j<i+N && j<=nf;j++)
{
int flag = rand()%2;
if(!flag)
{
printf("%d : Acknowledged! \n", j);
x++;
}
else
{
printf("Frame %d Not Received \n", j);
printf("Retransmitting Window \n");
break;
}
}
printf("\n");
i+=x;
}
printf("Total number of transmissions : %d \n", tr);
getch();
}