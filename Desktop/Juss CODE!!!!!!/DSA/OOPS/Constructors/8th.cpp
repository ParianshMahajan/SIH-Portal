#include<bits/stdc++.h>
using namespace std;

class A{
    int x;
    public:
        friend void get(A &s1);
        friend int disp(A &s1);
};

class B{
    int y;
    public:
    friend class A;
};


void get(A &s1){
    int d;
    cin>>d;
    s1.x=d;
}

int disp(A &s1){
    return s1.x;
}

int main(){
    A arr[5];
    int sum=0;

    for(int i=0;i<5  ;i++){
        get(arr[i]);
    }

    for(int i=0 ;i<5  ;i++){
        cout<<disp(arr[i])<<endl;
    }

    // cout<<"Average is :: "<<sum/5;

    return 0;
}