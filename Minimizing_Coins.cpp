#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(auto &i:coins) cin>>i;
    vector<int> dp(x+1,1e9);

    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        if(x>=coins[i]) dp[coins[i]]=1;
    }

    
    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)
            dp[i]=min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if(dp[x]!=1e9)
    cout<<dp[x]<<endl;
    else cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);solve();
}