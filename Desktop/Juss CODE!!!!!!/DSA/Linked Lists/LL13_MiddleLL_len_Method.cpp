#include<bits/stdc++.h>
using namespace std;

class node{
public:
int a;
node *ptr;

node(int d){
    a=d;
    ptr=NULL;
}

};



//Insertion
void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->ptr=temp; 
    tail=temp;       
}


node* mid_list(node*&head){
    node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->ptr;
    }
    temp=head;
    for(int i=0 ;i<((len/2)+1)-1  ;i++){
        temp=temp->ptr;
    }
    return temp;
}


//Traversing
void print(node* &head){
 node *temp=head;
 while(temp!=NULL){             
    cout<<temp->a<<"  ";
    temp=temp->ptr;             
 }   
 cout<<endl;
}



int main(){
    node *n1=new node(1);
    node *head=n1;

    insert_at_tail(n1,2);
    insert_at_tail(n1,3);
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);
 
    print(head);

    node *x=mid_list(head);
    cout<<x->a;

    return 0;
}