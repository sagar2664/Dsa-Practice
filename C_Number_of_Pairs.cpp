#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> v(n);
    for(auto& i:v)
    cin>>i;
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int j=0,k=n-1;
        while(j<=k)
        {
            int m=(j+k)/2;
            if(v[m]>=l-v[i]) k=m;
            else j=m;
        }
        int left=k;
        j=0;
        k=n;
        while(k-j>1)
        {
            int m=(j+k)/2;
            if(v[m]>r-v[i]) k=m;
            else j=m;
        }
        int right=k-1;
        cout<<left<<' '<<right<<endl;
        if(right<left) continue;
        ans+=(right-left+1);
        if(left<=i && i<=right) ans--;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);int _t;cin >> _t;while (_t--)
        solve();
}