#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>v[i][j];

    for(int p=0;p<n;p++)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            for(int j=0;j<m;j++)
            {
                if(v[i][v[p][j]-1]!=cnt) break;
                cnt++;
            }
            ans=max(ans,cnt-1);
        }
        cout<<ans<<' ';
    }
    cout<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin >> _t;while (_t--)
        solve();
}