// Sagar Bapu Raykar
// IIT Kharagpur
// Maharahtra
// time 21:14
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    string blah = to_string(n);
    string result;
    string cat;

    vector<pair<int, int>> a;
    for (int i = 1, res, cur; i <= 10000; i++)
    {
        res = n * i;
        result = to_string(res);

        cat = "";
        for (int j = 0; j < i and cat.size() < result.size(); j++)
        {
            cat += blah;
        }

        while (cat.size())
        {
            if (cat.size() <= result.size())
            {
                cur = stoi(cat);
                if (res > cur and
                    i * (int)blah.size() - (int)cat.size() == res - cur)
                {
                    a.push_back({i, res - cur});
                }
            }
            cat.pop_back();
        }
    }

    cout << a.size() << '\n';
    for (const auto &mor : a)
    {
        cout << mor.first << ' ' << mor.second << '\n';
    }
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