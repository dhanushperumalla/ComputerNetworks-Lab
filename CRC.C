#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
char s[100],p[100],d[30];
int k,len,i;
clrscr();
printf("Enter frame:");
scanf("%s",&s);
printf("Enter gen:");
scanf("%s",&d);
k=strlen(d)-1;
len=strlen(s);
strcpy(p,s);
for(i=len;i<len+k;i++)
p[i]='0';
p[i]='\0';
printf("Msg after appending %d zero bits:\n",k);
puts(p);
while(strlen(p)>k)
{
if(p[0]=='1')
for(i=0;d[i]!='\0';i++)
p[i]=(p[i]-'0')^(d[i]-'0')+'0';
else
for(i=0;p[i]!='\0';i++)
p[i]=p[i+1];
}
strcat(s,p);
puts("Transmitted frame is:\n");
puts(s);
getch();
}