#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int a;
    node *ptr;

    //constructor
    node(){ 
        ptr=NULL;       
    }

    node(int x){
        a=x;
        ptr=NULL;
    }
};



//Insertion
void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->ptr=temp; 
    tail=temp;       
}




//Traversing
void print(node* &head){
 node *temp=head;
 int len=0;
 while(temp!=NULL){             
    cout<<temp->a<<"  ";
    len++;
    temp=temp->ptr;             
 }   
 cout<<endl<<"Length of the linked list is :: "<<len<<endl;
}




int main(){
    node *n1= new node(1);
    node *head=n1;                      // here we saved the starting node (head of the node).       

    insert_at_tail(n1,2);
    insert_at_tail(n1,3);
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);
 
    print(head);
    
    return 0;
}