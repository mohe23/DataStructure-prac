#include<stdio.h>
#include<stdlib.h>

typedef struct{
     char name;//舞者的姓名。
     char sex;//舞者的性别。“F”表示女性，“M”表示男性。

}Person;//结构体数组


typedef struct{
     Person*base;//基地址。
     int front;//队首“指针”
     int rear;//队尾“指针”

}Queue;


Queue*InitQueue(Queue*q,Person*t)//初始化循环队列。t是数组，q是循环队列。
{
  q->base=t;//为队列q分配一个一定大小的数组。
  if(q->base==NULL)
      printf("队列存储空间分配失败！\n");
  q->front=q->rear=0;
  return q;
}


Queue*EnQueue(Queue*q,int size,Person*p)//将舞者p从队尾入队。
{
   int a;
   a=(q->rear+1)%size;
   if(a==q->front)//队满，无法再从队尾入队。
      printf("队已满，无法从队尾插入新的元素！\n");
   else
   {
     q->base[q->rear].name=p->name;
     q->base[q->rear].sex=p->sex;
     q->rear=a;//新元素e入栈后，要将队尾指针加1。
   }

   return q;
}


Person*DeQueue(Queue*q,int size)//删除队列q的队首元素，返回其被删除的元素值。
{
    Person*e=(Person*)malloc(sizeof(Person));
    if(q->front==q->rear)//队尾“指针”与队首“指针”相同，表示循环队列为空。
        printf("队列为空，从队首删除元素失败！\n");
      else
      {
          e->name=q->base[q->front].name;//e存放被删除的队列q的队首元素。
          e->sex=q->base[q->front].sex;
          q->front=(q->front+1)%size;
      }
    return e;
}


int EmptyQueue(Queue*q)//判断循环队列是否为空，若为空，返回1；否则返回0.
{
   int e;
   if(q->front==q->rear)//循环队列中，如果队首指针与队尾指针相同，则表示队空。
       e=1;
    else
       e=0;

  return e;
}



Queue*CreateQueue(Queue*q,int size)//创建一个拥有数据的循环队列。
{
    int i;
    char str;
    char ch;
    for(i=0;i<size;i++)//循环队列中数据的数量比实际的存储空间少一个。
    {
        if(i==size)//队尾指针指向最后一个存储空间，表示循环队列满了。
            break;

        Person*p=(Person*)malloc(sizeof(Person));
        printf("输入数据:");
        scanf("%c",&str);
        scanf("%c",&ch);
        p->name=str;
        p->sex=ch;
        //printf("\n");
        q=EnQueue(q,size,p);
    }

    return q;
}

Person*CreatePerson(Person*p,int size)//创建一个Person类型的数据个数为size的结构体数组p。
{
  int i;
  char ca,cb;
  for(i=0;i<(size-1);i++)
  {
    printf("输入数据(name,sex): ");
    scanf("%c %c",&ca,&cb);
    fflush(stdin);
    //printf("\n");
    //printf("输入数据（sex）:");
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



Person*GetHead(Queue*q)//取循环队列q的队首元素，不删除队首元素。
{
  Person*p=(Person*)malloc(sizeof(Person));

  if(q->front!=q->rear)//队列不空，取队首元素。
       {
         p->name=q->base[q->front].name;
         p->sex=q->base[q->front].sex;
       }
  else//队列q为空。
  {
    printf("队列为空，无法取队首元素");
  }

  return p;
}


void TraverseQueue(Queue*q)//打印循环队列中的各个元素的name与sex字段。
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
   while(sq->front!=sq->rear)//只要循环队列队首指针不等于队尾指针
    {
        //printf("11111\n");
        printf(" %c",sq->base[sq->front].name);
        printf("          %c\n",sq->base[sq->front].sex);
        sq->front=sq->front+1;
    }
    printf("\n");
}


void DanceParter(Person*p,int size,Queue*Fq,Queue*Mq)//舞伴问题。size大小是结构体数组p的大小。
{
   int i,a,b;
   char str;
   char ch;

      // Pe=p;

     // printf("d-11111\n");


   for(i=0;i<size-1;i++)//舞者数量=结构体数组的大小-1，因为在循环队列中会空出一个储存空间（为了利于判断栈满）。
    {

      Person*Pe=(Person*)malloc(sizeof(Person));
      Pe->name=p[i].name;
      Pe->sex=p[i].sex;
       ch=Pe->sex;

      if(ch=='F')//舞者为女舞者
         Fq=EnQueue(Fq,size,Pe);//入女舞者队。
       else
         Mq=EnQueue(Mq,size,Pe);//入男舞者队。

    }

   // printf("d-22222\n");
    TraverseQueue(Fq);
    TraverseQueue(Mq);


    a=EmptyQueue(Fq);
    b=EmptyQueue(Mq);

    printf(" 女舞者    男舞者\n");
    while((a!=1)&&(b!=1))//当2个队列都不为空。
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
   if((a==1)&&(b!=1))//女舞者队先空了，输出男舞者队头的姓名。
   {
      p3=GetHead(Mq);
      printf("女舞者队已空，男舞者队队首姓名：%c\n",p3->name);

   }

   else if((a!=1)&&(b==1))//男舞者队先空，输出女舞者名字。
   {
     p3=GetHead(Fq);
      printf("男舞者队已空，女舞者队队首姓名：%c\n",p3->name);
   }

   else//男女舞者数量刚好相等。
   printf("男女舞者人数相等！\n");

   //printf("d-4444\n");
}


int main()
{
    Queue*Fdancers=(Queue*)malloc(sizeof(Queue));//女舞者队列
    Queue*Mdancers=(Queue*)malloc(sizeof(Queue));//男舞者队列
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


