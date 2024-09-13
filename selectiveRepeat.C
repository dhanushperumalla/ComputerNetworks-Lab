#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int i,x;
int input(int a[] , int frame_size)
{
printf("Input \n");
for(i = 1 ; i <= frame_size ; i++)
{
printf(" Enter Value For Frame[%d] : " , i);
scanf("%d",&a[i]);
}

return 0;
}
int display(int a[] , int frame_size)
{
printf("Display");
for(i = 1 ; i <= frame_size ; i++)
{
printf(" Frame[%d] : %d " , i , a[i]);
}
return 0;
}
int selective_repeat(int frames[] , int window_size , int frame_size)
{
int nt =0;
int k = 0;
int left[10000] = {-1};
for(i = 1 ; i <= frame_size ; i++)
{
int flag = rand() % 2;
if(flag)
{
printf(" Frame[%d] with value %d Acknowledged !!! \n\n", i , frames[i]);
nt++;
}
else
{
printf(" Frame[%d] with value %d Not Acknowledged !!! \n\n", i , frames[i]);
left[k++] = frames[i];
nt++;
}
if(i % window_size == 0)
{
for(x = 0 ; x < k ; x++)
{
printf(" Frame[%d] with value %d Retransmitted \n\n", x , left[x]);
nt++;
printf(" Frame[%d] with value %d Acknowledged on Second Attempt \n\n", x, left[x]);
}
k = 0;
}
}
for(i = 0 ; i < k ; i++)
{
printf(" Frame[%d] with value %d Retransmitted \n\n", i , left[i]);
nt++;
printf(" Frame[%d] with value %d Acknowledged on Second Attempt \n\n", i, left[i]);
}
printf(" Total Transmissions : %d \n\n", nt);
return 0;
}
void main()
{
int frames[50];
int window_size;
int frame_size;
clrscr();
printf(" Selective Repeat \n");
printf(" Enter Window Size : ");
scanf("%d",&window_size);
printf(" Enter Number Of Frames To Be Transmitted : ");
scanf("%d",&frame_size);
input(frames , frame_size);
display(frames , frame_size);
selective_repeat(frames , window_size , frame_size);
getch();
}