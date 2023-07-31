#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  int n;
  cout<<"Enter the dimension :: ";
  cin>>n;
  int a[n][n];
  for(int i=0 ;i<n ;i++){
   for(int j=0 ;j<n  ;j++){
    cout<<"Enter the "<<n<<","<<n<<" element :: ";
    cin>>a[i][j];
   }
  }
  
  for(int i=0 ;i<n ;i++){
   for(int j=0 ;j<n  ;j++){
    cout<<a[i][j]<<" ";
   }
   cout<<endl;
  }
  
 cout<<endl<<endl; 

for(int i=0 ;i<n ;i++){
   for(int j=i+1 ;j<n  ;j++){
      swap(a[i][j],a[j][i]);
   }
  }

  for(int i=0 ;i<n ;i++){
   for(int j=0 ;j<n  ;j++){
    cout<<a[i][j]<<" ";
   }
   cout<<endl;
  }  


return 0;
}