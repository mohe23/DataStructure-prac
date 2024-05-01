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
    //free(z);
}

 int main()
 {

    int w1,w2,w3,w4=1;
    SNode*a=(SNode*)malloc(sizeof(SNode));
    SNode*b=(SNode*)malloc(sizeof(SNode));
    a=Inits(a);
    a=Pushs(a,5);
    a=Pushs(a,6);
    a=Pushs(a,23);
    a=Pushs(a,32);

    //Traverses(a);
    w1=Getops(a);
     printf("w1: %d\n",w1);
    a=Pops(a);
    w3=Getops(a);
     printf("w3: %d\n",w3);

    //printf("w4: %d\n",w4);


    //w2=Pop(a);
    //printf("w2: %d\n",w2);
   // w4=Getops(a);



    // a=Pops(a);
     //w1=a->data;
     //a=Pops(a);
     //w2=a->data;

     //w3=Getops(a);
     //printf("w3: %d\n",w3);


       //a=Pops(a);


    //printf("w3: %d\n",w3);
    //printf("w4: %d\n",w4);
    return 0;
 }
