#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion6(int _n){
    int n=_n,j;
    int a=0,b=0,c=0,d=0,e=0;
    for(int i=0; condition(i,n,a);i++){ //n+1 
        j=1; b++; // n --9
        while(condition(j,n,c)){ //n(log2n + 1) 
            cout<<j<<endl; d++; //n(log2n)  
            j *= 2; e++; //n(log2n)
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"-"<<e<<endl;
    //O(nlog2n)
}

int main(){
    funcion6(9);
    return 0;
}
