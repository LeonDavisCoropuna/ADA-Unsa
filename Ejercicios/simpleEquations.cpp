#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int A,B,C;
        cin>>A;cin>>B;cin>>C;
        bool sol = false; int x ,y ,z;
        for(x = -22; (x <= 22) && !sol; x++){
            if(x*x<=C){
                for(y = -100; (y <= 100) && !sol; y++){
                    if((y!=x)&&(x*x+y*y<=C)){
                        for(z = -100; (z <= 100) && !sol; z++){
                            if((z!=x) && (z!=y) && (x+y+z == A) && (x*y*z == B) && (x*x+y*y+z*z == C)){
                                cout<<x<<" "<<y<<" "<<z<<endl;
                                sol = true;
                            }
                        }
                    }
                }
            }
        }
        if(!sol) cout<<"No solution."<<endl;
    }
    return 0;
}
