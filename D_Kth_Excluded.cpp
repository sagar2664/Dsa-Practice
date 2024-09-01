#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> c(n+1),a(n+1);
    c[0]=0;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i]-i;
    }

    // for(auto it:c)
    // cout<<it<<' ';
    // cout<<endl;

    while(q--)
    {
        int k;
        cin>>k;
        int i=lower_bound(c.begin(),c.end(),k)-c.begin();
        //cout<<i<<' ';
        if(i==n+1)
        cout<<a[n]+(k-c[n])<<endl;
        else
        cout<<a[i]-(c[i]-k+1)<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}