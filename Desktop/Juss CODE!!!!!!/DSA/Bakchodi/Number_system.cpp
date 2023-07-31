#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>

int dec_to_bin(int n){
    int bin=0,i=0;
    while(n>0){
      int d=n%2;
      bin=bin+d*(pow(10,i));
      i++;
      n=n/2;
    }
    return bin;
  }

int bin_to_dec(int n){
    int dec=0,i=0;
    while(n>0){
      int d=n%10;
      dec=dec+d*(pow(2,i));
      i++;
      n=n/10;
    }
    return dec;
}

int dec_to_oct(int n){
 int oct=0,i=0;
    while(n>0){
      int d=n%8;
      oct=oct+d*(pow(10,i));
      i++;
      n=n/8;
    }
    return oct;
}

int oct_to_dec(int n){
  int dec=0,i=0;
    while(n>0){
      int d=n%10;
      dec=dec+d*(pow(8,i));
      i++;
      n=n/10;
    }
    return dec; 
}

void dec_to_hex(int n){
    deque<int>s;
    int hex=0,i=0;
    while(n>0){
      int d=n%16;
      if(d<=9){
        s.push_front(int(d));
      }
      else if(d>9&&d<=15){
        s.push_front(char(d+55));
      }
      
      n=n/16;
    }
    cout<<"The Hexadecimal code is :: ";
    for(int i:s){
      if(i<=9){
      cout<<i;
    }
    else{
      cout<<char(i);
    }
    }
}

int hex_to_dec(string s){
  int dec=0;
  int x;
  for(int i=s.size()-1 ;i>=0  ;i--){
  if(48<=s[i]&&s[i]<=57){
    x=int(s[i])-48;
  }
  else if(65<=s[i]&&s[i]<=70){
    x=int(s[i])-55;
  }
  dec+=x*pow(16,s.size()-1-i);
 }
 return dec;
}

int main(){ 
  int a,b,k=-1;
  while(k==-1){
  

  cout<<"1 : Decimal \n";
  cout<<"2 : Binary  \n";
  cout<<"3 : Octal \n";
  cout<<"4 : Hexadecimal \n";
  cout<<"0: To exit the code.\n ";
  cout<<"Press following for desired function in the format of  \n";
  cout<<"____ to ____ \n";
  
  cout<<"Enter the 1st operator value :: ";
  cin>>a;
  
  //To exit.
  if(a==0){
    k=1;
    break;
  }

  cout<<"Enter the 2nd operator value :: ";
  cin>>b;



  //Decimal To Binary
   if(a==1&&b==2){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int bin = dec_to_bin(n);
    cout<<"The binary code is :: "<<bin<<endl<<endl;
   }
  
  //Decimal To Octal
  else if(a==1&&b==3){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int oct=dec_to_oct(n);
    cout<<"The octal code is :: "<<oct<<endl<<endl;
  }

  //Decimal To Hexadecimal
  else if(a==1&&b==4){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    dec_to_hex(n);
    cout<<endl<<endl;
  }



  //Binary To Decimal;
  else if(a==2&&b==1){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=bin_to_dec(n);
    cout<<"The decimal code is :: "<<dec<<endl<<endl;
  }
  
  //Binary To Octal;
  else if(a==2&&b==3){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=bin_to_dec(n);
    int oct=dec_to_oct(dec);
    cout<<"The octal code is :: "<<oct<<endl<<endl;
  }
  
  //Binary To Hexadecimal
  else if(a==2&&b==4){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=bin_to_dec(n);
    dec_to_hex(dec);
    cout<<endl<<endl;
  }
  

  
  //Octal To Decimal;
  else if(a==3&&b==1){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=oct_to_dec(n);
    cout<<"The decimal code is :: "<<dec<<endl<<endl;
  }
  
  //Octal To Binary;
  else if(a==3&&b==2){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=oct_to_dec(n);
    int bin=dec_to_bin(dec);
    cout<<"The binary code is :: "<<bin<<endl<<endl;
  }
  
  //Octal To Hexadecimal
  else if(a==3&&b==4){
    int n;
    cout<<"Enter the number :: ";
    cin>>n;
    int dec=oct_to_dec(n);
    dec_to_hex(dec);
    cout<<endl<<endl;
  }


  
   //Hexadecimal To Decimal;
  else if(a==4&&b==1){
    cout<<"Enter the number :: ";
    string s;
    cin>>s;
    int dec=hex_to_dec(s);
    cout<<"The decimal code is :: "<<dec<<endl<<endl;
  }
  
  //Hexadecimal To Binary;
  else if(a==4&&b==2){
    string s;
    cout<<"Enter the number :: ";
    cin>>s;
    int dec=hex_to_dec(s);
    int bin=dec_to_bin(dec);
    cout<<"The binary code is :: "<<bin<<endl<<endl;
  }
  
  //Hexadecimal To Octal;
  else if(a==4&&b==3){
    string s;
    cout<<"Enter the number :: ";
    cin>>s;
    int dec=hex_to_dec(s);
    int oct=dec_to_oct(dec);
    cout<<"The octal code is :: "<<oct<<endl<<endl;
  }
  
  }
  return 0;
}