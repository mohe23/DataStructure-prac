//P237  《数据结构》  插入排序

#include<iostream>
using namespace std;

//P237《数据结构》
void InsertSort(int a[], int num){ //num是数组长度，比数组中实际存储的元素个数大1。
    int i,j;
    for(i=2;i<num;i++){
        if(a[i]<a[i-1]){ //说明当前元素需要插入到前面的有序序列。
            a[0] = a[i];//将当前待插入元素存放在第1个位置。
            a[i] = a[i-1]; //将有序序列最后1个元素后移一个位置。
            for(j=i-2;a[0]<a[j];j--)//从后向前找插入位置。因为前面已经移动1个元素了，所以是从i-2开始。
                a[j+1] = a[j];  //如果有序序列的当前元素大于a[0]，说明a[0]的插入位置还要往前，这样让当前元素a[j]后移一个位置。
            a[j+1] = a[0];  //若果当前元素小于a[0],说明a[0]的位置在这个元素a[j]之后，正好是a[j+1]
        }
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
    //for(i=1;i<9;i++)
      //  cin>>b[i];
    cout<<"排序前："<<endl;
    Prt(b,1,9);
    cout<<endl;
    InsertSort(b,9);
     cout<<"直接插入排序后："<<endl;
    Prt(b,1,9);

return 0;
}
