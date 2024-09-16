#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> dp(x+1);
    vector<int> coins(n);
    for(auto &i:coins) cin>>i;

    dp[0]=1;
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)
            dp[i]=(dp[i]+dp[i-coins[j]])%mod;
        }
    }

    cout<<dp[x]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin >> _t;while (_t--)
        solve();
}