#include<bits/stdc++.h>
using namespace std;

template <class T,int n>

class press{
    T var;
    public:
        press(){
            var=n;
        }

        T half();
};

//It is complex to declare template function outside class

template <class T,int n>
T press<T,n> :: half(){
    return var/2;
}


int main(){
    press<int,20> s1;
    press<double,30> s2;

    cout<<s1.half()<<endl<<s2.half()<<endl;
    return 0;
}