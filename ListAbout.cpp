#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node{
      int order;  // ������
      Node *next;  //ָ����
}; // �øýṹ��Lists ��ʾһ����㡣


Node* CreateNode(Node *node, int dat){  // ����1�����,��������dat�����ָ������NULL��
    node = (Node*)malloc(sizeof(Node)); //Ϊ���������Ľڵ�����ַ�ռ䡣
    node->order = dat;   // ������Ϊdat
    node->next = NULL;   // ָ����Ϊ NULL
    return  node;
}


void Prt(Node *node){    //��ӡ�ڵ�������

  cout<<"������ "<<node->order<<endl;
}


Node* InitList(Node* node){  //�½�1���ڵ���Ϊ����������ͷ���,����ʼ��������

     node = CreateNode(node, -1);  //�ýڵ㼴Ϊͷ��㡣
     return node;                  //����ָ��ͷ����ָ�롣

}


int GetElem(Node* node,int j){  //����j��ֵȡ������node�е�j��Ԫ�ص�ֵ��

     Node *p;
     int i=0,data;
     p = node;
     while(p&&i<j){ //��������Χ����ѭ����������ַǷ���������������ڸ�Ԫ�ء�
        p = p->next;
        i = i + 1;
     }
     if(!p||i>j)  //
        cout<<"��������û�и�ֵ��"<<endl;
     else
        data = p->order;

  return data;
}


Node* LocateElem(Node* node, int exp){   //�����ڵ����������������exp�Ľڵ㡣

      Node *p;
      int flag=0; //�������б�ǡ�
      p = node->next; //p����ָ����Ԫ�ڵ㡣
      while(p){  //ֻҪ�ڵ������ȷ�Χ��û���ҵ����
         if(p->order != exp)
              p = p->next;
         else{
            flag = 1;  //��ʾ�ڵ��������ҳ�����������exp��ͬ�Ľڵ㡣
            break;
         }
      }
      if(flag == 0) // ��ʾ�����ҵĵ�������û��������Ϊexp�Ľڵ㡣
        p = node;    // ��ô�ͷ��ص������ͷ��㡣

    return  p;
}


Node* ListInsert(Node*node, int j, int exp){  // ������Ϊexp���½ڵ���뵽�������j��λ�á�
       Node*p,*q;
       p = node;  //ָ�������ͷ��㡣
       int i=0;
       q = CreateNode(q,exp); // ����Ҫ���뵥����Ľڵ㡣
       while(p&&(i<j-1)){
           p = p->next;   // �ҵ�����ǰ������ĵ�i-1���ڵ㡣
           i = i + 1;
       }

       if(!p&&(j>i-1))  //2�������1������λ�� > ������+1��2������λ�� < 1,
          cout<<"����λ�÷Ƿ���"<<endl;
       else{
             q->next = p->next;
             p->next = q;
       }


       return node;
}



Node* ListDelete(Node*node, int i){ //  ɾ��������node�е�i���ڵ㡣
      Node *p,*q;
      int j=0;
      p = node;
      while((p->next)&&(j<i-1)){  // ���ҳ���ɾ����ǰһ��Ԫ�صĹ����У���֤ѭ��ʱ��Ԫ�ش��ڡ�
            p = p->next;
            j = j + 1;
      }
       if(!(p->next)||(j>i-1)) // �� i>n ���� i<1��ɾ��λ�ò���������ɾ��
            cout<<"ɾ��λ�ò�������������ɾ������!!"<<endl;
       else{
             q = p->next; // q�Ǵ���ɾ����Ԫ�ء�
             p->next = q->next;
             delete q;
       }

    return node;
}


Node* CreateList_H(Node*node, int n){ // �� ǰ�巨 ����1����n��Ԫ�صĵ�����ÿ�ζ��Ѵ�����Ԫ�ز��뵽ͷ��㡣
       int i,d;
       node = InitList(node);
        cout<<"������ "<<n<<" �ڵ��������"<<endl;
       for(i=0;i<n;i++){
            Node* p;

           cout<<"�� "<<i+1<<" ������Ľڵ�������";
           cin>>d;
           cout<<endl;
           p = CreateNode(p,d);
           p->next = node->next; //���ڵ���뵽�������С�
           node->next = p;
       }

  return node;  //���ش����ĵ������ͷ���node��
}


void Prts(Node*node){  // ��ӡ�������������ֵ��
    Node*p;
    int i=1;
    p = node->next;
    while(p){ //��ӡ�������ݽڵ��������
        cout<<"�� "<<i<<" ���ڵ�������"<<p->order<<endl;
        p = p->next;
        i = i + 1;
    }

}


void Prtw(Node*node){  // ��ӡ�������������
    Node*p;
    p = node->next;

    while(p){
        cout<<p->order;

        if(p->next) // ��ǰҪ��ӡ�Ľڵ㲻�����1���ڵ㣬��Ҫ��ӡ->��
            cout<<" -> ";

        p = p->next;
    }
    cout<<endl;

}


Node* CreateList_R(Node*node, int n){ // �� ��巨 ��������n��Ԫ�صĵ�������ÿ�ΰ��½ڵ��������β����
    Node* r;
    int i,d;
    node = InitList(node);
    r = node;
    cout<<"������ "<<n<<" �ڵ��������"<<endl;
    for(i=0;i<n;i++){
            Node* p;

           cout<<"�� "<<i+1<<" ���Ľڵ�������";
           cin>>d;
           cout<<endl;
           p = CreateNode(p,d);
           r->next = p; //���ڵ���뵽�������С�
           r = p;
       }

  return node;
}


int ListLength(Node*node){ // ������node��Ԫ�ظ�����
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
  cout<<"��ӡ���ݣ�"<<endl;
  Prts(h);
  Prtw(h);
  a = ListLength(h);
  cout<<"a: "<<a<<endl;

  return 0;
}

