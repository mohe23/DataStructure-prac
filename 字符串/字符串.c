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


String*StrCopy(String*s,String*t)//将字符串t复制给字符串s（已经初始化了）。
{
   int i,sum;
   sum=t->length;
   for(i=0;i<sum;i++)
    s->ch[i]=t->ch[i];

   s->length=sum;
   return s;
}


int StrEmpty(String*s)//判断字符串s是否是空串，若是空串，返回1.否则为0.
{
   int t,k;
   k=s->length;
   if(k==0)//空串。
      t=1;
   else//非空串。
    t=0;

 return t;
}


int StrCompare(String*s,String*t)//比较字符串s和字符串t,如果s>t,返回值为1；s=t,返回值为0；s<t,返回值为-1。
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
          if(s->ch[i]!=t->ch[i])//如果有一个元素不相等，就跳出循环。
          {
             r=0;
             break;
          }

      }

      if(r==1)
        key=0;
      else
        key=10;//表示字符串s和字符串t虽然长度相同，但是2个字符串不相同。
    }

    return key;
}


int StrLength(String*s)//返回字符串s的长度。
{
  int leng;
  leng=s->length;
  return leng;
}


String*StrClear(String*s)//将字符串s清空，将存储空间“清空”。
{
  int i,l;
  l=s->length;
  for(i=0;i<l;i++)
    s->ch[i]=NULL;

    s->length=0;
  return s;
}


String*StrCat(String*s,String*t)//返回串s与串t连接后的串。
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

void TraString(String*s)//打印字符串s。
{
    int i;
    if(s->length==0)//表示字符串s是空串，输出错误。
       printf("字符串为空串!");
      else
      {
        for(i=0;i<s->length;i++)
        printf("%c",s->ch[i]);
      }

  printf("\n");
}


String*SubString(String*Sub,String*s,int pos,int len)//Sub是长度为len的字符串，返回字符串s从第pos个字符开始长度为len的子字符串。
{
  int i,sum;
  sum=s->length;

  if((sum-pos+1)<len)//如果子字符串长度大于这个字符串从pos位置开始剩余的字符串的长度，报错
    printf("所求字符串的长度>主串中从第pos个字符开始的子串的长度，返回一个空串!\n");

  else
  {
     for(i=0;i<len;i++)
        Sub->ch[i]=s->ch[pos-1+i];//存储Sub字符串，第i个字符存储在数组里的下标是i-1。

     Sub->length=len;
  }

  return Sub;
}


int Index(String*s,String*t,int pos)//返回字符串s在第pos个字符以后与字符串t相同的串的位置，否则返回0.
{
    int i,re,te,lens,lent;
    char*c;
    String*sq=(String*)malloc(sizeof(String));
    re=0;
    lens=s->length;
    lent=t->length;
    c=(char*)calloc(lent,sizeof(char));//存储字符串s的中长度与字符串t的子串
    sq->ch=c;
    sq->length=lent;

    for(i=pos-1;i<lens;i++)//从第pos个字符开始取长度为lent的子字符串。
    {
        te=lens-i;
        //printf("te:%d\n",te);
        //printf("lent:%d\n",lent);
        if(te<lent)//如果剩下的字符长度小于字符t的长度，表示找不到与t相同的字符串。
        {
           printf("待取的子字符串长度<要查找的字符的长度,查找失败!\n");
           break;
        }

        else
        {
            sq=SubString(sq,s,i+1,lent);//求得主串s第i个字符之后长度为lent的子字符串。
            //TraString(sq);

            if(StrCompare(sq,t)==0)//如果该子字符串与字符串t相同,就跳出循环。
               {
                   re=i+1;
                   break;
               }
        }
    }

 return re;
}


String*Replace(String*s,String*t,String*v)//用字符串v替换主串s中出现的子串t。
{                                         //这里分为了3种情况：v的长度>t的长度；v的长度=t的长度；v的长度<t的长度.首先实现“=”。
    int i,de;                            //这里也有可能是出现1处要替换，也有可能有2处及以上处要替换。先实现1处替换。
    de=Index(s,t,1);

        if(de==0)//第1次在主字符串中查找子字符串，没有找到就返回。
          printf("ERROR！主字符串中不存在指定的字符串序列！\n");

    while(de!=0)
    {
       for(i=0;i<v->length;i++)

        s->ch[de-1+i]=v->ch[i];//字符串v替换字符串t。

       de=Index(s,t,1);
    }


    return s;
}


String*StrInsert(String*s,int pos,String*t)//在串s的第pos个字符前插入字符串t。
{
  int i,length;
  char*c;
  //sc=(char*)calloc(s->length,sizeof(char));
  String*sq=(String*)malloc(sizeof(String));
    //sq=StrCopy(sq,s);
  length=s->length+t->length;//最后返回插入子串的字符串。
     c=(char*)calloc(length,sizeof(char));
     sq->ch=c;
     sq->length=0;//类似于初始化。
     //s->ch=c;//重新给主串s分配更大的存储空间。

     if((pos<1)||(pos>s->length))//插入位置异常，
       printf("ERROR,插入位置异常！！！\n");
     else
     {
         for(i=0;i<pos-1;i++)//总字符串的第1个字符~第pos-1个字符。
            sq->ch[i]=s->ch[i];

         for(i=pos-1;i<pos+(t->length)-1;i++)//总字符串的第pos个字符到第pos+t->length-1个字符。
            sq->ch[i]=t->ch[i-pos+1];

         for(i=pos+t->length-1;i<length;i++)//总字符串的第pos+t->length到第length个字符。
            sq->ch[i]=s->ch[i-(t->length)];

     }
      sq->length=length;
  return sq;
}


String*StrDelete(String*s,int pos,int len)//删除字符串s从第pos个字符开始长度为len的子字符串。
{                                          //创建一个新的字符串来存放，而不是用原本的字符串换一个存储空间。
  int i,le;
  le=s->length;
  String*sq=(String*)malloc(sizeof(String));
  char*c=(char*)calloc(le-len,sizeof(char));//为删除了一段主字符准备新的存储空间。
    sq->ch=c;
    sq->length=0;//注意存储字符串的字符数组的长度也要改变。

  if((le-pos+1)>=len)//从第pos个字符开始剩余的子字符串长度>=要删除字符串的长度。
  {
    for(i=0;i<(le-len);i++)
    {
        if(i<(pos-1))
            sq->ch[i]=s->ch[i];//将原本主串的第1个字符到第pos-1个字符赋给新的字符串。
        else
            sq->ch[i]=s->ch[i+len];//将主串剩余部分子串赋给新的字符串的剩余部分。
    }
     sq->length=le-len;
  }

  else//从第pos个字符开始剩余的子字符串长度<要删除字符串的长度，剩余的长度不够要被删除的长度。

    {
        printf("主串从第pos个开始的字符长度<指定删除的长度!,应该返回的是一个空串。\n");

    }

  return sq;
}


void StrDestroy(String*s)//将字符串s销毁。
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
  //printf("字符串在从%d个字符开始出现指定的字符串\n",g);
  //else
    //printf("字符串中不存在指定长度的字符串的子字符串\n");

   // g=Index(ste,st,1);
  //if(g!=0)
  //printf("字符串在从%d个字符开始出现指定的字符串\n",g);
  //else
  //  printf("字符串中不存在指定长度的字符串的子字符串\n");


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
