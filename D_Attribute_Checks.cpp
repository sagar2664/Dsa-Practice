#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n;
int m;
vector<int> r;
vector<vector<int>> dp;

int rec(int i,int I,int p)
{
    if(i==n) return 0;

    if(dp[i][I]!=-1) return dp[i][I];

    int ans=0;

    if(r[i]==0)
    {
        ans=max(rec(i+1,I,p+1),rec(i+1,I+1,p+1));
    }
    else if(r[i]>0)
    {
        if(I>=r[i]) ans=1+rec(i+1,I,p);
        else ans=rec(i+1,I,p);
    }
    else
    {
        if(-r[i]<=p-I) ans=1+rec(i+1,I,p);
        else ans=rec(i+1,I,p);
    }

    return dp[i][I]=ans;
}
void solve()
{
    cin>>n>>m;
    dp.resize(n,vector<int>(m+1,-1));
    r.resize(n);
    for(auto &i:r) cin>>i;
    cout<<rec(0,0,0)<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}