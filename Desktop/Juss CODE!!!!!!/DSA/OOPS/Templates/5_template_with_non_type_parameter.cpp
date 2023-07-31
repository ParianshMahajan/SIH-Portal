#include<bits/stdc++.h>
using namespace std;

template <class T,int n>
T show(T a){
    cout<<"Entered parameter is :: "<<n<<endl;
    return a/2;
}

int main(){
    cout<<show<char,30>('c'); 
    return 0;
}