 #include<stdio.h>
 #include<stdlib.h>

 typedef struct{

      int data;//����
      struct SNode*next;//ָ����һ���ڵ��ָ�롣

 }SNode;


 SNode*Inits(SNode*s)//��ʼ����ջ��û��������Ϊ�յ�ͷ�ڵ㣬s��ջ���ڵ㡣
 {
    s->data=-1;
    s->next=NULL;
    return s;
 }



 SNode*Pushs(SNode*s,int w)//����һ���µĽڵ�p��Ȼ����뵽�����У�p��nextָ��ָ��s��û����֮ǰ��ջ���ڵ㣩
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


 SNode*Pops(SNode*s)//ɾ��ջ��Ԫ�أ������µ�ջ��Ԫ�ء�
 {

      SNode*k=(SNode*)malloc(sizeof(SNode));

     if(s->next==NULL)
     {
          printf("��ջ��\n");

     }

     else
     {
        k=s;
        s=s->next;//��ջ��Ԫ��ɾ�������ر�ɾ���Ľڵ��dataֵ��
        //printf("22233:  ");
        //printf("%d\n",s->data);
        free(k);

     }

    return s;
 }




int Getops(SNode*s)//ȡջ��Ԫ�أ���ɾ��ջ��Ԫ�ء�
{
    int e1;
    //if(s->next==NULL)
      //  printf("��ջ(dataֵΪһ��ʼ���ĳ�ֵ)��%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}


void Traverses(SNode*s)//��ջ����ջ�ױ��������ÿ���ڵ��dataֵ��
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
