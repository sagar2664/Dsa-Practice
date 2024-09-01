#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    int i=n;
    int t=0;
    while(k>0)
    {
        if(i==n) k-=n,i--;
        else{
            k-=i;
            if(t&1) i--;
            t++;
        }
        ans++;
    }
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