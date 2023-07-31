#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

bool issorted(int *arr,int n){
    if(n<=1){
     return true;
    }

     if((*(arr+n-1))>=(*(arr+n-2))){
          issorted(arr,n-1);
     }
     else{
          return false;
     }
}


int main(){
     int arr[5]={0,1,3,4,5};
     bool ans=issorted(arr,5);
     
     if(ans)
     cout<<"Array is sorted";

     else
     cout<<"Array is not sorted";
     
     return 0;
}