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


String*StrCopy(String*s,String*t)//���ַ���t���Ƹ��ַ���s���Ѿ���ʼ���ˣ���
{
   int i,sum;
   sum=t->length;
   for(i=0;i<sum;i++)
    s->ch[i]=t->ch[i];

   s->length=sum;
   return s;
}


int StrEmpty(String*s)//�ж��ַ���s�Ƿ��ǿմ������ǿմ�������1.����Ϊ0.
{
   int t,k;
   k=s->length;
   if(k==0)//�մ���
      t=1;
   else//�ǿմ���
    t=0;

 return t;
}


int StrCompare(String*s,String*t)//�Ƚ��ַ���s���ַ���t,���s>t,����ֵΪ1��s=t,����ֵΪ0��s<t,����ֵΪ-1��
{
    int l1,l2,i,r,key;
       r=1;
      l1=s->length;
      l2=t->length;
    if(l1>l2)
        key=1;
    else if(l1<l2)
        key=-1;
    else//l1=l2
    {
      for(i=0;i<l1;i++)
      {
          if(s->ch[i]!=t->ch[i])//�����һ��Ԫ�ز���ȣ�������ѭ����
          {
             r=0;
             break;
          }

      }

      if(r==1)
        key=0;
      else
        key=10;//��ʾ�ַ���s���ַ���t��Ȼ������ͬ������2���ַ�������ͬ��
    }

    return key;
}


int StrLength(String*s)//�����ַ���s�ĳ��ȡ�
{
  int leng;
  leng=s->length;
  return leng;
}


String*StrClear(String*s)//���ַ���s��գ����洢�ռ䡰��ա���
{
  int i,l;
  l=s->length;
  for(i=0;i<l;i++)
    s->ch[i]=NULL;

    s->length=0;
  return s;
}


String*StrCat(String*s,String*t)//���ش�s�봮t���Ӻ�Ĵ���
{
  int i,len,len1,len2;
  String*g=(String*)malloc(sizeof(String));

  len1=s->length;
  len2=t->length;
  len=len1+len2;

char*r=(char*)calloc(len,sizeof(char));
  g=StrInit(g,r);

  for(i=0;i<len;i++)
  {
      if(i<len1)
        g->ch[i]=s->ch[i];
      else
        g->ch[i]=s->ch[i-len1];
  }

  g->length=len;

  return g;

}

void TraString(String*s)//��ӡ�ַ���s��
{
    int i;
    if(s->length==0)//��ʾ�ַ���s�ǿմ����������
       printf("�ַ���Ϊ�մ�!");
      else
      {
        for(i=0;i<s->length;i++)
        printf("%c",s->ch[i]);
      }

  printf("\n");
}


String*SubString(String*Sub,String*s,int pos,int len)//Sub�ǳ���Ϊlen���ַ����������ַ���s�ӵ�pos���ַ���ʼ����Ϊlen�����ַ�����
{
  int i,sum;
  sum=s->length;

  if((sum-pos+1)<len)//������ַ������ȴ�������ַ�����posλ�ÿ�ʼʣ����ַ����ĳ��ȣ�����
    printf("�����ַ����ĳ���>�����дӵ�pos���ַ���ʼ���Ӵ��ĳ��ȣ�����һ���մ�!\n");

  else
  {
     for(i=0;i<len;i++)
        Sub->ch[i]=s->ch[pos-1+i];//�洢Sub�ַ�������i���ַ��洢����������±���i-1��

     Sub->length=len;
  }

  return Sub;
}


int Index(String*s,String*t,int pos)//�����ַ���s�ڵ�pos���ַ��Ժ����ַ���t��ͬ�Ĵ���λ�ã����򷵻�0.
{
    int i,re,te,lens,lent;
    char*c;
    String*sq=(String*)malloc(sizeof(String));
    re=0;
    lens=s->length;
    lent=t->length;
    c=(char*)calloc(lent,sizeof(char));//�洢�ַ���s���г������ַ���t���Ӵ�
    sq->ch=c;
    sq->length=lent;

    for(i=pos-1;i<lens;i++)//�ӵ�pos���ַ���ʼȡ����Ϊlent�����ַ�����
    {
        te=lens-i;
        //printf("te:%d\n",te);
        //printf("lent:%d\n",lent);
        if(te<lent)//���ʣ�µ��ַ�����С���ַ�t�ĳ��ȣ���ʾ�Ҳ�����t��ͬ���ַ�����
        {
           printf("��ȡ�����ַ�������<Ҫ���ҵ��ַ��ĳ���,����ʧ��!\n");
           break;
        }

        else
        {
            sq=SubString(sq,s,i+1,lent);//�������s��i���ַ�֮�󳤶�Ϊlent�����ַ�����
            //TraString(sq);

            if(StrCompare(sq,t)==0)//��������ַ������ַ���t��ͬ,������ѭ����
               {
                   re=i+1;
                   break;
               }
        }
    }

 return re;
}


String*Replace(String*s,String*t,String*v)//���ַ���v�滻����s�г��ֵ��Ӵ�t��
{                                         //�����Ϊ��3�������v�ĳ���>t�ĳ��ȣ�v�ĳ���=t�ĳ��ȣ�v�ĳ���<t�ĳ���.����ʵ�֡�=����
    int i,de;                            //����Ҳ�п����ǳ���1��Ҫ�滻��Ҳ�п�����2�������ϴ�Ҫ�滻����ʵ��1���滻��
    de=Index(s,t,1);

        if(de==0)//��1�������ַ����в������ַ�����û���ҵ��ͷ��ء�
          printf("ERROR�����ַ����в�����ָ�����ַ������У�\n");

    while(de!=0)
    {
       for(i=0;i<v->length;i++)

        s->ch[de-1+i]=v->ch[i];//�ַ���v�滻�ַ���t��

       de=Index(s,t,1);
    }


    return s;
}


