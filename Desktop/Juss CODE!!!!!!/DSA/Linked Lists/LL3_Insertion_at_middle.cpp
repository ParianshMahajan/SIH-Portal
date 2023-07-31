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


//Insertion
void insert_at_mid(node* &head,int d,int n){
    node *insert = new node(d);
    node *temp=head;

    for(int i=0 ;i<n-2  ;i++){
        temp=temp->ptr;
    }
    insert->ptr=temp->ptr;
    temp->ptr=insert;

}


//Traversing
void print(node* &head){
 node *temp=head;
 while(temp!=NULL){             //means till the temp pointer have no address of any node means till last node; coz last's node ptr=NULL.
    cout<<temp->a<<"  ";
    temp=temp->ptr;             // means we assigned value of temp = address of nxt node.
 }   
}




int main(){
    node *n1= new node(1);
    node *head=n1;                      // here we saved the starting node (head of the node).       
    
    insert_at_tail(n1,2);
    insert_at_tail(n1,3);
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);

    insert_at_mid(head,22,4);
    print(head);
    
    return 0;
}