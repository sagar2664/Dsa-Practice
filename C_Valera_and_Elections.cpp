#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
vector<vector<int>> g;
vector<bool> re;
vector<int> dp;

void rec(int u,int prev)
{
    dp[u]=re[u];
    for(auto v:g[u])
    {
        if(v==prev) continue;
        rec(v,u);
        dp[u]+=dp[v];
    }
}

void solve()
{
    cin>>n;
    g.resize(n);
    re.resize(n,false);
    dp.resize(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,r;
        cin>>u>>v>>r;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        if(r==2)
        re[u]=1,re[v]=1;
    }
    rec(0,-1);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==1 && re[i])
        ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    for(auto it:ans)
    cout<<it<<' ';
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}