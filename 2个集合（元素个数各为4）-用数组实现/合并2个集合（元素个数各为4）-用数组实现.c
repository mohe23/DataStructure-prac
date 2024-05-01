#include<stdio.h>
#include<stdlib.h>

  int Pan(int*d,int l,int e)//判断整数e是否在集合d中（若在，返回0；不在，返回1）
  {
     int i,v,t=1;//t是返回值，代表判断结果。
	 for(i=0;i<l;i++)//l是集合d中的元素个数。
	 {
	    v=d[i]-e;
	    if(v==0)//如果d集合中一个元素值等于e,跳出循环，返回值为0。
		{
			t=0;
			break;
		}

	 }

	 return t;
  }

 int Notsum(int*m,int*s,int k1,int k2)//统计集合s中不被包含在集合m中的元素个数。k1,k2分别是集合m,s的元素个数。
 {
   int i,key,sum=0;

   for(i=0;i<k2;i++)
   {
      key=Pan(m,k1,s[i]);

      if(key==1)//当前处理元素不被包括在集合m中，则sum加1.
        sum=sum+1;
      else      //当前处理元素被包括在集合m中，则sum不变.
        sum=sum;

   }

   return sum;

 }

  int*Tone(int*s,int*h,int*k,int p1,int p2)//获得2个集合合并后的大集合。p1,p2分别是集合s,h的元素个数。
  {
        int i,j,p;
        int z=0;

        for(i=0;i<p1;i++)//先将其中一个集合的元素放入到大集合中。
		  k[i]=s[i];

        for(j=0;j<p2;j++)
        {
           p=Pan(s,p1,h[j]);
            if(p==1)//若另一个集合中某个元素值不在前一个集合中，则把该元素放入到合并的集合中。合并后集合的元素个数加一。
            {
              k[p1+z]=h[j];
              z=z+1;
            }

           else//当前处理元素已经在集合中，则当前集合数目不变，继续处理下一个元素。

            z=z;
        }

    return k;
  }





int main()
{
  int i,de,dr,dr1,dr2,*a,*b,*c;

   printf("输入集合a,集合b的元素个数： \n");
   scanf("%d%d",&dr1,&dr2);//输入时，每输入一个后敲“enter”键。
   printf("\n");


  a=(int*)calloc(dr1,sizeof(int));
  b=(int*)calloc(dr2,sizeof(int));

  printf("输入集合a的元素：\n");
  for(i=0;i<dr1;i++)
    scanf("%3d",&a[i]);
  printf("\n");

  printf("输入集合b的元素：\n");
  for(i=0;i<dr2;i++)
    scanf("%3d",&b[i]);
  printf("\n");


  de=Notsum(a,b,dr1,dr2);
  //printf("多的元素数：");
  //printf("%d\n",de);
  dr=dr1+de;//合并集合所需要的元素个数。
  c=(int*)calloc(dr,sizeof(int));//创建一个拥有8个元素的动态数组

  c=Tone(a,b,c,dr1,dr2);

  printf("数组a:\n");
  for(i=0;i<dr1;i++)
   printf("%d  ",a[i]);
   printf("\n");

   printf("数组b:\n");
   for(i=0;i<dr2;i++)
   printf("%d  ",b[i]);
   printf("\n");

   printf("数组c:\n");
  for(i=0;i<dr;i++)
   printf("%d  ",c[i]);
   printf("\n");

   return 0;

}
