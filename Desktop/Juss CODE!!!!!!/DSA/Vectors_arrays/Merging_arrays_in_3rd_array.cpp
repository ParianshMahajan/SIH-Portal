#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

void inputvect(vector<int> v,int n){
    int a;
   for(int i=0 ;i<n  ;i++){
    cin>>a;
    v.push_back(a);
   }
}

int main(){
    int n1,n2;
    cout<<"Enter the number of terms in array 1 :: ";
    cin>>n1;
    
    vector<int> v1;
    int a;
   for(int i=0 ;i<n1  ;i++){
    cin>>a;
    v1.push_back(a);
   }
    
    cout<<"Enter the number of terms in array 2 :: ";
    cin>>n2;
    
    vector<int> v2;
   for(int i=0 ;i<n2  ;i++){
    cin>>a;
    v2.push_back(a);
   }


   vector <int> v3;
   int i=0,j=0;
   
   while(i<n1 && j<n2){
    if(v1[i]>v2[j]){
        v3.push_back(v2[j]);
        j++;
    }
    else{
        v3.push_back(v1[i]);
        i++;
    }
   }

    while(i<n1){
        v3.push_back(v1[i]);
        i++;
    }
   
    while(j<n2){
        v3.push_back(v2[j]);
        j++;
    }

    cout<<"The sorted array is :: ";
    for(int i:v3){
        cout<<i <<" ";
    }

    return 0;
}