#include<bits/stdc++.h>
using namespace std;

class A{
    int age;
    public:
        int get(int age){
            this->age=age;
        }

        int ret(){
            return this->age;
        }
};

int main(){
    A u1;  
    u1.get(20);
    cout<<u1.ret();  
    return 0;
}