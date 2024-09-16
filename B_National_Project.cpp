#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,g,b;
    cin>>n>>g>>b;

    int need=(n+2-1)/2;
    int nslot=need/g;
    int add=need%g;

    int ans=(g+b)*nslot;
    if(add==0)
    ans-=b;
    else
    ans+=add;

    cout<<max(n,ans)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}