#include<bits/stdc++.h>
using namespace std;


class person{
    char name[20];
    int age;

    public:
        
    // default constructor :: It is always called whenever we create an object;
    // we define here default values
        person(){
            
        }   



    //other functions
        void get();
        void disp();

};



// Explicitly defining constructor function outside the class
person::person(){

}


void person::get(){
    cout<<"Enter the name :"<<endl;
    gets(name);
    cout<<"Enter the age :: ";
    cin>>age;
}

void person::disp(){
    cout<<"My name is ";
    puts(name);
    cout<<"And I am "<<age<<" years old";
}



int main(){
    
    person p1;

    p1.get();
    p1.disp();

    return 0;
}