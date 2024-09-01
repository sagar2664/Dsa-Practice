#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v(n),p(n);
    for(auto& i:v)cin>>i;
    sort(v.begin(),v.end());
    p[0]=v[0];
    for(int i=1;i<n;i++)p[i]=v[i]+p[i-1];
    while(q--)
    {
        int x;
        cin>>x;
        int idx=n,l=0,r=n-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(v[m]<=x)
            l=m+1;
            else idx=m,r=m-1;
        }
        int cnt=0;
        if(idx!=0)
        cnt+=(idx*x)-p[idx-1];
        cnt+=(p[n-1]-((idx-1>=0)?p[idx-1]:0))-(n-idx)*x;
        cout<<cnt<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}