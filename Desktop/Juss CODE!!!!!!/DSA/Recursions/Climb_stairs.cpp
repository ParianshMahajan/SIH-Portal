#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>


int count(int n){
     if(n<=0)
          return 0;
     
     if(n==1)
          return 1;

     if(n==2)
          return 2;


     return count(n-1)+count(n-2);
}


int main(){
     int n;
     cin>>n;
     cout<<count(n);
     return 0;
}