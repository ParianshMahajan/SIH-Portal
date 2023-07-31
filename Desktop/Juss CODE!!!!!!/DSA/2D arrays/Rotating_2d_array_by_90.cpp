#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>                                               //NOTE:: Evaluate by putting i=0, i=1......to prevent confusion

int main(){
  int n;
  cout<<"Enter the dimension side :: ";
  cin>>n;

 int a[n][n];
 
 for(int i=0;i<n  ;i++){
  for(int j=0 ;j<n  ;j++){
   cout<<"Enter the value of "<<i<<","<<j<<" :: ";
      cin>>a[i][j];
  }
 }

 for(int i=0;i<n  ;i++){
 for(int j=0 ;j<n  ;j++){
      cout<<a[i][j]<<" ";
 }
 cout<<endl;
 }
 cout<<endl;

 int m=n-1;

                                          //for(int i=0 ;i<n-1  ;i++){
                                          //     
                                          //    for(int j=0 ;j<3  ;j++){
//juss a random logic                     //          swap(a[0][i],a[m*j-(j/2)*m][m-(j]);
                                          //    }    
                                          //}

//no optimisation aise hi hogaaaaa..🙌🙌🔥🔥🔥

for(int i=0 ;i<n/2  ;i++){                           //for inner rotation;
     
for(int j=0 ;j<n-1-(2*i)  ;j++){                     //increasing element from corner   
     swap(a[0+i][j+i],a[j+i][m-i]);                       
     swap(a[0+i][j+i],a[m-i][m-j-i]);                //creating cycle for four elements
     swap(a[0+i][j+i],a[m-j-i][0+i]);
}
} 

for(int i=0;i<n ;i++){
 for(int j=0 ;j<n  ;j++){
      cout<<a[i][j]<<" ";
 }
 cout<<endl;
 }
 cout<<endl;



  return 0;
}