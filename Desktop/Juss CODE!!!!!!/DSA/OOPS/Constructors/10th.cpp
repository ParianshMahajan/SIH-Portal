#include<bits/stdc++.h>
using namespace std;

class A{
    int *ptr;
    public:
        void get(){
            cin>>*ptr;
        }
        
        void disp(){
            int x=*ptr;
            cout<<x;
        }
        
};

int main(){
    A u1;
    u1.get();
   // cout<<endl;
    u1.disp();
    return 0;
}