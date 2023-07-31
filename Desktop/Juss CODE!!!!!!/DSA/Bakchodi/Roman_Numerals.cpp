#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>
#include<string>


int main(){
  string s;
  cin>>s;

  int a[s.size()];



  // Declaration of roman info.
 for(int i=0 ;i<s.size()  ;i++){
  if(s[i]=='I'){
    a[i]=1;
  }
  else if(s[i]=='V'){
    a[i]=5;
  }
  else if(s[i]=='X'){
    a[i]=10;
  }
  else if(s[i]=='L'){
    a[i]=50;
  }
  else if(s[i]=='C'){
    a[i]=100;
  }
  else if(s[i]=='D'){
    a[i]=500;
  }
  else if(s[i]=='M'){
    a[i]=1000;
  }
 }

int sum =0;
for(int i=0 ;i<s.size()  ;i++){
  if(i<s.size()-1){
  if(a[i]>=a[i+1]){
  sum+=a[i];  
}
  else{
    sum-=a[i];
  }
  }
  else{
    sum+=a[i];
  } 
}

cout<<sum<<endl;

  return 0;
}