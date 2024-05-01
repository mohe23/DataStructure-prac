#include<stdio.h>
#include<stdlib.h>

typedef struct{
      int *top;//栈顶指针。
      int *base;//栈底指针。
      int size;//栈的最大容量。
}Stack;

Stack*InitStack(Stack*s,int*array,int l)//初始化栈s。
{

   s->base=array;
   s->top=s->base;
   s->size=l;

   return s;
}


Stack*Push(Stack*s,int e)//将整数e入栈。
{
   int length;
   length=s->top-s->base;


    if(length>=s->size)
        printf("栈已满,当前元素无法入栈!\n");
    else
    {
        *(s->top)=e;
        s->top=s->top+1;
    }

    return s;
}


int Pop(Stack*s)//出栈，将栈顶元素删除,并返回其值。
{
    int w,w1;
    w1=s->top-s->base;
    if(w1==0)
        printf("栈为空栈，无栈顶元素可取!\n");
    else
    {
        s->top=s->top-1;
        w=*(s->top);
    }

    return w;
}


int Getop(Stack*s)//取栈顶元素。
{
  int w,r;
  r=s->top-s->base;

  if(r==0)
    printf("此栈为空栈！\n");
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

    while(z<s->top)//只要z小于指针s->top，从栈底开始输出数据，一直到栈顶。
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

    printf("输出栈底到栈顶的元素：\n");
    Traverse(sq);

    leng=SLength(sq);
    printf("栈底元素：");
    printf("%d\n",*(sq->base));

     printf("栈的元素个数：");
     printf("%d\n",leng);



    return 0;
}
