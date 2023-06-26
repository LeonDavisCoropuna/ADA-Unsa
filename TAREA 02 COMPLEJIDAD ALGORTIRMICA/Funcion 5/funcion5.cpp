#include <iostream>

using namespace std;


void funcion5(string _a,string _b){
    string A = _a, B = _b; 
    int a=0,b=0,c=0;
    for(int i=0;i <= A.size()+2;i++){ // A + 1
        for(int j=0;j <= B.size()+1;j++){ // A(B+1)
            c++;
            cout<<A[i]<<","<<B[j]<<endl; // AB
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(A*B)
}


int main(){
    funcion5("hola","buenas");
    return 0;
}
