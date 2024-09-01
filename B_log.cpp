#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    n++;
    int l=0,r=2e9;
    while(r-l>1)
    {
        int m=l+(r-l)/2;
        if((m*(m+1)/2) <= n)
        l=m;
        else r=m;
    }
    //cout<<l<<endl;
    cout<<(n-l)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}