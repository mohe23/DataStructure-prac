 #include<stdio.h>
 #include<stdlib.h>

 typedef struct{

      int data;//数据
      struct SNode*next;//指向下一个节点的指针。

 }SNode;


 SNode*Inits(SNode*s)//初始化链栈，没有数据域为空的头节点，s是栈顶节点。
 {
    s->data=-1;
    s->next=NULL;
    return s;
 }



 SNode*Pushs(SNode*s,int w)//创建一个新的节点p，然后插入到链表中，p的next指针指向s（没插入之前的栈顶节点）
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


 SNode*Pops(SNode*s)//删除栈顶元素，返回新的栈顶元素。
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


int Getops(SNode*s)//取栈顶元素，不删除栈顶元素。
{
    int e1;
    //if(s->next==NULL)
      //  printf("空栈(data值为一开始赋的初值)，%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}


void Traverses(SNode*s)//从栈顶到栈底遍历，输出每个节点的data值。
{
    SNode*z=(SNode*)malloc(sizeof(SNode));
    z=s;
    while(z->next!=NULL)
    {
        printf("%d\n",z->data);
        z=z->next;
    }
}




int main()
{
  int a=1348,b=8,c,a1;//a为被转换的数，b为目标“进制”，c为余数。
  a1=a;
  SNode*sq=(SNode*)malloc(sizeof(SNode));
  SNode*sp=(SNode*)malloc(sizeof(SNode));
  sq=Inits(sq);
   while(a!=0)//得到的商不为0为循环条件。
   {
       c=a%b;//求余数。压栈。
       sq=Pushs(sq,c);
       a=a/b;//将这次得到的"商"，作为下一次的“被除数”。

   }

   sp=sq;
   printf("转换后的八进制数：");
   while(sp->next!=NULL)
   {
     printf("%d",sp->data);
     sp=sp->next;
   }
   printf("\n");
   printf("转换前的十进制数：%d\n",a1);

   return 0;
}
