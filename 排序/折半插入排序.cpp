//P238�����ݽṹ��
#include<iostream>
using namespace std;


void BInsertSort(int a[],int num){ //�۰��������.num������a���ȡ�
    int i,j,low,high,m;
    for(i=2;i<num;i++){
        a[0] = a[i];  //���������Ԫ����ʱ��ŵ�a[0]��
        low = 1;
        high = i-1; //ȷ�����������䡣
        while(low<=high){
            cout<<"i: "<<i<<"   low: "<<low<<"   high: "<<high<<endl;
            m = (low+high)/2;   //�۰�
            if(a[0]<a[m])
                high = m-1;  //�������ǰһ���ӱ�
            else
                low = m+1;  //������ں�һ���ӱ�
        }
        for(j=i-1;j>=high+1;--j)
            a[j+1] = a[j];  //��¼���ơ�
        a[high+1] = a[0];   //��a[0]��a[i]���뵽��ȷλ�á��±�Ϊ(high+1)�����ղ���λ�á�
        cout<<"i: "<<i<<"   high+1: "<<high+1<<endl;
    }

}


void Prt(int a[],int k,int s){ //�������ӵ�k������ʼ֮�������Ԫ�ء�������С��Ϊk��Ԫ�ؿ�ʼ���������ĩβ��s�����鳤�ȡ�
    int i;
    for(i=k;i<s;i++)
        cout<<a[i]<<"   ";
}


int main(){
   int i,b[9];
    b[1]=49;b[2]=38;b[3]=65;b[4]=97;b[5]=76;b[6]=13;b[7]=27;b[8]=49;

    cout<<"����ǰ��"<<endl;
    Prt(b,1,9);
    cout<<endl;
    BInsertSort(b,9);
     cout<<"ֱ�Ӳ��������"<<endl;
    Prt(b,1,9);
}
