#include<bits/stdc++.h>
using namespace std;

class student{
    int age;
    public:
        student(){

        }
        
        student(int x){
            age=x;
        }

        void get(){
            cin>>age;
        }

        void disp(){
            cout<<age<<endl;
        }
        
        bool greaterThan( student x);

        void func(student obj);
};

// Juss a random function
bool student::greaterThan(student x){
    if(x.age>age){
        return false;
    }
    else{
        return true;
    }
}

// CLass member function
void student:: func(student obj){
    obj.get();
    obj.disp();
    cout<<obj.age;
}

// Friend function;


int main(){
    student s1(40),s2(30);
    cout<<s1.greaterThan(s2)<<endl;    
 
    student s3;
    s3.func(s3);
 
    return 0;
}