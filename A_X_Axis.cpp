#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int m=1e18;
    for(int i=-5;i<15;i++)
    {
        int t=abs(a-i)+abs(b-i)+abs(c-i);
        m=min(t,m);
    }
    cout<<m<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}