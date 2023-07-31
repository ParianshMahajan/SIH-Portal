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


//Deletion with value
void del_with_value(node* &head,int d){
    node *temp=head;

    if(temp->a==d){
        head=head->ptr;

        //memory freeing 
        temp->ptr=NULL;
        delete temp;
    }
    
    else{    
        while((temp->ptr)->a!=d){               // Here we r taking (temp->ptr)->a instead of temp->a becoz it will take us to the node which is to be deleted
            temp=temp->ptr;                     // whereas we want to go to the node b4 the node to be deleted.
        }
        node *mem=temp->ptr;   

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

    del_with_value(head,10);
    print(head);
    
    return 0;
}