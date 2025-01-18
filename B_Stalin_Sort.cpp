#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v) cin>>i;

    int ans=1e18;

    for(int i=0;i<n;i++)
    {
        bool af=false;
        int cnt=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]>v[i]) cnt++;
        }
        //cout<<cnt<<' ';
        ans=min(ans,cnt);
    }
    //cout<<endl;
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