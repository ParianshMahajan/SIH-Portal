#include<bits/stdc++.h>
using namespace std;

class node{
public:
int a;
node *ptr;

node(int d){
    a=d;
    ptr=this;
}


};



//Insertion
void insert_at_tail(node* &tail,int d){
    if(tail==NULL){
        node *temp=new node(d);
        tail=temp;
    }
    
    else{
        node *temp = new node(d);
        temp->ptr=tail->ptr; 
        tail->ptr=temp;
        tail=temp;       
    }
}


//cutting into two halves
node* cut_LL(node*&tail){
    node*fast=tail;
    node*slow=tail;
    do{
        fast=fast->ptr;
        if(fast!=tail){
            fast=fast->ptr;
        }
        slow=slow->ptr;
    }while(fast!=tail);
    node *second=slow->ptr;                 // Head of 2nd list
    node *first=tail->ptr;                  // Head of 1st list
    
    slow->ptr=first;                        // Making 1st circular
    tail->ptr=second;                        // Making 2nd circular


    return first;                           // Because we have tail as it is so we can easily get head of second i.e tail->ptr.
}


//Traversing with head
void print(node* &head){                    
 node *temp=head;
 do{
    cout<<temp->a<<" ";
    temp=temp->ptr;
 }while(temp!=head);   
 cout<<endl;
}





int main(){
    node *n1=new node(2);
    node *head=n1;

    insert_at_tail(n1,2);
    insert_at_tail(n1,2);
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);
    insert_at_tail(n1,4);
    node *tail=n1;
    
    print(head);
    
    node*first=cut_LL(tail);
    node*second=tail->ptr;

    print(first);
    print(second);
    return 0;
}