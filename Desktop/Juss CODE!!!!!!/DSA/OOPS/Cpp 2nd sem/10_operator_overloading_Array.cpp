#include<bits/stdc++.h>
using namespace std;

class A{
    int x[3];
    public:
        void getarray(){
            for(int i=0 ;i<3  ;i++){
                cin>>x[i];
            }
        }

        void show(){
            for(int i=0 ;i<3  ;i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }

        int operator[](int i){
            return x[i];
        };                                         // prefix operator
};




int main(){
    A n1;
    n1.getarray();
    cout<<n1[2];
    return 0;
}