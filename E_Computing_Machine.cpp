#define ll long long
class Solution {
public:
    int n;
    vector<int> v;
    ll dp[100010][2];
    
    ll rec(int i,int prev)
    {
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        ll ans=-1e18;
        if(prev==1)
        {
            ll t=v[i]+rec(i+1,0);
            ans=max(ans,t);
        }
        if(prev==0)
        {
            ll t=(-v[i])+rec(i+1,1);
            ll j=v[i]+rec(i+1,0);
            ans=max({ans,t,j});
        }
        return dp[i][prev]=ans;
    }
    
    long long maximumTotalCost(vector<int>& v) {
        this->v=v;
        n=v.size();
        for(int i=0;i<n;i++)
        {
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        return rec(0,1);
    }
};