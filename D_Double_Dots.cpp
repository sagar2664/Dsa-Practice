#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+1,1e9);
    dist[1]=0;
    vector<int> sign(n+1);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto v:g[u])
        {
            if(dist[v]>dist[u]+1)
            {
                dist[v]=dist[u]+1;
                sign[v]=u;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(dist[i]==1e9)
        {
            cout<<"No"<<endl;
            return;
        }
    }

    cout<<"Yes"<<endl;
    for(int i=2;i<=n;i++)
    cout<<sign[i]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}