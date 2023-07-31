#include<bits/stdc++.h>
using namespace std;

class A{
int a,b;

public:
 
    void get(int x ,int y){
        a=x;
        b=y;
        cout<<this<<endl;                                 // 'this' is the unknown hidden argument which automatically stores the object's address;
    }

    void disp(){
        cout<<a<<"  "<<b<<endl;
        cout<<this<<endl;
    }

    void show(){
        cout<< this->a;                                   //we can access the data members by object's address using arrow operator
    }

};

int main(){
    A p1;
    p1.get(2,3);                                   // p1's address also get passed to the function;
    
    cout<<&p1<<endl;                                // same address will be printed;
    
    
    p1.disp();                                      //even again its adress is also passed as hidden argument;   

    p1.show();
    return 0;
}