#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> v;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }

    vector<int> b;
    int prev=-1;
    int j=0;
    for(auto it:mp)
    {
        //cout<<it.first<<' ';
        if(prev==-1)
        {
            v.push_back(it.second);
        }
        else if(it.first!=prev+1)
        {
            b.push_back(j-1);
            v.push_back(it.second);
        }
        else
        {
            v.push_back(it.second);
        }
        j++;
        prev=it.first;
    }
    // cout<<endl;
    b.push_back((int)mp.size()-1);
    // for(auto it:b)
    // cout<<it<<' ';
    // cout<<endl;
    
    // for(auto it:v)
    // cout<<it<<' ';
    // cout<<endl;
    // cout<<endl;

    
    int ans=0;
    for(int sz=0;sz<b.size();sz++)
    {
        int cur=0;
        if(sz==0) cur=b[sz]+1;
        else cur=b[sz]-b[sz-1];
        int cnt=0;
        //cout<<cur<<' ';
        int st=0;
        if(sz!=0) st=b[sz-1]+1;

        if(cur<=k)
        {
            for(int i=st;i<=b[sz];i++)
            cnt+=v[i];
            ans=max(ans,cnt);
            continue;
        }

        for(int i=st;i<=st+k-1;i++)
        cnt+=v[i];

        ans=max(ans,cnt);

        int j=st;
        for(int i=st+k;i<=b[sz];i++)
        {
            cnt-=v[j];
            cnt+=v[i];
            ans=max(ans,cnt);
            j++;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}