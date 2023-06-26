#include <iostream>

using namespace std;

bool condition(int i,int n,int &count){
    count++;
    return i < n;
}

void funcion7(){
    int a=0,b=0,c=0,d=0,e=0;
    int n = 1000; a++; //1
    if(n % 2 == 0){ //1
        b++;
        cout<<"par"<<endl; //1
    }
    else{ 
        c++;
        cout<<"impar"<<endl;
    }
    //3
    //O(1)
}



int main(){
    funcion7();
    return 0;
}
