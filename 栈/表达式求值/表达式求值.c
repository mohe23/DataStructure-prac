#include<stdio.h>
 #include<stdlib.h>



 typedef struct{

      char data;//数据
      struct SNodes*next;//指向下一个节点的指针。

 }SNodes;


  typedef struct{

      int data;//数据
      struct SNode*next;//指向下一个节点的指针。

 }SNode;




 SNodes*Inits(SNodes*s)//初始化链栈，没有数据域为空的头节点，s是栈顶节点。
 {
    s->data='$';
    s->next=NULL;
    return s;
 }


SNodes*Create(SNodes*s)//创建一个头结点为s类型为char的单链表。
{
  int i=0;
  char cq;
  SNodes*r=(SNodes*)malloc(sizeof(SNode));//尾指针r。
  r=s;
  printf("请输入表达式字符：\n");
  while(i!=2)//统计"#"的个数，如果个数达到2，就结束这个链表的创造。
  {
      SNodes*m=(SNodes*)malloc(sizeof(SNode));

      scanf("%c",&cq);
      if(cq=='#')
        i=i+1;//统计#的个数。

       m->data=cq;
       m->next=NULL;
       r->next=m;
       r=m;
  }

  return s;
}


void Traver(SNodes*s)//遍历单链表s（头结点为s）。
{
    char c1;
    SNodes*a=(SNodes*)malloc(sizeof(SNode));
    a=s->next;//a一开始指向首元节点。
    while(a->next!=NULL)
    {
        c1=a->data;
        if(c1=='#')
            printf(" ");
        else
        printf("%c",c1);

        a=a->next;
    }

}


 SNode*Init(SNode*s)//初始化链栈，没有数据域为空的头节点，s是栈顶节点。
 {
    s->data=-1;
    s->next=NULL;
    return s;
 }



 SNodes*Pushs(SNode*s,char w)//创建一个新的节点p，然后插入到链表中，p的next指针指向s（没插入之前的栈顶节点）
 {
    SNodes*p=(SNodes*)malloc(sizeof(SNodes));
    SNodes*q=(SNodes*)malloc(sizeof(SNodes));
    p->data=w;
    p->next=s;
    s=p;
     //q=s->next;
   //int s1,s2;
   //s1=s->data;
   //s2=q->data;

    //printf("s1: %d\n",s1);
    // printf("s2: %d\n",s2);
    return s;
 }


 SNode*Push(SNode*s,int w)//创建一个新的节点p，然后插入到链表中，p的next指针指向s（没插入之前的栈顶节点）
 {
    SNode*p=(SNode*)malloc(sizeof(SNode));
    SNode*q=(SNode*)malloc(sizeof(SNode));
    p->data=w;
    p->next=s;
    s=p;
     //q=s->next;
   //int s1,s2;
   //s1=s->data;
   //s2=q->data;

    //printf("s1: %d\n",s1);
    // printf("s2: %d\n",s2);
    return s;
 }


 SNodes*Pops(SNodes*s)//删除栈顶元素，返回新的栈顶元素。
 {

      SNodes*k=(SNodes*)malloc(sizeof(SNodes));

     if(s->next==NULL)
     {
          printf("空栈s！\n");

     }

     else
     {
        k=s;
        s=s->next;//将栈顶元素删除，返回被删除的节点的data值。
        //printf("22233:  ");
        //printf("%d\n",s->data);
        free(k);

     }

    return s;
 }

SNode*Pop(SNode*s)//删除栈顶元素，返回新的栈顶元素。
 {

      SNode*k=(SNode*)malloc(sizeof(SNode));

     if(s->next==NULL)
     {
          printf("空栈！\n");

     }

     else
     {
        k=s;
        s=s->next;//将栈顶元素删除，返回被删除的节点的data值。
        //printf("22233:  ");
        //printf("%d\n",s->data);
        free(k);

     }

    return s;
 }


