#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,num_monedas,m;
    cin>>n;
    for(int h=0;h<n;h++){
        cin>>num_monedas;
        vector<int> monedas;
        for(int i=0;i<num_monedas;i++){
            cin >> m;
            monedas.push_back(m);
        }
        int curSum = 0, res = 0;
        for (int i = 0; i < num_monedas; i++){
            if (num_monedas - 1 == i || curSum + monedas[i] < monedas[i + 1]){
                curSum += monedas[i];
                res++;
            }
        }
        cout << res << endl;
    }
}