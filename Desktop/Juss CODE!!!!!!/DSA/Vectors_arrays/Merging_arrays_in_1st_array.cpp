#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

void inputarray(int a[],int n){
   for(int i=0 ;i<n  ;i++){
    cin>>a[i];
   }
}

int main(){
    int n1;
    cout<<"Enter the number of terms in 1st array :: ";
    cin>>n1;

    
    int n2;
    cout<<"Enter the number of terms in 2nd array :: ";
    cin>>n2;

    int a1[n1+n2];
    cout<<"Enter the 1st array :: ";
    inputarray(a1,n1);
    
    int a2[n2];
    cout<<"Enter the 2nd array :: ";
    inputarray(a2,n2);

    bool implemented =false;
   for(int j=0;j<n2  ;j++){
   for(int i=0 ;i<n1+j  ;i++){
    if(a2[j]<a1[i]){
       for(int k=(n1-1+j) ;k>=i  ;k--){
       a1[k+1]=a1[k];
       }
        a1[i]=a2[j];
        implemented =true;
    }
    if(implemented==true){
        break;
    }
   }
   if(implemented == false){
        a1[n1+j]=a2[j];
   }
   implemented =false;
   }

cout<<"Merged array is :: ";
for(int i=0;i<(n1+n2);i++){
    cout<<a1[i]<<" ";
}

    return 0;
}