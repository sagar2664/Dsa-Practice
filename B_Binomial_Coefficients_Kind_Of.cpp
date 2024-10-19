#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int pow2[100010];
void pre()
{
    pow2[0]=1;
    for(int i=1;i<100010;i++)
    {
        pow2[i]=(pow2[i-1]*2)%mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cout<<pow2[x]<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pre();
        solve();
}