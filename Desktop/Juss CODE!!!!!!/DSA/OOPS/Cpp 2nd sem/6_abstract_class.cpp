//Any class containing virtual function is called abstract class


#include<bits/stdc++.h>
using namespace std;

class base{
    public:
        virtual void sound()=0;
        void sleeping(){
            cout<<"sleeping"<<endl;
        }
};

class derived:virtual public base{
    public:
        void sound(){
            cout<<"woof"<<endl;
        }

};

int main(){
    derived obj;
    obj.sound();
    obj.sleeping();

    base *b1= new derived;
    b1->sleeping();
    b1->sound();

    return 0;
}   