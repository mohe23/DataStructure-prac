//P238《数据结构》
#include<iostream>
using namespace std;


void BInsertSort(int a[],int num){ //折半插入排序.num是数组a长度。
    int i,j,low,high,m;
    for(i=2;i<num;i++){
        a[0] = a[i];  //将待插入的元素暂时存放到a[0]。
        low = 1;
        high = i-1; //确定待查找区间。
        while(low<=high){
            cout<<"i: "<<i<<"   low: "<<low<<"   high: "<<high<<endl;
            m = (low+high)/2;   //折半
            if(a[0]<a[m])
                high = m-1;  //插入点在前一个子表。
            else
                low = m+1;  //插入点在后一个子表。
        }
        for(j=i-1;j>=high+1;--j)
            a[j+1] = a[j];  //记录后移。
        a[high+1] = a[0];   //将a[0]即a[i]插入到正确位置。下标为(high+1)是最终插入位置。
        cout<<"i: "<<i<<"   high+1: "<<high+1<<endl;
    }

}


void Prt(int a[],int k,int s){ //输出数组从第k个数开始之后的所有元素。从数组小标为k的元素开始输出到数组末尾，s是数组长度。
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
    BInsertSort(b,9);
     cout<<"直接插入排序后："<<endl;
    Prt(b,1,9);
}
