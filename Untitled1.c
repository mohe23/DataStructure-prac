#include<stdio.h>
#include<stdlib.h>



int main()
{
  int*a=(int*)calloc(4,sizeof(int));
  int*b=(int*)calloc(4,sizeof(int));
  a[0]=12;
  a[1]=32;
  a[2]=42;
  a[3]=9;

  b=a;
  printf("%d\n",b[0]);
  printf("%d\n",b[1]);
  printf("%d\n",b[2]);
  printf("%d\n",b[3]);

  return 0;
}
