#include<bits/stdc++.h>
using namespace std;

class A{        
    int a,b;                    //Constructor Overloading
                
    public:
        A(){                        //Default Constructor
            a=0;
            b=0;
        }

        A(int x,int y){             //Parametrised Constructor
            a=x;
            b=y;
        }

        A(A&p1){                    //Copy constructor
            a=p1.a;
            b=p1.b;
        }

        void disp(){
            cout<<a<<endl<<b<<endl;
        }

};

int main(){

    A z1;
    A z2(2,3);
    A z3(z2);
    
    z1.disp();
    z2.disp();
    z3.disp();

    return 0;
}