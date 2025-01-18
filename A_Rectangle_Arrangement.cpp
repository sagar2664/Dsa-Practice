#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    int h=0,w=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        h=max(x,h);
        w=max(w,y);
    }
    cout<<2*(h+w)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}