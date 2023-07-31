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

        friend Complex operator+(Complex c1, Complex c2);
};

Complex operator+(Complex c1,Complex c2){
    Complex c3(0,0);
    c3.x=c1.x+c2.x;
    c3.y=c1.y+c2.y;
    return c3;
}


int main(){
    Complex c1(1,2),c2(3,5),c3;
    c3=c1+c2;
    c3.show();
    return 0;
}