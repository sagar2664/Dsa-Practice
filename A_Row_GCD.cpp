#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto& i:a) cin>>i;
    for(auto& i:b) cin>>i;
    sort(a.begin(),a.end());

    if(n==1)
    {
        for(int i=0;i<m;i++)
        cout<<a[0]+b[i]<<' ';
        cout<<endl;
        return;
    }

    int g=0;
    for(int i=1;i<n;i++)
    g=__gcd(g,a[i]-a[0]);

    for(int i=0;i<m;i++)
    cout<<__gcd(g,a[0]+b[i])<<' ';
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}