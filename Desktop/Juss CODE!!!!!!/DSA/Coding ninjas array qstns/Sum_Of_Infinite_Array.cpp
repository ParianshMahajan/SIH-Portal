#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int fsum(int x,int y,vector<int>v){
     int sum=0;
    for(int i=x ;i<=y  ;i++){
     sum+=v[i-1];
    }
    return sum;
}


int main(){
     vector <int> v,v1;
     int n;
     cout<<"Enter the number of terms :: ";
     cin>>n;

     int c;
     cout<<"Enter the array :: ";
    for(int i=0 ;i<n  ;i++){
     cin>>c;
     v.push_back(c);
    }

     int m;
     cout<<"Enter the number of sum you wanted to find :: ";
     cin>>m;

     int sum=0;

    for(int i=0 ;i<m  ;i++){
     
     int x,y;
     cin>>x>>y;

    if(y<=n){
     v1.push_back(fsum(x,y,v));
    }

     else{
          sum=fsum(1,n,v)*((y/n)-(x/n));
          if(y%n!=0){
               sum=sum+fsum(1,y%n,v);
          }
          if(x%n==0){
               sum+=v[n-1];
          }
          else{
               if((x-1)%n!=0)
               sum=sum-fsum(1,(x-1)%n,v);
          }
          v1.push_back(sum);
     }
    }
 for(int i:v1){
          cout<<i<<" ";
     }


     return 0;
}