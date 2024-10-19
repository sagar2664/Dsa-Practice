#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'
#define ld long double

void solve()
{
    int n;
    cin>>n;
    int a=0,b=0;
    ld ans=0;
    for(int i=0;i<n;i++)
    {
        int c,d;
        cin>>c>>d;
        ans+=sqrt((a-c)*(a-c)+(b-d)*(b-d));
        a=c;
        b=d;
    }
    ans+=sqrt(a*a+b*b);
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        solve();
}