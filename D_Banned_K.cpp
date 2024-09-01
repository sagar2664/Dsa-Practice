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
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }

    int ans=0;
    for(auto it:mp)
    {
        ans+=(it.second)*(it.second-1)/2;
    }

    for(int k=0;k<n;k++)
    {
        int t=ans;
        t-=mp[v[k]]*(mp[v[k]]-1)/2;
        mp[v[k]]--;
        t+=mp[v[k]]*(mp[v[k]]-1)/2;
        cout<<t<<endl;
        mp[v[k]]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}