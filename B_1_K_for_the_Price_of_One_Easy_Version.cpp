#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,p,k;
    cin>>n>>p>>k;

    map<int,int> mp;
    vector<int> rem;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }

    int ans=0;
    vector<pair<int,int>> v;

    for(auto it:mp)
    v.push_back({it.first,it.second});
    int m=(int)v.size();

    for(int i=0;i<m-1;i++)
    {
        int price=v[i].first;
        int cnt=v[i].second;

        if(cnt&1)
        {
            cnt--;
            rem.push_back(price);
            int t=p/price;
            
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}