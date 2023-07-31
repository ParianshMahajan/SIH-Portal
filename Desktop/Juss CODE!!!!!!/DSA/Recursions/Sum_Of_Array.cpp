#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int sumn(int *arr,int n){
     
     if(n==0)
     return 0;

     if(n==1)
     return *(arr);


     int sum =*(arr+n-1) + sumn(arr,n-1);
     return sum;
}


int main(){
     int arr[5]={0,1,3,4,5};
     int ans=sumn(arr,5);
     cout<<ans;
     return 0;
}