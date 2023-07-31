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

    //destructor
    ~node(){
        int value=a;
        
        //memory free
        if(ptr!=NULL){
            delete ptr;
            ptr=NULL;
        }
        cout<<"Memory of node with data "<<value<<" is freed"<<endl;
    }

};



void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->ptr=temp; 
    tail=temp;       
}



//Deletion
void del(node* &head,int n){
    node *temp=head;

    if(n==1){
        head=head->ptr;
        //memory freeing 
        temp->ptr=NULL;
        delete temp;
    }

    else{
        for(int i=0 ;i<n-2  ;i++){
            temp=temp->ptr;
        }
        node *mem=temp->ptr;            // for memory free;

        temp->ptr=(temp->ptr)->ptr;
        
        //memory free
        mem->ptr=NULL;
        delete mem;
    }
}




//Traversing
void print(node* &head){
 node *temp=head;
 while(temp!=NULL){             
    cout<<temp->a<<"  ";
    temp=temp->ptr;             
 }   
}




int main(){
    node *n1= new node(10);
    node *head=n1;                            
    
    insert_at_tail(n1,20);
    insert_at_tail(n1,30);
    insert_at_tail(n1,40);
    insert_at_tail(n1,50);

    node *tail=n1;

    del(head,3);
    print(head);
    
    cout<<endl<<"Head :: "<<head->a<<endl<<"Tail :: "<<tail->a<<endl;
    
    // If we delete the element at position 1 we handled the head when its value is outputed 
    // But in case of tail if we delete position 5, tail's value will give garbage value;
    // So we have to handle tail now;
    // like if 
    // del(head,1);                 //head will move to 20;
    // del(head,5);                 //tail will remain there and will give random garbage value coz the node is deleted by the destructor





    return 0;
}