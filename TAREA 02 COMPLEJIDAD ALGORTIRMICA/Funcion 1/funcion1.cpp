#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion1(int _n){
    
    int n=_n;
    int a=0,b=0,c=0;
    
    for(int i=0;condition(i,n,a);i++){  //n + 1
        b++; 
        if(i % 2 == 0){ // n 
            c++; 
            cout<<i<<endl; // n/2 + 1
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
}

int main(){
    funcion1(13);
    return 0;
}
