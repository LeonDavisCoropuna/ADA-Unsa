#include<iostream>

using namespace std;

int Recursivo(int x, int ** A,int *&q,int n){
    if((q[0] > n-1) || (q[1] < 0)){ return 0;}
    if(x<A[q[0]][q[1]]){
        q[1]--;
    }
    else if(x > A[q[0]][q[1]]){
        q[0]++;
    }
    else return 1;
    return Recursivo(x,A,q,n);
}

int main(){
    int n = 4;
    int x = -30;
    int x2 = 13;
    int x3 = 56;
    int ** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int;
    }
    int aux = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = aux;aux++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }
    int *con = new int[2];
    con[0] = 0;con[1] = n-1;
    cout<<"Encontrado "<<x<<"?: "<<Recursivo(x,arr,con,n);
    con[0]=0;con[1]=n-1;
    cout<<endl;
    cout<<"Encontrado "<<x2<<"?: "<<Recursivo(x2,arr,con,n);

    con[0]=0;con[1]=n-1;
    cout<<endl;
    cout<<"Encontrado "<<x3<<"?: "<<Recursivo(x3,arr,con,n);

    return 0;
}