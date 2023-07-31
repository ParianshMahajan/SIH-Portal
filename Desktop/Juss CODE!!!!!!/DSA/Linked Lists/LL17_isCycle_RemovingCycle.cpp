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




//isCycle Floyd's detection loop algo  ;
node* isCycle_Floyd(node *&head){
    
    //empty list;
    if(head==NULL){
        return NULL;
    }
    if(head->ptr==NULL){
        return NULL;
    }

    node *fast=head;
    node *slow=head;
    while(fast->ptr!=NULL&&slow->ptr!=NULL){
        fast=(fast->ptr);
        if(fast!=NULL){
           fast= fast->ptr;
        }
        
        slow=slow->ptr;

        //cycle is present
        if(slow==fast){
            return slow;
        }
    }

    return NULL;
}





//starting Node 
node* get_starting_node(node*&head){
    if(head==NULL){
        return NULL;
    }
   
    node *intersexn=isCycle_Floyd(head);
   
    if(intersexn== NULL){
        return NULL;
    }
   
    node*fast=intersexn;
    node*slow=head;
    while(slow!=fast){
       slow=slow->ptr;
       fast=fast->ptr;             //same pace
    }
    
    // we got the beginning node ;
        return slow;
    }




//Removing cycle
void remove_cycle(node*&head){
    node*temp=get_starting_node(head);
    
    while(temp->ptr!=get_starting_node(head)){
        temp=temp->ptr;
    }

    //pointing last element to null, hence removing the loop.   
    temp->ptr=NULL;

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
    n1->ptr=head;
    //print(head);

    
    if(get_starting_node(head)==NULL){
        cout<<"No cycle found";
    }
    else{
        cout<<"Cycle is present at node with value :: "<<(get_starting_node(head))->a<<endl;
        remove_cycle(head);
        cout<<"Cycle removed."<<endl;
        print(head);
    }

    return 0;
}