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


//isCycle Map Method;
bool isCycle_Map(node *&head){
    
    //empty list;
    if(head==NULL){
        return false;
    }
    if(head->ptr==NULL){
        return false;
    }

    map<node*,bool> visited;
    node *temp=head;
    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            cout<<"Cycle is present at node with value :: "<<temp->a<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->ptr;
    }

    return false;
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
    }
    // Therefore, space complexity = O(1);
    // and time complexity only for detecting isCycle = O(n);
    

    return 0;
}