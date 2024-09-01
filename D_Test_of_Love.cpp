#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    string t;
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'L')
        {
            t += 'L';
            while (i < n && s[i] == 'L')
                i++;
        }
        else
        {
            t += s[i];
            i++;
        }
    }

    int cnt = 0;
    t = "L" + t + "L";
    n = t.size();
    i = 0;
    while (i < n)
    {
        if (t[i] == 'L')
        {
            bool f = 0;
            int l = m;
            for (int j = 1; j <= m; j++)
            {
                if (i + j < n)
                {
                    if (t[i + j] == 'L')
                    {
                        f = 1;
                        l = j;
                        break;
                    }
                }
            }
            if (i + l < n && t[i + l] == 'C')
            {
                cout << "NO" << endl;
                return;
            }
            i += l;
            continue;
        }

        else
        {
            while (i < n && t[i] == 'W')
                i++, cnt++;
            if (i < n && t[i] == 'C')
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (cnt <= k)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}