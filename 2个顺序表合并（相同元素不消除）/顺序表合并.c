#include<stdio.h>
#include<stdlib.h>


  int*Getone(int*x,int*y,int*z,int d1,int d2)//��2��˳���ϲ������������С�
  {
    int r1,r2,r3;
    r1=r2=r3=0;

    while((r1<d1)&&(r2<d2))//ֻҪ2����������һ������������Ԫ�رȽ��꣬�ͽ����˹��̡�
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

    if((r1==d1)&&(r2<d2))//������x������Ԫ�����ȱȽ���ɣ�������y��ʣ���Ԫ�ذ�˳����ڼ���z�м��ɡ�
    {
      while(r2<d2)
      {
        z[r3]=y[r2];
        r3=r3+1;
        r2=r2+1;
      }
    }

    else if((r1<d1)&&(r2==d2))//������y������Ԫ�����ȱȽ���ɣ�������x��ʣ���Ԫ�ذ�˳����ڼ���z�м��ɡ�
    {
       while(r1<d1)
      {
        z[r3]=x[r1];
        r1=r1+1;
        r3=r3+1;
      }
    }

    else//2�����ϱȽ����ʱ��2�����϶���ʣ��Ԫ�ء�
    printf("�Ƚ���ɣ�\n");

    return z;
  }

int main()
{
  int i,w1,w2,w3,*a,*b,*c;

   printf("���뼯��a,b��Ԫ�ظ�����\n");
   scanf("%d%d",&w1,&w2);

   w3=w1+w2;

   a=(int*)calloc(w1,sizeof(int));
   b=(int*)calloc(w2,sizeof(int));
   c=(int*)calloc(w3,sizeof(int));

   printf("���뼯��a�����������������ݣ���\n");
   for(i=0;i<w1;i++)
    scanf("%d",&a[i]);

   printf("���뼯��b�����������������ݣ���\n");
   for(i=0;i<w2;i++)
    scanf("%d",&b[i]);

   c=Getone(a,b,c,w1,w2);


     printf("�������a��\n");
   for(i=0;i<w1;i++)
   printf("%d ",a[i]);
   printf("\n");

    printf("�������b��\n");
   for(i=0;i<w2;i++)
   printf("%d ",b[i]);
   printf("\n");

   printf("����ϲ���ļ��ϣ�\n");
   for(i=0;i<w3;i++)
   printf("%d ",c[i]);
   printf("\n");

   return 0;

}

