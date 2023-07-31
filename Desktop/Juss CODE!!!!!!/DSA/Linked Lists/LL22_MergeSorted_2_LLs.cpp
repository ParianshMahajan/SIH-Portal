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

~node(){
    if(ptr!=NULL){
        delete ptr;
        ptr=NULL;
    }
}

};



//Insertion
void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->ptr=temp; 
    tail=temp;       
}


//Merging 2 sorted lists :: Method 1
//creating 3rd LL;
 node* merge(node *&head1,node *&head2){
    node*temp1=head1;
    node*temp2=head2;

    node*temp=new node(-1);
    node* newhead=temp;

    while(temp1!=NULL && temp2!=NULL){
        if((temp1->a)<(temp2->a)){
            temp->ptr=temp1;
            temp=temp1;
            temp1=temp1->ptr;
        }
        else{
            temp->ptr=temp2;
            temp=temp2;
            temp2=temp2->ptr; 
        }
    }

    if(temp1==NULL){
        while(temp2!=NULL){
            temp->ptr=temp2;
            temp=temp2;
            temp2=temp2->ptr;
        }
    }
    else if(temp2==NULL){
        while(temp1!=NULL){
            temp->ptr=temp1;
            temp=temp1;
            temp1=temp1->ptr;
        }
    }


    temp->ptr=NULL;
    node *head=newhead->ptr;

   // delete newhead;
    return head;
}



//Merging 2 sorted lists :: Method 2
//In same 1st LL;
 void mergeSame(node *&head1,node *&head2){
    node*temp1=head1;
    node*temp2=head2;
    node*save;

    while(temp1->ptr!=NULL && temp2!=NULL){
        if((temp1->a)<=(temp2->a)&&(temp2->a)<=((temp1->ptr)->a)){
            save=temp2;
            temp2->ptr=temp1->ptr;
            temp1->ptr=temp2;
            temp1=temp2;
            temp2=save->ptr;
        }
        else{  
            temp1=temp1->ptr; 
        }
        cout<<"! ";
    }

    if(temp1->ptr==NULL){
        while(temp2!=NULL){
            temp1->ptr=temp2;
            temp1=temp2;
            temp2=temp2->ptr;
        }
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
    node *n1= new node(1);
    node *head1=n1;   
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);

    node *n2= new node(2);
    node *head2=n2;   
    insert_at_tail(n2,3);
    insert_at_tail(n2,5);
    
    mergeSame(head1,head2);
    print(head1);
    return 0;
}