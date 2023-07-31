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
        cout<<"Memory of node with the value "<<value<<" is freed."<<endl;
    }

};



//Insertion
void insert_at_tail(node *&head,int d){
    node *temp=new node(d);
    head->next=temp;
    temp->prev=head;
    head=temp;
}

void insert_at_head(node *&head,int d){
    node *temp=new node(d);
    head->prev=temp;
    temp->next=head;
    head=temp;
}

//midinsertion
void insert_at_mid(node* &head,int d,int n){
    node *insert = new node(d);
    node *temp = head;

    for(int i=0 ;i<n-1  ;i++){
        temp = temp->next;
    }
    insert->prev=temp->prev;
    insert->next=temp;
    (temp->prev)->next=insert;
    temp->prev=insert;
}

//Deletion
void del(node *&head,int n){
    node *temp= head;
    
    //Head deletion handling
    if(n==1){
        head=head->next;
    }

    else{
        for(int i=0 ;i<n-1;i++){
            temp=temp->next;
        }
        
        //Tail deletion Handling
        if(temp->next==NULL){
            (temp->prev)->next=NULL;
        }
        else{
            (temp->next)->prev=temp->prev;
            (temp->prev)->next=temp->next;
        }
    }        
    temp->prev=NULL;
    temp->next=NULL;
    delete temp;
}

//traverse
void for_trav(node *&head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->a<<" ";
        temp=temp->next;
    }
}

void back_trav(node *&tail){
    node *temp=tail;
    while(temp!=NULL){
        cout<<temp->a<<" ";
        temp=temp->prev;
    }
}



int main(){
    node *n1=new node(10);
    node *head=n1;          // At initialisation, the single node is both head and tail.
    node *tail=n1;
    
    //Insertion at head
    insert_at_head(head,9);
    insert_at_head(head,8);

    //Insertion at head
    insert_at_tail(tail,11);
    insert_at_tail(tail,12);

    for_trav(head);
    cout<<endl;
    back_trav(tail);  
    cout<<endl;

    //Insertion at mid
    insert_at_mid(head,100,4);
    for_trav(head);

    cout<<endl;

    //Deletion
    del(head,6);
    for_trav(head);
    
    return 0;
}