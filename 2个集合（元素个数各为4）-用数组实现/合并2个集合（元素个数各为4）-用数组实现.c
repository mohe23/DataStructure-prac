#include<stdio.h>
#include<stdlib.h>

  int Pan(int*d,int l,int e)//�ж�����e�Ƿ��ڼ���d�У����ڣ�����0�����ڣ�����1��
  {
     int i,v,t=1;//t�Ƿ���ֵ�������жϽ����
	 for(i=0;i<l;i++)//l�Ǽ���d�е�Ԫ�ظ�����
	 {
	    v=d[i]-e;
	    if(v==0)//���d������һ��Ԫ��ֵ����e,����ѭ��������ֵΪ0��
		{
			t=0;
			break;
		}

	 }

	 return t;
  }

 int Notsum(int*m,int*s,int k1,int k2)//ͳ�Ƽ���s�в��������ڼ���m�е�Ԫ�ظ�����k1,k2�ֱ��Ǽ���m,s��Ԫ�ظ�����
 {
   int i,key,sum=0;

   for(i=0;i<k2;i++)
   {
      key=Pan(m,k1,s[i]);

      if(key==1)//��ǰ����Ԫ�ز��������ڼ���m�У���sum��1.
        sum=sum+1;
      else      //��ǰ����Ԫ�ر������ڼ���m�У���sum����.
        sum=sum;

   }

   return sum;

 }

  int*Tone(int*s,int*h,int*k,int p1,int p2)//���2�����Ϻϲ���Ĵ󼯺ϡ�p1,p2�ֱ��Ǽ���s,h��Ԫ�ظ�����
  {
        int i,j,p;
        int z=0;

        for(i=0;i<p1;i++)//�Ƚ�����һ�����ϵ�Ԫ�ط��뵽�󼯺��С�
		  k[i]=s[i];

        for(j=0;j<p2;j++)
        {
           p=Pan(s,p1,h[j]);
            if(p==1)//����һ��������ĳ��Ԫ��ֵ����ǰһ�������У���Ѹ�Ԫ�ط��뵽�ϲ��ļ����С��ϲ��󼯺ϵ�Ԫ�ظ�����һ��
            {
              k[p1+z]=h[j];
              z=z+1;
            }

           else//��ǰ����Ԫ���Ѿ��ڼ����У���ǰ������Ŀ���䣬����������һ��Ԫ�ء�

            z=z;
        }

    return k;
  }





int main()
{
  int i,de,dr,dr1,dr2,*a,*b,*c;

   printf("���뼯��a,����b��Ԫ�ظ����� \n");
   scanf("%d%d",&dr1,&dr2);//����ʱ��ÿ����һ�����á�enter������
   printf("\n");


  a=(int*)calloc(dr1,sizeof(int));
  b=(int*)calloc(dr2,sizeof(int));

  printf("���뼯��a��Ԫ�أ�\n");
  for(i=0;i<dr1;i++)
    scanf("%3d",&a[i]);
  printf("\n");

  printf("���뼯��b��Ԫ�أ�\n");
  for(i=0;i<dr2;i++)
    scanf("%3d",&b[i]);
  printf("\n");


  de=Notsum(a,b,dr1,dr2);
  //printf("���Ԫ������");
  //printf("%d\n",de);
  dr=dr1+de;//�ϲ���������Ҫ��Ԫ�ظ�����
  c=(int*)calloc(dr,sizeof(int));//����һ��ӵ��8��Ԫ�صĶ�̬����

  c=Tone(a,b,c,dr1,dr2);

  printf("����a:\n");
  for(i=0;i<dr1;i++)
   printf("%d  ",a[i]);
   printf("\n");

   printf("����b:\n");
   for(i=0;i<dr2;i++)
   printf("%d  ",b[i]);
   printf("\n");

   printf("����c:\n");
  for(i=0;i<dr;i++)
   printf("%d  ",c[i]);
   printf("\n");

   return 0;

}
