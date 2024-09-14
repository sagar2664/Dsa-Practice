#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int rec(int n,vector<int>& dp)
{
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];

    dp[n]=0;
    for(int i=1;i<=6;i++)
    dp[n]=(dp[n]+rec(n-i,dp))%mod;

    return dp[n];
}

void solve()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<rec(n,dp)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}