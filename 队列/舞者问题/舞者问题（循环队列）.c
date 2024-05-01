#include<stdio.h>
#include<stdlib.h>

typedef struct{
     char name;//���ߵ�������
     char sex;//���ߵ��Ա𡣡�F����ʾŮ�ԣ���M����ʾ���ԡ�

}Person;//�ṹ������


typedef struct{
     Person*base;//����ַ��
     int front;//���ס�ָ�롱
     int rear;//��β��ָ�롱

}Queue;


Queue*InitQueue(Queue*q,Person*t)//��ʼ��ѭ�����С�t�����飬q��ѭ�����С�
{
  q->base=t;//Ϊ����q����һ��һ����С�����顣
  if(q->base==NULL)
      printf("���д洢�ռ����ʧ�ܣ�\n");
  q->front=q->rear=0;
  return q;
}


Queue*EnQueue(Queue*q,int size,Person*p)//������p�Ӷ�β��ӡ�
{
   int a;
   a=(q->rear+1)%size;
   if(a==q->front)//�������޷��ٴӶ�β��ӡ�
      printf("���������޷��Ӷ�β�����µ�Ԫ�أ�\n");
   else
   {
     q->base[q->rear].name=p->name;
     q->base[q->rear].sex=p->sex;
     q->rear=a;//��Ԫ��e��ջ��Ҫ����βָ���1��
   }

   return q;
}


Person*DeQueue(Queue*q,int size)//ɾ������q�Ķ���Ԫ�أ������䱻ɾ����Ԫ��ֵ��
{
    Person*e=(Person*)malloc(sizeof(Person));
    if(q->front==q->rear)//��β��ָ�롱����ס�ָ�롱��ͬ����ʾѭ������Ϊ�ա�
        printf("����Ϊ�գ��Ӷ���ɾ��Ԫ��ʧ�ܣ�\n");
      else
      {
          e->name=q->base[q->front].name;//e��ű�ɾ���Ķ���q�Ķ���Ԫ�ء�
          e->sex=q->base[q->front].sex;
          q->front=(q->front+1)%size;
      }
    return e;
}


int EmptyQueue(Queue*q)//�ж�ѭ�������Ƿ�Ϊ�գ���Ϊ�գ�����1�����򷵻�0.
{
   int e;
   if(q->front==q->rear)//ѭ�������У��������ָ�����βָ����ͬ�����ʾ�ӿա�
       e=1;
    else
       e=0;

  return e;
}



Queue*CreateQueue(Queue*q,int size)//����һ��ӵ�����ݵ�ѭ�����С�
{
    int i;
    char str;
    char ch;
    for(i=0;i<size;i++)//ѭ�����������ݵ�������ʵ�ʵĴ洢�ռ���һ����
    {
        if(i==size)//��βָ��ָ�����һ���洢�ռ䣬��ʾѭ���������ˡ�
            break;

        Person*p=(Person*)malloc(sizeof(Person));
        printf("��������:");
        scanf("%c",&str);
        scanf("%c",&ch);
        p->name=str;
        p->sex=ch;
        //printf("\n");
        q=EnQueue(q,size,p);
    }

    return q;
}

Person*CreatePerson(Person*p,int size)//����һ��Person���͵����ݸ���Ϊsize�Ľṹ������p��
{
  int i;
  char ca,cb;
  for(i=0;i<(size-1);i++)
  {
    printf("��������(name,sex): ");
    scanf("%c %c",&ca,&cb);
    fflush(stdin);
    //printf("\n");
    //printf("�������ݣ�sex��:");
   // scanf("%c",&cb);
    //printf("\n");
    //printf("\n");
    printf("ca:%c  ",ca);
    printf("cb:%c  ",cb);
    printf("i:%d\n",i);

    p[i].name=ca;
    p[i].sex=cb;
    printf("");

  }

  return p;
}



Person*GetHead(Queue*q)//ȡѭ������q�Ķ���Ԫ�أ���ɾ������Ԫ�ء�
{
  Person*p=(Person*)malloc(sizeof(Person));

  if(q->front!=q->rear)//���в��գ�ȡ����Ԫ�ء�
       {
         p->name=q->base[q->front].name;
         p->sex=q->base[q->front].sex;
       }
  else//����qΪ�ա�
  {
    printf("����Ϊ�գ��޷�ȡ����Ԫ��");
  }

  return p;
}


