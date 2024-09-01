#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,a,b,c;
vector<int> dp;

int rec(int l)
{
    if(dp[l]!=-1) return dp[l];

    if(l==0) return dp[l]=0;

    int ans=INT_MIN;
    if(l>=a) ans=max(ans,1+rec(l-a));
    if(l>=b) ans=max(ans,1+rec(l-b));
    if(l>=c) ans=max(ans,1+rec(l-c));

    return dp[l]=ans;
}
void solve()
{
    cin>>n>>a>>b>>c;
    dp.resize(n+1,-1);
    cout<<rec(n)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}