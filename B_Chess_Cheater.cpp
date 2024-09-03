#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int s = 0, e = n - 1, cnt = 0;

    while (s < n && t[s] == 'L')
    {
        s++;
        cnt++;
    }

    if (s == n)
    {
        if (k == 0)
            cout << 0 << endl;
        else
            cout << min(k * 2 - 1, n * 2 - 1) << endl;
        return;
    }

    while (e >= 0 && t[e] == 'L')
    {
        e--;
        cnt++;
    }

    vector<int> v;

    int c = 0;
    for (int i = s; i <= e; i++)
    {
        if (t[i] == 'L')
            c++;
        else
        {
            if (c == 0)
                continue;
            v.push_back(c);
            c = 0;
        }
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (k >= v[i])
        {
            ans += v[i] * 2 + 1;
            k -= v[i];
        }
        else
        {
            ans += k * 2;
            k = 0;
        }
    }

    ans += min(k * 2, cnt * 2);

    for (int i = 0; i < n; i++)
    {
        if (t[i] == 'W')
        {
            if (i - 1 >= 0 && t[i - 1] == 'W')
                ans += 2;
            else
                ans++;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}