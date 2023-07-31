#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //creating an object of fstream
    fstream dataFile;             




    //Again opening the file in append mode to append in the same file
    dataFile.open("1.txt",ios::app);
    

    if(!dataFile){                                                
        cout<<"Error in file opening "<<endl;
        return 0;
    }   
    cout<<"File opened successfully"<<endl;

    //Appending in the file
    cout<<"Now we are appending in the file"<<endl;   
    dataFile<<"My age is 17."<<endl;
    dataFile<<"I am not an adult :)";

    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}