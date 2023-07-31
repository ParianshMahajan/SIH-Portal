#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of terms :: ";
    cin>>n;

    int a[n];
    cout<<"Enter the array :: ";
   for(int i=0 ;i<n  ;i++){
    cin>>a[i];
   }

  //Selection sort;
   for(int i=0 ;i<n-1 ;i++){
   for(int j=i+1 ;j<n  ;j++){
    if(a[i]>a[j]){
      swap(a[i],a[j]);
    }
   }
   }

//Bubble sort;
  bool swapped =false;
  for(int i=0 ;i<n-1  ;i++){
  for(int j=0 ;j<n-i  ;j++){
    if(a[j]>a[j+1]){
    swap(a[j],a[j+1]);
    swapped =true;
   }
   }
   if(swapped == false){
    break;
   }
   }

//Insertion sort;
  for(int i=1 ;i<n  ;i++){
  int temp=a[i];
   for(int j=i-1 ;j>=0  ;j--){
    if(a[j]>temp){
      a[j+1]=a[j];
      a[j]=temp;
    }
    else{
      break;
    }
   }
  }

    cout<<"Sorted array is :: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }


    return 0;
}