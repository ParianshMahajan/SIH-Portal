#include<bits/stdc++.h>
using namespace std;

int main(){
    
    //creating an object of fstream
    fstream dataFile;             

    //Again opening the file in append mode
    dataFile.open("2.txt",ios::app);
    

    if(!dataFile){                                                
        cout<<"Error in file opening "<<endl;
        return 0;
    }   
    cout<<"File opened successfully"<<endl;

    //Accessing from the file
    char ch;

    //PUT FUNCTION
    // used to put charcter by charcter to the file;

    //so for multiple lines::
    while(1){
         cin.get(ch);                  
         dataFile.put(ch);
         if(ch=='.'){
            break;
         }
    }
    cout<<endl;

    
    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}