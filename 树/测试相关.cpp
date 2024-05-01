#include<iostream>
using namespace std;


struct Wes{
    int dat;
    char chd;
};


int main(){
     Wes*w1,*w2;
     w1 = new Wes;
     w2 = new Wes;
     w1->dat = 1;
     w2->dat = 2;
     cout<<"w1: ";
     cout<<w1->dat<<endl;
     cout<<"w2: ";
     cout<<w2->dat<<endl;

return 0;
}
