#include<iostream>
using namespace std;

                                                                  // Vector is a dynamic array. Let us say we have 
                                                                  // a vector of size 5 nd its completely filled. Now   
#include <vector>                                                 // if we want to add more elemnts to it ( in case of 
                                                                  // array it is not possible becoz its static bt vector is dynamic).
                                                                  // So a new vector get created of double size nd the old vector get
                                                                  // copied to the new one. The old vector get dumped.                       

int main(){

    vector<int> v;

    v.push_back(5);

    cout<<"The size of the vector :: "<< v.size() << endl;
    
    cout<<"The capacity of the vector :: "<< v.capacity() << endl;


    v.push_back(6);
    cout<<"The size of the vector :: "<< v.size() << endl;
    cout<<"The capacity of the vector :: "<< v.capacity() << endl;

    v.push_back(7);
    cout<<"The size of the vector :: "<< v.size() << endl;
    cout<<"The capacity of the vector :: "<< v.capacity() << endl;

    v.push_back(8);
    cout<<"The size of the vector :: "<< v.size() << endl;
    cout<<"The capacity of the vector :: "<< v.capacity() << endl;

    v.push_back(9);
    cout<<"The size of the vector :: "<< v.size() << endl;
    cout<<"The capacity of the vector :: "<< v.capacity() << endl;

    
    return 0;
}