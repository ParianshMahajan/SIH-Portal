#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    int b;

    public:
    // default parametrised constructor
        A(int x,int y=2){
            a=x;
            b=y;
        }

    void disp(){
        cout<<a<<endl<<b<<endl;
    }

};




int main(){
    
    A person1(2);       //default value is used
    A person2(3,4);     // value overwrited
 

    person1.disp();
    person2.disp();

    return 0;
}