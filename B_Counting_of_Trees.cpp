#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> cnt(n);
    int m=0;
    bool f=false;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(i==0 && x) f=true;
        cnt[x]++;
        m=max(m,x);
    }

    if(cnt[0]!=1 || f)
    {
        cout<<0<<endl;
        return;
    }

    int ans=1;
    for(int i=1;i<=m;i++)
    {
        int p=cnt[i];
        while(p--)
        ans=(ans*cnt[i-1])%mod;
    }

    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);solve();
}