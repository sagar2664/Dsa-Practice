#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (auto &i : c) cin >> i;

    vector<int> dp(x + 1, 0);
    dp[0] = 1; // There's 1 way to make sum 0 (by choosing no coins)

    // Process each coin one by one
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - c[i]]) % mod;
        }
    }

    cout << dp[x] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
