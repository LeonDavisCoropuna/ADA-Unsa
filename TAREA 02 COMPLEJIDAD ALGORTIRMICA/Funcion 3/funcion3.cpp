#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion3(int _n){
    int n=_n;
    
    int a=0,b=0,c=0;
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        for(int j=i;condition(j,n,b);j++){ // (n+1)(n)/2 + n
            c++;
            cout<<i<<","<<j<<endl; //n(n+1)/2
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(n^2)
}
int main(){
    funcion3(21);
    return 0;
}
