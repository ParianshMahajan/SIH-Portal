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
void insert_at_head(node* &head,int d){
    node *temp = new node;
    temp->a=d;
    // as in constructor temp->ptr is already NULL so need to make it again NULL;

    temp->ptr=head; 
    head=temp;       
    // adding address of next node in head as it was NULL before
}




//Traversing
void print(node &head){
 node *temp=&head;
 int len=0;
 while(temp!=NULL){             //means till the temp pointer have no address of any node means till last node; coz last's node ptr=NULL.
    cout<<temp->a<<"  ";
    len++;                      
    temp=temp->ptr;             // means we assigned value of temp = address of nxt node.
 }   
 cout<<endl<<"Length of the linked list is :: "<<len<<endl;
}




int main(){
    node *n1= new node(1);
    insert_at_head(n1,2);
    insert_at_head(n1,3);
    insert_at_head(n1,4);
    insert_at_head(n1,5);
 
    print(*n1);
    return 0;
}