#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int*base;//���д洢�ռ�Ļ���ַ��
    int front;//���ס�
    int rear;//��β��
}Queue;//ѭ������


Queue*InitQueue(Queue*q,int*t)//��ʼ��ѭ�����С�t�����飬q��ѭ�����С�
{
  q->base=t;//Ϊ����q����һ��һ����С�����顣
  if(q->base==NULL)
      printf("���д洢�ռ����ʧ�ܣ�\n");
  q->front=q->rear=0;
  return q;
}


int LengthQueue(Queue*q,int size)//������еĳ��ȣ�������Ԫ�صĸ�������size�Ƕ��д洢�ռ�����Ĵ�С��
{
  int len,length;
  len=q->rear-q->front+size;
  length=len%size;
  return length;
}


Queue*EnQueue(Queue*q,int size,int e)//������e�Ӷ�β��ӡ�
{
   int a;
   a=(q->rear+1)%size;
   if(a==q->front)//�������޷��ٴӶ�β��ӡ�
      printf("���������޷��Ӷ�β�����µ�Ԫ�أ�\n");
   else
   {
     *(q->base+q->rear)=e;
     q->rear=a;//��Ԫ��e��ջ��Ҫ����βָ���1��
   }

   return q;
}


int DeQueue(Queue*q,int size)//ɾ������q�Ķ���Ԫ�أ������䱻ɾ����Ԫ��ֵ��
{
    int e;
    if(q->front==q->rear)//��β��ָ�롱����ס�ָ�롱��ͬ����ʾѭ������Ϊ�ա�
        printf("����Ϊ�գ��Ӷ���ɾ��Ԫ��ʧ�ܣ�\n");
      else
      {
          e=*(q->base+q->front);//e��ű�ɾ���Ķ���q�Ķ���Ԫ�ء�
          q->front=(q->front+1)%size;
      }
    return e;
}


int GetHead(Queue*q)//ȡѭ������q�Ķ���Ԫ�أ���ɾ������Ԫ�ء�
{
  int e;
  if(q->front!=q->rear)//���в��գ�ȡ����Ԫ�ء�
        e=*(q->base+q->front);
  else//����qΪ�ա�
  {
    printf("����Ϊ�գ��޷�ȡ����Ԫ��");
  }

  return e;
}


Queue*CreateQueue(Queue*q,int size)//����һ��ӵ�����ݵ�ѭ�����С�
{
    int i,a;
    for(i=0;i<size-1;i++)//ѭ�����������ݵ�������ʵ�ʵĴ洢�ռ���һ����
    {
        printf("��������(int):");
        scanf("%d",&a);
        printf("\n");
        q=EnQueue(q,size,a);
    }

    return q;
}

int main()
{
   int m,n,m1,n1,m2,n2;
 int*a=(int*)calloc(4,sizeof(int));//����һ����СΪ4�����顣
 Queue*sq=(Queue*)malloc(sizeof(Queue));
 sq=InitQueue(sq,a);//��ʼ������sq��
 sq=CreateQueue(sq,4);
   //m1=sq->front;
   //n1=sq->rear;
   //printf("front: %d\n",m1);
   //printf("rear: %d\n",n1);

   //sq=EnQueue(sq,4,23);

   //sq=EnQueue(sq,4,56);

   m1=sq->front;
   n1=sq->rear;
   printf("front: %d\n",m1);
   printf("rear: %d\n",n1);

   m2=GetHead(sq);
   //m=DeQueue(sq,4);
   n2=GetHead(sq);
   //n=DeQueue(sq,4);

   m=sq->front;
   n=sq->rear;
   printf("����Ԫ��1: %d\n",m);
   printf("����Ԫ��2: %d\n",n);

   m1=sq->front;
   n1=sq->rear;
   printf("front: %d\n",m1);
   printf("rear: %d\n",n1);

   printf("%d\n",m2);
   printf("%d\n",n2);
   m2=*(sq->base+sq->rear-1);
   printf("%d\n",m2);
   return 0;

}
