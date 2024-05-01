#include<stdio.h>
#include<stdlib.h>


  int*Getone(int*x,int*y,int*z,int d1,int d2)//将2个顺序表合并按照升序排列。
  {
    int r1,r2,r3;
    r1=r2=r3=0;

    while((r1<d1)&&(r2<d2))//只要2个集合中有一个集合中所有元素比较完，就结束此过程。
    {
      if(x[r1]<=y[r2])
       {
          z[r3]=x[r1];
          r1=r1+1;
          r2=r2;
       }
      else
      {
        z[r3]=y[r2];
        r1=r1;
        r2=r2+1;
      }

      r3=r3+1;
    }

    if((r1==d1)&&(r2<d2))//当集合x的所有元素首先比较完成，将集合y中剩余的元素按顺序放在集合z中即可。
    {
      while(r2<d2)
      {
        z[r3]=y[r2];
        r3=r3+1;
        r2=r2+1;
      }
    }

    else if((r1<d1)&&(r2==d2))//当集合y的所有元素首先比较完成，将集合x中剩余的元素按顺序放在集合z中即可。
    {
       while(r1<d1)
      {
        z[r3]=x[r1];
        r1=r1+1;
        r3=r3+1;
      }
    }

    else//2个集合比较完成时，2个集合都不剩余元素。
    printf("比较完成！\n");

    return z;
  }

int main()
{
  int i,w1,w2,w3,*a,*b,*c;

   printf("输入集合a,b的元素个数：\n");
   scanf("%d%d",&w1,&w2);

   w3=w1+w2;

   a=(int*)calloc(w1,sizeof(int));
   b=(int*)calloc(w2,sizeof(int));
   c=(int*)calloc(w3,sizeof(int));

   printf("输入集合a（按照升序输入数据）：\n");
   for(i=0;i<w1;i++)
    scanf("%d",&a[i]);

   printf("输入集合b（按照升序输入数据）：\n");
   for(i=0;i<w2;i++)
    scanf("%d",&b[i]);

   c=Getone(a,b,c,w1,w2);


     printf("输出集合a：\n");
   for(i=0;i<w1;i++)
   printf("%d ",a[i]);
   printf("\n");

    printf("输出集合b：\n");
   for(i=0;i<w2;i++)
   printf("%d ",b[i]);
   printf("\n");

   printf("输出合并后的集合：\n");
   for(i=0;i<w3;i++)
   printf("%d ",c[i]);
   printf("\n");

   return 0;

}

