#include<stdio.h>
 #include<stdlib.h>



 typedef struct{

      char data;//����
      struct SNodes*next;//ָ����һ���ڵ��ָ�롣

 }SNodes;


 SNodes*Inits(SNodes*s)//��ʼ����ջ��û��������Ϊ�յ�ͷ�ڵ㣬s��ջ���ڵ㡣
 {
    s->data='$';
    s->next=NULL;
    return s;
 }


SNodes*Create(SNodes*s)//����һ��ͷ���Ϊs����Ϊchar�ĵ�����
{
  int i=0;
  char cq;
  SNodes*r=(SNodes*)malloc(sizeof(SNodes));//βָ��r��
  r=s;
  printf("��������ʽ�ַ�(�ԡ�#��Ϊ�����ַ�)��\n");
  while(i!=1)//��#Ϊ�������������ǲ���
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



SNodes*Pushs(SNodes*s,char w)//����һ���µĽڵ�p��Ȼ����뵽�����У�p��nextָ��ָ��s��û����֮ǰ��ջ���ڵ㣩
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

 SNodes*Pops(SNodes*s)//ɾ��ջ��Ԫ�أ������µ�ջ��Ԫ�ء�
 {

      SNodes*k=(SNodes*)malloc(sizeof(SNodes));

     if(s->next==NULL)
     {
          printf("��ջs��\n");

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


char Getops(SNodes*s)//ȡջ��Ԫ�أ���ɾ��ջ��Ԫ�ء�
{
    char e1;
    //if(s->next==NULL)
      //  printf("��ջ(dataֵΪһ��ʼ���ĳ�ֵ)��%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}


int SLength(SNodes*s)//������ĳ��ȡ�
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

void Traver(SNodes*s)//����������s��ͷ���Ϊs����
{
    char c1;
    SNodes*a=(SNodes*)malloc(sizeof(SNodes));
    a=s->next;//aһ��ʼָ����Ԫ�ڵ㡣
    while(a!=NULL)
    {
        c1=a->data;

        printf("%c",c1);

        a=a->next;
    }
   printf("\n");
}


int Huiwen(SNodes*s,SNodes*r)//�ж�һ���ַ����Ƿ��ǻ������У�������������ͬ���ַ�������������ջs�ں���֮��ͱ�����ˣ�����
{//s�Ǵ洢һ���ַ�����ջ��r�Ǵ���ַ���һ��λ���Ժ��һ��ָ�롣

   int t=1;//1�����ǻ������У�0�����ǻ������С�
   char c1,c2;
   //SNodes*q=(SNodes*)malloc(sizeof(SNodes));
    //q=s;
    //printf("h-11111\n");
    while(s->next!=NULL)//�����s��ʾ������ջ���ұ�д����ջ���һ������ǿսڵ㡣������������ǿ��Եġ�
    {
      c1=Getops(s);//ȡջ����Ԫ��
      c2=r->data;//�õ��ַ�����һ���Ԫ�ء�
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
       s=Pops(s);//���ν�ջ��Ԫ�س�ջ��
       r=r->next;
       //printf("h4-t: %d\n",t);

    }

   return t;
}

int main()
{
     int i,k=0,leng;
     char cr;
     SNodes*sq=(SNodes*)malloc(sizeof(SNodes));//ջsq.
      SNodes*sk=(SNodes*)malloc(sizeof(SNodes));//������sk��
     SNodes*sr=(SNodes*)malloc(sizeof(SNodes));//ָ��sr��
      sq=Inits(sq);//��ʼ��ջ��
     sk=Create(sk);//����������s�����ַ�����
     sr=sk->next;//��ָ��ָ������s��
     printf("���֮ǰ������ַ���:\n");
     Traver(sk);
    leng=SLength(sk);
     printf("\n����Ϊ��%d\n",leng);
     for(i=0;i<leng/2;i++)
        {
            cr=sr->data;//ȡ�������1���ڵ㵽��leng/2���ڵ㡣
            sq=Pushs(sq,cr);//����ȡ�����ַ���һ����ַ�ѹջ��
            sr=sr->next;//ָ��sr����ƶ�������ָ���ַ����ĵڣ�leng/2+1�����ַ���
        }
     //printf("22222\n");
     k=Huiwen(sq,sr);
     printf("k: %d\n",k);
     //printf("1111\n");
     if(k==1)
        printf("���ַ���Ϊ�������С�\n");
     else
        printf("���ַ������ǻ������У�\n");

     return 0;
}
