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
void insert_at_tail(node* &tail,int element,int d){             // here element is that value in whose tail we have to insert the new node
                                                                
    //Empty List    
    if(tail==NULL){
        node *temp=new node(d);                                 // CONDITION: The element muss be present in the existing linked list
        tail=temp;
    }
    
    else{
        node *insert = new node(d);
        
        node *temp=tail;
        while(temp->a!=element){
            temp=temp->next;
        }
        //Now temp is on that node whose value = element

        insert->next=temp->next;          // bcoz while adding 2nd element, temp->next is equal to temp itself;
        temp->next=insert;       
    }
}



//Traversing
//Using do while

void print(node* &tail){                    
 node *temp=tail;
 do{             
    cout<<temp->a<<" ";                         //here 2 is head.
    temp=temp->next;
 }while(temp!=tail);   
 cout<<endl;
}




int main(){
    node *tail=NULL;       
    
    insert_at_tail(tail,7,2);           // since empty linked list, so whatever the element, a node get created with value 2
    print(tail);                        //basically here 2 is at head.


    insert_at_tail(tail,2,5);           // means in tail of 2, we inserted 5
    print(tail);

    insert_at_tail(tail,5,7);
    print(tail);

    insert_at_tail(tail,5,10);           // middle insertion                 
    print(tail);
    
    return 0;
}