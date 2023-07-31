#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
   vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

   int m=matrix.size();
   int n=matrix[0].size();

   int key;
   cout<<"Enter the key :: ";
   cin>>key;

  for(int i=0 ;i<m  ;i++){
     for(int j=0 ;j<n  ;j++){
      cout<<matrix[i][j]<<" ";
     }
     cout<<endl;
  }
  cout<<endl<<endl;

  int row=0;
  int col=n-1;   
   while(col>=0&&row<m){  
   if(matrix[row][col]==key){
      cout<<"["<<row<<"]"<<"["<<col<<"]";
      return 0;
   }
   
   else if(matrix[row][col]<key){
      row++;
   }
   
   else if(matrix[row][col]>key){
     col--;
   }
}

cout<<"Key not foutnd !!";
   return 0;
}