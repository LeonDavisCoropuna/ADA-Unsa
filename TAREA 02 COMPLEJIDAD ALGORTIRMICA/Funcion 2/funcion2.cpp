#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion2(int _n){
    int n=_n;
    //contadores del primer for {a,b,c}
    //contadores del segundo for {d,e,f}
    int a=0,b=0,c=0,d=0,e=0,f=0;
    
    for(int i=0;condition(i,n,a);i++){ //n+1
        b++;
        if(i % 2 == 0){ //n
            c++;
            cout<<i<<endl; //n/2 (piso) + 1
        }
    }
    
    for(int i=0;condition(i,n,d);i++){ //n+1
        e++;
        if(i % 2 != 0){ //n
            f++;
            cout<<i<<endl; //n/2 (piso)
        }
    }
    cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"-"<<e<<"-"<<f<<endl;
    //
}
int main(){
    funcion2(15);
    return 0;
}
