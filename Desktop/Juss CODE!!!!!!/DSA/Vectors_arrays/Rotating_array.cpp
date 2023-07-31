#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  int n;
  cout<<"Enter the number of elements in array :: ";
  cin>>n;

  int a[n];
 for(int i=0 ;i<n  ;i++){
  cin>>a[i]; 
 }

 int k;
 cout<<"Enter the right or left shift value :: ";
 cin>>k;

int x=0;
int temp1,temp2;
temp2=a[x];
for(int i=0 ;i<n  ;i++){
if(x<n-k){
temp1=a[x+k];
a[x+k]=temp2;
x=x+k;
temp2=temp1;
}
else{
x=x+k;
temp1=a[x-n];
a[x-n]=temp2;
x=x-n;
temp2=temp1;
}

}

for(int i=0 ;i<n  ;i++){
cout<<a[i]<<" ";
}
  return 0;
}