//P241 《数据结构》交换排序。

#include<iostream>
using namespace std;


void BubbleSort(int a[],int num){ //冒泡排序，每一趟选取最大的一个数，放在数组后面，从最后向前一个一个放。
                                   //num是数组长度，不是数组中数据个数，因为a[0]被另做他用，数据是存储在下标从1~num-1的空间中。
     int j,m,flag=1;
     m = num-2;  //第1次是n个元素排序，第2次是n-1个元素排序，依次类推。
     while((m>0)&&(flag==1)){
        flag = 0; //flag置0，若本次排序没有发生交换，就不会有下一趟排序了。
        for(j=1;j<=m;j++)
          if(a[j]>a[j+1]){
              flag = 1; //本趟发生了交换。
              a[0] = a[j];
              a[j] = a[j+1];
              a[j+1] = a[0]; //交换前后2个记录。
          }
        --m;
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
    BubbleSort(b,9);
     cout<<"冒泡排序后："<<endl;
    Prt(b,1,9);

return 0;
}
