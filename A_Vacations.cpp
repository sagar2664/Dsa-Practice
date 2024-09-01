#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n, m;
vector<vector<int>> g;
int sz = 0;
vector<bool> vis;

void dfs(int node)
{
    sz++;
    vis[node] = 1;
    for (auto it : g[node])
    {
        if (!vis[it])
            dfs(it);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> compsz;
    for (int i = 1; i <= n; i++)
    {
        sz = 0;
        if (!vis[i])
        {
            dfs(i);
            compsz.push_back(sz);
        }
    }
    int ans = 0, prev = 0;
    for (auto v : compsz)
    {
        ans += prev * v;
        prev += v;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
}