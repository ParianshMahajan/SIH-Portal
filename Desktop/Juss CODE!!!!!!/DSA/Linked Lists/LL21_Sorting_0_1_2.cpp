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



// Approach 1 :: counting 0's,1's and 2,s nd  overwriting values;
// Data replacement
void sort012(node *&head){
    node*temp=head;
    vector<int>vect(3,0);
    while(temp!=NULL){
        vect[(temp->a)]++;
        temp=temp->ptr;
    }
    temp=head;
    int i=0;
    while(temp!=NULL){
        while(vect[i]!=0 && temp!=NULL){
            temp->a=i;
            temp=temp->ptr;
            vect[i]--;
        }
        i++;
    }
}






//Approach 2 :: Without data Replacement;
//By creating different LL and merging em;
 void merge_sort012(node *&head){
    node*temp=head;
 
    //3 LLs
    node*zerohead=new node(-1);
    node*zerotail=zerohead;
    node*onehead=new node(-1);
    node*onetail=onehead;
    node*twohead=new node(-1);
    node*twotail=twohead;

    while(temp!=NULL){
        if(temp->a==0){
            zerotail->ptr=temp;
            zerotail=temp;
        }
        else if(temp->a==1){
            onetail->ptr=temp;
            onetail=temp;
        }
        else if(temp->a==2){
            twotail->ptr=temp;
            twotail=temp;
        }
        temp=temp->ptr;
    }

    //Merging
    //NOTE : Initially,every list's first element is -1

    //1sLL is not empty
    if(onehead->ptr!=NULL){
        zerotail->ptr=(onehead->ptr);    //Linking 0sLL nd 1sLL ignoring -1;
    }
    else{
    //1sLL is empty
        zerotail->ptr=(twohead->ptr);    //Linking 0sLL with 2sLL;
    }


    onetail->ptr=(twohead->ptr);     //Linking 1sLL nd 2sLL ignoring -1;

    twotail->ptr=NULL;               //because at temp==NULL loop breaks due to which twotail->ptr still not NULL

    head=zerohead->ptr;              //Updating head ignoring starting's -1;


    //Deleting dummy nodes (-1s)
    delete zerohead;
    delete onehead;
    delete twohead;

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
    merge_sort012(head);
    print(head);

    return 0;
}