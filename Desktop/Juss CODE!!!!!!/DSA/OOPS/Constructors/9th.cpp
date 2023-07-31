#include<bits/stdc++.h>
using namespace std;

class twovalues{
    int a,b;
    public:
        twovalues(){
        }

        twovalues(int x,int y){
            a=x;
            b=y;
        }
    
        friend class B;
};

class B{
    public:
void min(twovalues v);
};

void B::min(twovalues v){
    if(v.a>v.b){
        cout<<"a is greater than b";
    }
    else{
        cout<<"b is greater than a";
    }
}


int main(){
    
    twovalues v1(2,3);
    B d1;
    d1.min(v1);

    return 0;
}