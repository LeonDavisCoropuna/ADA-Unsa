#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion4(int _n){
    int n=_n,i=1; //1
    int a=0,b=0,c=0;
    while(condition(i,n,a)){ //log2n + 1 se redondeda el log2n a techo
        cout<<i<<endl; b++;//log2n 
        i *= 2; c++;//log2n
    }
    cout<<a<<"-"<<b<<"-"<<c<<endl;
    //O(log2n)
}

int main(){
    funcion4(32);
    return 0;
}
