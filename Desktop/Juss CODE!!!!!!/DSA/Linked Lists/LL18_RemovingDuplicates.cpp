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
    int value=a;
    //memory free
    if(ptr!=NULL){
        delete ptr;
        ptr=NULL;
    }
    //cout<<"The duplicate node with value :: "<<value<<" is deleted";
}

};



//Insertion
void insert_at_tail(node* &tail,int d){
    node *temp = new node(d);
    tail->ptr=temp; 
    tail=temp;       
}



//Removing Duplicates in a sorted list;
void duplicates_S(node*&head){
    //Empty list || 1 element list || 1 element CLL
    if(head==NULL||head->ptr==NULL||head->ptr==head){
        return;
    }

    node*temp=head;
    while(temp->ptr!=NULL){
        if(temp->a==(temp->ptr)->a){
            node *mem=temp->ptr;

            temp->ptr=(temp->ptr)->ptr;

            mem->ptr=NULL;
            delete mem;  
        }
        else{
            temp=temp->ptr;                     // here we took it in else coz if suppose there are 3 duplicates (say 6 6 6), then after removing 2nd 6, 
        }                                       // it will jump to 3rd 6 nd hence 3rd 6 nd its next(4) are not same, so 3rd 6 will not get removed. But with else 
    }                                           // we will stay on 1st 6 and compare all the upcoming numbers nd hence they will get removed (only in sorted list)
}



//Removing Duplicates in a unsorted list. O(n^2) approach
void duplicates_UnS1(node*&head){
    
    if(head==NULL||head->ptr==NULL||head->ptr==head){
        return;
    }

    node*temp=head;
    while(temp->ptr!=NULL){
        node*trav=temp;
        while(trav->ptr!=NULL){

            if(temp->a==(trav->ptr)->a){
                node *mem=trav->ptr;

                trav->ptr=(trav->ptr)->ptr;                     // Taking 1 node and traversing other node to remaining list, and comparing them;
                mem->ptr=NULL;                                  // Space complexity = O(1);
                delete mem;                                     // Time Complexity = O(n^2);
            }
            else{
                trav=trav->ptr;
            }
        
        }
        temp=temp->ptr;
    }
}




//Removing Duplicates in a unsorted list. O(n.log(n)) approach

//Step-I  : Sort the list. O(n.log(n))
//Step-II : Algo of sorted list. O(n)
//Net time complexity = O(n.log(n))
void duplicates_US2(node*&head){
    
    if(head==NULL||head->ptr==NULL||head->ptr==head){
        return;
    }

}




//Removing Duplicates in a unsorted list. Map approach
//Time complexity =O(n).
//Space Complexity = O(n). 
void duplicates_UnS3(node*&head){
    
    if(head==NULL||head->ptr==NULL||head->ptr==head){
        return;
    }

    map<int,bool>visited;
    node*temp=head;
    while(temp->ptr!=NULL){
        visited[temp->a]=true;
        if(visited[(temp->ptr)->a]==true){
             node *mem=temp->ptr;
 
             temp->ptr=(temp->ptr)->ptr;
 
             mem->ptr=NULL;
             delete mem;  
        }
        else{
             temp=temp->ptr;
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
    node *n1=new node(2);
    node *head=n1;

    insert_at_tail(n1,2);
    insert_at_tail(n1,2);
    insert_at_tail(n1,4);
    insert_at_tail(n1,5);
    insert_at_tail(n1,4);

    duplicates_UnS3(head);

    print(head);
    return 0;
}