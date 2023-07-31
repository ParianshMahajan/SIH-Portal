#include<bits/stdc++.h>
using namespace std;

class base1{
    public:
        base1(){
            cout<<"base1 class constructor"<<endl;
        }
        
        ~base1(){
            cout<<"base1 class destructor"<<endl;
        }
};

class base2{
    public:
        base2(){
            cout<<"base2 class constructor"<<endl;
        }
        
        ~base2(){
            cout<<"base2 class destructor"<<endl;
        }
};

class derived:public base2,public base1{                                    // here, if base1 is b4 base2 then base1 constructors will run first    
    public:
        derived(){
            cout<<"derived class constructor"<<endl;
        }
        
        ~derived(){
            cout<<"derived class destructor"<<endl;
        }

};


int main(){
    derived d1;
    return 0;
}