#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int b, c, d;
    cin >> b >> c >> d;
    int a = 0;
    bool fail = false;
    for (int bit = 0; bit < 60; bit++)
    {
        int bb = (b >> bit) & 1;
        int cc = (c >> bit) & 1;
        int dd = (d >> bit) & 1;

        vector<int> ac;
        for (int aa = 0; aa < 2; aa++)
        {
            if ((aa | bb) - (aa & cc) == dd)
                ac.push_back(aa);
        }
        if (ac.empty())
        {
            fail = true;
            break;
        }
        a |= (ac[0] << bit);
    }
    if (fail)
        cout << -1 << endl;
    else
        cout << a << endl;
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