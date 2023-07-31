#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int gcd(int a,int b){
   while(a>0){
      a=a-b;
   }
   return a+b;
}


int main(){
   int n,m;
   cout<<"Enter the numbers :: ";
   cin>>n;
   cin>>m;
   if(m<n){
      swap(m,n);
   }
   int x=gcd(m,n);
   cout<<x;

   return 0;
}