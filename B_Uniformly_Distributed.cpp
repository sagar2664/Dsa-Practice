#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &it : v)
        cin >> it;

    int ans = 1;
    for (int sum = 0; sum <= n + m - 2; sum++)
    {
        int cntr = 0, cntb = 0, cntd = 0;
        for (int i = 0; i < n; i++)
        {
            int j = sum - i;
            if(j<0 || j>=m) continue;
            cntr += (v[i][j] == 'R');
            cntb += (v[i][j] == 'B');
            cntd += (v[i][j] == '.');
        }
        if (cntr && cntb)
        {
            ans = 0;
            break;
        }
        else if (cntd && !cntb && !cntr)
            ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}