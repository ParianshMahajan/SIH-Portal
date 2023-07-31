#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int a;
    node *next;

    //constructor
    node(){ 
        next=this;                  // Empty list with 1 node : next pointer will point to itself; 
    }

    node(int x){
        a=x;
        next=this;
    }

    //destructor
    ~node(){
        int value=a;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory of node with the value "<<value<<" is freed.";
    }

};




//Insertion
void insert_at_tail(node* &tail,int d){
    
    //Empty List
    if(tail==NULL){
        node *temp=new node(d);
        tail=temp;
    }
    
    else{
        node *temp = new node(d);
        temp->next=tail->next; 
        tail->next=temp;
        tail=temp;       
    }
}


//MidInsertion
void insert_at_mid(node* &tail,int d,int n){
    node *insert = new node(d);
    node *temp=tail;

    for(int i=0 ;i<n-1  ;i++){      // n-1 bcoz at 1st iteration, temp= head, so at n-1 it will reach a node at position b4 n 
        temp=temp->next;
    }
    insert->next=temp->next;
    temp->next=insert;
}


//Traversing
void print(node* &tail){
 node *temp=tail;
 temp=temp->next;                // making temp =head;
 while(temp!=tail){             
    cout<<temp->a<<endl;
    temp=temp->next;             // tail not get printed bcoz as it approches 2nd last node, its node= tail, hence loop breaks.
 }
 cout<<tail->a;    
}




int main(){
    node *tail= new node(1);                                 
    
    insert_at_tail(tail,2);
    insert_at_tail(tail,3);
    insert_at_tail(tail,4);
    insert_at_tail(tail,5);

    insert_at_mid(tail,22,4);
    print(tail);
    
    return 0;
}