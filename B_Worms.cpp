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
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        if(i) v[i]+=v[i-1];
    }
    // for(auto it:v)
    // cout<<it<<' ';
    // cout<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        int l=0,r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(v[m]<x) l=m+1;
            else r=m-1;
        }
        cout<<l+1<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}