#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,m;
vector<vector<int>> v;

int mn(int i,int j)
{
    int ans=-1e18;
    if(i-1>=0)
    ans=max(ans,v[i-1][j]);
    if(i+1<n)
    ans=max(ans,v[i+1][j]);
    if(j-1>=0)
    ans=max(ans,v[i][j-1]);
    if(j+1<m)
    ans=max(ans,v[i][j+1]);
    return ans;
}

void solve()
{
    cin>>n>>m;
    v.clear();
    v.resize(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>v[i][j];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int k=mn(i,j);
            if(v[i][j]>k) v[i][j]=k;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}