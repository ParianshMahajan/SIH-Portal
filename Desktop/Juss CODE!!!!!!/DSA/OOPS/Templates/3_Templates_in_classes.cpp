#include<bits/stdc++.h>
using namespace std;

template <class T>

class press{
    T var;
    public:
        press(T x){
            var=x;
        }
        T half(){
            return var/2;
        }
};

// Tip:: Juss initiate evry variable with datatype int and then replace it with T;


int main(){
    press<int> s1(20);
    press<char> s2('F');                                // Ascii value of 'F' = 70 ::-> so show fnction will return (35)->'#'
    press<double> s3(20.5);

    cout<<s1.half()<<endl<<s2.half()<<endl<<s3.half()<<endl;
    return 0;
}