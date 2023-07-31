#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

void update(int **a){
    //  a=a+1; //Incrementing Double Pointer (Single pointer's address) (Passed Value);
    //  *a=*a+1; //Incrementing value of Double Pointer (Single pointer's value) (x's address) (Passed by reference)(pointing address of p1);
    //  **a=**a+1;//Incrementing value of Single Pointer (x value) (Passed by double reference)(pointing address of p);


}


int main(){
      int x=5;
      int *p1=&x;
      int **p2=&p1;


      cout<<"Before Updation :: "<<endl;
      cout<<"x = "<<x<<endl<<"p1 = "<<p1<<endl<<"p2 = "<<p2<<endl;

      update(p2);

      cout<<"After Updation :: "<<endl;
      cout<<"x = "<<x<<endl<<"p1 = "<<p1<<endl<<"p2 = "<<p2<<endl;


      return 0;
}