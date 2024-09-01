#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n-1);
    for(auto &i:v) cin>>i;
    int l;
    cin>>l;
    sort(v.begin(),v.end());
    cout<<v[n-2]+l<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}