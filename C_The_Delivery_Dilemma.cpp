#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    cin>>v[i].first;
    for(int j=0;j<n;j++)
    cin>>v[j].second;

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int s=0;
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,max(v[i].first,s));
        s+=v[i].second;
    }
    ans=min(ans,max(0LL,s));
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