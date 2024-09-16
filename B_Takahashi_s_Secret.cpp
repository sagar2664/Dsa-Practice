#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> g(n);
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        g[i]=t-1;
        //g[t-1].push_back(i);
    }
    x--;
    vector<bool> vis(n,false);

    int i=x;
    int cnt=0;
    while(!vis[i])
    {
        vis[i]=true;
        i=g[i];
        cnt++;
    }
    cout<<cnt<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}