#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int a;

    void show(int x){
        a=x;
        cout<<a;
    }

};

int main(){
    //Pointer to data member

    int A::*ptr=& A::a;
    A u1;
    u1.*ptr=20;
    cout<<u1.a<<endl;

    
    //Pointer to object

    A *obj=new A;
    *obj.*ptr=25;
    cout<<obj->a;


    //Pointer to function

    void (A::*fptr)(int)=& A::show;
    (u1.*fptr)(20);


    return 0;
}