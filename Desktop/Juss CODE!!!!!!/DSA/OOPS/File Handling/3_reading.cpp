#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //creating an object of fstream
    fstream dataFile;             




    //Again opening the file in input mode to read from the file
    dataFile.open("1.txt",ios::in);
    

    if(!dataFile){                                                
        cout<<"Error in file opening "<<endl;
        return 0;
    }   
    cout<<"File opened successfully"<<endl;

    //Accessing from the file
    char output[81];

    //By default it will count only single word 
    //but to read multiple lines we have to initiate it multiple times

    //  dataFile>>output;           //will stop after a space or new line  

    int count=4;            //count is the number of words we want to access;
    for(int i=0 ;i<count  ;i++){
        dataFile>>output;
        cout<<output<<" ";
    }
    cout<<endl;
    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}