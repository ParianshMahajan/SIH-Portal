#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  string s;
  cout<<"Enter the string :: ";
  cin>>s;
  int c=1;
while(c!=0){  
  c=0;  
 for(int i=0 ;i<s.length()-1 ;i++){
  if(s[i]==s[i+1]){
    s.erase(s.begin()+i,s.begin()+i+2);
    c=1;
  }
 }
}
 cout<<s;

  return 0;
}