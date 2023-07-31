#include<bits/stdc++.h>
using namespace std;

class node{
public:
int a;
node *next;

node(int d){
    a=d;
    next=NULL;
}

};



//Insertion
void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->next=temp; 
    tail=temp;       
}




node* rec_prob(node *&temp,node*&head){
        //base case;
    if(temp==NULL){
        return NULL;
    }
    if(temp->next==NULL){
        head=temp;                  //only occurs when temp is at the tail and temp->next=NULL; so head =temp::pointing the last element;
        return temp;
    }
    
    node *node1=rec_prob(temp->next,head);    //when finally temp->next = null we r on the last node; 
    
    //solving nth case;
    node1->next=temp;
    temp->next=NULL;
    return temp;
}

node* reverse_list(node*&head){
    node *temp =head;                   //problem is whenevr we r calling func in this func *node gettin created and assigned again and again;
    rec_prob(temp,head);
}


//Traversing
void print(node* &head){
 node *temp=head;
 while(temp!=NULL){             
    cout<<temp->a<<"  ";
    temp=temp->next;             
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
 
   // print(head);

    //Reversed list 
    reverse_list(head);
    print(head);



    //Disadvantage ::
    //by using recuersive method we lost the original ll;


    return 0;
}