#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    int b;

    public:
    //parametrised constructor
        A(int x,int y){
            a=x;
            b=y;
        }

    void disp(){
        cout<<a<<endl<<b<<endl;
    }

};




int main(){
    
    A person1(2,3);
    A person2(3,4);
 // A person3;         //will throw error if we declare object now without argument coz now its not default cunstructor       

    person1.disp();
    person2.disp();

    
 // Array initialisation with the help of constructor

    A obj[3]={A(0,1),A(5,6),A(3,9)};

    for(int i=0 ;i<3  ;i++){
        obj[i].disp();
    }

    return 0;
}