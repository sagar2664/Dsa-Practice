#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& i:a) cin>>i;

    vector<int> last(1e6,-1),dp(n);

    int ans=1;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        vector<int> div;
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j!=0) continue;
            
            if(last[j]!=-1 && j!=1) dp[i]=max(dp[i],dp[last[j]]+1);
            if(j!=1) div.push_back(j);

            if(a[i]/j!=j)
            {
                if(last[a[i]/j]!=-1) dp[i]=max(dp[i],dp[last[a[i]/j]]+1);
                div.push_back(a[i]/j);
            }
        }
        // for(auto it:div) cout<<it<<' ';
        // cout<<endl;
        for(auto it:div) last[it]=i;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}