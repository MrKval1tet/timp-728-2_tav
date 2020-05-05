#include <stdio.h>
int main()
{
   int n,i,x;
   double sum=0;
   i=1;
   sum=0;
   (void)scanf("%d", &n);
   while (i <=n)
    {
      (void)scanf("%d", &x);  
      sum =sum+(x*x);
      i++; 
    }
   printf("%lf\n", sum);
   return 0;
}
