#include<stdio.h>
#include<stdlib.h>

typedef struct{
        char*ch;//存放字符串的字符数组的首地址。
        int length;
}String;


String*StrInit(String*s,char*c)//初始化String,给字符串s分配一定的存储空间，以及将串的长度置为0。
{
    s->ch=c;
    s->length=0;
    return s;
}


//int Length(char*c)//计算字符数组的长度
String*StrAssign(String*s,char*c,int size)//字符串数组存储着字符串，将该字符串赋给串s。
{
    int i;
    for(i=0;i<size;i++)
        s->ch[i]=c[i];//将字符串的字符一个一个赋值给字符串s。

    s->length=size;

    return s;
}


int BF(String*s,String*t,int pos)//字符串t是否被包含在字符串s中，如果是返回t的第1个字符在主串s的序号(第1次出现的位置)（第几个字符）
{                                //如果否，返回0。pos表示从主串s的第pos个字符开始进行比较。
  int i,j,k=0;
  i=pos;
  j=1;

  while((i<=s->length)&&(j<=t->length))
  {
    if(s->ch[i-1]==t->ch[j-1])//字符在数组中的序号是字符在字符串中的位置少1。因为数组是从0开始计数。
    {
      i=i+1;
      j=j+1;
    }

    else//出现字符不相同。
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
