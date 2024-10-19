#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,k;
    cin>>n>>k;

    if(k==1)
    {cout<<n<<endl;
    return;}
    int ans=0;
    while(n)
    {
        ans+=n%k;
        n/=k;
    }
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