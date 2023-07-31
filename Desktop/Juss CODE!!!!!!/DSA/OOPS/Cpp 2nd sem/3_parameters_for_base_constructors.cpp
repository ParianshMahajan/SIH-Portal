#include<bits/stdc++.h>
using namespace std;

class base1{
    protected:
        int a;
    public:
        base1(int x){
            a=x;
        }
        
};

class base2{
    protected:
        int b;
    public:
        base2(int y){
            b=y;
        }
};

class derived:public base2,public base1{                                       
    protected:
        int c;
    public:
        derived(int x,int y,int z):base1(x),base2(y){
            c=z;
        }
        
        void show(){
            cout<<a<<" "<<b<<" "<<c<<endl;
        }

};


int main(){
    derived d1(2,3,4);
    d1.show();
    return 0;
}