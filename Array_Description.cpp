#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n, m;
vector<int> v;
vector<vector<int>> dp;

int rec(int i, int prev)
{
    //cout<<i<<' '<<prev<<endl;
    if (i == n)
        return 1;
    if (dp[i][prev] != -1)
        return dp[i][prev];

    int ans = 0;

    if (v[i] == 0)
    {
        if (prev - 1 >= 1)
            ans = (ans + rec(i + 1, prev - 1)) % mod;
        if (prev + 1 <= m)
            ans = (ans + rec(i + 1, prev + 1)) % mod;
        ans = (ans + rec(i + 1, prev)) % mod;
    }
    else
    {
        if(abs(prev-v[i])>1)
        {
            dp[i][prev]=0;
            return 0;
        }
        else ans=rec(i+1,v[i]);
    }

    return dp[i][prev] = ans;
}

void solve()
{
    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    dp.resize(n,vector<int>(m+1,-1));
    int ans=0;
    if(v[0]==0)
    {
        for(int i=1;i<=m;i++)
        ans=(ans+rec(1,i))%mod;
    }
    else ans=rec(0,v[0]);
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}