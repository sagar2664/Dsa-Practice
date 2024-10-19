#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl '\n'

int n;
vector<vector<int>> g;
vector<int> seq;
vector<bool> vis;
vector<int> pr;
vector<int> stidx;

void dfs(int city,int par)
{
    seq.push_back(city);
    for(auto v:g[city])
    {
        if(v==par) continue;
        dfs(v,city);
        seq.push_back(city);
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    vis.resize(n + 1);
    pr.resize(n + 1);
    stidx.resize(n + 1);
    pr[1] = -1;

    for (int i = 0; i <= n - 2; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());

    dfs(1,-1);

    for (auto it : seq)
        cout << it << ' ';
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}