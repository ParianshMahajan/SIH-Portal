#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
  string s;
  cout<<"Enter the word :: ";
  cin>>s;
  int arr[26]={0};
 for(int i=0 ; i<s.length() ;i++){
    if(s[i]>='a'&&s[i]<='z'){
      int number =s[i]-'a';
      arr[number]++;
    } 
    else{
      int number =s[i]-'A';
      arr[number]++;
    }
 }
  int max=arr[0];
  int ans=0;
 for(int i=0 ;i<26  ;i++){
  if(max<arr[i]){
    ans=i;
    max=arr[i];
  }
 }


 cout<<"Most occuring letter is :: "<<char(ans+'A');

  return 0;
}