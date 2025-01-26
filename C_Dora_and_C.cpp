#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int g=__gcd(a,b);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]%=g;
    }
    sort(v.begin(),v.end());
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        if(i==0) ans=min(ans,v[n-1]-v[0]);
        else ans=min(ans,g+v[(i+n-1)%n]-v[i]);
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