#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m,r,c;
    cin>>n>>m>>r>>c;

    int ans=(n-r)*(m-1+1);
    ans+=(n-r)*(m-1);
    ans+=(m-c);

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}