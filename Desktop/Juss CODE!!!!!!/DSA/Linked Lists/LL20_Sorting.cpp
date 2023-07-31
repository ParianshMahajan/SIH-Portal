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


//Swapping
void swap(node*&x,node*&y){
    int temp=x->a;
    x->a=y->a;
    y->a=temp;
}


// Insertion Sort
void ins_sort(node *&head){
    node*temp=head;
    node*trav;
    while(temp->ptr!=NULL){
        trav=temp->ptr;
        while(trav!=NULL){
            if(trav->a < temp->a){             //ascending order
                swap(trav,temp);
            }
            trav=trav->ptr;
        }
        temp=temp->ptr;
    }
}

 //Bubble sort
 void bub_sort(node *&head){
    node*temp=head;
    node*trav=head;
    while(temp->ptr!=NULL){                  // juss for number of turns; no use of temp;
        while(trav->ptr!=NULL){
            if(trav->a > (trav->ptr)->a){             //ascending order
                swap(trav,temp);
            }
            trav=trav->ptr;
        }
        temp=temp->ptr;
    }
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
    int x;
    cin>>x;
    node *n1=new node(x);
    node *head=n1;
    for(int i=0 ;i<5  ;i++){
        int m;
        cin>>m;
        insert_at_tail(n1,m);
    }

    node *tail=n1;
    bub_sort(head);
    print(head);

    return 0;
}