#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int n,x,ans;
vector<vector<int>> pl;

void dfs(int pos,int mul)
{
    if(pos==n)
    {
        if(mul==x) ans++;
        return;
    }

    for(auto c:pl[pos])
    {
        if(mul>x/c) continue;
        dfs(pos+1,mul*c);
    }
}
void solve()
{
    cin>>n>>x;
    pl.resize(n);
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        pl[i].resize(l);
        for(int j=0;j<l;j++)
        cin>>pl[i][j];
    }
    dfs(0,1);
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}