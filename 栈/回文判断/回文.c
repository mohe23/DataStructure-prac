#include<stdio.h>
 #include<stdlib.h>



 typedef struct{

      char data;//数据
      struct SNodes*next;//指向下一个节点的指针。

 }SNodes;


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
  SNodes*r=(SNodes*)malloc(sizeof(SNodes));//尾指针r。
  r=s;
  printf("请输入表达式字符(以“#”为结束字符)：\n");
  while(i!=1)//以#为结束条件，但是不会
  {
      SNodes*m=(SNodes*)malloc(sizeof(SNodes));

      scanf("%c",&cq);
      if(cq=='#')
       break;
       else
       {
         m->data=cq;
         m->next=NULL;
         r->next=m;
         r=m;
       }
  }

  return s;
  }



SNodes*Pushs(SNodes*s,char w)//创建一个新的节点p，然后插入到链表中，p的next指针指向s（没插入之前的栈顶节点）
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


char Getops(SNodes*s)//取栈顶元素，不删除栈顶元素。
{
    char e1;
    //if(s->next==NULL)
      //  printf("空栈(data值为一开始赋的初值)，%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}


int SLength(SNodes*s)//求单链表的长度。
{
   int length=0;
   SNodes*q=(SNodes*)malloc(sizeof(SNodes));
   q=s->next;
   while(q->next!=NULL)
    {
      length=length+1;
      q=q->next;
    }
   length=length+1;

   return length;
}

void Traver(SNodes*s)//遍历单链表s（头结点为s）。
{
    char c1;
    SNodes*a=(SNodes*)malloc(sizeof(SNodes));
    a=s->next;//a一开始指向首元节点。
    while(a!=NULL)
    {
        c1=a->data;

        printf("%c",c1);

        a=a->next;
    }
   printf("\n");
}


int Huiwen(SNodes*s,SNodes*r)//判断一个字符串是否是回文序列（正反读都是相同的字符串）。！！！栈s在函数之后就被清空了！！！
{//s是存储一半字符串的栈，r是存放字符串一半位置以后的一个指针。

   int t=1;//1代表是回文序列，0代表不是回文序列。
   char c1,c2;
   //SNodes*q=(SNodes*)malloc(sizeof(SNodes));
    //q=s;
    //printf("h-11111\n");
    while(s->next!=NULL)//这里的s表示的是链栈，我编写的链栈最后一个结点是空节点。所以这个条件是可以的。
    {
      c1=Getops(s);//取栈顶的元素
      c2=r->data;//得到字符串后一半的元素。
      if(c1!=c2)
       {
        // printf("h2-11111\n");
          t=0;
          break;
       }
       //q=q->next;
       else
       {
         // printf("h3-1111\n");
          t=t;
       }
       s=Pops(s);//依次将栈顶元素出栈。
       r=r->next;
       //printf("h4-t: %d\n",t);

    }

   return t;
}

int main()
{
     int i,k=0,leng;
     char cr;
     SNodes*sq=(SNodes*)malloc(sizeof(SNodes));//栈sq.
      SNodes*sk=(SNodes*)malloc(sizeof(SNodes));//单链表sk。
     SNodes*sr=(SNodes*)malloc(sizeof(SNodes));//指针sr。
      sq=Inits(sq);//初始化栈。
     sk=Create(sk);//创建单链表s保存字符串。
     sr=sk->next;//用指针指向单链表s。
     printf("输出之前输入的字符串:\n");
     Traver(sk);
    leng=SLength(sk);
     printf("\n长度为：%d\n",leng);
     for(i=0;i<leng/2;i++)
        {
            cr=sr->data;//取单链表第1个节点到第leng/2个节点。
            sq=Pushs(sq,cr);//依次取到的字符串一半的字符压栈。
            sr=sr->next;//指针sr向后移动，最终指向字符串的第（leng/2+1）个字符。
        }
     //printf("22222\n");
     k=Huiwen(sq,sr);
     printf("k: %d\n",k);
     //printf("1111\n");
     if(k==1)
        printf("该字符串为回文序列。\n");
     else
        printf("该字符串不是回文序列！\n");

     return 0;
}
