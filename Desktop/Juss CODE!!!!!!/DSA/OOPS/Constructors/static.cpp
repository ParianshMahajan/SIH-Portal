#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    static int b;
    public:
        
        void get(){
            cin>>a;
        }

        void dispstat(){
            b++;
            cout<<b<<endl;
        }
        
        static void show(){
            b++;
        //    a++;
            cout<<b<<endl;
        }
};

int A::b=12;


int main(){
    A u1;
    u1.get();
    u1.dispstat();
    A::show();
    
    return 0;
}