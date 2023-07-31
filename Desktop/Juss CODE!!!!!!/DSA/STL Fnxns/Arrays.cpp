#include<iostream>
using namespace std;

#include<array>                                                      // Array Library

int main(){
    
    array<int,4> x={1,2,3,4};                                       // way of initialising an array :: 
                                                                    // array<datatype,size> array_name = define; 


    cout<<"The element at index 2 is :: "<< x.at(2) <<endl;         // Fnxn returns element at given index.


    cout<<"The size of array is :: "<< x.size() <<endl;             // Fnxn returns size (length) of array.


    cout<<"Empty or not "<< x.empty() <<endl;                       // Tells us whether the array is empty or  
                                                                    // not by returning bool values               


    cout<<"The value of first element :: "<< x.front() <<endl;      // Gives the first value of array.
    
    
    cout<<"The value of last element :: "<< x.back() <<endl;        // Gives the last value of array.


    return 0;
}