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
}




int main()
{
  int a=1348,b=8,c,a1;//aΪ��ת��������bΪĿ�ꡰ���ơ���cΪ������
  a1=a;
  SNode*sq=(SNode*)malloc(sizeof(SNode));
  SNode*sp=(SNode*)malloc(sizeof(SNode));
  sq=Inits(sq);
   while(a!=0)//�õ����̲�Ϊ0Ϊѭ��������
   {
       c=a%b;//��������ѹջ��
       sq=Pushs(sq,c);
       a=a/b;//����εõ���"��"����Ϊ��һ�εġ�����������

   }

   sp=sq;
   printf("ת����İ˽�������");
   while(sp->next!=NULL)
   {
     printf("%d",sp->data);
     sp=sp->next;
   }
   printf("\n");
   printf("ת��ǰ��ʮ��������%d\n",a1);

   return 0;
}
