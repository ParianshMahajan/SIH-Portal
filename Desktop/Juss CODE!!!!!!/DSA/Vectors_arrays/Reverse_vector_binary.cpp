#include<iostream>
using namespace std;
#include <vector>

vector<int> reverse(vector<int>v){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

int main(){
    vector <int> v;
    int n;
    cout<<"Enter the number of terms in array :: ";
    cin>>n;

   cout<<"Enter the array :: ";
   int a;                       // Random Variable 
   for(int i=0 ;i<n  ;i++){
    cin>>a;
    v.push_back(a);
   }

    vector<int>v1=reverse(v);    // Cannot access directly because like array allocations acts like pointers.
                                 // vector allocations doesn't act like poiners so will be considered as call by value

    cout<<"The reversed array is :: ";
    for(int i:v1){
        cout<<i<<" ";
    }

    return 0;
}