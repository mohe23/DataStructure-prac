#include<iostream>
#include<stdlib.h>
using namespace std;


struct TNode{ //二叉树中1个节点的结构。
    char  data;
    struct TNode*lnext;//指向左孩子。
    struct TNode*rnext;//指向右孩子。
};


void CreateBiTree(TNode*t,char a){// 创建1个二叉树，先序遍历的顺序创建二叉树。
    //char a;
    cout<<"请输入待创建的字符：";
    cin>>a;
    cout<<endl;
    if(a=='#'){
                t = NULL;
    }
    else{
          t = (TNode*)malloc(sizeof(TNode));//为二叉树的该节点分配存储空间。
          t->data = a;
          cout<<"qw:  "<<t->data<<endl;
          CreateBiTree(t->lnext,a);//递归创建左子树。
          CreateBiTree(t->rnext,a);//递归创建右子树。
    }
 //cout<<"111"<<endl;
 //return 0;
}


void traver(TNode *t,int flag){  //先序，中序，后序遍历。
   if(1==flag){ //先序遍历
      if(t!=NULL){

       cout<<t->data<<endl;
       traver(t->lnext,flag);
       traver(t->rnext,flag);

     }
   }
   else if(2==flag){ //中序遍历
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

      cout<<"flag值非法！，flag只能取1,2,3！！"<<endl;
   }

}

int main(){
   TNode q1, q2, q3, q4, q5,*q,*p;
   char ch;
   int e;
   //p = (TNode*)malloc(sizeof(TNode));
   //p->lnext = q; //p作为头指针指向首元节点。
   e = CreateBiTree(q,ch);
   cout<<"!!!"<<endl;
  // cout<<q->data<<endl;
    traver(p->lnext,1);
   /*cout<<"中序遍历："<<endl;
   traver(&q1,2);
   cout<<endl<<endl;
   cout<<"先序遍历："<<endl;
   traver(&q1,1);
   cout<<endl<<endl;
   cout<<"后序遍历： "<<endl;
   traver(&q1,3);
   cout<<endl<<endl;*/

return 0;
}

