//P245 《数据结构》交换排序

#include<iostream>
using namespace std;

int Partitions(int a[],int low,int high){ //完成1次快速排序，返回枢纽的位置。
    int piv;  //存放枢纽的值。
    a[0] = a[low]; //将数组中第1个数据元素（a[1]）作为枢纽记录。
    piv = a[0]; //枢纽值。
    while(low<high){
        while(low<high&&a[high]>=piv) //从数组右侧向左
            --high;
        a[low] = a[high];  //将比枢纽小的值移动到低端。
        while(low<high&&a[low]<=piv)  //从数组左侧开始
            ++low;   //若当前数值小于枢纽值，则将low指针向右移动。
        a[high] = a[low];  //将比枢纽大的值移动到高端，即数组右边。
    }
    a[low] = a[0]; //此时，low==high,找到了枢纽的位置，以枢纽为界，将数组分为2个“数组”。

return low;//返回枢纽位置。
}


void Qsort(int a[],int low,int high){ //。low=1,high=数组中元素个数。
    int pv;
   if(low<high){
     pv = Partitions(a,low,high);
     Qsort(a,low,pv-1); //对左子表排序
     Qsort(a,pv+1,high); //对右子表排序。
   }
}


void QuickSort(int a[],int length){
      Qsort(a,1,length);//length是数组中元素个数。
}


void Prt(int a[],int k,int s){ //输出数组从第k个数开始之后的所有元素。，s是数组长度。
    int i;
    for(i=k;i<s;i++)
        cout<<a[i]<<"   ";
}


int main(){
   int i,b[9];
    b[1]=49;b[2]=38;b[3]=65;b[4]=97;b[5]=76;b[6]=13;b[7]=27;b[8]=49;
    cout<<"排序前："<<endl;
    Prt(b,1,9);
    cout<<endl;
    QuickSort(b,8);
    cout<<"快速排序后："<<endl;
    Prt(b,1,9);

 return 0;
}
