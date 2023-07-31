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
    char name[81];





    //GETLINE FUNCTION

    // dataFile.getline(name,81);                  //It will read whole 1 complete line including spaces          
    // cout<<name<<" ";
    
    //there is also a third parameter in getline function (str_name, string_length, stoppper_character)  
    // say stopper= ','   -> this means that after every , it will stop taking input;
    // by default it is '\n'  -> that is after evry new line it will stop accessing further so we have to initiate it again.
    // We can set it to '.'   -> to count number of lines 
    // We can set it to ' '   -> to count number of words 





    //GET FUNCTION
    
    // dataFile.get(ch);                  //It will read 1 single character and store it in ch          
    // cout<<ch<<" ";

    //It is useful to count number of letters in a file





    //so for multiple lines::
    while(!dataFile.eof()){
         dataFile.getline(name,81,'\n');                  
         cout<<name<<endl;
    }




    cout<<endl;
    //closing the file
    dataFile.close();
    cout<<"Done";

    return 0;
}