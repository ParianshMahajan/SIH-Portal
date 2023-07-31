#include<bits/stdc++.h>
using namespace std;

class A{
    private:
        int x;

    protected:
        int y;

    public:
        int z;    
};


class B: public A{                                  // CLASS A IS PUBLICLY INHERITED :: PRIVATE DATA NOT BE TRANSFERRED 
                                                    //                               :: PROTECTED DATA WILL BE TRANSFERRED AND ACCESSED AS PROTECTED DATA
                                                    //                               :: PUBLIC DATA WILL BE TRANSFERRED AND ACCCESSED AS PUBLIC DATA
};



class C: protected A{                               // CLASS A IS PROTECTEDLY INHERITED :: PRIVATE DATA NOT BE TRANSFERRED 
                                                    //                                  :: PROTECTED DATA WILL BE TRANSFERRED AND ACCESSED AS PROTECTED DATA
                                                    //                                  :: PUBLIC DATA WILL BE TRANSFERRED AND ACCCESSED AS PROTECTED DATA
};



class D: private A{                                 // CLASS A IS PUBLICLY INHERITED :: PRIVATE DATA NOT BE TRANSFERRED 
                                                    //                               :: PROTECTED DATA WILL BE TRANSFERRED AND ACCESSED AS PRIVATE DATA
                                                    //                               :: PUBLIC DATA WILL BE TRANSFERRED AND ACCCESSED AS PRIVATE DATA
};







int main(){
    

    return 0;
}