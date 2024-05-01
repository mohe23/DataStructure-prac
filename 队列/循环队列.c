#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int*base;//队列存储空间的基地址。
    int front;//队首。
    int rear;//队尾。
}Queue;//循环队列


Queue*InitQueue(Queue*q,int*t)//初始化循环队列。t是数组，q是循环队列。
{
  q->base=t;//为队列q分配一个一定大小的数组。
  if(q->base==NULL)
      printf("队列存储空间分配失败！\n");
  q->front=q->rear=0;
  return q;
}


int LengthQueue(Queue*q,int size)//计算队列的长度（队列中元素的个数），size是队列存储空间数组的大小。
{
  int len,length;
  len=q->rear-q->front+size;
  length=len%size;
  return length;
}


Queue*EnQueue(Queue*q,int size,int e)//将数据e从队尾入队。
{
   int a;
   a=(q->rear+1)%size;
   if(a==q->front)//队满，无法再从队尾入队。
      printf("队已满，无法从队尾插入新的元素！\n");
   else
   {
     *(q->base+q->rear)=e;
     q->rear=a;//新元素e入栈后，要将队尾指针加1。
   }

   return q;
}


int DeQueue(Queue*q,int size)//删除队列q的队首元素，返回其被删除的元素值。
{
    int e;
    if(q->front==q->rear)//队尾“指针”与队首“指针”相同，表示循环队列为空。
        printf("队列为空，从队首删除元素失败！\n");
      else
      {
          e=*(q->base+q->front);//e存放被删除的队列q的队首元素。
          q->front=(q->front+1)%size;
      }
    return e;
}


int GetHead(Queue*q)//取循环队列q的队首元素，不删除队首元素。
{
  int e;
  if(q->front!=q->rear)//队列不空，取队首元素。
        e=*(q->base+q->front);
  else//队列q为空。
  {
    printf("队列为空，无法取队首元素");
  }

  return e;
}


Queue*CreateQueue(Queue*q,int size)//创建一个拥有数据的循环队列。
{
    int i,a;
    for(i=0;i<size-1;i++)//循环队列中数据的数量比实际的存储空间少一个。
    {
        printf("输入数据(int):");
        scanf("%d",&a);
        printf("\n");
        q=EnQueue(q,size,a);
    }

    return q;
}

int main()
{
   int m,n,m1,n1,m2,n2;
 int*a=(int*)calloc(4,sizeof(int));//创建一个大小为4的数组。
 Queue*sq=(Queue*)malloc(sizeof(Queue));
 sq=InitQueue(sq,a);//初始化队列sq。
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
   printf("队首元素1: %d\n",m);
   printf("队首元素2: %d\n",n);

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
