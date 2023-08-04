#include <iostream>
using namespace std;
int n, p;
int nums[25];
int ans;
void dfs(int sum, int i) {
    if (sum > n) return ;
    if (sum == n) ans = 1;
    for (;i < p; i++) {
        dfs(sum+nums[i], i+1);
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--) {
        cin>>n;cin>>p;
        for (int i = 0; i < p; i++)
            cin>>nums[i];
        ans = 0;
        dfs(0, 0);
        if (ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
