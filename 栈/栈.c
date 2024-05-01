#include<stdio.h>
#include<stdlib.h>

typedef struct{
      int *top;//ջ��ָ�롣
      int *base;//ջ��ָ�롣
      int size;//ջ�����������
}Stack;

Stack*InitStack(Stack*s,int*array,int l)//��ʼ��ջs��
{

   s->base=array;
   s->top=s->base;
   s->size=l;

   return s;
}


Stack*Push(Stack*s,int e)//������e��ջ��
{
   int length;
   length=s->top-s->base;


    if(length>=s->size)
        printf("ջ����,��ǰԪ���޷���ջ!\n");
    else
    {
        *(s->top)=e;
        s->top=s->top+1;
    }

    return s;
}


int Pop(Stack*s)//��ջ����ջ��Ԫ��ɾ��,��������ֵ��
{
    int w,w1;
    w1=s->top-s->base;
    if(w1==0)
        printf("ջΪ��ջ����ջ��Ԫ�ؿ�ȡ!\n");
    else
    {
        s->top=s->top-1;
        w=*(s->top);
    }

    return w;
}


int Getop(Stack*s)//ȡջ��Ԫ�ء�
{
  int w,r;
  r=s->top-s->base;

  if(r==0)
    printf("��ջΪ��ջ��\n");
  else
  {
      s->top=s->top-1;
      w=*(s->top);
      s->top=s->top+1;
  }

  return w;
}


void Traverse(Stack*s)
{
    int *z;
     z=s->base;

    while(z<s->top)//ֻҪzС��ָ��s->top����ջ�׿�ʼ������ݣ�һֱ��ջ����
    {
      printf("%d\n",*z);
      z=z+1;
    }
}


int SLength(Stack*s)
{
    int length;
    length=s->top-s->base;
    return length;
}


int main()
{
   Stack*sq=(Stack*)malloc(sizeof(Stack));
   int len,leng,*a;
   a=(int*)calloc(4,sizeof(int));

    //int w=4;
    //int *e;
    //e=&w;
    //printf("%d\n",*e);
    sq=InitStack(sq,a,4);

    sq=Push(sq,3);
    sq=Push(sq,12);
    sq=Push(sq,23);
    sq=Push(sq,35);

    len=Pop(sq);
    printf("len: %d\n",len);
    printf("%d\n",*(sq->top-1));

    printf("���ջ�׵�ջ����Ԫ�أ�\n");
    Traverse(sq);

    leng=SLength(sq);
    printf("ջ��Ԫ�أ�");
    printf("%d\n",*(sq->base));

     printf("ջ��Ԫ�ظ�����");
     printf("%d\n",leng);



    return 0;
}
