#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //creating an object of fstream
    fstream dataFile;             
    // Every operation is performed through "dataFile." operator
    

    //opening the file
    dataFile.open("new.txt",ios::out);
    //output mode :: a file will get created nd get stored in dataFile object. 
    
    

    //checking if there is error in opening the file
    if(!dataFile){                                                
        cout<<"Error in file opening "<<endl;
        return 0;
    }   


    //else
    cout<<"File opened successfully"<<endl;
 
    //Writing in the file
    cout<<"Now we are writing in the file"<<endl;
    
    dataFile<<"My name is :: "<<endl;
    dataFile<<"Pariansh Mahajan"<<endl;



    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}