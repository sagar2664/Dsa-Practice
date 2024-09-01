#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> isleaf(n, false);
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
            isleaf[i] = true;
    }

    vector<int> dist(n, 1e9);
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(0);
    dist[0] = 0;
    vis[0] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto v : g[u])
        {
            if (vis[v])
                continue;
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int cnt = 0;
    long double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (isleaf[i])
            ans += dist[i], cnt++;
    }
    ans /= cnt;
    cout << fixed << setprecision(15) << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}