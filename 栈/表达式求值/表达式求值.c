#include<stdio.h>
 #include<stdlib.h>



 typedef struct{

      char data;//����
      struct SNodes*next;//ָ����һ���ڵ��ָ�롣

 }SNodes;


  typedef struct{

      int data;//����
      struct SNode*next;//ָ����һ���ڵ��ָ�롣

 }SNode;




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
  SNodes*r=(SNodes*)malloc(sizeof(SNode));//βָ��r��
  r=s;
  printf("��������ʽ�ַ���\n");
  while(i!=2)//ͳ��"#"�ĸ�������������ﵽ2���ͽ����������Ĵ��졣
  {
      SNodes*m=(SNodes*)malloc(sizeof(SNode));

      scanf("%c",&cq);
      if(cq=='#')
        i=i+1;//ͳ��#�ĸ�����

       m->data=cq;
       m->next=NULL;
       r->next=m;
       r=m;
  }

  return s;
}


void Traver(SNodes*s)//����������s��ͷ���Ϊs����
{
    char c1;
    SNodes*a=(SNodes*)malloc(sizeof(SNode));
    a=s->next;//aһ��ʼָ����Ԫ�ڵ㡣
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


 SNode*Init(SNode*s)//��ʼ����ջ��û��������Ϊ�յ�ͷ�ڵ㣬s��ջ���ڵ㡣
 {
    s->data=-1;
    s->next=NULL;
    return s;
 }



 SNodes*Pushs(SNode*s,char w)//����һ���µĽڵ�p��Ȼ����뵽�����У�p��nextָ��ָ��s��û����֮ǰ��ջ���ڵ㣩
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


 SNode*Push(SNode*s,int w)//����һ���µĽڵ�p��Ȼ����뵽�����У�p��nextָ��ָ��s��û����֮ǰ��ջ���ڵ㣩
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

SNode*Pop(SNode*s)//ɾ��ջ��Ԫ�أ������µ�ջ��Ԫ�ء�
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


char Getops(SNodes*s)//ȡջ��Ԫ�أ���ɾ��ջ��Ԫ�ء�
{
    char e1;
    //if(s->next==NULL)
      //  printf("��ջ(dataֵΪһ��ʼ���ĳ�ֵ)��%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}

int Getop(SNode*s)//ȡջ��Ԫ�أ���ɾ��ջ��Ԫ�ء�
{
    int e1;
    //if(s->next==NULL)
      //  printf("��ջ(dataֵΪһ��ʼ���ĳ�ֵ)��%d\n : ",s->data);
    //else

    e1=s->data;
    return e1;
}



int In(char c)//�ж϶�����ַ�c�Ƿ��������������ǣ�����1��������ǣ�����0��
{
   int b1;

   if((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='(')||(c==')')||(c=='#'))
      b1=1;

      else
        b1=0;

    return b1;
}


char Precede(SNode*OPTR,char ch)//�ж������ջ��Ԫ������������������ȹ�ϵ������ֵΪ">"��"<"��"="��
{
   char c1,c2;

   c2=Getops(OPTR);//ȡ�����ջ��ջ��Ԫ�ء�

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
         else//������
            c1='<';
   }


   else if(c2=='(')
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='('))
            c1='<';
       else if(ch==')')
             c1='=';
       else//'#'
        printf("  �� # �����﷨���󣡷���ֵδ֪������ֵ��");
   }

   else if(c2==')')
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch==')')||(ch=='#'))
            c1='>';

       else//'('
        printf("   ���� �����﷨���󣡷���ֵδ֪,����ֵΪ��");
   }

   else if(c2=='#')//c2=='#'
   {
       if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='('))
            c1='<';
       else if(ch=='#')
        c1='=';
        else if(ch=='$')
            c1='>';
       else//chΪ������
        printf("   # �������﷨���󣡷���ֵδ֪������ֵ��");
   }

   else
   {
       if(ch=='#')
        c1='<';
   }

  return c1 ;
}


int Operate(int a,int b,char ch)//��a,b�������Ķ�Ԫ��������Ĭ��ֻ�мӼ��˳���
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
  SNodes*sq=(SNodes*)malloc(sizeof(SNodes));//�����ջ
   SNode*sr=(SNode*)malloc(sizeof(SNode));//�������Լ���ż�������ջ
    sq=Inits(sq);//��ʼ�������ջ��
    sr=Init(sr);//��ʼ��������ջ��
    //sq=Pushs(sq,'#');
 // ce=Getops(sq);
   cd=Getops(sq);
  s=Create(s);
  //Traver(sq);
  t=s->next;//��Ԫ�ڵ㡣
  ck=t->data;
  while((ck!='#')||(cd!='#'))//��ȡ���ʽ��ѭ��������
  {
      //ck=c[i];
       printf("��ȡ���ַ�: %c\n",ck);
       ke=In(ck);//��ʼ���������ʽ��ÿһ��ֵ��
       printf("������ַ��Ƿ����������ke��%d\n",ke);
       if(!ke)//�������ַ����������
       {

           kw=ck-'0';
            printf("�������ǲ������������� %d ��ջ\n\n",kw);
           sr=Push(sr,kw);//����������ջ��
            t=t->next;
            ck=t->data;
             cd=Getops(sq);
       }

         else
         {
            // printf("12333!\n");
             //cr=c[i];
             printf("ջ��Ԫ��cd: %c\n",cd);
             cw=Precede(sq,ck);//�Ƚ������ջ��Ԫ�����ȡ�������֮������ȼ���ϵ

            // printf("4455666\n");
             switch(cw)
             {
             case'<':
                sq=Pushs(sq,ck);//��ȡ���ַ�ѹջ��
                printf("<--����� %c ��ջ\n\n",cr);
                 t=t->next;
                ck=t->data;
                 cd=Getops(sq);
                break;

             case'>':
                 //i=i-1;//!!!!!!!!!!!!!!!!!!!!!!!�ٴ��ж�֮ǰ��ȡ�����������
                 ca=Getops(sq);//ȡ�������ջ�������������
                  printf(">--����� %c ջ����ջ\n",ca);
                 sq=Pops(sq);//��ջ��Ԫ��ɾ����
                 a=Getop(sr);//ȡ������1��
                 printf(">--������ջ��Ԫ�� %d ��ջ\n",a);
                 sr=Pop(sr);
                 b=Getop(sr);//ȡ������2.
                 printf(">--������ջ��Ԫ�� %d ��ջ\n",b);
                 sr=Pop(sr);
                 sum=Operate(b,a,ca);
                 printf("%d %c %d = %d\n",b,ca,a,sum);
                 sr=Push(sr,sum);//��������ѹջ��
                 printf(">--������������ %d ��������ջ\n\n",sum);
                  cd=Getops(sq);
                 break;

             case'=':
                 cb=Getops(sq);
                 sq=Pops(sq);//����ջ��Ԫ�ء�
                 printf("=--����� %c ��ջ\n\n",cb);
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
printf("���ʽ���ֵΪ��%d\n",kr);



  return 0;
}
