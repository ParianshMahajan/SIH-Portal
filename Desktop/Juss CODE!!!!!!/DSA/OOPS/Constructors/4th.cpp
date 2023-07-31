#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    int b;

    public:
    // Default constructor
        A(){

        }
        
    //copy constructor
    A(A&P){
        a=P.a;
        b=P.b;
    }

    void get(){
        cin>>a>>b;
    }

    void disp(){
        cout<<a<<endl<<b<<endl;
    }

};




int main(){
    
    A p1 ;        
    p1.get();

     A p2(p1) ;   
    p2.disp();




    return 0;
}