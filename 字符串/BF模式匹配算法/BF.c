#include<stdio.h>
#include<stdlib.h>

typedef struct{
        char*ch;//����ַ������ַ�������׵�ַ��
        int length;
}String;


String*StrInit(String*s,char*c)//��ʼ��String,���ַ���s����һ���Ĵ洢�ռ䣬�Լ������ĳ�����Ϊ0��
{
    s->ch=c;
    s->length=0;
    return s;
}


//int Length(char*c)//�����ַ�����ĳ���
String*StrAssign(String*s,char*c,int size)//�ַ�������洢���ַ����������ַ���������s��
{
    int i;
    for(i=0;i<size;i++)
        s->ch[i]=c[i];//���ַ������ַ�һ��һ����ֵ���ַ���s��

    s->length=size;

    return s;
}


int BF(String*s,String*t,int pos)//�ַ���t�Ƿ񱻰������ַ���s�У�����Ƿ���t�ĵ�1���ַ�������s�����(��1�γ��ֵ�λ��)���ڼ����ַ���
{                                //����񣬷���0��pos��ʾ������s�ĵ�pos���ַ���ʼ���бȽϡ�
  int i,j,k=0;
  i=pos;
  j=1;

  while((i<=s->length)&&(j<=t->length))
  {
    if(s->ch[i-1]==t->ch[j-1])//�ַ��������е�������ַ����ַ����е�λ����1����Ϊ�����Ǵ�0��ʼ������
    {
      i=i+1;
      j=j+1;
    }

    else//�����ַ�����ͬ��
    {
      i=i-j+2;
      j=1;
    }

  }

   if(j>t->length)
    k=i-(t->length);

 return k;
}


int main()
{
  int a,b;
  char*c1=(char*)calloc(4,sizeof(char));
  char*c2=(char*)calloc(4,sizeof(char));
  char*c3=(char*)calloc(12,sizeof(char));
  char*c4=(char*)calloc(12,sizeof(char));
  char*c5=(char*)calloc(4,sizeof(char));
  char*c6=(char*)calloc(4,sizeof(char));
  String*str=(String*)malloc(sizeof(String));
  String*st=(String*)malloc(sizeof(String));
  String*ste=(String*)malloc(sizeof(String));


  c1[0]='s';
  c1[1]='w';
  c1[2]='o';
  c1[3]='x';

  c5[0]='k';
  c5[1]='d';
  c5[2]='w';
  c5[3]='d';

  c4[0]='l';
  c4[1]='w';
  c4[2]='s';
  c4[3]='w';
  c4[4]='o';
  c4[5]='x';
  c4[6]='l';
  c4[7]='s';
  c4[8]='w';
  c4[9]='o';
  c4[10]='x';
  c4[11]='k';

  str=StrInit(str,c2);
  st=StrInit(st,c6);
  ste=StrInit(ste,c3);

  str=StrAssign(str,c1,4);
  st=StrAssign(st,c5,4);
  ste=StrAssign(ste,c4,12);

  a=BF(ste,str,1);
  b=BF(ste,st,1);

  printf("%d\n",a);
  printf("%d\n",b);

  return 0;
  }
