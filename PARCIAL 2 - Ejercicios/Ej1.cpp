#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mediana(vector <int> &vec){
    int n = vec.size();
    if(n % 2 == 0){
        return (vec[n/2]+vec[n/2-1])/2;
    }
    return vec[n/2];
};

int main(){
    int c;
    vector<int> vec;
    while(cin>>c){
        vec.push_back(c);
        sort(vec.begin(),vec.end(),greater<int>());
        cout<<mediana(vec)<<endl;
    }

    return 0;
}