String*StrInsert(String*s,int pos,String*t)//�ڴ�s�ĵ�pos���ַ�ǰ�����ַ���t��
{
  int i,length;
  char*c;
  //sc=(char*)calloc(s->length,sizeof(char));
  String*sq=(String*)malloc(sizeof(String));
    //sq=StrCopy(sq,s);
  length=s->length+t->length;//��󷵻ز����Ӵ����ַ�����
     c=(char*)calloc(length,sizeof(char));
     sq->ch=c;
     sq->length=0;//�����ڳ�ʼ����
     //s->ch=c;//���¸�����s�������Ĵ洢�ռ䡣

     if((pos<1)||(pos>s->length))//����λ���쳣��
       printf("ERROR,����λ���쳣������\n");
     else
     {
         for(i=0;i<pos-1;i++)//���ַ����ĵ�1���ַ�~��pos-1���ַ���
            sq->ch[i]=s->ch[i];

         for(i=pos-1;i<pos+(t->length)-1;i++)//���ַ����ĵ�pos���ַ�����pos+t->length-1���ַ���
            sq->ch[i]=t->ch[i-pos+1];

         for(i=pos+t->length-1;i<length;i++)//���ַ����ĵ�pos+t->length����length���ַ���
            sq->ch[i]=s->ch[i-(t->length)];

     }
      sq->length=length;
  return sq;
}


String*StrDelete(String*s,int pos,int len)//ɾ���ַ���s�ӵ�pos���ַ���ʼ����Ϊlen�����ַ�����
{                                          //����һ���µ��ַ�������ţ���������ԭ�����ַ�����һ���洢�ռ䡣
  int i,le;
  le=s->length;
  String*sq=(String*)malloc(sizeof(String));
  char*c=(char*)calloc(le-len,sizeof(char));//Ϊɾ����һ�����ַ�׼���µĴ洢�ռ䡣
    sq->ch=c;
    sq->length=0;//ע��洢�ַ������ַ�����ĳ���ҲҪ�ı䡣

  if((le-pos+1)>=len)//�ӵ�pos���ַ���ʼʣ������ַ�������>=Ҫɾ���ַ����ĳ��ȡ�
  {
    for(i=0;i<(le-len);i++)
    {
        if(i<(pos-1))
            sq->ch[i]=s->ch[i];//��ԭ�������ĵ�1���ַ�����pos-1���ַ������µ��ַ�����
        else
            sq->ch[i]=s->ch[i+len];//������ʣ�ಿ���Ӵ������µ��ַ�����ʣ�ಿ�֡�
    }
     sq->length=le-len;
  }

  else//�ӵ�pos���ַ���ʼʣ������ַ�������<Ҫɾ���ַ����ĳ��ȣ�ʣ��ĳ��Ȳ���Ҫ��ɾ���ĳ��ȡ�

    {
        printf("�����ӵ�pos����ʼ���ַ�����<ָ��ɾ���ĳ���!,Ӧ�÷��ص���һ���մ���\n");

    }

  return sq;
}


void StrDestroy(String*s)//���ַ���s���١�
{
  //free(s->ch);
  //free(s->length);
  free(s);
}


int main()
{
  int a,a1;
  char b,c,d;
  char*c1=(char*)calloc(4,sizeof(char));
  char*c2=(char*)calloc(6,sizeof(char));
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
  //st=StrInit(st,c6);
  ste=StrInit(ste,c3);

  str=StrAssign(str,c1,4);
  //st=StrAssign(st,c5,4);
  ste=StrAssign(ste,c4,12);



   printf("%c\n",c1[0]);
   printf("%c\n",c1[1]);
   printf("%c\n",c1[2]);
   printf("%c\n",c1[3]);

   StrDestroy(str);

   printf("%c\n",c1[0]);
   printf("%c\n",c1[1]);
   printf("%c\n",c1[2]);
   printf("%c\n",c1[3]);
   //TraString(ste);
   //str=StrDelete(ste,3,8);
   //TraString(str);

  //TraString(ste);
  //TraString(str);
  //st=StrInsert(ste,4,str);
  //TraString(st);

 // TraString(ste);
  //ste=Replace(ste,str,st);
  //TraString(ste);


  //int g=Index(ste,str,1);
  //if(g!=0)
  //printf("�ַ����ڴ�%d���ַ���ʼ����ָ�����ַ���\n",g);
  //else
    //printf("�ַ����в�����ָ�����ȵ��ַ��������ַ���\n");

   // g=Index(ste,st,1);
  //if(g!=0)
  //printf("�ַ����ڴ�%d���ַ���ʼ����ָ�����ַ���\n",g);
  //else
  //  printf("�ַ����в�����ָ�����ȵ��ַ��������ַ���\n");


  //st=StrCopy(st,str);

  //str=SubString(str,ste,3,3);
  //st=SubString(st,ste,3,4);

  //TraString(ste);
  //printf("%d\n",ste->length);
  //TraString(str);
  //TraString(st);

  //printf("%d\n",a);
  return 0;
}
