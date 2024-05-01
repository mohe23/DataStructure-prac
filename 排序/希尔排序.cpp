//P239 《数据结构》选择排序。

#include<iostream>
using namespace std;

void Prt(int a[],int k,int s){ //输出数组从第k个数开始之后的所有元素。从数组小标为k的元素开始输出到数组末尾，s是数组长度。
    int i;
    for(i=k;i<s;i++)
        cout<<a[i]<<"   ";
}


void ShellInsert(int a[],int num,int dk){ //增量是dk。这个算法可以参照“直接插入算法”，直接插入算法相当于这个算法的dk取1。
     int i,j;
     for(i=dk+1;i<num;++i){
        if(a[i]<a[i-dk]){ //需要将a[i]插入有序增量子表。
            a[0] = a[i];  //待排序元素暂时存放在a[0]中。
            for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
                a[j+dk] = a[j];  //元素后移，
            a[j+dk] = a[0];
        }
     }
}


void ShellSort(int a[],int anum,int dt[],int tnum){ //希尔排序。dt数组存放的增量。tnum是增量个数。
     int k;
     for(k=0;k<tnum;++k){
         ShellInsert(a,anum,dt[k]); //通过改变增量，不断排序。
         Prt(a,1,anum);
         cout<<endl<<endl;
     }

}




int main(){
   int i,b[9],c[3];
   c[0]=5; c[1]=3; c[2]=1;
    b[1]=49;b[2]=38;b[3]=65;b[4]=97;b[5]=76;b[6]=13;b[7]=27;b[8]=49;
    //for(i=1;i<9;i++)
      //  cin>>b[i];
    cout<<"排序前："<<endl;
    Prt(b,1,9);
    cout<<endl;
    ShellSort(b,9,c,3);
     cout<<"希尔排序后："<<endl;
    Prt(b,1,9);

return 0;
}