char Getops(SNodes*s)//取栈顶元素，不删除栈顶元素。
{
    char e1;
    //if(s->next==NULL)
      //  printf("空栈(data值为一开始赋的初值)，%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}

int Getop(SNode*s)//取栈顶元素，不删除栈顶元素。
{
    int e1;
    //if(s->next==NULL)
      //  printf("空栈(data值为一开始赋的初值)，%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}



int In(char c)//判断读入的字符c是否是运算符，如果是，返回1；如果不是，返回0。
{
   int b1;

   if((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='(')||(c==')')||(c=='#'))
      b1=1;

      else
        b1=0;

    return b1;
}


char Precede(SNode*OPTR,char ch)//判断运算符栈顶元素与读入的运算符的优先关系，返回值为">"或"<"或"="。
{
   char c1,c2;

   c2=Getops(OPTR);//取运算符栈的栈顶元素。

   if((c2=='+')||(c2=='-'))
   {
       if((ch=='+')||(ch=='-')||(ch==')')||(ch=='#'))
           c1='>';
         else
            c1='<';
   }


   else if((c2=='*')||(c2=='/'))
   {
       if((ch=='+')||(ch=='-')||(ch==')')||(ch=='#')||(ch=='*')||(ch=='/'))
           c1='>';
         else//“（”
            c1='<';
   }


   else if(c2=='(')
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='('))
            c1='<';
       else if(ch==')')
             c1='=';
       else//'#'
        printf("  （ # 出现语法错误！返回值未知，返回值：");
   }

   else if(c2==')')
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch==')')||(ch=='#'))
            c1='>';

       else//'('
        printf("   ）（ 出现语法错误！返回值未知,返回值为：");
   }

   else if(c2=='#')//c2=='#'
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='('))
            c1='<';
       else if(ch=='#')
        c1='=';
        else if(ch=='$')
            c1='>';
       else//ch为“）”
        printf("   # ）出现语法错误！返回值未知，返回值：");
   }

   else
   {
       if(ch=='#')
        c1='<';
   }

  return c1 ;
}


int Operate(int a,int b,char ch)//求a,b两个数的二元运算结果。默认只有加减乘除。
{
    int outs;
    switch(ch)
    {
    case'+':
        outs=a+b;
        break;
    case'-':
        outs=a-b;
        break;
    case'*':
        outs=a*b;
        break;
    case'/':
        outs=a/b;
        break;

    }

 return outs;
}


int main()
{
  int i,a,b,sum,ke,kw,kr;
  char cr,cw,ca,cb,ck,ce,cd,c[15];
  //c[0]='#';
  SNodes*s=(SNodes*)malloc(sizeof(SNodes));
  SNodes*t=(SNodes*)malloc(sizeof(SNodes));
  SNodes*sq=(SNodes*)malloc(sizeof(SNodes));//运算符栈
   SNode*sr=(SNode*)malloc(sizeof(SNode));//操作数以及存放计算结果的栈
    sq=Inits(sq);//初始化运算符栈。
    sr=Init(sr);//初始化操作数栈。
    //sq=Pushs(sq,'#');
 // ce=Getops(sq);
   cd=Getops(sq);
  s=Create(s);
  //Traver(sq);
  t=s->next;//首元节点。
  ck=t->data;
  while((ck!='#')||(cd!='#'))//读取表达式的循环条件。
  {
      //ck=c[i];
       printf("读取的字符: %c\n",ck);
       ke=In(ck);//开始逐个读入表达式的每一个值。
       printf("读入的字符是否是运算符，ke：%d\n",ke);
       if(!ke)//读到的字符不是运算符
       {

           kw=ck-'0';
            printf("读到的是操作数，操作数 %d 进栈\n\n",kw);
           sr=Push(sr,kw);//将操作数入栈。
            t=t->next;
            ck=t->data;
             cd=Getops(sq);
       }

         else
         {
            // printf("12333!\n");
             //cr=c[i];
             printf("栈顶元素cd: %c\n",cd);
             cw=Precede(sq,ck);//比较运算符栈顶元素与读取的运算符之间的优先级关系

            // printf("4455666\n");
             switch(cw)
             {
             case'<':
                sq=Pushs(sq,ck);//读取的字符压栈。
                printf("<--运算符 %c 进栈\n\n",cr);
                 t=t->next;
                ck=t->data;
                 cd=Getops(sq);
                break;

             case'>':
                 //i=i-1;//!!!!!!!!!!!!!!!!!!!!!!!再次判断之前读取到的运算符。
                 ca=Getops(sq);//取出运算符栈顶“运算符”。
                  printf(">--运算符 %c 栈顶出栈\n",ca);
                 sq=Pops(sq);//将栈顶元素删除。
                 a=Getop(sr);//取操作数1；
                 printf(">--操作数栈顶元素 %d 出栈\n",a);
                 sr=Pop(sr);
                 b=Getop(sr);//取操作数2.
                 printf(">--操作数栈顶元素 %d 出栈\n",b);
                 sr=Pop(sr);
                 sum=Operate(b,a,ca);
                 printf("%d %c %d = %d\n",b,ca,a,sum);
                 sr=Push(sr,sum);//将计算结果压栈。
                 printf(">--操作数计算结果 %d 进操作数栈\n\n",sum);
                  cd=Getops(sq);
                 break;

             case'=':
                 cb=Getops(sq);
                 sq=Pops(sq);//弹出栈顶元素。
                 printf("=--运算符 %c 出栈\n\n",cb);
                  t=t->next;
                 ck=t->data;
                  cd=Getops(sq);
                 break;



             }
         }

      //t=t->next;
      //ck=t->data;

   }


kr=Getop(sr);
printf("表达式最后值为：%d\n",kr);



  return 0;
}
