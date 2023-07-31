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
        cout<<"Memory of node with the value "<<value<<" is freed."<<endl;
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


//Deletion
void del(node *&tail,int n){
    //for deleting first element
    // Here no need to make cases coz no NULL pointer is included nd evrything is in a cycle
    
    node *temp=tail;
    for(int i=0 ;i<n-1  ;i++){          //coz at n-1 it is on a node b4 nth position
        temp=temp->next;
    }
    node *mem=temp->next;               //for memory deletion

    temp->next=(temp->next)->next;
    mem->next=NULL;
    delete mem;
};


//Traversing
void print(node* &tail){
 node *temp=tail;                //applying do while
 do{             
    temp=temp->next;
    cout<<temp->a<<"   ";             
 }while(temp!=tail);
 cout<<endl;
}




int main(){
    node *tail= new node(1);                                 
    
    insert_at_tail(tail,2);
    insert_at_tail(tail,3);
    insert_at_tail(tail,4);
    insert_at_tail(tail,5);

    print(tail);
    
    del(tail,5);
    print(tail);
    return 0;
}