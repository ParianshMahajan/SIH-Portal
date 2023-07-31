#include<bits/stdc++.h>
using namespace std;

class Complex{
    int x;
    int y;
    public:
        Complex(){

        }

        Complex(int a, int b){
            x=a;
            y=b;
        }
        void show(){
            cout<<x<<" + "<<y<<"i"<<endl;
        }

        Complex operator+(Complex c);
};

Complex Complex::operator+(Complex c){
    Complex c1(0,0);
    c1.x=c.x+x;
    c1.y=c.y+y;
    return c1;
}


int main(){
    Complex c1(1,2),c2(3,5),c3;
    c3=c1+c2;
    c3.show();
    return 0;
}