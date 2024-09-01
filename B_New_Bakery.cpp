#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    int k=0;
    int i=1;
    int l=0;
    int h=n;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(b-m+1>a)
        k=m,l=m+1;
        else h=m-1;
    }
    //cout<<k<<' ';
    if(k==0)
    cout<<(n*a)<<endl;
    else
    {
        int ans=k*b;
        ans-=k*(k+1)/2;
        ans+=k;
        ans+=(n-k)*a;
        cout<<ans<<endl;
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