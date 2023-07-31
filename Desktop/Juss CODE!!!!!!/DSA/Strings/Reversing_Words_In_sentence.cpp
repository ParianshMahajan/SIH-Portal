#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  string s;
  cout<<"Enter the string :: ";
  getline(cin,s);
int a=0;
 for(int i=0 ;i<s.length() ;i++){
  if(s[i]==' '||i==s.length()-1){
    int b=i-1;
    if(i==s.length()-1){
      b++;
    }
    while(a<=b){
  swap(s[a++],s[b--]);
 }
  a=i+1;
  }
 }

 cout<<"The reversed string is :: "<<s;
  return 0;
}