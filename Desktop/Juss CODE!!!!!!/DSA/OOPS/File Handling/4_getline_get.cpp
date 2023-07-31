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

    //dataFile.eof() represents the end of file

    while(!dataFile.eof()){
        dataFile>>output;
        cout<<output<<" ";
    }

    //still it is printing every word with 1 space gap. No line gap.



    cout<<endl;
    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}