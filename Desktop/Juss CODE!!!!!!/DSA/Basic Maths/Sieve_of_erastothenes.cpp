#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
   int n;
   cout<<"Enter the number :: ";
   cin>>n;
   vector<bool> v(n,true);
   v[0]=v[1]=0;
  int count=0;
  for(int i=2 ; i<n ;i++){
   
   if(v[i]){
      count++;
   for(int j=i+1 ; j<n ;j++){
      if(j%i==0){
         v[j]=0;
      }   
    }
   }
  }
  
  cout<<count;
   return 0;
}