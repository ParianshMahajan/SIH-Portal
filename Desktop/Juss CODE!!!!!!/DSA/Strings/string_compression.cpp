#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int main(){
//   string s;
//   cout<<"Enter the string :: ";
//   cin>>s;

//   string ans;

//   int arr[26]={0};
//  for(int i=0 ;i<s.length() ;i++){
//     arr[s[i]-'a']++;
//  }

//  for(int i=0 ;i<26  ;i++){
//   if(arr[i]!=0){
//     if(arr[i]==1){
//       ans.push_back(i+'a');
//     }
//     else{
//       ans.push_back(i+'a');
//       ans.push_back(arr[i]+'0');
//     }
//   }
//  }

//  cout<<ans;
int x=9876;
cout<<((x/1000))<<endl;
                            cout<<(((x%1000)/100))<<endl;
                            cout<<(((x%100)/10))<<endl;
                            cout<<((x%10))<<endl;

  return 0;
}