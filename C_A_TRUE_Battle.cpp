#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 2)
    {
        if (s == "00")
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1')
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (s[0] == '1' || s[n - 1] == '1')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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