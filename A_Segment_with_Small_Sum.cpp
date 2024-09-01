#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    for(auto& i:v)
    cin>>i;

    int sum=0,j=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        while(j<n && sum>s)
        {
            sum-=v[j];
            j++;
        }
        ans=max(i-j+1,ans);
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}