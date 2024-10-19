#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n, l;
vector<vector<int>> dp;
vector<int> h;
vector<int> p;

void solve()
{
    cin >> n >> l;
    dp.resize(n + 1, vector<int>(l + 1, 0));  // Initialize dp array with 0
    h.resize(n + 1);
    p.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    // DP transitions
    for (int i = 1; i <= n; i++) {
        for (int x = h[i]-1; x <= l; x++) {
            dp[i][x] = dp[i - 1][x];  // Don't take book i
            if (x >= h[i])  // Take book i if the budget allows
                dp[i][x] = max(dp[i][x], p[i] + dp[i - 1][x - h[i]]);
        }
    }

    cout << dp[n][l] << endl;  // Maximum number of pages with budget l
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
