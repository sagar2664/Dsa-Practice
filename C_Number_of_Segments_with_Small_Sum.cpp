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

    int l=0,ans=0,sum=0;
    for(int r=0;r<n;r++)
    {
        sum+=v[r];
        while(sum>s)
        {
            sum-=v[l];
            l++;
        }
        ans+=r-l+1;
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