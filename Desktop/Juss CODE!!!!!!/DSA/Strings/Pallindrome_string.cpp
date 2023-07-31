#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

void tolowercase(char a[],int n){
 for(int i=0 ;i<n  ;i++){
 if(a[i]<'a'){
  a[i]+=32;
 }
 }
}

bool ispallindrome(char a[],int n){
  int s=0;
  int e=n-1;
  while(s<e){
    if(a[s]!=a[e]){
      return 0;
    }
    else if(a[s]==a[e]){
      s++;
      e--;
    }
  }
  return 1;
}

int getlength(char a[]){
int len =0;
 for(int i=0 ;a[i]!='\0'  ;i++){
  len++;
 }
 return len;
}

int main(){
  char name[100];
  cout<<"Enter the name :: ";
  cin>>name;
  int n=getlength(name);
  
  tolowercase(name,n);

  cout<<"Pallindrome or not :: "<<ispallindrome(name,n);
  return 0;
}