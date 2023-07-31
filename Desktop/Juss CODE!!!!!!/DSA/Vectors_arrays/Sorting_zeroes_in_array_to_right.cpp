#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>


int main(){
    int n;
    cout<<"Enter the number of terms :: ";
    cin>>n;

    int a[n];
    cout<<"Enter the array :: ";
    for(int i=0 ;i<n  ;i++){
    cin>>a[i];
    }

//for(int i=0 ;i<n  ;i++){
//  for(int j=0 ;j<n-i-1  ;j++){
//    if(a[j]==0){
//        swap(a[j],a[j+1]);
//    }
//   }
//}
int nonzero =0;
for(int i=0 ;i<n  ;i++){                   // Important logic :: DO DRY RUN;
    if(a[i]!=0){
        swap(a[i],a[nonzero]);
        nonzero++;
    }
}

cout<<"Sorted array is :: ";
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}

    return 0;
}