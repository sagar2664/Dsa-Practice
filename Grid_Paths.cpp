#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<string> g(n);
    for(auto &i:g) cin>>i;

    vector<vector<int>> dp(n+1,vector<int>(n+1));

    if(g[0][0]!='*')
    dp[0][0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j]=='*') continue;
            if(i-1>=0)
            dp[i][j]=dp[i-1][j];
            if(j-1>=0)
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }

    cout<<dp[n-1][n-1]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}