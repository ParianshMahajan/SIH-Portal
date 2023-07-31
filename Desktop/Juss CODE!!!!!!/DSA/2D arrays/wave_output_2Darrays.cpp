#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  int n,m;
  cout<<"Enter the number of rows :: ";
  cin>>m;
  
  cout<<"Enter the number of collumns :: ";
  cin>>n;
 
 vector<int>v;
 int a[m][n];
 
 for(int i=0;i<m  ;i++){
  for(int j=0 ;j<n  ;j++){
   cout<<"Enter the value of "<<i<<","<<j<<" :: ";
      cin>>a[i][j];
  }
 }

 for(int i=0;i<m  ;i++){
 for(int j=0 ;j<n  ;j++){
      cout<<a[i][j]<<" ";
 }
 cout<<endl;
 }
 cout<<endl;


 for(int j=0 ;j<n  ;j++){
if((j+1)%2==0){
 for(int i=m-1 ;i>=0  ;i--){
      cout<<a[i][j]<<" ";
 }
}
else{
 for(int i=0 ;i<m  ;i++){
      cout<<a[i][j]<<" ";
 }
}
 }

  return 0;
}