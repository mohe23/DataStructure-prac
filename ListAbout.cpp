#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node{
      int order;  // 数据域
      Node *next;  //指针域
}; // 用该结构体Lists 表示一个结点。


Node* CreateNode(Node *node, int dat){  // 创建1个结点,数据域是dat，后继指针域是NULL。
    node = (Node*)malloc(sizeof(Node)); //为即将创建的节点分配地址空间。
    node->order = dat;   // 数据域为dat
    node->next = NULL;   // 指针域为 NULL
    return  node;
}


void Prt(Node *node){    //打印节点数据域。

  cout<<"数据域： "<<node->order<<endl;
}


Node* InitList(Node* node){  //新建1个节点作为这个单链表的头结点,即初始化单链表。

     node = CreateNode(node, -1);  //该节点即为头结点。
     return node;                  //返回指向头结点的指针。

}


int GetElem(Node* node,int j){  //根据j的值取单链表node中第j个元素的值。

     Node *p;
     int i=0,data;
     p = node;
     while(p&&i<j){ //在正常范围中做循环，如果出现非法，比如根本不存在该元素。
        p = p->next;
        i = i + 1;
     }
     if(!p||i>j)  //
        cout<<"单链表中没有该值！"<<endl;
     else
        data = p->order;

  return data;
}


Node* LocateElem(Node* node, int exp){   //查找在单链表中数据域等于exp的节点。

      Node *p;
      int flag=0; //用来进行标记。
      p = node->next; //p用来指向首元节点。
      while(p){  //只要在单链表长度范围内没有找到这个
         if(p->order != exp)
              p = p->next;
         else{
            flag = 1;  //表示在单链表中找出了数据域与exp相同的节点。
            break;
         }
      }
      if(flag == 0) // 表示待查找的单链表中没有数据域为exp的节点。
        p = node;    // 那么就返回单链表的头结点。

    return  p;
}


Node* ListInsert(Node*node, int j, int exp){  // 数据域为exp的新节点插入到单链表弟j个位置。
       Node*p,*q;
       p = node;  //指向单链表的头结点。
       int i=0;
       q = CreateNode(q,exp); // 创建要出入单链表的节点。
       while(p&&(i<j-1)){
           p = p->next;   // 找到插入前单链表的第i-1个节点。
           i = i + 1;
       }

       if(!p&&(j>i-1))  //2种情况，1：插入位置 > 链表长度+1；2：插入位置 < 1,
          cout<<"插入位置非法！"<<endl;
       else{
             q->next = p->next;
             p->next = q;
       }


       return node;
}



Node* ListDelete(Node*node, int i){ //  删除单链表node中第i个节点。
      Node *p,*q;
      int j=0;
      p = node;
      while((p->next)&&(j<i-1)){  // 在找出待删除的前一个元素的过程中，保证循环时有元素存在。
            p = p->next;
            j = j + 1;
      }
       if(!(p->next)||(j>i-1)) // 当 i>n 或者 i<1，删除位置不合理。不会删除
            cout<<"删除位置不合理，单链表不做删除处理！!!"<<endl;
       else{
             q = p->next; // q是待待删除的元素。
             p->next = q->next;
             delete q;
       }

    return node;
}


Node* CreateList_H(Node*node, int n){ // 用 前插法 创建1个有n个元素的单链表，每次都把创建的元素插入到头结点。
       int i,d;
       node = InitList(node);
        cout<<"请输入 "<<n<<" 节点的数据域："<<endl;
       for(i=0;i<n;i++){
            Node* p;

           cout<<"第 "<<i+1<<" 个输入的节点数据域：";
           cin>>d;
           cout<<endl;
           p = CreateNode(p,d);
           p->next = node->next; //将节点插入到单链表中。
           node->next = p;
       }

  return node;  //返回创建的单链表的头结点node。
}


void Prts(Node*node){  // 打印单链表的数据域值。
    Node*p;
    int i=1;
    p = node->next;
    while(p){ //打印所有数据节点的数据域。
        cout<<"第 "<<i<<" 个节点数据域："<<p->order<<endl;
        p = p->next;
        i = i + 1;
    }

}


void Prtw(Node*node){  // 打印单链表的数据域。
    Node*p;
    p = node->next;

    while(p){
        cout<<p->order;

        if(p->next) // 当前要打印的节点不是最后1个节点，需要打印->。
            cout<<" -> ";

        p = p->next;
    }
    cout<<endl;

}


Node* CreateList_R(Node*node, int n){ // 用 后插法 创建含有n个元素的单链表。即每次把新节点挂在链表尾部。
    Node* r;
    int i,d;
    node = InitList(node);
    r = node;
    cout<<"请输入 "<<n<<" 节点的数据域："<<endl;
    for(i=0;i<n;i++){
            Node* p;

           cout<<"第 "<<i+1<<" 个的节点数据域：";
           cin>>d;
           cout<<endl;
           p = CreateNode(p,d);
           r->next = p; //将节点插入到单链表中。
           r = p;
       }

  return node;
}


int ListLength(Node*node){ // 求单链表node的元素个数。
      int len=0;
      Node*p;
      p = node->next;
      while(p){
         len++;
         p = p->next;
      }

  return len;
}


int main(){

  //cout<<"wondeful!"<<endl;
  Node *s,*s1,*s2,*s3,*s4,*s5,*h;
  int a=0,b=0;
  s = InitList(s);
  s1 = CreateNode(s1,1);
  s2 = CreateNode(s2,2);
  s3 = CreateNode(s3,3);
  s4 = CreateNode(s4,4);
  s5 = CreateNode(s5,5);
  s->next = s1;
  s1->next = s2;
  s2->next = s3;
  s3->next = s4;
  s4->next = s5;

  h = CreateList_R(h,4);
  cout<<"打印数据："<<endl;
  Prts(h);
  Prtw(h);
  a = ListLength(h);
  cout<<"a: "<<a<<endl;

  return 0;
}

