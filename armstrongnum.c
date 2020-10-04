#include<stdio.h>
#include<conio.h>

int main(){

int x,y,sum=0,temp;

printf("Enter the number:");
scanf("%d",&x);
while(x>0){
 y=x%10;
 sum=sum+(y*y*y);
 x=x/10;
}
if(temp==sum)

 printf("Armstrong number");

else

 printf("not an Armstrong number");

return 0;
}
