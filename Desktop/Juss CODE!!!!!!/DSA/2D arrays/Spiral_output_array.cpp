#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  int m,n;
  
  cout<<"Enter the rows :: ";
  cin>>m;

  cout<<"Enter the collumns :: ";
  cin>>n;
  
  int arr[m][n];
 for(int i=0 ;i<m  ;i++){
  for(int j=0 ;j<n  ;j++){
      cout<<"Enter the "<<i<<","<<j<<" element :: ";
      cin>>arr[i][j];
  }
 }

 for(int i=0 ;i<m  ;i++){
  for(int j=0 ; j<n ;j++){
    cout<<arr[i][j]<<" ";
  }
  cout<<endl;
 }
cout<<endl<<endl<<endl;
int count=0;

int startingRow=0;
int endingCol=n-1;
int endingRow=m-1;
int startingCol=0;

while(count<m*n){
    //printing starting row ::
   for(int index=startingCol ;count<m*n && index<=endingCol  ;index++){
    cout<<arr[startingRow][index]<<" ";
    count++;
   }
    startingRow++;

    //printing ending collumn ::
   for(int index=startingRow ;count<m*n && index<=endingRow ;index++){
    cout<<arr[index][endingCol]<<" ";
    count++;
  }
   endingCol--;

    //printing ending row ::
   for(int index=endingCol ;count<m*n &&index>=startingCol ;index--){
    cout<<arr[endingRow][index]<<" ";
    count++;
   }
  endingRow--;

    //printing starting collumn :: 
   for(int index=endingRow ;count<m*n &&index>=startingRow ;index--){
    cout<<arr[index][startingCol]<<" ";
    count++;
   }
    startingCol++; 

  
  }


  return 0;
}