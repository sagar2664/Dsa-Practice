#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int INF = 1e18;
#define endl '\n'

int n, m;
vector<vector<int>> dp;
vector<int> ps, b, v;

int rec(int i, int k) {
    if (i >= n) return 0;
    if (k >= m) return INF;

    if (dp[i][k] != -1) return dp[i][k];

    int ans = rec(i, k + 1);

    int value = (i == 0) ? b[k] : b[k] + ps[i - 1];
    int len = upper_bound(ps.begin() + i, ps.end(), value) - (ps.begin() + i);
    if (len > 0)
        ans = min(ans, m - k - 1 + rec(i + len, k));

    return dp[i][k] = ans;
}

vector<vector<pair<int, int>>> d;

pair<int, int> cnt(int i, int k) {
    if (i >= n) return {0, 1};
    if (k >= m) return {INF, 0};

    if (d[i][k].first != -1) return d[i][k];

    // Option 1: Move to the next `k`
    pair<int, int> c1 = cnt(i, k + 1);

    // Option 2: Remove all valid prefix sums within the limit of b[k]
    int value = (i == 0) ? b[k] : b[k] + ps[i - 1];
    pair<int, int> best = c1;

    for (int len = 1; len <= n - i; ++len) {
        if (ps[i + len - 1] > value) break;

        pair<int, int> c2 = cnt(i + len, k);
        c2.first += m - k - 1;

        if (c2.first < best.first) {
            best = c2;
        } else if (c2.first == best.first) {
            best.second = (best.second + c2.second) % mod;
        }
    }

    d[i][k] = best;
    return best;
}

void solve() {
    cin >> n >> m;
    dp.clear();
    v.clear();
    ps.clear();
    b.clear();
    d.clear();

    dp.resize(n + 1, vector<int>(m + 1, -1));
    d.resize(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    v.resize(n);
    ps.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ps[i] = v[i] + (i > 0 ? ps[i - 1] : 0);
    }

    for (auto &x : b) cin >> x;

    for (int i = 0; i < n; i++) {
        if (v[i] > b[0]) {
            cout << -1 << endl;
            return;
        }
    }

    auto result = cnt(0, 0);
    cout << result.first << ' ' << result.second << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}
