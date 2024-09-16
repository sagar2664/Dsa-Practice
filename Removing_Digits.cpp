#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,1e9);
    // for(int i=1;i<=9;i++)
    // dp[i]=1;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        int t=i;
        while(t)
        {
            dp[i]=min(dp[i],1+dp[i-(t%10)]);
            t/=10;
        }
    }
    cout<<dp[n]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}