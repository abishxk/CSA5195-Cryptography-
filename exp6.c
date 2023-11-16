//rail fence exp 6

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
 int i,j,len,rails,count,code[100][1000];
    char str[1000];
    printf("Enter the Plain text :");
    gets(str);
    char text[100];
	strcpy(text,str);
    len=strlen(str);
 printf("Enter the Depth :");
 scanf("%d",&rails);
 for(i=0;i<rails;i++)
 {
  for(j=0;j<len;j++)
  {
   code[i][j]=0;
  }
 }
count=0;
j=0;
while(j<len)
{
if(count%2==0)
{
 for(i=0;i<rails;i++)
 {
  code[i][j]=(int)str[j]; 
  j++;
 }
 
}
else
{

 for(i=rails-2;i>0;i--)
 {
  code[i][j]=(int)str[j];
 j++;
 }  
} 

count++;
}
printf("After Encryption :");
for(i=0;i<rails;i++)
{
 for(j=0;j<len;j++)
 {
  if(code[i][j]!=0)
  printf("%c",code[i][j]);
 }
 
}
printf("\n");
printf("After decryption :%s",text);
}
