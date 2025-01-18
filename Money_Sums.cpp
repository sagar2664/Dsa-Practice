#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    set<int> ps;
    ps.insert(0);

    for(int c:v)
    {
        set<int> ns;
        for(int i:ps)
        ns.insert(i+c);

        ps.insert(ns.begin(),ns.end());
    }

    ps.erase(0);

    cout<<ps.size()<<endl;
    for(auto it:ps) cout<<it<<' ';
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}