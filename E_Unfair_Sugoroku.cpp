#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,sx,sy,a,b;
vector<vector<vector<int>>> dp;

int rec(int x,int y,int t)
{
    if(x>=n) return 1;
    if(y>=n) return 0;

    if(dp[x][y][t]!=-1) return dp[x][y][t];

    int ans=0;
    if(t==0)
    {
        for(int i=1;i<=a;i++)
        ans=(ans+rec(x+i,y,1))%mod;
    }
    else
    for(int i=1;i<=b;i++)
        ans=(ans+rec(x,y+i,0))%mod;
    
    return dp[x][y][t]=ans;
}

int cnt(int x,int y,int t)
{
    if(x>=n) return 1;
    if(y>=n) return 1;

    if(dp[x][y][t]!=-1) return dp[x][y][t];

    int ans=0;
    if(t==0)
    {
        for(int i=1;i<=a;i++)
        ans=(ans+cnt(x+i,y,1))%mod;
    }
    else
    for(int i=1;i<=b;i++)
        {
            if(y+i>=n) return dp[x][y][t]=1;
        }
    
    return dp[x][y][t]=ans;
}

void solve()
{
    cin>>n>>sx>>sy>>a>>b;
    dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    int y=rec(sx,sy,0);
    cout<<y<<endl;
    dp.clear();
    dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
    int x=cnt(sx,sy,0);
    cout<<x<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}