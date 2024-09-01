#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    map<int,int> mp;
    vector<vector<int>> g(n*2+10);
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        if(mp[u]==0)
        mp[u]=2*i;
        if(mp[v]==0)
        mp[v]=2*i + 1;
        if(u==1) mp[u]=1;
        if(v==1) mp[v]=1;
        g[mp[u]].push_back(mp[v]);
        g[mp[v]].push_back(mp[u]);
    }

   
    queue<int> q;
    vector<bool> vis(n*2+10);
    vis[1]=true;
    q.push(1);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto it:g[u])
        {
            if(vis[it]) continue;
            vis[it]=true;
            q.push(it);
        }
    }

    
        int ans=1;
        for(auto it:mp)
        {
            if(vis[it.second])
            ans=it.first;
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