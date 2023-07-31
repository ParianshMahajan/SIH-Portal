#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node *prev;
    int a;
    node *next;

    //constructor
    node(){
        prev=NULL;
        next=NULL;
    }
    node(int d){
        a=d;
        prev=NULL;
        next=NULL;
    }

    //Destructor
    ~node(){
        int value=a;
        //Memory free
        if(next!=NULL||prev!=NULL){
            delete next;
            delete prev;
            next=NULL;
            prev=NULL;
        }
        cout<<"Memory of node with the value "<<value<<" is freed.";
    }

};




//Insertion
void insert_at_tail(node *&head,node *&tail,int d){
    if(tail==NULL){
        node *temp=new node(d);
        tail=temp;
        head=temp;
    }
    else{
        node *temp=new node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insert_at_head(node *&head,node *&tail,int d){
    if(head==NULL){
        node *temp=new node(d);
        head=temp;
        tail=temp;
    }
    else{
        node *temp=new node(d);
        head->prev=temp;
        temp->next=head;
        head=temp;
    }
}


//traverse
void print(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->a<<" ";
        temp=temp->next;
    }
}




int main(){
    node *head =NULL;
    node *tail =NULL;

    //Insertion at head
    insert_at_head(head,tail,10);           // Here head an tail are both passed coz at initialisation a single node is both head and tail.

    //Insertion at tail
    insert_at_tail(head,tail,20);

    print(head);

   return 0;
}