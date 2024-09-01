#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

int cube(int x)
{
    return x*x*x;
}

void solve()
{
    int n;
    cin>>n;
    int t=cbrt(n)+20;
    //cout<<t<<' ';
    for(int b=1;b<=t;b++)
    {
        if(n-cube(b)<=0) continue;
        int l=1,r=t;
        while(r-l>1)
        {
            int m=(l+r)/2;
            if(cube(m)>=n-cube(b)) r=m;
            else l=m;
        }
        if(cube(r)==n-cube(b) || cube(l)==n-cube(b))
        {
            //cout<<b<<' '<<l<<' ';
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>>_t;while(_t--)
    solve();
}