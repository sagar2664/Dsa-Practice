#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n,u;
    cin>>n>>u;
    vector<int> v(n);
    for(auto& i:v)
    cin>>i;

    int ia=-1,ib,ic;
    int k=0;
    bool f=false;
    long double ans=0.0;
    for(int i=0;i<n;i++)
    {
        k=max(k,i);
        while(k+1<n && v[k+1]-v[i]<=u)
        k++;

        if(k-i+1>=3)
        {
            f=true;
            if(ia==-1 || (v[k]-v[i+1])*(v[ic]-v[ia])>(v[ic]-v[ib])*(v[k]-v[i]))
            {ia=i;ib=i+1,ic=k;}
        }
    }
    if(f)
    {
        ans=v[ic]-v[ib];
        ans/=v[ic]-v[ia];
        cout<<fixed<<setprecision(16)<<ans<<endl;
    }
    else
    cout<<-1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}