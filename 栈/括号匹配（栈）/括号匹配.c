#include<stdio.h>
#include<stdlib.h>

typedef struct{
      char *top;//ջ��ָ�롣
      char *base;//ջ��ָ�롣
      int size;//ջ�����������
}Stack;

Stack*InitStack(Stack*s,char*array,int l)//��ʼ��ջs��
{

   s->base=array;
   s->top=s->base;
   s->size=l;

   return s;
}


Stack*Push(Stack*s,char e)//���ַ�e��ջ��
{
   int length;
   length=s->top-s->base;


    if(length>=s->size)
        printf("ջ����,��ǰԪ���޷���ջ!\n");
    else
    {
        *(s->top)=e;
        s->top=s->top+1;
    }

    return s;
}


char Pop(Stack*s)//��ջ����ջ��Ԫ��ɾ��,��������ֵ��
{
    int w1;
    char w;
    w1=s->top-s->base;
    if(w1==0)
        printf("ջΪ��ջ����ջ��Ԫ�ؿ�ȡ!\n");
    else
    {
        s->top=s->top-1;
        w=*(s->top);
    }

    return w;
}


char Getop(Stack*s)//ȡջ��Ԫ��,��Ҫ�ı�ջ��ָ���λ�á�
{
  char w;
  int r;
  r=s->top-s->base;

  if(r==0)
    printf("��ջΪ��ջ��\n");
  else
  {
      s->top=s->top-1;
      w=*(s->top);
      s->top=s->top+1;
  }

  return w;
}


int WFit(Stack*s,char*c,int l)//�ж��ַ�������洢�������Ƿ�ƥ�䣬ƥ�䷵��1,���򷵻�0��ջs���Ѿ���ʼ�����ջ��
{
  int i,flag=1;
  int ds;
  char d,d1,d2;

  for(i=0;i<l;i++)
  {
      d=c[i];

      printf("����Ԫ�أ�%c\n",d);
    if((d=='(')||(d=='['))//�����ǰ�ַ��ǡ��������ߡ�[������ջ���ɡ�
       {
           s=Push(s,d);
           printf("1-flag: %d\n",flag);
           ds=s->top-s->base;
           printf("1-ds: %d\n",ds);
       }
       else if((d==')')&&(s->top!=s->base))//�����ǰ�ַ��ǡ�������ջ���ա�
         {
           d1=Getop(s);//ȡջ��Ԫ��
           if(d1!='(')//���ջ��Ԫ�ز���'('����flag��0��
              flag=0;
             else
                d2=Pop(s);//���ջ��Ԫ����'('����ջ��Ԫ�س�ջ��

           printf("2-flag: %d\n",flag);
            ds=s->top-s->base;
           printf("2-ds: %d\n",ds);
         }

          else if((d==']')&&(s->top!=s->base))//�����ǰ�ַ��ǡ�]����ջ���ա�
          {
              d1=Getop(s);//ȡջ��Ԫ��
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
    printf("ƥ��ɹ���\n");
  else
    printf("ƥ��ʧ�ܣ�\n");

  if(ab==1)
    printf("ƥ��ɹ���\n");
  else
    printf("ƥ��ʧ�ܣ�\n");


    return 0;
}
