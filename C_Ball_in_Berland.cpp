#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int a,b,k;
    cin>>a>>b>>k;
    vector<vector<int>> v(a+1);
    
    vector<int> A(k);
    map<int,int> cnt;
    for(auto &i:A) cin>>i;

    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        v[A[i]].push_back(x);
        cnt[x]++;
    }

    int ans=0;
    int sum=0;

    for(int i=1;i<=a;i++)
    {
        sum+=v[i].size();
        for(int j=0;j<v[i].size();j++)
        {
            ans+=k-sum-cnt[v[i][j]]+1;
            cnt[v[i][j]]--;
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