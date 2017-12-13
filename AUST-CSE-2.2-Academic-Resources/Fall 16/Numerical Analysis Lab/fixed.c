#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define E 0.00001
#define g(x) 2-x*x

int main()
{
 float x1,x2,e;
 int c=1;
 int i ;

 printf("Enter the initial guess : ");
 scanf("%f",&x1);
 printf("Maximum iteration: ");
 scanf("%d",&i);

 do{
      x2=  g(x1);
 e=fabs(((x2-x1)/x2));
 if(i==0)
    break;
  //if(e>E)
  //{
   printf("iteration: %d    The root is %f    error %f\n",c,x2,e);
   //if(i==0)
    //break;

  //}
 // else
      //{
    x1=x2;

   //}
   c++;


 }while(e>=E&& c<i);
 printf("Root is %f",x1);
  return(0);
}
