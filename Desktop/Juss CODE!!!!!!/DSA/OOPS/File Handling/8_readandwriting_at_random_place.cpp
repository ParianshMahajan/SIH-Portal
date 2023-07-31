#include <iostream>
#include <fstream>
using namespace std;

int main(){ 
    fstream file("1.txt", ios::in);                // both input(read) and output(write)
    char ch;

    //Seek get

    file.seekg(6L, ios::beg);                       //sets cursor to the pos 6 bytes away from beginning
    file.get(ch);
    cout << "Byte 5 from beginning: " << ch <<endl;

    file.seekg(-5L, ios::end);
    file.get(ch);
    cout << "Byte 10 from end: " << ch<< endl;
    
    file.seekg(3L, ios::cur);
    file.get(ch);
    cout << "Byte 3 from current: " << ch<< endl;



    //seek put
    
    file.seekp(3L, ios::beg);
    file.put('g');
    //since write so it will replace the byte with 'H'
    cout<<"We put 'H' on 3rd byte from beginning"<<endl;



    file.close();

    return 0;
}