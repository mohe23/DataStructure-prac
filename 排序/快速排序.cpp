//P245 �����ݽṹ����������

#include<iostream>
using namespace std;

int Partitions(int a[],int low,int high){ //���1�ο������򣬷�����Ŧ��λ�á�
    int piv;  //�����Ŧ��ֵ��
    a[0] = a[low]; //�������е�1������Ԫ�أ�a[1]����Ϊ��Ŧ��¼��
    piv = a[0]; //��Ŧֵ��
    while(low<high){
        while(low<high&&a[high]>=piv) //�������Ҳ�����
            --high;
        a[low] = a[high];  //������ŦС��ֵ�ƶ����Ͷˡ�
        while(low<high&&a[low]<=piv)  //��������࿪ʼ
            ++low;   //����ǰ��ֵС����Ŧֵ����lowָ�������ƶ���
        a[high] = a[low];  //������Ŧ���ֵ�ƶ����߶ˣ��������ұߡ�
    }
    a[low] = a[0]; //��ʱ��low==high,�ҵ�����Ŧ��λ�ã�����ŦΪ�磬�������Ϊ2�������顱��

return low;//������Ŧλ�á�
}


void Qsort(int a[],int low,int high){ //��low=1,high=������Ԫ�ظ�����
    int pv;
   if(low<high){
     pv = Partitions(a,low,high);
     Qsort(a,low,pv-1); //�����ӱ�����
     Qsort(a,pv+1,high); //�����ӱ�����
   }
}


void QuickSort(int a[],int length){
      Qsort(a,1,length);//length��������Ԫ�ظ�����
}


void Prt(int a[],int k,int s){ //�������ӵ�k������ʼ֮�������Ԫ�ء���s�����鳤�ȡ�
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
    QuickSort(b,8);
    cout<<"���������"<<endl;
    Prt(b,1,9);

 return 0;
}
