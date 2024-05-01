#include<stdio.h>
#include<stdlib.h>

typedef struct{
   int data;//������
   struct Qnode*next;//ָ����
}Qnode;


typedef struct{
    Qnode*front;//����ָ�롣
    Qnode*rear;//��βָ�롣

}Queue;


Queue*InitQueue(Queue*sq)//��ʼ�����ӣ�����һ���ս����Ϊͷ��㣬����ָ�룬��βָ�붼ָ�����ͷ��㡣
{
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));
  q->data=-1;
  q->next=NULL;
  sq->front=sq->rear=q;//����ָ�����βָ��ָ��ͷ��㡣
  return sq;
}


Queue*EnQueue(Queue*sq,int e)//��e�Ӷ�β���뵽����sq�С�
{
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));//ΪԪ��e����һ���洢�ռ䡣
  q->data=e;
  q->next=NULL;
  sq->rear->next=q;
  sq->rear=q;

  return sq;
}


int DeQueue(Queue*sq)//�Ӷ���ɾ����㣬�����ظý���dataֵ��
{
  int e;
  Qnode*q=(Qnode*)malloc(sizeof(Qnode));
  if(sq->front==sq->rear)//�նӡ�
    printf("����Ϊ�նӣ�\n");
   else//�ǿ����ӡ�
  {
     q=sq->front->next;
     e=q->data;
     sq->front->next=q->next;//ͷ����ָ������ָ����һ����㡣
     if(sq->rear==q)//���ɾ��ʱ������ֻ��1�����ݽ�㣬Ϊ�˲���ʧ��βָ�룬��Ҫ���¸�ֵ��βָ�� ��
        sq->rear=sq->front;//��βָ������ָ��ͷ��㡣

     free(q);
  }

return e;

}


int GetHead(Queue*sq)//ȡ���ӵĶ���Ԫ��ֵ,��ɾ������Ԫ�ء�
{
    int e;
    Qnode*q=(Qnode*)malloc(sizeof(Qnode));
    if(sq->front==sq->rear)//����Ϊ�ա�
       printf("����Ϊ�գ�\n");
    else
    {
      q=sq->front->next;
      e=q->data;
    }

   return e;
}


Queue*CreateQueue(Queue*sq)//�ڳ�ʼ������sq�Ļ����ϣ�����һ�����ӡ�
{
    int i,j=1;
    while(j==1)
    {
       // Qnode*q=(Qnode*)malloc(sizeof(Qnode));
        printf("��������:");
        scanf("%d",&i);
        printf("\n");
        //if(i!=-1)
            sq=EnQueue(sq,i);
        //else
          //  break;

     printf("�Ƿ�������һ��Ԫ�أ����Ҫ���룬��j��Ϊ0������jΪ1������");
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
 sq=InitQueue(sq);//��ʼ������sq��
 sq=CreateQueue(sq);

 q=sq->front->next;
 q1=sq->rear;
 a=q->data;
 b=q1->data;
 printf("a:%d\n",a);
 printf("b:%d\n",b);

 return 0;

}
