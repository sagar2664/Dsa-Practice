#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    string s;
    cin >> s;
    vector<bool> b(n);

    int mi = 1e18, ma = -2;
    for (int i = 0; i < n; i++)
    {
        mi = min(mi, v[i]);
        ma = max(ma, v[i]);
        if (mi == 1 && ma == i + 1)
            b[i] = true;
        else
            b[i] = false;
    }
    set<int> st;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'L' && s[i + 1] == 'R' && b[i] == false)
            st.insert(i);
    }

    // for (auto it : v)
    //     cout << it << ' ';
    // cout << endl;
    // for (auto it : b)
    //     cout << it << ' ';
    // cout << endl;
    // for (auto it : st)
    //     cout << it << ' ';
    // cout << endl;

    while (q--)
    {
        int idx;
        cin >> idx;
        idx--;

        if (s[idx] == 'L')
            s[idx] = 'R';
        else
            s[idx] = 'L';

        if (s[idx] == 'L' && s[idx + 1] == 'R' && b[idx]==false)
        {
            st.insert(idx);
        }
        else
            st.erase(idx);
        if (s[idx - 1] == 'L' && s[idx] == 'R' && b[idx-1]==false)
        {
            st.insert(idx - 1);
        }
        else
            st.erase(idx - 1);

        if (st.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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