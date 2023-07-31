 
#include<iostream>
using namespace std;
 
#include <deque>
 
int main(){
 
  deque<int> d={1,2,3,4,5,6,7,8};

  cout<<"The first element is :: "<< d.front() <<endl;
  cout<<"The last element is :: "<< d.back() <<endl;
  
  cout<<"The element at index 2 is :: "<< d.at(2) <<endl; 
  
  d.push_front(9);  
  d.push_back(10);
  
  for (int i:d){
    cout<<i<<" ";
  }
  cout<<endl;  
  cout<<"The size of the deque :: "<< d.size() << endl;
 
  d.pop_front();  
  d.pop_back();
  
  for (int i:d){
    cout<<i<<" ";
  }
  cout<<endl;  
  cout<<"The size of the deque :: "<< d.size() << endl;

  
  d.erase(d.begin()+1,d.begin()+4);
    for (int i:d){
    cout<<i<<" ";
      }
    cout<<endl;  


    return 0;
}
