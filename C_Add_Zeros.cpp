#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
map<int,vector<int>>  mp;
map<int,bool> vis;

int ans;

void dfs(int l)
{
    //cout<<l<<endl;
    vis[l]=true;
    ans=max(ans,l);

    if(mp[l].empty()) return;

    for(auto idx:mp[l])
    {
        int nl=l+idx;
        if(vis[nl]) continue;
        dfs(nl);
    }
}

void solve()
{
    cin>>n;
    ans=n;
    mp.clear();
    vis.clear();
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int l=i+x;
        mp[l].push_back(i);
    }

    dfs(n);

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