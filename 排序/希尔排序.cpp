//P239 �����ݽṹ��ѡ������

#include<iostream>
using namespace std;

void Prt(int a[],int k,int s){ //�������ӵ�k������ʼ֮�������Ԫ�ء�������С��Ϊk��Ԫ�ؿ�ʼ���������ĩβ��s�����鳤�ȡ�
    int i;
    for(i=k;i<s;i++)
        cout<<a[i]<<"   ";
}


void ShellInsert(int a[],int num,int dk){ //������dk������㷨���Բ��ա�ֱ�Ӳ����㷨����ֱ�Ӳ����㷨�൱������㷨��dkȡ1��
     int i,j;
     for(i=dk+1;i<num;++i){
        if(a[i]<a[i-dk]){ //��Ҫ��a[i]�������������ӱ�
            a[0] = a[i];  //������Ԫ����ʱ�����a[0]�С�
            for(j=i-dk;j>0&&a[0]<a[j];j-=dk)
                a[j+dk] = a[j];  //Ԫ�غ��ƣ�
            a[j+dk] = a[0];
        }
     }
}


void ShellSort(int a[],int anum,int dt[],int tnum){ //ϣ������dt�����ŵ�������tnum������������
     int k;
     for(k=0;k<tnum;++k){
         ShellInsert(a,anum,dt[k]); //ͨ���ı���������������
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
    cout<<"����ǰ��"<<endl;
    Prt(b,1,9);
    cout<<endl;
    ShellSort(b,9,c,3);
     cout<<"ϣ�������"<<endl;
    Prt(b,1,9);

return 0;
}
