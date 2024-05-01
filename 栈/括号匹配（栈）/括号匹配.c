#include<stdio.h>
#include<stdlib.h>

typedef struct{
      char *top;//栈顶指针。
      char *base;//栈底指针。
      int size;//栈的最大容量。
}Stack;

Stack*InitStack(Stack*s,char*array,int l)//初始化栈s。
{

   s->base=array;
   s->top=s->base;
   s->size=l;

   return s;
}


Stack*Push(Stack*s,char e)//将字符e入栈。
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


char Pop(Stack*s)//出栈，将栈顶元素删除,并返回其值。
{
    int w1;
    char w;
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


char Getop(Stack*s)//取栈顶元素,不要改变栈顶指针的位置。
{
  char w;
  int r;
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


int WFit(Stack*s,char*c,int l)//判断字符数组里存储的括号是否匹配，匹配返回1,否则返回0。栈s是已经初始化后的栈。
{
  int i,flag=1;
  int ds;
  char d,d1,d2;

  for(i=0;i<l;i++)
  {
      d=c[i];

      printf("数组元素：%c\n",d);
    if((d=='(')||(d=='['))//如果当前字符是“（”或者“[”，入栈即可。
       {
           s=Push(s,d);
           printf("1-flag: %d\n",flag);
           ds=s->top-s->base;
           printf("1-ds: %d\n",ds);
       }
       else if((d==')')&&(s->top!=s->base))//如果当前字符是“）”且栈不空。
         {
           d1=Getop(s);//取栈顶元素
           if(d1!='(')//如果栈顶元素不是'('，则将flag置0。
              flag=0;
             else
                d2=Pop(s);//如果栈顶元素是'('，则将栈顶元素出栈。

           printf("2-flag: %d\n",flag);
            ds=s->top-s->base;
           printf("2-ds: %d\n",ds);
         }

          else if((d==']')&&(s->top!=s->base))//如果当前字符是“]”且栈不空。
          {
              d1=Getop(s);//取栈顶元素
           if(d1!='[')
              flag=0;
             else
            d2=Pop(s);

            printf("3-flag: %d\n",flag);

            ds=s->top-s->base;
            printf("3-ds: %d\n",ds);
          }

             else
             {
                flag=0;
                printf("4-flag: %d\n",flag);
                 ds=s->top-s->base;
                printf("4-ds: %d\n",ds);
             }

  }

     return flag;
}

int main()
{
  int aa,ab;
  char cs,cd;
  Stack*sq=(Stack*)malloc(sizeof(Stack));
  Stack*sr=(Stack*)malloc(sizeof(Stack));
  char*cq=(char*)calloc(4,sizeof(char));
  char*cr=(char*)calloc(5,sizeof(char));

   char*arr1=(char*)calloc(5,sizeof(char));
   char*arr2=(char*)calloc(5,sizeof(char));
  cq[0]='(';
  cq[1]='[';
  cq[2]=']';
  cq[3]=')';

  cr[0]='(';
  cr[1]=']';
  cr[2]=']';
  cr[3]=')';
  cr[4]=']';


  sq=InitStack(sq,arr1,4);
  sr=InitStack(sr,arr2,5);

   aa=WFit(sq,cq,4);
   ab=WFit(sr,cr,5);

  printf("aa: %d\n",aa);
  printf("ab: %d\n",ab);

  if(aa==1)
    printf("匹配成功！\n");
  else
    printf("匹配失败！\n");

  if(ab==1)
    printf("匹配成功！\n");
  else
    printf("匹配失败！\n");


    return 0;
}
