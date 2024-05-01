#include<stdio.h>
#include<stdlib.h>

typedef struct{
   int data;//数据域
   struct Qnode*next;//指针域。
}Qnode;


typedef struct{
    Qnode*front;//队首指针。
    Qnode*rear;//队尾指针。

}Queue;


Queue*InitQueue(Queue*sq)//初始化链队，生成一个空结点作为头结点，队首指针，队尾指针都指向这个头结点。
{
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));
  q->data=-1;
  q->next=NULL;
  sq->front=sq->rear=q;//队首指针与队尾指针指向头结点。
  return sq;
}


Queue*EnQueue(Queue*sq,int e)//将e从队尾插入到队列sq中。
{
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));//为元素e分配一个存储空间。
  q->data=e;
  q->next=NULL;
  sq->rear->next=q;
  sq->rear=q;

  return sq;
}


int DeQueue(Queue*sq)//从队首删除结点，并返回该结点的data值。
{
  int e;
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));
  if(sq->front==sq->rear)//空队。
    printf("链队为空队！\n");
   else//非空链队。
  {
     q=sq->front->next;
     e=q->data;
     sq->front->next=q->next;//头结点的指针域是指向下一个结点。
     if(sq->rear==q)//如果删除时，队列只有1个数据结点，为了不丢失队尾指针，需要重新赋值队尾指针 。
        sq->rear=sq->front;//队尾指针重新指向头结点。

     free(q);
  }

return e;

}


int GetHead(Queue*sq)//取链队的队首元素值,不删除队首元素。
{
    int e;
    Qnode*q=(Qnode*)malloc(sizeof(Qnode));
    if(sq->front==sq->rear)//链队为空。
       printf("链队为空！\n");
    else
    {
      q=sq->front->next;
      e=q->data;
    }

   return e;
}


Queue*CreateQueue(Queue*sq)//在初始化链队sq的基础上，创建一个链队。
{
    int i,j=1;
    while(j==1)
    {
       // Qnode*q=(Qnode*)malloc(sizeof(Qnode));
        printf("输入数据:");
        scanf("%d",&i);
        printf("\n");
        //if(i!=-1)
            sq=EnQueue(sq,i);
        //else
          //  break;

     printf("是否输入下一个元素（如果要输入，将j置为0；否则，j为1。）：");
     scanf("%d",&j);
     printf("\n");
    }

  return sq;
}



int main()
{
 int a,b,c;
 Queue*sq=(Queue*)malloc(sizeof(Queue));
 Qnode*q=(Qnode*)malloc(sizeof(Qnode));
 Qnode*q1=(Qnode*)malloc(sizeof(Qnode));
 sq=InitQueue(sq);//初始化队列sq。
 sq=CreateQueue(sq);

 q=sq->front->next;
 q1=sq->rear;
 a=q->data;
 b=q1->data;
 printf("a:%d\n",a);
 printf("b:%d\n",b);

 return 0;

}
