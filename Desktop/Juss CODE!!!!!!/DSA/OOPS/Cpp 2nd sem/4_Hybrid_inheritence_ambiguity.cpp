#include<bits/stdc++.h>
using namespace std;

class base{
    public:
        int i;
        
};

class derived1:public base{
    public:
        int a;

};

class derived2:public base{                                       
    public:
        int b;
};

class derived:public derived1,public derived2{                                       
    public:
        int m;
};




int main(){
    derived obj;

    obj.a=20;
    obj.b=25;

    //obj.i=10;                       //It will give ambiguity error 

    // means since obj object of derived class has its parent class derived1 and derived2.
    //Since both of em have one parent class base , so copy of base class's i is gone in both derived1 and derived2
    //So compiler is confused by statement which i?   i.e ambiguity
    //So we have to specify which i :: done by scope resolution operator or virtual class

    obj.derived1::i=10;



    cout<<obj.derived2::i<<endl;                        //will give some random value
    cout<<obj.derived1::i<<endl;                        //will give the value whih we have set i.e 10;


    return 0;
}