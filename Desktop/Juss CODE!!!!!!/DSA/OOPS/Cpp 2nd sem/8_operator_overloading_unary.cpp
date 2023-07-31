#include<bits/stdc++.h>
using namespace std;

class number{
    int x;
    public:
        number(){

        }

        number(int a){
            x=a;
        }
        void show(){
            cout<<x<<endl;
        }

        void operator ++();                                         // prefix operator
        void operator --(int);                                         // postfix operator
};

void number::operator ++(){
    x++;
}
void number::operator --(int){
    x--;
}


int main(){
    number n1(2);
    ++n1;
    n1.show();
    n1--;
    n1.show();
    return 0;
}