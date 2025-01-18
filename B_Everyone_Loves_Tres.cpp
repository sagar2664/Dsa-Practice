#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
#define endl '\n'

void solve()
{
    int n;
    cin>>n;

    if(n==1 || n==3)
    {
        cout<<-1<<endl;
        return;
    }

    string e="66",o="36366";

    string ans;
    if(n%2)
    {
        for(int i=0;i<n-5;i++)
        ans+='3';
        ans+=o;
    }
    else
    {
        for(int i=0;i<n-2;i++)
        ans+='3';
        ans+=e;
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