#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int l,r;
    cin>>l>>r;
    int k=63-__builtin_clzll(l^r);
    int a=l | ((1ll<<k)-1);
    int b=a+1;
    int c=(a==l)?r:l;
    cout<<a<<' '<<b<<' '<<c<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;cin >> _t;while (_t--)
        solve();
}