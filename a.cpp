#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> g[MAXN];
#define ll long long

vector<ll> dijkstra(int s, int n) {
    vector<ll> d(n + 1, LLONG_MAX);
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist > d[u]) continue;

        for (auto it : g[u]) {
            int v = it.first;
            ll cost = it.second;
            if (d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    vector<ll> d1 = dijkstra(1, n);
    vector<ll> dN = dijkstra(n, n);

    ll minCost = d1[n];

    for (int u = 1; u <= n; ++u) {
        for (auto it : g[u]) {
            int v = it.first;
            ll cost = it.second;
            if (u < v) {
                ll discountedCost = cost / 2;
                ll totalCost = d1[u] + discountedCost + dN[v];
                minCost = min(minCost, totalCost);
            }
        }
    }

    cout << minCost << endl;

    return 0;
}
