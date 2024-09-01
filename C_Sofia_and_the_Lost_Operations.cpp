#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto& i:a) cin>>i;
    for(auto& i:b) cin>>i;
    int m;
    cin>>m;
    map<int,int> mp;
    int last=b[0];
    for(int i=0;i<m;i++)
    {
        cin>>last;
        mp[last]++;
    }

    bool l=false;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        if(mp[b[i]]==0){cout<<"NO"<<endl;return;}
        mp[b[i]]--;
    }

    for(int i=0;i<n;i++)
    if(b[i]==last) l=true;

    if(l) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}