void TraverseQueue(Queue*q)//��ӡѭ�������еĸ���Ԫ�ص�name��sex�ֶΡ�
{
   Queue*sq=(Queue*)malloc(sizeof(Queue));
   Person*d=(Person*)calloc(5,sizeof(Person));
   //sq=InitQueue(sq,d);
   d=q->base;
   sq->base=d;

   //sq->base=q->base;
   sq->front=q->front;
   sq->rear=q->rear;

   printf("name       sex\n");
   while(sq->front!=sq->rear)//ֻҪѭ�����ж���ָ�벻���ڶ�βָ��
    {
        //printf("11111\n");
        printf(" %c",sq->base[sq->front].name);
        printf("          %c\n",sq->base[sq->front].sex);
        sq->front=sq->front+1;
    }
    printf("\n");
}


void DanceParter(Person*p,int size,Queue*Fq,Queue*Mq)//������⡣size��С�ǽṹ������p�Ĵ�С��
{
   int i,a,b;
   char str;
   char ch;

      // Pe=p;

     // printf("d-11111\n");


   for(i=0;i<size-1;i++)//��������=�ṹ������Ĵ�С-1����Ϊ��ѭ�������л�ճ�һ������ռ䣨Ϊ�������ж�ջ������
    {

      Person*Pe=(Person*)malloc(sizeof(Person));
      Pe->name=p[i].name;
      Pe->sex=p[i].sex;
       ch=Pe->sex;

      if(ch=='F')//����ΪŮ����
         Fq=EnQueue(Fq,size,Pe);//��Ů���߶ӡ�
       else
         Mq=EnQueue(Mq,size,Pe);//�������߶ӡ�

    }

   // printf("d-22222\n");
    TraverseQueue(Fq);
    TraverseQueue(Mq);


    a=EmptyQueue(Fq);
    b=EmptyQueue(Mq);

    printf(" Ů����    ������\n");
    while((a!=1)&&(b!=1))//��2�����ж���Ϊ�ա�
    {
      Person*p1=(Person*)malloc(sizeof(Person));
      Person*p2=(Person*)malloc(sizeof(Person));

      //printf("d-21\n");

      p1=DeQueue(Fq,size);
      p2=DeQueue(Mq,size);

     // printf("d-22\n");

      a=EmptyQueue(Fq);
      b=EmptyQueue(Mq);

      printf("   %c    ",p1->name);
      printf("     %c\n",p2->name);


    }

    printf("\n");


    Person*p3=(Person*)malloc(sizeof(Person));
   if((a==1)&&(b!=1))//Ů���߶��ȿ��ˣ���������߶�ͷ��������
   {
      p3=GetHead(Mq);
      printf("Ů���߶��ѿգ������߶Ӷ���������%c\n",p3->name);

   }

   else if((a!=1)&&(b==1))//�����߶��ȿգ����Ů�������֡�
   {
     p3=GetHead(Fq);
      printf("�����߶��ѿգ�Ů���߶Ӷ���������%c\n",p3->name);
   }

   else//��Ů���������պ���ȡ�
   printf("��Ů����������ȣ�\n");

   //printf("d-4444\n");
}


int main()
{
    Queue*Fdancers=(Queue*)malloc(sizeof(Queue));//Ů���߶���
    Queue*Mdancers=(Queue*)malloc(sizeof(Queue));//�����߶���
    Person*p=(Person*)calloc(5,sizeof(Person));
    Person*s1=(Person*)calloc(5,sizeof(Person));
    Person*s2=(Person*)calloc(5,sizeof(Person));

     Fdancers=InitQueue(Fdancers,s1);
     Mdancers=InitQueue(Mdancers,s2);

     p=CreatePerson(p,5);
    //p[0].name='J';
    //p[0].sex='F';

    //p[1].name='H';
    //p[1].sex='M';

    //p[2].name='S';
    //p[2].sex='F';

    //p[3].name='E';
   // p[3].sex='F';

    //p[4].name='V';
    //p[4].sex='F';

    //printf("q11111\n");


    DanceParter(p,5,Fdancers,Mdancers);

    //printf("222222\n");
    return 0;

}


