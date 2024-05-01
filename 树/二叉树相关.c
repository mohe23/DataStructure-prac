TNode  q,q2,q3,t[4];
    int a = 0;
   q.data = 4;
   q2.data = 5;
   q3.data = 6;
   t[0].data = 34;
   t[0].lnext = &q;
   t[0].rnext = &q3;
   t[1].data = 24;
   t[2].data = 45;
   q.lnext =&q2;
   a = (q.lnext)->data;
   cout<<q.data<<endl;
   cout<<"a: "<<a<<endl;
   cout<<"t: "<<t[0].data<<endl;

   t.lnext!=NULL||t.rnext!=NULL

   void traver(TNode t,int k){//中序遍历二叉树t，k是节点的顺序数。

  if((&t)!=NULL){
         cout<<"!111"<<endl;
     traver(*(t.lnext),k);
         cout<<"!222"<<endl;
     cout<<k<<"  "<<t.data<<endl;

     k++;
         cout<<"!333"<<endl;
     traver(*(t.rnext),k);
  }

}


void traver(TNode *t){//中序遍历二叉树t，k是节点的顺序数。
    int k=1;
  if(t!=NULL){
         //cout<<"!111"<<endl;
     traver(t->lnext);
         //cout<<"!222"<<endl;
     cout<<t->data<<" ";

     //k++;
         //cout<<"!333"<<endl;
     traver(t->rnext);
  }

}



void Ftraver(TNode *t){  //先序遍历。
   if(t!=NULL){
      cout<<t->data<<endl;
      Ftraver(t->lnext);
      Ftraver(t->rnext);
   }
}


void Ntraver(TNode *t){  //后序遍历。
   if(t!=NULL){

      Ntraver(t->lnext);
      Ntraver(t->rnext);
      cout<<t->data<<endl;
   }
}


int g=1;
   q1.data = 11;
   q2.data = 12;
   q3.data = 13;
   q4.data = 14;
   q5.data = 15;
   //q6.data = 16;
   q1.lnext = &q2;
   q1.rnext = &q3;
   q2.lnext = &q4;
   q2.rnext = &q5;//手动构造了一个有5个节点的二叉树。
   q3.lnext = NULL;
   q3.rnext = NULL;
   q4.lnext = NULL;
   q4.rnext = NULL;
   q5.lnext = q5.rnext = NULL;
