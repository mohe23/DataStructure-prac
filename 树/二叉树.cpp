#include<iostream>
#include<stdlib.h>
using namespace std;


struct TNode{ //��������1���ڵ�Ľṹ��
    char  data;
    struct TNode*lnext;//ָ�����ӡ�
    struct TNode*rnext;//ָ���Һ��ӡ�
};


void CreateBiTree(TNode*t,char a){// ����1�������������������˳�򴴽���������
    //char a;
    cout<<"��������������ַ���";
    cin>>a;
    cout<<endl;
    if(a=='#'){
                t = NULL;
    }
    else{
          t = (TNode*)malloc(sizeof(TNode));//Ϊ�������ĸýڵ����洢�ռ䡣
          t->data = a;
          cout<<"qw:  "<<t->data<<endl;
          CreateBiTree(t->lnext,a);//�ݹ鴴����������
          CreateBiTree(t->rnext,a);//�ݹ鴴����������
    }
 //cout<<"111"<<endl;
 //return 0;
}


void traver(TNode *t,int flag){  //�������򣬺��������
   if(1==flag){ //�������
      if(t!=NULL){

       cout<<t->data<<endl;
       traver(t->lnext,flag);
       traver(t->rnext,flag);

     }
   }
   else if(2==flag){ //�������
      if(t!=NULL){

       traver(t->lnext,flag);
       cout<<t->data<<endl;
       traver(t->rnext,flag);

     }

   }
   else if(3==flag){
      if(t!=NULL){

        traver(t->lnext,flag);
        traver(t->rnext,flag);
        cout<<t->data<<endl;
     }

   }
   else{

      cout<<"flagֵ�Ƿ�����flagֻ��ȡ1,2,3����"<<endl;
   }

}

int main(){
   TNode q1, q2, q3, q4, q5,*q,*p;
   char ch;
   int e;
   //p = (TNode*)malloc(sizeof(TNode));
   //p->lnext = q; //p��Ϊͷָ��ָ����Ԫ�ڵ㡣
   e = CreateBiTree(q,ch);
   cout<<"!!!"<<endl;
  // cout<<q->data<<endl;
    traver(p->lnext,1);
   /*cout<<"���������"<<endl;
   traver(&q1,2);
   cout<<endl<<endl;
   cout<<"���������"<<endl;
   traver(&q1,1);
   cout<<endl<<endl;
   cout<<"��������� "<<endl;
   traver(&q1,3);
   cout<<endl<<endl;*/

return 0;
}

