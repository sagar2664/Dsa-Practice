#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
vector<vector<int>> g;
vector<int> vis;

void dfs(int u)
{
    vis[u]=true;
    for(auto it:g[u])
    {
        if(vis[it]) continue;
        dfs(it);
    }
}

void solve()
{
    cin>>n;
    g.resize(n+26);
    vis.resize(n+26,false);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(auto c:s)
        {
            g[i].push_back(n+c-'a');
            g[n+c-'a'].push_back(i);
        }
    }

    int ans=0;
    for(int i=0;i<n+26;i++)
    {
        if(!g[i].empty() && !vis[i])
        dfs(i),ans++;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}