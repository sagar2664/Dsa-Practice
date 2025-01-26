#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,k;
int rec(int r,int s)
{
    if(r<k || r<=0) return 0;

    int ans=0;
    if(r&1)
    {
        int m=(r+1)/2;
    }
    else 
    ans=rec(r/2,s*2);

    return ans;
}

void solve()
{
    cin>>n>>k;
    cout<<rec(n,1)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}