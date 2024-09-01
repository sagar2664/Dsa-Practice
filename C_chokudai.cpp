#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

// int rec(int i,int j,string &s,string& t,vector<vector<int>> &dp)
// {
//     if(j==t.length()) return 1;
//     if(i==s.length()) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int ans=0;
//     ans=rec(i+1,j,s,t,dp);
//     if(s[i]==t[j]) ans=(ans+rec(i+1,j+1,s,t,dp))%mod;
//     return dp[i][j]=ans;
// }

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int m=8;
    string t="chokudai";
    vector<vector<int>> dp(s.length()+1,vector<int>(9));
    for(int i=0;i<=n;i++)
    dp[i][0]=1;

    for(int j=1;j<=8;j++)
    dp[0][j]=0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }

    cout<<dp[n][m]<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}