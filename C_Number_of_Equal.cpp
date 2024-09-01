#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,int> mp;
    int ans=0;
    while(n--)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    while(m--)
    {
        int x;
        cin>>x;
        ans+=mp[x];
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}